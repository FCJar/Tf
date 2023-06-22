#ifndef JANELACOMANDA_H
#define JANELACOMANDA_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class JanelaComanda;
}

class JanelaComanda : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaComanda(QWidget *parent = nullptr);
    ~JanelaComanda();
    void dados(Caixa* cx,Estoque* es,Gerente* ge,std::vector<Atendente*> at);
private slots:
    void on_pushButton_clicked();

private:
    Ui::JanelaComanda *ui;
    Caixa* c;
    Estoque* e;
    Gerente* g;
    std::vector<Atendente*> a;
};

#endif // JANELACOMANDA_H
