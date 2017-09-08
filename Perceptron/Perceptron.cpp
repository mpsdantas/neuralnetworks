//
// Created by marcus on 07/09/17.
//

#include "Perceptron.h"

void Perceptron::criar(unsigned nL, unsigned pC) {
    n = nL;
    p = pC;
    vetorDePesos = new float[p-1];
    treinamento  = new float*[n];
    for(unsigned i=0; i<n;i++){
        treinamento[i] = new float[p];
        for(unsigned j=0; j<p; j++) treinamento[i][j] = 0;
    }
    for(unsigned j=0; j<p-1;j++) vetorDePesos[j] = 0;
}
void Perceptron::copiar(const Perceptron &perceptron) {
    criar(perceptron.n,perceptron.p);
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0; j<p;j++) treinamento[i][j] = perceptron.treinamento[i][j];

    }
    for(unsigned j=0; j<p-1;j++) vetorDePesos[j] = perceptron.vetorDePesos[j];
}
void Perceptron::limpar() {
    delete[] vetorDePesos;
    for(unsigned i=0;i<n;i++) delete[] treinamento[i];
    delete[] treinamento;
    n = 0;
    p = 0;
}
void Perceptron::carregar(unsigned Cn, unsigned Cp, float** MatrizTreinamento){
    criar(Cn, Cp);
    for(unsigned i=0; i<n;i++){
        for(unsigned j =0; j<p;j++) treinamento[i][j] = MatrizTreinamento[i][j];
    }
}
void Perceptron::treinar() {
    float wE = 0;
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0;j<p-1;j++){
            wE+=treinamento[i][j]*vetorDePesos[j];
        }
        if(!(wE>0 && treinamento[i][p-1]==1) || (wE<0 && treinamento[i][p-1]==-1)) {
            for(unsigned k=0;k<p-1;k++) vetorDePesos[k]+=treinamento[i][k]*treinamento[i][p-1];
        }
    }
}
void Perceptron::getVetorDepesos(){
    for(unsigned i=0;i<p-1;i++){
        cout << vetorDePesos[i] << " ";
    }
}
float Perceptron::getResult(float dadoComparacao[]) {
    float aux;
    for(unsigned i=0; i<p-1;i++){
        aux+=vetorDePesos[i]*dadoComparacao[i];
    }
    return aux;
}
