/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QVideoWidget *video_output;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSlider *sld_pos;
    QPushButton *btn_choose;
    QPushButton *btn_pause;
    QSlider *sld_volume;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(688, 492);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        video_output = new QVideoWidget(centralwidget);
        video_output->setObjectName("video_output");
        verticalLayoutWidget = new QWidget(video_output);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(-10, -30, 671, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");

        verticalLayout_2->addWidget(video_output);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        sld_pos = new QSlider(centralwidget);
        sld_pos->setObjectName("sld_pos");
        sld_pos->setOrientation(Qt::Orientation::Horizontal);

        gridLayout->addWidget(sld_pos, 0, 1, 1, 1);

        btn_choose = new QPushButton(centralwidget);
        btn_choose->setObjectName("btn_choose");

        gridLayout->addWidget(btn_choose, 1, 0, 1, 2);

        btn_pause = new QPushButton(centralwidget);
        btn_pause->setObjectName("btn_pause");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/play.webp"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        btn_pause->setIcon(icon);

        gridLayout->addWidget(btn_pause, 0, 0, 1, 1);

        sld_volume = new QSlider(centralwidget);
        sld_volume->setObjectName("sld_volume");
        sld_volume->setMaximum(100);
        sld_volume->setSliderPosition(100);
        sld_volume->setOrientation(Qt::Orientation::Vertical);

        gridLayout->addWidget(sld_volume, 0, 2, 2, 1);


        verticalLayout_2->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\264\320\265\320\276\320\277\320\273\320\265\320\265\321\200", nullptr));
        btn_choose->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        btn_pause->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
