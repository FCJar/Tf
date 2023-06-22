#include "verifica.h"
#include "ui_verifica.h"
#include<QMessageBox>
#include<string>
#include <qstring.h>
verifica::verifica(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::verifica)
{
    ui->setupUi(this);
}

verifica::~verifica()
{
    delete ui;
}

void verifica::dados(Caixa* cx,Estoque* es,Gerente* ge){
    this->caixP=cx;
    this->estoqP=es;
    this->gerenP=ge;
};

void verifica::on_pushButton_clicked()
{

}


void verifica::on_RecargaButton_clicked()
{
    int id=(ui->IdLineEdit->text()).split(" ")[0].toInt();
    int senha = (ui->SenhaLineEdit->text()).split(" ")[0].toInt();
    if(this->gerenP->ChecarSenha(id,senha)){
        this->estoqP->infoProduto();
    };
}


void verifica::on_DinheiroCxButton_clicked()
{
    int id=(ui->IdLineEdit->text()).split(" ")[0].toInt();
    int senha = (ui->SenhaLineEdit->text()).split(" ")[0].toInt();
    if(this->gerenP->ChecarSenha(id,senha)){
        QString d = QString::number(this->caixP->RetornarDinheiroCx());
        QMessageBox::about(this,"Dinheiro em Caixa",d);
    };
}

