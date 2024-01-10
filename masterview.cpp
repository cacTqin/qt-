#include "masterview.h"
#include "ui_masterview.h"
#include <QDebug>
#include "idatabase.h"

MasterView::MasterView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MasterView)
{
    ui->setupUi(this);

//    this->setWindowFlag(Qt::FramelessWindowHint);

    goLoginView();

    IDatabase::getInstance();
}

MasterView::~MasterView()
{
    delete ui;
}

void MasterView::goLoginView()
{
    qDebug()<<"goLoginView";
    loginView = new LoginView(this);

    pushWidgetToStackView(loginView);

    connect(loginView,SIGNAL(loginSuccess()),this,SLOT(goWelcomeView()));
}

void MasterView::goWelcomeView()
{
    qDebug()<<"goWelcomeView";
    welcomeView = new WelcomeView(this);

    pushWidgetToStackView(welcomeView);

    connect(welcomeView,SIGNAL(goDoctorView()),this,SLOT(goDoctorView()));
    connect(welcomeView,SIGNAL(goPatientView()),this,SLOT(goPatientView()));
    connect(welcomeView,SIGNAL(goDepartView()),this,SLOT(goDepartView()));
}

void MasterView::goDoctorView()
{
    qDebug()<<"goDoctorView";
    doctorView = new DoctorView(this);

    pushWidgetToStackView(doctorView);
    connect(doctorView,SIGNAL(goDoctorEditView(int)),this,SLOT(goDoctorEditView(int)));
}

void MasterView::goDepartView()
{
    qDebug()<<"goDepartView";
    departView = new DepartView(this);

    pushWidgetToStackView(departView);
}

void MasterView::goPatientView()
{
    qDebug()<<"goPatientView";
    patientView = new PatientView(this);

    pushWidgetToStackView(patientView);

    connect(patientView,SIGNAL(goPatientEditView(int)),this,SLOT(goPatienteditView(int)));
}

void MasterView::goPatienteditView(int rowNo)
{
    qDebug()<<"goPatientedView";
    patienteditView = new patientEditView(this, rowNo);
    pushWidgetToStackView(patienteditView);

    connect(patienteditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goDoctorEditView(int rowNo)
{
    qDebug()<<"goDoctorEditView";
    doctorEditView = new DoctorEditView(this, rowNo);
    pushWidgetToStackView(doctorEditView);

    connect(doctorEditView,SIGNAL(goPreviousView()),this,SLOT(goPreviousView()));
}

void MasterView::goPreviousView()
{
    int count = ui->stackedWidget->count();
    if(count>1){
        ui->stackedWidget->setCurrentIndex(count-2);
        ui->tableTitle->setText(ui->stackedWidget->currentWidget()->windowTitle());

        QWidget *widget = ui->stackedWidget->widget(count-1);
        ui->stackedWidget->removeWidget(widget);
        delete widget;
    }
}

void MasterView::pushWidgetToStackView(QWidget *widget)
{
    ui->stackedWidget->addWidget(widget);
    int count = ui->stackedWidget->count();
    ui->stackedWidget->setCurrentIndex(count-1);
    ui->tableTitle->setText(widget->windowTitle());
}


void MasterView::on_btBack_clicked()
{
    goPreviousView();
}


void MasterView::on_stackedWidget_currentChanged(int arg1)
{
    int count = ui->stackedWidget->count();
    if(count>1){
        ui->btBack->setEnabled(true);
    }else{
        ui->btBack->setEnabled(false);
    }

    QString title = ui->stackedWidget->currentWidget()->windowTitle();

    if(title == "欢迎"){
        ui->btLogout->setEnabled(true);
        ui->btBack->setEnabled(false);
    }else{
        ui->btLogout->setEnabled(false);
    }
}


void MasterView::on_btLogout_clicked()
{
    goPreviousView();
    ui->btLogout->setEnabled(false);
    ui->btBack->setEnabled(false);
}

