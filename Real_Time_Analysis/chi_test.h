#ifndef CHI_TEST_H
#define CHI_TEST_H

#include <QDialog>

namespace Ui {
class chi_test;
}

class chi_test : public QDialog
{
    Q_OBJECT

public:
    explicit chi_test(QWidget *parent = nullptr);
    ~chi_test();

private:
    Ui::chi_test *ui;
};

#endif // CHI_TEST_H
