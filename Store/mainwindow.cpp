#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "janelacomanda.h"
#include"verifica.h"
#include "adcionarprodutojanela.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    JanelaComanda j;
    j.dados(_Cx,_E,_G,_A);
    j.exec();
}


void MainWindow::on_AdcionarProduto_clicked()
{
    AdcionarProdutoJanela ja;
    ja.dados(_Cx,_E,_G);
    ja.exec();
}


void MainWindow::on_DadosDeCaixa_clicked()
{
    verifica v;
    v.dados(_Cx,_E,_G);
    v.exec();
}

