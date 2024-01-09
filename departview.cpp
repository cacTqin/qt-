#include "departview.h"
#include "ui_departview.h"

DepartView::DepartView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DepartView)
{
    ui->setupUi(this);
}

DepartView::~DepartView()
{
    delete ui;
}
