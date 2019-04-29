#include "t_test.h"
#include "ui_t_test.h"
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include <QStringList>
#include <QDebug>
#include <cmath>
#include <QDateTime>

t_test::t_test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::t_test)
{
    ui->setupUi(this);
}

t_test::~t_test()
{
    delete ui;
}

double t_test::table_import(int dof,double alpha){
    double ans=0;

    QFile file(":/resources/data/t-table.csv");
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::about(this,"Error","t-Table not accesible");
    }
    QTextStream in(&file);
    int row;
    if(dof>30){
        row=30;
    }
    else{
        row=dof-1;
    }

    int col=0;
    if(alpha==10.0){
        col=3;

    }
    if(alpha==5.0){
        col=4;
    }
    if(alpha==2.5){
        col=5;
    }
    if(alpha==1.0){
        col=6;
    }
    if(alpha==0.5){
        col=7;
    }

    int temp=0;
    while(!in.atEnd()){
                QStringList *loadCsv = new QStringList(in.readLine().split(","));
                if(temp==row){
                    ans=QVariant(loadCsv->at(col)).toDouble();

                }
                ui->debugg->setText(QVariant(temp).toString());
                temp++;
                delete loadCsv;
    }
    file.close();
    return ans;
}

void t_test::on_pushButton_clicked()
{
        QString file_path ;
        file_path = QFileDialog::getOpenFileName(this,"Open a File");


        QFile file(file_path);
        if(!file.open(QIODevice::ReadOnly)){
            QMessageBox::about(this,"Error","File not opening");
        }
        else {
            ui->label_2->setText(file_path);
        }

        QTextStream in(&file);


        int rowsCount = 1;

      /*  while(!in.atEnd()){
            QStringList *loadCsv = new QStringList(in.readLine().split(";"));
            ui->table->setRowCount(rowsCount);
            ui->table->setColumnCount(loadCsv->size());
            for(int col = 0; col < loadCsv->size(); ++col)
            {
                 QTableWidgetItem *items= new QTableWidgetItem(loadCsv->at(col));
                 ui->table->setItem((rowsCount - 1), col, items);
            }
            rowsCount++;
            delete loadCsv;
        }  */

        while(!in.atEnd()){
            QStringList *temp = new QStringList(in.readLine().split(";"));
            ui->table->setRowCount(rowsCount);
            ui->table->setColumnCount(1);
            QTableWidgetItem *item= new QTableWidgetItem(temp->at(0));
            ui->table->setItem((rowsCount - 1), 0, item);
            rowsCount++;
            delete temp;
        }
        file.close();
        ui->pushButton->setEnabled(0);
        ui->pushButton_2->setEnabled(1);
}



void t_test::on_pushButton_2_clicked()
{

    ui->pushButton->setEnabled(1);
    ui->label_2->setText("-----------");
    ui->table->setRowCount(0);
    ui->table->setColumnCount(0);
    ui->total_box_4->setText(NULL);
    ui->mean_box_4->setText(NULL);
    ui->lineEdit->setText(NULL);
    ui->pushButton_3->setEnabled(1);
    ui->pushButton_2->setEnabled(0);

}

void t_test::on_pushButton_3_clicked()
{
    int n = ui->table->rowCount();
  //  if(n==0){
    //    QMessageBox::about(this,"Error","Choose Data File ");
      //  return;
    //}
    ui->total_box_4->setText(QVariant(n).toString());
    int doff = n-1;
    ui->dof->setText(QVariant(doff).toString());
    double *data = new double(n);
    double temp=0;
    for(int i=0;i<n;i++){
        data[i] = ui->table->item(i,0)->text().toDouble();
        temp+=data[i];
    }
    double mean = temp/n;
    mean = ((int)(100*mean))/100.0;
    ui->mean_box_4->setText(QVariant(mean).toString());


    temp = 0;
    for(int i=0;i<n;i++){
        temp += (data[i] - mean)*(data[i] - mean);
    }

    double sigma = sqrt(temp/(n-1));
    double signi = QVariant(ui->comboBox->currentText()).toDouble();

    int d=QVariant(ui->lineEdit_2->text()).toInt();
    double alpha=QVariant(ui->lineEdit_3->text()).toDouble();
    ui->label_4->setText(QVariant(table_import(d,alpha)).toString());

    double phi = table_import(doff,signi);

    double x1 = mean - (phi*sigma/sqrt(n));
    double x2 = mean + (phi*sigma/sqrt(n));
    x1 = ((int)(100*x1))/100.0;
    x2 = ((int)(100*x2))/100.0;
    QString interval = QVariant(x1).toString() + "  to  " + QVariant(x2).toString();
    ui->lineEdit->setText(interval );
    ui->pushButton_3->setEnabled(0);

}
