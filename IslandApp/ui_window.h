/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "myglwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QVBoxLayout *verticalLayout;
    MyGLWidget *myGLWidget;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *pointsEdit;
    QPushButton *loadButton;
    QHBoxLayout *horizontalLayout;
    QLabel *Resolution;
    QSlider *resolutionSlider;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *frequencySlider;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSlider *landSlider;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSlider *landNoiseSlider;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QSlider *waterSlider;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QSlider *waterNoiseSlider;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QSlider *octavesSlider;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QSlider *scrollSlider;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QSlider *roughnessSlider;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QSlider *RoughnessFrequencySlider;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *saveEdit;
    QPushButton *saveButton;

    void setupUi(QWidget *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(348, 534);
        verticalLayout = new QVBoxLayout(Window);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        myGLWidget = new MyGLWidget(Window);
        myGLWidget->setObjectName(QString::fromUtf8("myGLWidget"));
        myGLWidget->setMinimumSize(QSize(200, 200));

        verticalLayout->addWidget(myGLWidget);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        pointsEdit = new QLineEdit(Window);
        pointsEdit->setObjectName(QString::fromUtf8("pointsEdit"));

        horizontalLayout_12->addWidget(pointsEdit);

        loadButton = new QPushButton(Window);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));

        horizontalLayout_12->addWidget(loadButton);


        verticalLayout->addLayout(horizontalLayout_12);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Resolution = new QLabel(Window);
        Resolution->setObjectName(QString::fromUtf8("Resolution"));

        horizontalLayout->addWidget(Resolution);

        resolutionSlider = new QSlider(Window);
        resolutionSlider->setObjectName(QString::fromUtf8("resolutionSlider"));
        resolutionSlider->setMinimum(2);
        resolutionSlider->setMaximum(100);
        resolutionSlider->setValue(40);
        resolutionSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(resolutionSlider);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Window);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        frequencySlider = new QSlider(Window);
        frequencySlider->setObjectName(QString::fromUtf8("frequencySlider"));
        frequencySlider->setMinimum(1);
        frequencySlider->setMaximum(100);
        frequencySlider->setValue(36);
        frequencySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(frequencySlider);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_3 = new QLabel(Window);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        landSlider = new QSlider(Window);
        landSlider->setObjectName(QString::fromUtf8("landSlider"));
        landSlider->setMinimum(0);
        landSlider->setMaximum(100);
        landSlider->setValue(6);
        landSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(landSlider);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Window);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        landNoiseSlider = new QSlider(Window);
        landNoiseSlider->setObjectName(QString::fromUtf8("landNoiseSlider"));
        landNoiseSlider->setMinimum(0);
        landNoiseSlider->setMaximum(100);
        landNoiseSlider->setSingleStep(1);
        landNoiseSlider->setValue(32);
        landNoiseSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(landNoiseSlider);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(Window);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        waterSlider = new QSlider(Window);
        waterSlider->setObjectName(QString::fromUtf8("waterSlider"));
        waterSlider->setMinimum(1);
        waterSlider->setMaximum(100);
        waterSlider->setValue(17);
        waterSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(waterSlider);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(Window);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_6->addWidget(label_5);

        waterNoiseSlider = new QSlider(Window);
        waterNoiseSlider->setObjectName(QString::fromUtf8("waterNoiseSlider"));
        waterNoiseSlider->setMinimum(0);
        waterNoiseSlider->setMaximum(100);
        waterNoiseSlider->setValue(10);
        waterNoiseSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(waterNoiseSlider);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_6 = new QLabel(Window);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_8->addWidget(label_6);

        octavesSlider = new QSlider(Window);
        octavesSlider->setObjectName(QString::fromUtf8("octavesSlider"));
        octavesSlider->setMinimum(0);
        octavesSlider->setMaximum(100);
        octavesSlider->setValue(43);
        octavesSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_8->addWidget(octavesSlider);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_7 = new QLabel(Window);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_7->addWidget(label_7);

        scrollSlider = new QSlider(Window);
        scrollSlider->setObjectName(QString::fromUtf8("scrollSlider"));
        scrollSlider->setMinimum(0);
        scrollSlider->setMaximum(1600);
        scrollSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(scrollSlider);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_8 = new QLabel(Window);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        roughnessSlider = new QSlider(Window);
        roughnessSlider->setObjectName(QString::fromUtf8("roughnessSlider"));
        roughnessSlider->setMaximum(50);
        roughnessSlider->setValue(14);
        roughnessSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_9->addWidget(roughnessSlider);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_9 = new QLabel(Window);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        RoughnessFrequencySlider = new QSlider(Window);
        RoughnessFrequencySlider->setObjectName(QString::fromUtf8("RoughnessFrequencySlider"));
        RoughnessFrequencySlider->setValue(7);
        RoughnessFrequencySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_10->addWidget(RoughnessFrequencySlider);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        saveEdit = new QLineEdit(Window);
        saveEdit->setObjectName(QString::fromUtf8("saveEdit"));

        horizontalLayout_11->addWidget(saveEdit);

        saveButton = new QPushButton(Window);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        horizontalLayout_11->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout_11);


        retranslateUi(Window);
        QObject::connect(landNoiseSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setLandNoise(int)));
        QObject::connect(landSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setLand(int)));
        QObject::connect(resolutionSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setResolution(int)));
        QObject::connect(frequencySlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setFrequency(int)));
        QObject::connect(waterNoiseSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setWaterNoise(int)));
        QObject::connect(waterSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setWater(int)));
        QObject::connect(octavesSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setOctaves(int)));
        QObject::connect(scrollSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setScroll(int)));
        QObject::connect(roughnessSlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setRoughness(int)));
        QObject::connect(RoughnessFrequencySlider, SIGNAL(valueChanged(int)), myGLWidget, SLOT(setRoughnessFrequency(int)));
        QObject::connect(saveEdit, SIGNAL(textChanged(QString)), myGLWidget, SLOT(setText(QString)));
        QObject::connect(saveButton, SIGNAL(clicked()), myGLWidget, SLOT(saveToFile()));
        QObject::connect(pointsEdit, SIGNAL(textChanged(QString)), myGLWidget, SLOT(setPointsString(QString)));
        QObject::connect(loadButton, SIGNAL(clicked()), myGLWidget, SLOT(loadPointsFromFile()));

        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QWidget *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "Window", nullptr));
        pointsEdit->setText(QCoreApplication::translate("Window", "[0.3,0.2],[0.1,0.9],[0.9,0.9],[0.6,0.7],[0.8,0.1]", nullptr));
        loadButton->setText(QCoreApplication::translate("Window", "Reload", nullptr));
        Resolution->setText(QCoreApplication::translate("Window", "Resolution", nullptr));
        label->setText(QCoreApplication::translate("Window", "Frequency", nullptr));
        label_3->setText(QCoreApplication::translate("Window", "Land height", nullptr));
        label_2->setText(QCoreApplication::translate("Window", "Land noise", nullptr));
        label_4->setText(QCoreApplication::translate("Window", "Seabed height", nullptr));
        label_5->setText(QCoreApplication::translate("Window", "Seabed noise", nullptr));
        label_6->setText(QCoreApplication::translate("Window", "Octaves", nullptr));
        label_7->setText(QCoreApplication::translate("Window", "Scroll", nullptr));
        label_8->setText(QCoreApplication::translate("Window", "Roughness", nullptr));
        label_9->setText(QCoreApplication::translate("Window", "Roughness freq", nullptr));
        saveEdit->setText(QCoreApplication::translate("Window", "test", nullptr));
        saveButton->setText(QCoreApplication::translate("Window", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
