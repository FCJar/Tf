#include "Funcionario.hpp"
#include <iostream>

int Funcionario::getId(){
    return this->_Id;
};

Funcionario::Funcionario(int id,int cpf,double salario){
    this->_Id=id;
    this->_Cpf=cpf;
    this->_Salario=salario;
};

void Funcionario::CriarComada(std::string formaPagamento,std::string endereco){
    this->_ComandasEmPendente=new Comanda(this->_Id,formaPagamento,endereco);    
};

void Funcionario::VenderItem(Estoque* e,std::string nomeProduto){
    //e necessario throe a error msg em caso de produto não encontrado
    Produto* p = e->venderProdutoemEstoque(nomeProduto);
    this->_ComandasEmPendente->getAdcionarProduto(p);
};

void Funcionario::RetirarProdutoComanda(std::string nomePr){
    this->_ComandasEmPendente->getRetirarProdutoNome(nomePr);
};

void Funcionario::MudarFormaDePagamento(std::string fp){
    this->_ComandasEmPendente->setFormaPaga(fp);
};

void Funcionario::PagarComanda(Caixa* cx){
    cx->AdcionarComanda(_ComandasEmPendente);
    this->_ComandasEmPendente=nullptr;
};

void Funcionario::DeletarComanda(Estoque* e){
    this->_ComandasEmPendente->retornarProdutos(Estoque* e);
    delete _ComandasEmPendente;
};