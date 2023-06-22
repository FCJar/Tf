#include "janelacomanda.h"
#include "ui_janelacomanda.h"
#include "mainwindow.h"
#include <string.h>
#include <stdlib.h>
#include <QMessageBox>
#include"janelapagamento.h"
JanelaComanda::JanelaComanda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaComanda)
{
    ui->setupUi(this);
}

void JanelaComanda::dados(Caixa* cx,Estoque* es,Gerente* ge,std::vector<Atendente*> at){
    this->c=cx;
    this->e=es;
    this->g=ge;
    this->a=at;
};

JanelaComanda::~JanelaComanda()
{
    delete ui;
}

void JanelaComanda::on_pushButton_clicked()
{
    int id = (ui->IdLine->text()).split(" ")[0].toInt();
    std::string endereço=(ui->EndeLine->text()).toStdString();
    std::string formaPagamento=(ui->FormaPagLine->text()).toStdString();
    int aux=0;
    Atendente* endat;

    for(int i=0;i<(a).size();i++){
        if(a[i]->getId()==id){
            a[i]->CriarComada(formaPagamento,endereço);
            endat=a[i];
            aux=1;
        };
    };

    if(aux==1){
        janelaPagamento je;
        je.dados(this->c,this->e,this->g,this->a,endat);
        je.exec();
        this->close();
    }else{
        QMessageBox::critical(this,"Erro","Id Incorreto");
    };

};

