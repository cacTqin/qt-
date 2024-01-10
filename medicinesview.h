#ifndef MEDICINESVIEW_H
#define MEDICINESVIEW_H

#include <QWidget>

namespace Ui {
class MedicinesView;
}

class MedicinesView : public QWidget
{
    Q_OBJECT

public:
    explicit MedicinesView(QWidget *parent = nullptr);
    ~MedicinesView();

private slots:
    void on_btSearch_clicked();

    void on_btAdd_clicked();

    void on_btDelete_clicked();

    void on_btEdit_clicked();

signals:
    void goMedicinesEditView(int index);

private:
    Ui::MedicinesView *ui;
};

#endif // MEDICINESVIEW_H
