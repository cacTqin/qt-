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

private:
    Ui::MedicinesView *ui;
};

#endif // MEDICINESVIEW_H
