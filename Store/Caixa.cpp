#include "Caixa.hpp"
#include <iostream>
#include <exception>
Caixa::Caixa(int idCaixa){
    this->_IdCaixa=idCaixa;
    this->_IdComanda=0;
};

double Caixa::RetornarDinheiroCx(){
    return this->_DindheiroCx;
};

double Caixa::RetornarLucroTotal(){
    return this->_LucroTotal;
};

void Caixa::AdcionarComanda(Comanda* c){
    c->setId(this->_IdComanda);
    this->_IdComanda++;
};

double Caixa::RetornarLucroPorDia(std::string dia){
    int aux=0;
    double lucroPorDia=0;

    for(int i=0;i<this->_comandasPagas.size();i++){
        if(this->_comandasPagas[i]->getDataVenda()==dia){
            lucroPorDia=_comandasPagas[i]->getTaxaLucro(); 
            aux=1;
        };
    };

    if(aux==0){
        throw std::invalid_argument("Lucro do Dia não encontrado");
    };

    return lucroPorDia;
}

double Caixa::RetornarDinheiroCxPorDia(std::string dia){
    int aux=0;
    double dinheiroCx=0;
    for(int i=0;i<this->_comandasPagas.size();i++){
        if(this->_comandasPagas[i]->getDataVenda()==dia){
            dinheiroCx=_comandasPagas[i]->getPrecoTotal();
            aux=1; 
        };
    };

    if (aux==0)
    {
        throw std::invalid_argument("Dinheiro em Caixa Por dia não encontrado");
    }
    
    return dinheiroCx;
};


double Caixa::RetornarVendasPorFuncionario(int idAtendente){
    int aux=0;
    double vendas=0;
    for(int i=0;i<this->_comandasPagas.size();i++){
        if(this->_comandasPagas[i]->getIdAtendente()==idAtendente){
            vendas+=_comandasPagas[i]->getPrecoTotal(); 
            aux=1;
        };
    };

    if (aux==0)
    {
        throw std::invalid_argument("Id do Funcionario invalido ou funcionario sem vendas");
    };

    return vendas;
    
};

double Caixa::RetornarVendasPorFuncionarioPorDia(int idAtendente,std::string dia){
    int aux=0;
    double vendas=0;
    for(int i=0;i<this->_comandasPagas.size();i++){
        if(this->_comandasPagas[i]->getIdAtendente()==idAtendente && this->_comandasPagas[i]->getDataVenda()==dia){
            vendas=_comandasPagas[i]->getPrecoTotal();
            aux=1 ;
        };
    };

    if (aux==0)
    {
        throw std::invalid_argument("Id do Funcionario invalido, funcionario sem vendas ou dia invalido");
    }
    

    return vendas;

};
