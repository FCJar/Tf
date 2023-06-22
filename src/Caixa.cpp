#include "../include/Caixa.hpp"
#include <iostream>
#include <exception>
Caixa::Caixa(int idCaixa){
    this->_IdCaixa=idCaixa;
    this->_IdComanda=0;
    this->_DindheiroCx=0;
    this->_LucroTotal=0;
};

double Caixa::RetornarDinheiroCx(){
    return this->_DindheiroCx;
};

double Caixa::RetornarLucroTotal(){
    return this->_LucroTotal;
};

void Caixa::AdcionarComanda(Comanda* c){
    this->_DindheiroCx=c->getPrecoTotal();
    this->_LucroTotal=c->getTaxaLucro();
    caixaArquivo.open("historico.txt",std::ios::app);
    c->setId(this->_IdComanda);
    caixaArquivo<<"_________________________\n"<<"Id Comanda:"<<c->getId()<<"\nForma de Pagementp:"
                <<c->getFormaPagamento()<<"\nPreço Total:"<<c->getPrecoTotal()
                <<"\nTaxa de lucro"<<c->getTaxaLucro()<<"_________________________";
    this->_IdComanda++;
    caixaArquivo.close();
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
