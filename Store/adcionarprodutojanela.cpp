#include "adcionarprodutojanela.h"
#include "ui_adcionarprodutojanela.h"
#include <QMessageBox>
#include <string.h>
#include <stdlib.h>

AdcionarProdutoJanela::AdcionarProdutoJanela(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdcionarProdutoJanela)
{
    ui->setupUi(this);
}

AdcionarProdutoJanela::~AdcionarProdutoJanela()
{
    delete ui;
}

void AdcionarProdutoJanela::dados(Caixa* cx,Estoque* es,Gerente* ge){
    this->caix=cx;
    this->estoq=es;
    this->geren=ge;
};

void AdcionarProdutoJanela::on_CoixinhaButton_clicked()
{
    this->coixinha++;
};


void AdcionarProdutoJanela::on_AdcionarPastel_clicked()
{
    this->pastel++;
};


void AdcionarProdutoJanela::on_AdcionarBisButton_clicked()
{
    this->bis++;
}


void AdcionarProdutoJanela::on_AdcionaCafeButton_clicked()
{
    this->cafe++;
}


void AdcionarProdutoJanela::on_AdcionarCocaButton_clicked()
{
    this->coca++;
}


void AdcionarProdutoJanela::on_AdcionarFantaButton_clicked()
{
    this->fanta++;
}


void AdcionarProdutoJanela::on_ConfirmarButton_clicked()
{
    int senha=(ui->SenhaEditLine->text()).split(" ")[0].toInt();
    int id = (ui->IdLineEdit->text()).split(" ")[0].toInt();
    if(this->geren->ChecarSenha(id,senha)){
        for(int i=0;i<this->coixinha;i++){
            Produto* p=new Produto("Coixinha","Salgado",3.0,1.20);
            this->geren->AdicionarProdutoAoEstoque(this->estoq,p);
        };
        this->coixinha=0;
        for(int i=0;i<this->pastel;i++){
            Produto* p=new Produto("Pastel","Salgado",4.0,1.50);
            this->geren->AdicionarProdutoAoEstoque(this->estoq,p);
        };
        this->pastel=0;
        for(int i=0;i<this->bis;i++){
            Produto* p=new Produto("Bis","Doce",1.0,0.70);
            this->geren->AdicionarProdutoAoEstoque(this->estoq,p);
        };
        this->bis=0;
        for(int i=0;i<this->cafe;i++){
            Produto* p=new Produto("Café","Bebida",0.75,0.25);
            this->geren->AdicionarProdutoAoEstoque(this->estoq,p);
        };
        this->cafe=0;
        for(int i=0;i<this->coca;i++){
            Produto* p=new Produto("Coca","Bebida",2.25,1.75);
            this->geren->AdicionarProdutoAoEstoque(this->estoq,p);
        };
        this->coca=0;
        for(int i=0;i<this->fanta;i++){
            Produto* p=new Produto("Fanta","Bebida",5.0,3.0);
            this->geren->AdicionarProdutoAoEstoque(this->estoq,p);
        };
        this->fanta=0;
    }
}

