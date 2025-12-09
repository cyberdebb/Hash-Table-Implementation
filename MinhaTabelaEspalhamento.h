#ifndef MINHA_TABELA_ESPALHAMENTO_H
#define MINHA_TABELA_ESPALHAMENTO_H

#include "MinhaListaEncadeada.h"
// MinhaListaEncadeada
#include "TabelaEspalhamentoAbstrata.h"
// TabelaEspalhamentoAbstrata
#include "excecoes.h"
// ExcecaoDadoInexistente
#include <cmath>
#include <string>
#include <type_traits> // Para usar std::enable_if e std::is_same

using namespace std;

template<typename T, size_t _capacidade>
class MinhaTabelaEspalhamento final : public TabelaEspalhamentoAbstrata<T, _capacidade>
{
public:
    MinhaTabelaEspalhamento() {};
    ~MinhaTabelaEspalhamento() {
        for (size_t i=0; i<_capacidade; i++) {
            if (!this->_tabela[i].vazia())
                this->_tabela[i].removerDoInicio();
        }
    };

    size_t capacidade() const {
        return _capacidade;
    };

    void inserir(T dado) {
        if (contem(dado)) return;
        this->_tabela[funcaoEspalhamento(dado)].inserirNoFim(dado);
    };

    void remover(T dado) {
        if(!contem(dado)) throw ExcecaoDadoInexistente();
        this->_tabela[funcaoEspalhamento(dado)].remover(dado);
    };

    bool contem(T dado) const {
        for (size_t i=0; i<_capacidade; i++) {
            if(this->_tabela[i].contem(dado)) return true;
        }
        return false;
    };

    size_t quantidade() const {
        size_t soma = 0;

        for (size_t i=0; i<_capacidade; i++) {
            size_t t = this->_tabela[i].tamanho();
            soma += t;
        }
        return soma;
    };
    
    template<typename U = T>
    typename std::enable_if<std::is_same<U, std::string>::value, size_t>::type
    funcaoEspalhamentoCondicional(const U& dado) const {
        return calcularHash(dado) % _capacidade;
    }

    template<typename U = T>
    typename std::enable_if<!std::is_same<U, std::string>::value, size_t>::type
    funcaoEspalhamentoCondicional(const U& dado) const {
        return dado % _capacidade;
    }

    size_t funcaoEspalhamento(T dado) const {
        return funcaoEspalhamentoCondicional(dado);
    }

    size_t calcularHash(string dado) const {
        size_t hash;
        size_t soma = 0;
        size_t tam = dado.size();

        for (size_t i=0; i<dado.size(); i++) {
            char ch = dado[i];
            hash = ch * pow(31, tam-1);
            soma += hash;
            tam--;
        }
        return soma;
    };
};

#endif
