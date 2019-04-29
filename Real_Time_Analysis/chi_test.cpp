#include "chi_test.h"
#include "ui_chi_test.h"

chi_test::chi_test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chi_test)
{
    ui->setupUi(this);
}

chi_test::~chi_test()
{
    delete ui;
}
