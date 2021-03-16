// myglwidget.h

#ifndef MYGLWIDGET_H
#define MYGLWIDGET_H

#include <QGLWidget>
#include "../IslandGenerator/islandgenerator.h"

class MyGLWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit MyGLWidget(QWidget *parent = 0);
    ~MyGLWidget();
signals:

public slots:

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void updateMap();

public slots:
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setLandNoise(int amount);
    void setLand(int amount);
    void setFrequency(int amount);
    void setResolution(int number);
    void setWaterNoise(int amount);
    void setWater(int amount);
    void setOctaves(int amount);
    void setScroll(int amount);
    void setRoughness(int amount);
    void setRoughnessFrequency(int amount);
    void setText(QString  name);
    void saveToFile();
    void setPointsString(QString in_string);
    void loadPointsFromFile();

signals:
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:
    void draw();

    int xRot;
    int yRot;
    int zRot;
    IslandGenerator islandGenerator;

    QPoint lastPos;
};

#endif // MYGLWIDGET_H

