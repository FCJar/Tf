#include "../include/Produto.hpp"
#include <iostream>

Produto::Produto (std::string nome,std::string tipo,double preco,double lucroProduto){
    this->_Nome=nome;
    this->_Tipo=tipo;
    this->_Preco=preco;
    this->_LucroProduto=lucroProduto;
};

void Produto::setId(int id){
    this->_Id=id;
};

int Produto::getId(){
    return this->_Id;
};

std::string Produto::getNome(){
    return this->_Nome;
};

std::string Produto::getTipo(){
    return this->_Tipo;
};

std::string Produto::getDataValidade(){
    return this->_DataValidade;
};

double Produto::getPreco(){
    return this->_Preco;
};

double Produto::getLucroProduto(){
    return this->_LucroProduto;
};
