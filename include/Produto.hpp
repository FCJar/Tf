#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <string>

class Produto
{
    private:
        int _Id;   
        std::string _Nome, _Tipo, _DataValidade;
        double _Preco, _LucroProduto;
    public:
        Produto (std::string nome,std::string tipo,double preco,double lucroProduto);
        void setId(int id);
        int getId();
        std::string getNome();
        std::string getTipo();
        std::string getDataValidade();
        double getPreco();
        double getLucroProduto();
};

#endif /* PRODUTO_HPP */