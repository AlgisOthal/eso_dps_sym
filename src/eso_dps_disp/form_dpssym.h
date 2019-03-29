#ifndef FORM_DPSSYM_H
#define FORM_DPSSYM_H

#include <QWidget>

#include <eso_dps_sym/dps_sym.h>

namespace Ui {
class FormDpsSym;
}

class FormDpsSym : public QWidget
{
    Q_OBJECT

public:
    explicit FormDpsSym(QWidget *parent = 0);
    ~FormDpsSym();

private slots:
    void on_pushButton_clicked();

private:
    TakenDamages symDamage();

    Ui::FormDpsSym *ui;
};

#endif // FORM_DPSSYM_H
