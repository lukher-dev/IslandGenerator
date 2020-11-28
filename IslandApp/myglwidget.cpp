// myglwidget.cpp

#include <QtWidgets>
#include <QOpenGLWidget>
#include <QtOpenGL>

#include "myglwidget.h"

static float map_size = 4;

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 400;
    yRot = 1000;
    zRot = 0;
    updateMap();
}

MyGLWidget::~MyGLWidget()
{
}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(1500, 1500);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 16;
    while (angle > 360)
        angle -= 360 * 16;
}


void MyGLWidget::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setLandNoise(int amount){
    islandGenerator.setLandNoise((float)amount/100.0);
    updateMap();
    updateGL();
}

void MyGLWidget::setLand(int amount){
    islandGenerator.setLand((float)amount/100.0);
    updateMap();
    updateGL();
}

void MyGLWidget::setWaterNoise(int amount){
    islandGenerator.setSeabedNoise((float)amount/100.0);
    updateMap();
    updateGL();
}

void MyGLWidget::setWater(int amount){
    islandGenerator.setSeabed((float)amount/100.0);
    updateMap();
    updateGL();
}

void MyGLWidget::setFrequency(int amount){
    islandGenerator.setFrequency(amount/10.0);
    updateMap();
    updateGL();
}

void MyGLWidget::setResolution(int number){
    islandGenerator.setResolution(number);
    updateMap();
    updateGL();
}

void MyGLWidget::setOctaves(int amount){
    islandGenerator.setOctaves(amount/100.0);
    updateMap();
    updateGL();
}

void MyGLWidget::setScroll(int amount){
    islandGenerator.setScroll(amount/100.0);
    updateMap();
    updateGL();
}

void MyGLWidget::setRoughness(int amount){
    islandGenerator.setRoughness(amount/100.0);
    updateMap();
    updateGL();
}

void MyGLWidget::setRoughnessFrequency(int amount){
    islandGenerator.setRoughnessFrequency(amount/10.0);
    updateMap();
    updateGL();
}

void MyGLWidget::setText(QString name){
    islandGenerator.setName(name.toUtf8().constData());
};

void MyGLWidget::setPointsString(QString name){
    islandGenerator.setPointsString(name.toUtf8().constData());
};

void MyGLWidget::saveToFile(){
    islandGenerator.saveToFile();
};

void MyGLWidget::loadPointsFromFile(){
    updateMap();
    updateGL();
}

void MyGLWidget::initializeGL()
{
    qglClearColor(Qt::black);

    glEnable(GL_SCISSOR_TEST);

        // Enable depth test
        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LEQUAL);

        // ** ORTHOGONAL VIEWS **

        // For orthogonal views, use wireframe rendering
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        // Enable line anti-aliasing
        glEnable(GL_LINE_SMOOTH);
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -10.0);
    glRotatef(xRot / 16.0, 1.0, 0.0, 0.0);
    glRotatef(yRot / 16.0, 0.0, 1.0, 0.0);
    glRotatef(zRot / 16.0, 0.0, 0.0, 1.0);
    draw();
}

void MyGLWidget::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void MyGLWidget::updateMap(){
    islandGenerator.generateIsland();
}

void MyGLWidget::draw()
{
    static GLuint island = 0;
    int    i, j, resolution;
    double x, y, z;

    resolution = islandGenerator.getResolution();
    std::vector<std::vector<float>> heightMap = islandGenerator.getIsland();
    float map_step = map_size / (float)resolution;

    island = glGenLists(1);
    glNewList(island, GL_COMPILE_AND_EXECUTE);

    for (i = 0; i < resolution - 1; i += 1) {
        for (j = 0; j < resolution - 1; j += 1) {
            glBegin(GL_TRIANGLE_STRIP);
            // Calculate point on surface
            x = (float)i * map_step - map_size / 2;
            z = (float)j * map_step - map_size / 2;
            y = heightMap[i][j];
            glVertex3f((float)x, (float)y, (float)z);

            x = (float)(i + 1) * map_step - map_size / 2;
            z = (float)j * map_step - map_size / 2;
            y = heightMap[i + 1][j];
            glVertex3f((float)x, (float)y, (float)z);

            x = (float)i * map_step - map_size / 2;
            z = (float)(j + 1) * map_step - map_size / 2;
            y = heightMap[i][j + 1];
            glVertex3f((float)x, (float)y, (float)z);

            x = (float)(i + 1) * map_step - map_size / 2;
            z = (float)(j + 1) * map_step - map_size / 2;
            y = heightMap[i + 1][j + 1];
            glVertex3f((float)x, (float)y, (float)z);
        }

        glEnd();
    }

    glEndList();
}
