#include "Gerente.hpp"
#include <iostream>

Gerente::Gerente(int senha,int id,int cpf,double salario):Gerente::Funcionario(id,cpf,salario){
    this->_Senha=senha;
};

double Gerente::RetornarLucroTotal(Caixa* cx){
    double valor=cx->RetornarDinheiroCx();
    return valor;
};

double Gerente::ConsultarLucroPorDia(Caixa* cx,std::string dia){
    double valor=cx->RetornarDinheiroCxPorDia(dia);
    return valor;
};

double Gerente::RetornarVendasaDiariasPorFuncionario(Caixa* cx,int idFunc,std::string dia){
    double valor=cx->RetornarVendasPorFuncionarioPorDia(idFunc,dia);
    return valor;
};

double Gerente::RetornarVendasTotaisPorFuncionario(Caixa* cx,int idFunc){
    double valor=cx->RetornarVendasPorFuncionario(idFunc);
    return valor;
}; 

bool Gerente::ChecarSenha(int id,int senha){
    bool a=false;
        if(this->getId()==id && this->_Senha==senha){
            a=true;
        };
    return a;
};

void Gerente::AdicionarProdutoAoEstoque(Estoque* e,Produto* p){
    e->adcionarProduto(p);
};
