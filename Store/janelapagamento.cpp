#include "janelapagamento.h"
#include "ui_janelapagamento.h"
#include "mainwindow.h"
#include <string.h>
#include <stdlib.h>
#include <exception>
#include<iostream>

janelaPagamento::janelaPagamento(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::janelaPagamento)
{
    ui->setupUi(this);
}

janelaPagamento::~janelaPagamento()
{
    delete ui;
}

void janelaPagamento::dados(Caixa* cx,Estoque* es,Gerente* ge,std::vector<Atendente*> at,Atendente* poat){
    this->cai=cx;
    this->est=es;
    this->ger=ge;
    this->ate=at;
    this->enAt=poat;
};

void janelaPagamento::on_CocaButton_clicked()
{
    //adcionar coca
    try{
        this->enAt->VenderItem(est,"Coca");
        this->coca++;
    }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Acabou a Coca");
    };
}


void janelaPagamento::on_RCocaButton_clicked()
{
    //remover Coca
    try{
            this->coca--;
            if(this->coca<=0){
                throw std::invalid_argument("Devolução reversa");
            }
            this->enAt->RetirarProdutoComanda(this->est,"Coca");
        }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Devolução Reversa Coca");
    };
}




void janelaPagamento::on_FantaButton_clicked()
{
    //adcionar fanta
    try{
        this->enAt->VenderItem(est,"Fanta");
        this->fanta++;
    }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Acabou a Fanta");
    };

}





void janelaPagamento::on_RFantaButton_clicked()
{
    //remover fanta
    try{
        this->fanta--;
            if(this->fanta<=0){
                throw std::invalid_argument("Devolução reversa");
            }
            this->enAt->RetirarProdutoComanda(this->est,"Fanta");
        }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Devolução Reversa Fanta");
    };
}


void janelaPagamento::on_CafeButton_clicked()
{
    //adcionar cafe
    try{
        this->enAt->VenderItem(est,"Café");
            this->cafe++;
    }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Acabou o Café");
    };
}


void janelaPagamento::on_RCafeButton_clicked()
{
    //remover cafe
    try{
        this->cafe--;
            if(this->cafe<=0){
                throw std::invalid_argument("Devolução reversa");
            }
            this->enAt->RetirarProdutoComanda(this->est,"Café");
        }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Devolução Reversa Café");
    };

}


void janelaPagamento::on_PastelButton_clicked()
{
    //adcionar Pastel
    try{
        this->enAt->VenderItem(est,"Pastel");
        this->pastel++;
    }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Acabou o Pastel");
    };
}




void janelaPagamento::on_RPastelButton_clicked()
{
    //remover Pastel

    try{
        this->pastel--;
            if(this->pastel<=0){
                throw std::invalid_argument("Devolução reversa");
            }
            this->enAt->RetirarProdutoComanda(this->est,"Pastel");
        }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Devolução Reversa Pastel");
    };
}



void janelaPagamento::on_CoixinhaButton_clicked()
{
    //adcionar Coixinha
    try{
        this->enAt->VenderItem(est,"Coxinha");
        this->coixinha++;
    }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Acabou o Coxinha");
    };
}



void janelaPagamento::on_RCoixinhaButton_clicked()
{
    //remover Coixinha
    try{
        this->coixinha--;
            if(this->coixinha<=0){
                throw std::invalid_argument("Devolução reversa");
            }
            this->enAt->RetirarProdutoComanda(this->est,"Coixinha");
        }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Devolução Reversa Coixinha");
    };
}


void janelaPagamento::on_BisButton_clicked()
{
    //adcionar Bis
    try{
        this->enAt->VenderItem(est,"Bis");
        this->bis++;
    }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Acabou o Bis");
    };
}


void janelaPagamento::on_RBisButton_clicked()
{
    //remover bis
    try{
        this->bis--;
            if(this->bis<=0){
                throw std::invalid_argument("Devolução reversa");
            }
            this->enAt->RetirarProdutoComanda(this->est,"Bis");
        }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Devolução Reversa Bis");
    };
}


void janelaPagamento::on_FinalizarButton_clicked()
{
    //pagar comanda
    this->enAt->PagarComanda(this->cai);
    QMessageBox::about(this,"","Compra Finalizada");
    this->close();
}



void janelaPagamento::on_DeletarButton_clicked()
{
    this->enAt->DeletarComanda(this->est);
    QMessageBox::about(this,"","Comanda Deletada");
    this->close();
}

