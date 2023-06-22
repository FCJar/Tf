#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <string>
#include "Produto.hpp"
#include "Comanda.hpp"
#include "Funcionario.hpp"
#include "Estoque.hpp"

#include <vector>

class Gerente : public Funcionario
{   
    private:
        int _Senha;

    public:
        Gerente(int senha,int id,int cpf,double salario);
        double RetornarLucroTotal(Caixa* cx);
        double ConsultarLucroPorDia(Caixa* cx,std::string dia);
        double RetornarVendasaDiariasPorFuncionario(Caixa* cx,int idFunc,std::string dia);
        double RetornarVendasTotaisPorFuncionario(Caixa* cx,int idFunc);
        bool ChecarSenha(int id,int senha);
        void AdicionarProdutoAoEstoque(Estoque* e,Produto* p);
};

#endif /* GERENTE_HPP */
