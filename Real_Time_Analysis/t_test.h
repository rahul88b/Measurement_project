#ifndef T_TEST_H
#define T_TEST_H

#include <QDialog>

namespace Ui {
class t_test;
}

class t_test : public QDialog
{
    Q_OBJECT

public:
    explicit t_test(QWidget *parent = nullptr);
    ~t_test();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    double table_import(int dof,double alpha);

private:
    Ui::t_test *ui;
};

#endif // T_TEST_H
