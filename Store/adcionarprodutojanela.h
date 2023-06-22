#ifndef ADCIONARPRODUTOJANELA_H
#define ADCIONARPRODUTOJANELA_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class AdcionarProdutoJanela;
}

class AdcionarProdutoJanela : public QDialog
{
    Q_OBJECT

public:
    explicit AdcionarProdutoJanela(QWidget *parent = nullptr);
    ~AdcionarProdutoJanela();
    void dados(Caixa* cx,Estoque* es,Gerente* ge);
private slots:
    void on_CoixinhaButton_clicked();

    void on_AdcionarPastel_clicked();

    void on_AdcionarBisButton_clicked();

    void on_AdcionaCafeButton_clicked();

    void on_AdcionarCocaButton_clicked();

    void on_AdcionarFantaButton_clicked();

    void on_ConfirmarButton_clicked();

private:
    Ui::AdcionarProdutoJanela *ui;
    int coca=0,fanta=0,cafe=0,bis=0,coixinha=0,pastel=0;
    Caixa* caix;
    Estoque* estoq;
    Gerente* geren;
};

#endif // ADCIONARPRODUTOJANELA_H
