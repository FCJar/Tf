#include "../include/Comanda.hpp"
#include <iostream>
#include <exception>
Comanda::Comanda(int idAtendente, std::string formaPagamento,std::string endereco){
    this->_Endereco=endereco;
    this->_IdAtendente=idAtendente;
    this->_FormaPagamento=formaPagamento;
};

void Comanda::setId(int id){
    this->_Id=id;
};

void Comanda::getAdcionarProduto(Produto* p){
    this->_Produtos.push_back(p);
    this->_PrecoTotal=this->_PrecoTotal+(p->getPreco());
    this->_TaxaLucro=this->_TaxaLucro+(p->getLucroProduto());
};

void Comanda::imprimirInfoComanda(){
    std::cout<<"Valor:"<<this->_PrecoTotal<<std::endl;
    std::cout<<"Produtos na Comanda:"<<std::endl;
    for (int i=0;i<this->_Produtos.size();i++)
    {
        std::cout<<this->_Produtos[i]->getNome()<<"\t"<<this->_Produtos[i]->getDataValidade()<<"\t"
        <<this->_Produtos[i]->getPreco()<<std::endl;
    }; 
};

int Comanda::getId(){
    return this->_Id;
};

int Comanda::getIdAtendente(){
    return this->_IdAtendente;
};

double Comanda::getPrecoTotal(){
    return this->_PrecoTotal;
};

double Comanda::getTaxaLucro(){
    return this->_TaxaLucro;
};

std::string Comanda::getFormaPagamento(){
    return this->_FormaPagamento;
};

std::string Comanda::getDataVenda(){
    return this->_DataVenda;
};

std::string Comanda::getEndereco(){
    return this->_Endereco;
};

void Comanda::getRetirarProdutoNome(Estoque* e,std::string nomeProduto){
    int aux=0;
    for (int i=0;i<this->_Produtos.size();i++)
    {
        if(this->_Produtos[i]->getNome()==nomeProduto){
            e->adcionarProduto(this->_Produtos[i]);
            this->_Produtos.erase(_Produtos.begin()+i);
            aux=1;
        };
    }; 
    if (aux==0)
    {
        throw std::invalid_argument("Nome Invalido");
    }
};

void Comanda::setFormaPaga(std::string fp){
    this->_FormaPagamento=fp;
};

void Comanda::retornarProdutos(Estoque* e){
    for(int i=0;i<=this->_Produtos.size();i++){
        e->adcionarProduto(this->_Produtos[i]);
        this->_Produtos.erase(this->_Produtos.begin()+i);
    };
};
