#include "janeladecompras.h"
#include "ui_janeladecompras.h"
#include<QMessageBox>

#include <exception>

JanelaDeCompras::JanelaDeCompras(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaDeCompras)
{
    ui->setupUi(this);
}

JanelaDeCompras::~JanelaDeCompras()
{
    delete ui;
}

void JanelaDeCompras::dados(Caixa* cx,Estoque* es,Gerente* ge,std::vector<Atendente*> at,Atendente* poat){
    this->cai=cx;
    this->est=es;
    this->ger=ge;
    this->ate=at;
    this->enAt=poat;
};

void JanelaDeCompras::on_CocaButton_clicked()
{
    try{
        this->enAt->VenderItem(est,"Coca");
        this->coca++;
    }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Acabou a Coca");
    };
};



void JanelaDeCompras::on_FantaButton_clicked()
{

};


void JanelaDeCompras::on_CafeButton_clicked()
{

};


void JanelaDeCompras::on_PastelButton_clicked()
{


}


void JanelaDeCompras::on_Coxinha_clicked()
{

}


void JanelaDeCompras::on_BisButton_clicked()
{

};


void JanelaDeCompras::on_FinalizarCompra_clicked()
{
    this->enAt->PagarComanda(this->cai);
    QMessageBox::about(this,"","Compra Finalizada");
}


void JanelaDeCompras::on_RemoverCocaButton_clicked()
{};

void JanelaDeCompras::on_RemoverPastelButton_clicked()
{
}


void JanelaDeCompras::on_RemoverFanta_clicked()
{
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


void JanelaDeCompras::on_RemoverCoxinhaButton_clicked()
{

}


void JanelaDeCompras::on_RemoverCafeButton_clicked()
{

}


void JanelaDeCompras::on_RemoverBisButton_clicked()
{

}


void JanelaDeCompras::on_DeletarComanda_clicked()
{

}


void JanelaDeCompras::on_pushButton_clicked()
{

};


void JanelaDeCompras::on_pushButton_2_clicked()
{
    //novo remover coca
    try{
            this->coca--;
            if(this->coca<=0){
                throw std::invalid_argument("Devolução reversa");
            }
            this->enAt->RetirarProdutoComanda(this->est,"Coca");
        }catch(std::invalid_argument &e){
        QMessageBox::critical(this,"Erro","Devolução Reversa Coca");
    }
}


void JanelaDeCompras::on_pushButton_3_clicked()
{
    //  novo remover fanta
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


void JanelaDeCompras::on_pushButton_4_clicked()
{


}

