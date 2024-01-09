#ifndef MASTERVIEW_H
#define MASTERVIEW_H

#include <QWidget>
#include "loginview.h"
#include "doctorview.h"
#include "departview.h"
#include "patientview.h"
#include "patienteditview.h"
#include "welcomeview.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MasterView; }
QT_END_NAMESPACE

class MasterView : public QWidget
{
    Q_OBJECT

public:
    MasterView(QWidget *parent = nullptr);
    ~MasterView();

public slots:
    void goLoginView();
    void goWelcomeView();
    void goDoctorView();
    void goDepartView();
    void goPatientView();
    void goPatienteditView(int rowNo);
    void goPreviousView();

private slots:
    void on_btBack_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btLogout_clicked();

private:
    void pushWidgetToStackView(QWidget *widget);

    Ui::MasterView *ui;

    WelcomeView *welcomeView;
    DoctorView *doctorView;
    DepartView *departView;
    PatientView *patientView;
    LoginView *loginView;
    patientEditView *patienteditView;
};
#endif // MASTERVIEW_H
