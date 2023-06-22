#include "../include/Estoque.hpp"
#include<iostream>
#include <exception>

Estoque::Estoque(){
    this->_IdRegistro=0;
};

void Estoque::retiraProdutoNome(std::string nomeProduto){
    int aux=0;
    for (int i=0;i<this->_Produtos.size();i++)
    {
        if(this->_Produtos[i]->getNome()==nomeProduto){
            delete this->_Produtos[i];
            this->_Produtos.erase(_Produtos.begin()+i);
            aux=1;
        };
    };

    if (aux==0)
    {
        throw std::invalid_argument("Produto nao encontrado");
    };
    

};

Produto* Estoque::venderProdutoemEstoque(std::string nomeProduto){
    int aux=0;
    Produto* p;
    for (int i=0;i<this->_Produtos.size();i++)
    {
        if(this->_Produtos[i]->getNome()==nomeProduto){
            p=_Produtos[i];
            this->_Produtos.erase(_Produtos.begin()+i);
            aux=1;
        };
    };

    if (aux==0)
    {
        throw std::invalid_argument("Produto não encontrado");
    };
    
    return p;
};

void Estoque::infoProduto(){
    arquivo.open("est.txt",std::ios::app);
    arquivo<<"Produto em estoque\n";
    arquivo.close();
    for (int i=0;i<this->_Produtos.size();i++)
    {
        arquivo.open("est.txt",std::ios::app);
        arquivo<<this->_Produtos[i]->getNome()<<"\t"<<this->_Produtos[i]->getPreco()<<"\n";
        arquivo.close();
    };

};

void Estoque::adcionarProduto(Produto* p){
    p->setId(this->_IdRegistro);
    this->_IdRegistro++;
    this->_Produtos.push_back(p);
};

void Estoque::retornarProduto(Produto* p){
    this->_Produtos.push_back(p);
};
