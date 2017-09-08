//
// Created by marcus on 07/09/17.
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

#include <iostream>
using namespace std;

class Perceptron {
private:
    float **treinamento;
    unsigned n;
    unsigned p;
    float *vetorDePesos;
    void criar(unsigned n, unsigned p);
    void copiar(const Perceptron &perceptron);
    void limpar();
public:
    inline Perceptron(): treinamento(NULL), n(0), p(0), vetorDePesos(NULL){}
    inline Perceptron(unsigned n, unsigned p){criar(n,p);}
    inline Perceptron(const Perceptron &perceptron){copiar(perceptron);}
    inline ~Perceptron(){limpar();}
    void carregar(unsigned Cn, unsigned Cp, float** MatrizTreinamento);
    void treinar();
    void getVetorDepesos();
    float  getResult(float dadoComparacao[]);

};


#endif //PERCEPTRON_PERCEPTRON_H
