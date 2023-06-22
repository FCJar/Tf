#ifndef JANELAVENDA_H
//#define JANELAVENDA_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class JanelaVenda;
}

class JanelaVenda : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaVenda(QWidget *parent = nullptr);
    ~JanelaVenda();
    dados(Caixa* cx,Estoque* es,Gerente* ge,std::vector<Atendente*> at,Atendente* end);
private slots:
    void on_pushButton_clicked();

private:
    Ui::JanelaVenda *ui;
    Caixa* c;
    Estoque* e;
    Gerente* g;
    std::vector<Atendente*> a;
    Atendente* ender;
};

#endif // JANELAVENDA_H
