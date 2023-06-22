#ifndef VERIFICA_H
#define VERIFICA_H

#include <QDialog>
#include "mainwindow.h"
#include<QMessageBox>
namespace Ui {
class verifica;
}

class verifica : public QDialog
{
    Q_OBJECT

public:
    explicit verifica(QWidget *parent = nullptr);
    ~verifica();
    Caixa* caixP;
    Estoque* estoqP;
    Gerente* gerenP;
    void dados(Caixa* cx,Estoque* es,Gerente* ge);
private slots:
    void on_pushButton_clicked();

    void on_RecargaButton_clicked();

    void on_pushButton_3_clicked();

    void on_DinheiroCxButton_clicked();

private:
    Ui::verifica *ui;
};


#endif // VERIFICA_H
