#ifndef JANELADECOMPRAS_H
#define JANELADECOMPRAS_H

#include <QDialog>

namespace Ui {
class JanelaDeCompras;
}

class JanelaDeCompras : public QDialog
{
    Q_OBJECT

public:
    explicit JanelaDeCompras(QWidget *parent = nullptr);
    ~JanelaDeCompras();
    void dados(Caixa* cx,Estoque* es,Gerente* ge,std::vector<Atendente*> at,Atendente* poat);
    int coca=0,fanta=0,cafe=0,pastel=0,coixinha=0,bis=0;
private slots:
    void on_pushButton_clicked();

    void on_CocaButton_clicked();

    void on_pushButton_2_clicked();

    void on_FantaButton_clicked();

    void on_CafeButton_clicked();

    void on_PastelButton_clicked();

    void on_Coxinha_clicked();

    void on_BisButton_clicked();

    void on_RemoverCocaButton_clicked();

    void on_FinalizarCompra_clicked();

    void on_RemoverPastelButton_clicked();

    void on_RemoverFanta_clicked();

    void on_RemoverCoxinhaButton_clicked();

    void on_RemoverCafeButton_clicked();

    void on_RemoverBisButton_clicked();

    void on_DeletarComanda_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::JanelaDeCompras *ui;
    Caixa* cai;
    Estoque* est;
    Gerente* ger;
    std::vector<Atendente*> ate;
    Atendente* enAt;
};

#endif // JANELADECOMPRAS_H
