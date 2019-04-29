#ifndef Z_TEST_H
#define Z_TEST_H

#include <QDialog>

namespace Ui {
class z_test;
}

class z_test : public QDialog
{
    Q_OBJECT

public:
    explicit z_test(QWidget *parent = nullptr);
    ~z_test();

private slots:
    void on_pushButton_clicked();

private:
    Ui::z_test *ui;
};

#endif // Z_TEST_H
