#include "idatabase.h"
#include <QUuid>

void IDatabase::ininDatabase()
{
    database=QSqlDatabase::addDatabase("QSQLITE"); //添加 SQL LITE 数据库驱动
    QString aFile="../../MySQL/lab3.db";
    database.setDatabaseName(aFile); //设置数据库名称

    if(!database.open()){
        qDebug()<<"failed to open database";
    }else{
        qDebug()<<"open database is ok";
    }
}

//患者管理
bool IDatabase::initPatientModel()
{
    patientTabModel = new QSqlTableModel(this,database);
    patientTabModel->setTable("patient");
    patientTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//数据保存方式，OnManualSubmit , OnRowChange
    patientTabModel->setSort(patientTabModel->fieldIndex("name"),Qt::AscendingOrder); //排序
    if (!(patientTabModel->select())) return false;  //查询数据

    thePatientSelection = new QItemSelectionModel(patientTabModel);
    return true;
}

int IDatabase::addNewPatient()
{
    patientTabModel->insertRow(patientTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = patientTabModel->index(patientTabModel->rowCount()-1,1);
    int curRecNo = curIndex.row();
    QSqlRecord curRec = patientTabModel->record(curRecNo);
    curRec.setValue("CREATETIMESTAMP",QDateTime::currentDateTime().toString("yyyy-MM-dd"));

    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));

    patientTabModel->setRecord(curRecNo,curRec);

    return curIndex.row();
}

bool IDatabase::searchPatient(QString filter)
{
    patientTabModel->setFilter(filter);
    return patientTabModel->select();
}

bool IDatabase::deleteCurrentPatient()
{
    QModelIndex curIndex = thePatientSelection->currentIndex();
    patientTabModel->removeRow(curIndex.row());
    patientTabModel->submitAll();
    patientTabModel->select();
}

bool IDatabase::submitPatientEdit()
{
    return patientTabModel->submitAll();
}

void IDatabase::reverPatientEdit()
{
    patientTabModel->revertAll();
}

//医生管理
bool IDatabase::initDoctorModel()
{
    doctorTabModel = new QSqlTableModel(this,database);
    doctorTabModel->setTable("doctor");
    doctorTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//数据保存方式，OnManualSubmit , OnRowChange
    doctorTabModel->setSort(doctorTabModel->fieldIndex("name"),Qt::AscendingOrder); //排序
    if (!(doctorTabModel->select())) return false;  //查询数据

    theDoctorSelection = new QItemSelectionModel(doctorTabModel);
    return true;
}

int IDatabase::addNewDoctor()
{
    doctorTabModel->insertRow(doctorTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = doctorTabModel->index(doctorTabModel->rowCount()-1,1);
    int curRecNo = curIndex.row();
    QSqlRecord curRec = doctorTabModel->record(curRecNo);
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));
    doctorTabModel->setRecord(curRecNo,curRec);
    return curIndex.row();
}

bool IDatabase::searchDoctor(QString filter)
{
    doctorTabModel->setFilter(filter);
    return doctorTabModel->select();
}

bool IDatabase::deleteCurrentDoctor()
{
    QModelIndex curIndex = theDoctorSelection->currentIndex();
    doctorTabModel->removeRow(curIndex.row());
    doctorTabModel->submitAll();
    doctorTabModel->select();
}

bool IDatabase::submitDoctorEdit()
{
    return doctorTabModel->submitAll();
}

void IDatabase::reverDoctorEdit()
{
    doctorTabModel->revertAll();
}

//药物管理
bool IDatabase::initMedicinesModel()
{
    medicinesTabModel = new QSqlTableModel(this,database);
    medicinesTabModel->setTable("medicines");
    medicinesTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//数据保存方式，OnManualSubmit , OnRowChange
    medicinesTabModel->setSort(medicinesTabModel->fieldIndex("name"),Qt::AscendingOrder); //排序
    if (!(medicinesTabModel->select())) return false;  //查询数据
    theMedicinesSelection = new QItemSelectionModel(medicinesTabModel);
    return true;
}

int IDatabase::addNewMedicines()
{
    medicinesTabModel->insertRow(medicinesTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = medicinesTabModel->index(medicinesTabModel->rowCount()-1,1);
    int curRecNo = curIndex.row();
    QSqlRecord curRec = medicinesTabModel->record(curRecNo);
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));
    medicinesTabModel->setRecord(curRecNo,curRec);
    return curIndex.row();
}

bool IDatabase::searchMedicines(QString filter)
{
    medicinesTabModel->setFilter(filter);
    return medicinesTabModel->select();
}

bool IDatabase::deleteCurrentMedicines()
{
    QModelIndex curIndex = theMedicinesSelection->currentIndex();
    medicinesTabModel->removeRow(curIndex.row());
    medicinesTabModel->submitAll();
    medicinesTabModel->select();
}

bool IDatabase::submitMedicinesEdit()
{
    return medicinesTabModel->submitAll();
}

void IDatabase::reverMedicinesEdit()
{
    medicinesTabModel->revertAll();
}

//就诊记录
bool IDatabase::initHistoryModel()
{
    historyTabModel = new QSqlTableModel(this,database);
    historyTabModel->setTable("history");
    historyTabModel->setEditStrategy(QSqlTableModel::OnManualSubmit);//数据保存方式，OnManualSubmit , OnRowChange
    historyTabModel->setSort(historyTabModel->fieldIndex("name"),Qt::AscendingOrder); //排序
    if (!(historyTabModel->select())) return false;  //查询数据

    theHistorySelection = new QItemSelectionModel(historyTabModel);
    return true;
}

int IDatabase::addNewHistory()
{
    historyTabModel->insertRow(historyTabModel->rowCount(),QModelIndex());
    QModelIndex curIndex = historyTabModel->index(historyTabModel->rowCount()-1,1);
    int curRecNo = curIndex.row();
    QSqlRecord curRec = historyTabModel->record(curRecNo);
    curRec.setValue("ID",QUuid::createUuid().toString(QUuid::WithoutBraces));
    historyTabModel->setRecord(curRecNo,curRec);
    return curIndex.row();
}

bool IDatabase::searchHistory(QString filter)
{
    historyTabModel->setFilter(filter);
    return historyTabModel->select();
}

bool IDatabase::deleteCurrentHistory()
{
    QModelIndex curIndex = theHistorySelection->currentIndex();
    historyTabModel->removeRow(curIndex.row());
    historyTabModel->submitAll();
    historyTabModel->select();
}

bool IDatabase::submitHistoryEdit()
{
    return historyTabModel->submitAll();
}

void IDatabase::reverHistoryEdit()
{
    historyTabModel->revertAll();
}

//登录注册
QString IDatabase::userLogin(QString userName, QString password)
{
   // return "loginOK";
//    return "loginFailed";
    QSqlQuery query;
    query.prepare("select username,password from User where username= :USER");
    query.bindValue(":USER",userName);
    query.exec();
    if(query.first() && query.value("username").isValid()){
        QString passwd = query.value("password").toString();
        if(passwd == password){
            return "loginOK";
        }else{
            qDebug()<<"wrongPassword";
            return "wrongPassword";
        }
    }else{
        qDebug()<<"no such user";
        return "wroingUserName";
    }

}

IDatabase::IDatabase(QObject *parent) : QObject(parent)
{
    ininDatabase();
}


