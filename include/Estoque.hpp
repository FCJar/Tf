#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <string>
#include <vector>
#include "Produto.hpp"
#include<iostream>
#include<fstream>
class Estoque
{
    private:
        std::vector<Produto*> _Produtos;
        int _IdRegistro;
        std::ofstream arquivo;
    public:
        //id deve ser iniciado junto com com construtor
        Estoque();
        void retiraProdutoNome(std::string nomeProduto);
        Produto* venderProdutoemEstoque(std::string nomeProduto);
        void infoProduto();
        void adcionarProduto(Produto* p);
        void retornarProduto(Produto* p);
};

#endif /* ESTOQUE_HPP */
