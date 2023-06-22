#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"../include/Atendente.hpp"
#include"../include/Caixa.hpp"
#include"../include/Comanda.hpp"
#include"../include/Estoque.hpp"
#include"../include/Funcionario.hpp"
#include"../include/Gerente.hpp"
#include"../include/Produto.hpp"
#include<vector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Caixa* _Cx=new Caixa(2);
    Estoque* _E=new Estoque();
    Gerente* _G=new Gerente(123,1,222333333,1500);
    std::vector<Atendente*> _A;
private slots:
    void on_pushButton_clicked();

    void on_AdcionarProduto_clicked();

    void on_DadosDeCaixa_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
