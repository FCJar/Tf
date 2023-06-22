#ifndef COMANDA_HPP
#define COMANDA_HPP

#include <string>
#include "Produto.hpp"
#include "Estoque.hpp"
#include <vector>

class Comanda
{
    private:
        int _Id,_IdAtendente;
        double _PrecoTotal=0,_TaxaLucro=0;
        std::string _FormaPagamento, _DataVenda,_Endereco;
        std::vector<Produto*> _Produtos;
    public:

        Comanda(int idAtendente,std::string formaPagamento,std::string endereco);
        void setId(int id);
        void getAdcionarProduto(Produto* p);
        void imprimirInfoComanda();
        int getId();
        int getIdAtendente();
        double getPrecoTotal();
        double getTaxaLucro();
        std::string getFormaPagamento();
        std::string getDataVenda();
        std::string getEndereco();
        void setFormaPaga(std::string fp);
        void getRetirarProdutoNome(Estoque* e,std::string nomeProduto);
        void retornarProdutos(Estoque* e);

};

#endif /* COMANDA_HPP */
