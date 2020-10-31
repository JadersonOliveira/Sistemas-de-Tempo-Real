#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <stdlib.h>
#include <QTimer>
#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->clear();
    ui->treeWidget->setColumnCount(9);
    ui->treeWidget->header()->setDefaultAlignment(Qt::AlignCenter);

    comando = "ps -eo pid,user,pri,ni,s,psr,%cpu,%mem,command > arquivo3.txt";

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(attDados()));
    timer->start(1000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::attDados()
{
    QString aux = ui->lineEdit_2->text();

    if(aux == "") {
        comando = "ps -eo pid,user,pri,ni,s,psr,%cpu,%mem,command > arquivo3.txt";
    }else {
        comando = "ps -eo pid,user,pri,ni,s,psr,%cpu,%mem,command | grep " + aux + " > arquivo3.txt";
    }

    system(comando.toUtf8().constData());
    ui->treeWidget->clear();
    arquivo("/home/jaderson/Documentos/build-Trabalho2-Desktop-Debug/arquivo3.txt");

}

void MainWindow::addTreeRoot(QString name)
{

    QString a = name;

    do{
        a = name;
        name.replace(QString("  "), QString(" "));

    }while(a!=name);
    if(name[0]==' '){
        name.remove(0, 1);
    }

    QStringList A = name.split(" ");
    if(A[0] == "PID"){
        return;
    }

    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);
    for(int i=0;i<9;i++){
        treeItem->setText(i, A[i]);
        treeItem->setTextAlignment(i, Qt::AlignCenter);
    }

}
void MainWindow::arquivo(QString name){

        QFile file(name);
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file);
            while(!in.atEnd()){
                QString line = in.readLine();
                addTreeRoot(line);
            }

            file.close();
        }

}

void MainWindow::on_pushButton_2_clicked() //CONTINUAR
{
    QString aux = ui->lineEdit->text();
    aux = "kill -CONT " + aux;
    system(aux.toUtf8().constData());
}

void MainWindow::on_pushButton_clicked() //SUSPENDER
{
    QString aux = ui->lineEdit->text();
    aux = "kill -STOP " + aux;
    system(aux.toUtf8().constData());
}

void MainWindow::on_pushButton_3_clicked() //MATAR
{
    QString aux = ui->lineEdit->text();
    aux = "kill " + aux;
    system(aux.toUtf8().constData());
}

void MainWindow::on_pushButton_5_clicked() //ALTERAR PRIORIDADE
{
    QString aux = ui->comboBox_2->currentText();
    QString aux2 = ui->lineEdit->text();
    QString auxFinal = "renice " + aux + " -p " + aux2;
    system(auxFinal.toUtf8().constData());

}

void MainWindow::on_pushButton_4_clicked() //ALTERAR CPU
{
    QString aux = ui->comboBox->currentText();
    QString aux2 = ui->lineEdit->text();
    QString auxFinal = "taskset -cp " + aux + "," + aux + " " + aux2;
    system(auxFinal.toUtf8().constData());
}
