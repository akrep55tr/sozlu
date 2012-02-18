#ifndef FORM_H
#define FORM_H
#include "ui_form.h"


class MyForm:public QWidget
{
  Q_OBJECT
  public:
    MyForm(QWidget* parent=0);
    Ui::Form ui;   // See Note below

    QSize sizeHint() const;

    QString p_n ;
    int e_s ;


 private:


private slots:
    void on_buttonBox_accepted();
};

#endif // FORM_H
