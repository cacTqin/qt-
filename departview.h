#ifndef DEPARTVIEW_H
#define DEPARTVIEW_H

#include <QWidget>

namespace Ui {
class DepartView;
}

class DepartView : public QWidget
{
    Q_OBJECT

public:
    explicit DepartView(QWidget *parent = nullptr);
    ~DepartView();

private:
    Ui::DepartView *ui;
};

#endif // DEPARTVIEW_H
