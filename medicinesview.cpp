#include "medicinesview.h"
#include "ui_medicinesview.h"

MedicinesView::MedicinesView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MedicinesView)
{
    ui->setupUi(this);
}

MedicinesView::~MedicinesView()
{
    delete ui;
}
