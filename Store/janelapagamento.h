#ifndef JANELAPAGAMENTO_H
#define JANELAPAGAMENTO_H

#include <QDialog>
#include "mainwindow.h"
#include<QMessageBox>
namespace Ui {
class janelaPagamento;
}

class janelaPagamento : public QDialog
{
    Q_OBJECT

public:
    explicit janelaPagamento(QWidget *parent = nullptr);
    ~janelaPagamento();
    void dados(Caixa* cx,Estoque* es,Gerente* ge,std::vector<Atendente*> at,Atendente* poat);
    int coca=0,fanta=0,cafe=0,pastel=0,coixinha=0,bis=0;
    Caixa* cai;
    Estoque* est;
    Gerente* ger;
    std::vector<Atendente*> ate;
    Atendente* enAt;
private slots:
    void on_CocaButton_clicked();

    void on_RCocaButton_clicked();

    void on_FantaButton_clicked();

    void on_RFantaButton_clicked();

    void on_CafeButton_clicked();

    void on_RCafeButton_clicked();

    void on_PastelButton_clicked();

    void on_RPastelButton_clicked();

    void on_CoixinhaButton_clicked();

    void on_RCoixinhaButton_clicked();

    void on_BisButton_clicked();

    void on_RBisButton_clicked();

    void on_FinalizarButton_clicked();

    void on_DeletarButton_clicked();

private:
    Ui::janelaPagamento *ui;
};

#endif // JANELAPAGAMENTO_H
