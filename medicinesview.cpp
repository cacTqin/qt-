#include "medicinesview.h"
#include "ui_medicinesview.h"
#include "idatabase.h"

MedicinesView::MedicinesView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MedicinesView)
{
    ui->setupUi(this);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setAlternatingRowColors(true);

    IDatabase &iDatabase = IDatabase::getInstance();
    if(iDatabase.initMedicinesModel()){
        ui->tableView->setModel(iDatabase.medicinesTabModel);
        ui->tableView->setSelectionModel(iDatabase.theMedicinesSelection);
    }
}

MedicinesView::~MedicinesView()
{
    delete ui;
}

void MedicinesView::on_btSearch_clicked()
{
    QString filter = QString("name like '%%1%'").arg(ui->lineEdit->text());
    IDatabase::getInstance().searchMedicines(filter);
}


void MedicinesView::on_btAdd_clicked()
{
    int currow = IDatabase::getInstance().addNewMedicines();
    emit goMedicinesEditView(currow);
}


void MedicinesView::on_btDelete_clicked()
{
    IDatabase::getInstance().deleteCurrentMedicines();
}


void MedicinesView::on_btEdit_clicked()
{
    QModelIndex curIndex = IDatabase::getInstance().theMedicinesSelection->currentIndex();
    emit goMedicinesEditView(curIndex.row());
}

