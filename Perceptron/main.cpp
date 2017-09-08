#include <iostream>
#include "Perceptron.h"

using namespace std;
int main() {
    unsigned n=5;
    unsigned p=5;
    float MatrizDef[n][p] = {{1, -1, -1, -1,-1}, {1, 1, -1, -1,-1},{1,-1,-1,1,-1},{1, -1, 1, -1,-1},{1,1,1,1,1}};
    float DadoTeste[4] = {1,-1,1,1};
    float** MatrizReferencia = new float*[n];
    for(unsigned i =0; i<n;i++){
        MatrizReferencia[i] = new float[p];
        for(unsigned j =0; j<p;j++) MatrizReferencia[i][j] = MatrizDef[i][j];
    }
    Perceptron perceptron;
    perceptron.carregar(n,p,MatrizReferencia);
    perceptron.treinar();
    if(perceptron.getResult(DadoTeste)>0) cout << "True";
    else cout << "False";
    return 0;
}