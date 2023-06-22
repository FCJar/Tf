#ifndef CAIXA_HPP
#define CAIXA_HPP

#include <string>
#include "Produto.hpp"
#include "Comanda.hpp"
#include <vector>
#include <fstream>
#include <iostream>

class Caixa
{
    private:
        double _IdCaixa,_IdComanda;
        double _DindheiroCx,_LucroTotal;
        std::ofstream caixaArquivo;
        std::vector <Comanda*> _comandasPagas;
    public:
        Caixa(int idCaixa);
        double RetornarDinheiroCx();
        double RetornarLucroTotal();
        void AdcionarComanda(Comanda* C);
        double RetornarLucroPorDia(std::string dia);
        double RetornarDinheiroCxPorDia(std::string dia);
        double RetornarVendasPorFuncionario(int idAtendente);
        double RetornarVendasPorFuncionarioPorDia(int idAtendente,std::string dia);
};

#endif /* CAIXA_HPP */
