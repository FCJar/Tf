#include "mainwindow.h"

#include <QApplication>

#include"../include/Atendente.hpp"
#include"../include/Caixa.hpp"
#include"../include/Comanda.hpp"
#include"../include/Estoque.hpp"
#include"../include/Funcionario.hpp"
#include"../include/Gerente.hpp"
#include"../include/Produto.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Produto* p1=new Produto("Coca","Bebida",2.0,1.99);
    Produto* p2=new Produto("Coca","Bebida",2.0,1.99);
    Produto* p3=new Produto("Coca","Bebida",2.0,1.99);
    Produto* p4=new Produto("Coca","Bebida",2.0,1.99);
    Produto* p5=new Produto("Coca","Bebida",2.0,1.99);
    Produto* p6=new Produto("Coca","Bebida",2.0,1.99);

    w._E->adcionarProduto(p1);
    w._E->adcionarProduto(p2);
    w._E->adcionarProduto(p3);
    w._E->adcionarProduto(p4);
    w._E->adcionarProduto(p5);

    Comanda* c1= new Comanda(1,"A vista", "Antonio Carlos");
    c1->getAdcionarProduto(p6);

    w._Cx->AdcionarComanda(c1);

    Atendente* a1=new Atendente(1,111133,1200);
    Atendente* a2=new Atendente(2,222233,1200);

    w._A.push_back(a1);
    w._A.push_back(a2);

    w.show();
    return a.exec();
}
