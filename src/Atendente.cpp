#include "../include/Atendente.hpp"
#include <iostream>

Atendente::Atendente(int id,int cpf,double salario):Atendente::Funcionario(id,cpf,salario){};

double Atendente::RetornarVendasaDiarias(Caixa* cx,std::string dia){
    double valor = cx->RetornarVendasPorFuncionarioPorDia(this->getId(),dia);
    return valor;

};

double Atendente::RetornarVendasTotais(Caixa* cx){
   double valor = cx->RetornarVendasPorFuncionario(this->getId());
    return valor;
}; 
    

