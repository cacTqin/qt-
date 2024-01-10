#include "patienteditview.h"
#include "ui_patienteditview.h"
#include <QSqlTableModel>
#include "idatabase.h"

patientEditView::patientEditView(QWidget *parent,int index) :
    QWidget(parent),
    ui(new Ui::patientEditView)
{
    ui->setupUi(this);

    dataMapper= new QDataWidgetMapper();
    QSqlTableModel *tabModel = IDatabase::getInstance().patientTabModel;
    dataMapper->setModel(IDatabase::getInstance().patientTabModel);
    dataMapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);//

    dataMapper->addMapping(ui->dbEditID,tabModel->fieldIndex("ID"));
    dataMapper->addMapping(ui->dbEditName,tabModel->fieldIndex("NAME"));
    dataMapper->addMapping(ui->dbEditIDCard,tabModel->fieldIndex("ID_CARD"));

    dataMapper->addMapping(ui->dbSpinHeight,tabModel->fieldIndex("HEIHET"));
    dataMapper->addMapping(ui->dbSpinWeight,tabModel->fieldIndex("WEIGHT"));
    dataMapper->addMapping(ui->dbEditPhone,tabModel->fieldIndex("MOBILEPHONE"));

    dataMapper->addMapping(ui->dbCreateTime,tabModel->fieldIndex("CREATETIMESTAMP"));
    dataMapper->addMapping(ui->dbEditSex,tabModel->fieldIndex("SEX"));
    dataMapper->addMapping(ui->dbDateEditDOB,tabModel->fieldIndex("DOB"));

    dataMapper->setCurrentIndex(index);
}

patientEditView::~patientEditView()
{
    delete ui;
}

void patientEditView::on_btSave_clicked()
{
    IDatabase::getInstance().submitPatientEdit();
    emit goPreviousView();
}


void patientEditView::on_btCancel_clicked()
{
    IDatabase::getInstance().reverPatientEdit();
    emit goPreviousView();
}

