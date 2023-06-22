#include "janelavenda.h"
#include "ui_janelavenda.h"

JanelaVenda::JanelaVenda(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JanelaVenda)
{
    ui->setupUi(this);
}

JanelaVenda::~JanelaVenda()
{
    delete ui;
}

JanelaVenda::dados(Caixa* cx,Estoque* es,Gerente* ge,std::vector<Atendente*> at,Atendente* end){
    this->c=cx;
    this->e=es;
    this->g=ge;
    this->a=at;
    this->ender=end;
};

void JanelaVenda::on_pushButton_clicked()
{

}

