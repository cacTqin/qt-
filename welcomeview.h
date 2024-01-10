#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include <QWidget>

namespace Ui {
class WelcomeView;
}

class WelcomeView : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeView(QWidget *parent = nullptr);
    ~WelcomeView();

private slots:
    void on_departManager_clicked();

    void on_doctorManager_clicked();

    void on_patientManager_clicked();

    void on_medicinesManager_clicked();

signals:
    void goDepartView();
    void goDoctorView();
    void goPatientView();
    void goMedicinesView();


private:
    Ui::WelcomeView *ui;
};

#endif // WELCOMEVIEW_H
