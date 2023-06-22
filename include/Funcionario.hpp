#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <string>
#include "Produto.hpp"
#include "Comanda.hpp"
#include "Estoque.hpp"
#include "Caixa.hpp"
#include <vector>

class Funcionario
{
    private:
        int _Id,_Cpf;
        std::string _NomeCompleto;
        double _Salario;
        Comanda* _ComandasEmPendente;
    public:
        int getId();
        Funcionario(int id,int cpf,double salario);
        void CriarComada(std::string formaPagamento,std::string endereco);
        void VenderItem(Estoque* e,std::string nomeProduto);
        void RetirarProdutoComanda(Estoque* e,std::string nomePr);
        void MudarFormaDePagamento(std::string Fp);
        void PagarComanda(Caixa* cx);
        void DeletarComanda(Estoque* e);
};

#endif /* FUNCIONARIO_HPP */
