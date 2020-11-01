#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTreeWidget>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QTimer *timer;
    QString comando;

    int cpu[4];
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void attDados();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    void addTreeRoot(QString name);
    void addCPU(QString name);
    void arquivo(QString name, bool flag);

};
#endif // MAINWINDOW_H
