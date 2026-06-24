/********************************************************************************
** Form generated from reading UI file 'View_Dicom.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEW_DICOM_H
#define UI_VIEW_DICOM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvtkopenglnativewidget.h"

QT_BEGIN_NAMESPACE

class Ui_View_Dicom
{
public:
    QAction *actionOpen_File;
    QAction *actionOpen_Directory;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_5;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout;
    QVTKOpenGLNativeWidget *QVTK_axialWidget;
    QSlider *verticalSlider;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVTKOpenGLNativeWidget *QVTK_sagittalWidget;
    QSlider *verticalSlider_2;
    QHBoxLayout *horizontalLayout_3;
    QVTKOpenGLNativeWidget *QVTK_coronalWidget;
    QSlider *verticalSlider_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tableWidget;
    QWidget *tab_2;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *View_Dicom)
    {
        if (View_Dicom->objectName().isEmpty())
            View_Dicom->setObjectName("View_Dicom");
        View_Dicom->resize(1920, 1080);
        actionOpen_File = new QAction(View_Dicom);
        actionOpen_File->setObjectName("actionOpen_File");
        actionOpen_Directory = new QAction(View_Dicom);
        actionOpen_Directory->setObjectName("actionOpen_Directory");
        centralwidget = new QWidget(View_Dicom);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");

        horizontalLayout_4->addWidget(pushButton_1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_4->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_4->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_4->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_4->addWidget(pushButton_5);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setMinimumSize(QSize(0, 0));
        treeWidget->setMaximumSize(QSize(250, 16777215));

        horizontalLayout_5->addWidget(treeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMinimumSize);
        QVTK_axialWidget = new QVTKOpenGLNativeWidget(centralwidget);
        QVTK_axialWidget->setObjectName("QVTK_axialWidget");
        QVTK_axialWidget->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(QVTK_axialWidget);

        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName("verticalSlider");
        verticalSlider->setOrientation(Qt::Orientation::Vertical);

        horizontalLayout->addWidget(verticalSlider);


        horizontalLayout_5->addLayout(horizontalLayout);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        QVTK_sagittalWidget = new QVTKOpenGLNativeWidget(centralwidget);
        QVTK_sagittalWidget->setObjectName("QVTK_sagittalWidget");
        QVTK_sagittalWidget->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(QVTK_sagittalWidget);

        verticalSlider_2 = new QSlider(centralwidget);
        verticalSlider_2->setObjectName("verticalSlider_2");
        verticalSlider_2->setOrientation(Qt::Orientation::Vertical);

        horizontalLayout_2->addWidget(verticalSlider_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        QVTK_coronalWidget = new QVTKOpenGLNativeWidget(centralwidget);
        QVTK_coronalWidget->setObjectName("QVTK_coronalWidget");
        QVTK_coronalWidget->setMinimumSize(QSize(0, 0));

        horizontalLayout_3->addWidget(QVTK_coronalWidget);

        verticalSlider_3 = new QSlider(centralwidget);
        verticalSlider_3->setObjectName("verticalSlider_3");
        verticalSlider_3->setOrientation(Qt::Orientation::Vertical);

        horizontalLayout_3->addWidget(verticalSlider_3);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_5->addLayout(verticalLayout);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setMinimumSize(QSize(0, 0));
        tabWidget->setMaximumSize(QSize(400, 16777215));
        tab = new QWidget();
        tab->setObjectName("tab");
        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 0, 131, 171));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tableView = new QTableView(tab_2);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(0, 0, 131, 171));
        tabWidget->addTab(tab_2, QString());

        horizontalLayout_5->addWidget(tabWidget);


        verticalLayout_2->addLayout(horizontalLayout_5);

        View_Dicom->setCentralWidget(centralwidget);
        menubar = new QMenuBar(View_Dicom);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 21));
        menubar->setMinimumSize(QSize(500, 0));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        View_Dicom->setMenuBar(menubar);
        statusbar = new QStatusBar(View_Dicom);
        statusbar->setObjectName("statusbar");
        View_Dicom->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen_File);
        menuFile->addAction(actionOpen_Directory);

        retranslateUi(View_Dicom);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(View_Dicom);
    } // setupUi

    void retranslateUi(QMainWindow *View_Dicom)
    {
        View_Dicom->setWindowTitle(QCoreApplication::translate("View_Dicom", "MainWindow", nullptr));
        actionOpen_File->setText(QCoreApplication::translate("View_Dicom", "Open File", nullptr));
        actionOpen_Directory->setText(QCoreApplication::translate("View_Dicom", "Open Directory", nullptr));
        pushButton_1->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("View_Dicom", "Tab 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("View_Dicom", "Tab 2", nullptr));
        menuFile->setTitle(QCoreApplication::translate("View_Dicom", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class View_Dicom: public Ui_View_Dicom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEW_DICOM_H
