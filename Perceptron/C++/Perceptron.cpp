//
// Created by marcus on 07/09/17.
//

#include "Perceptron.h"

void Perceptron::create(unsigned nL, unsigned pC) {
    n = nL;
    p = pC;
    weight = new float[p-1];
    dataEntry  = new float*[n];
    for(unsigned i=0; i<n;i++){
        dataEntry[i] = new float[p];
        for(unsigned j=0; j<p; j++) dataEntry[i][j] = 0;
    }
    for(unsigned j=0; j<p-1;j++) weight[j] = 0;
}
void Perceptron::copy(const Perceptron &perceptron) {
    create(perceptron.n,perceptron.p);
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0; j<p;j++) dataEntry[i][j] = perceptron.dataEntry[i][j];
    }
    for(unsigned j=0; j<p-1;j++) weight[j] = perceptron.weight[j];
}
void Perceptron::clean() {
    delete[] weight;
    for(unsigned i=0;i<n;i++) delete[] dataEntry[i];
    delete[] dataEntry;
    n = 0;
    p = 0;
}
void Perceptron::load(unsigned Cn, unsigned Cp, float** matrixTraining){
    create(Cn, Cp);
    for(unsigned i=0; i<n;i++){
        for(unsigned j =0; j<p;j++) dataEntry[i][j] = matrixTraining[i][j];
    }
}
void Perceptron::train() {
    float wE = 0;
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0;j<p-1;j++) wE+=dataEntry[i][j]*weight[j];
        if(!(wE>0 && dataEntry[i][p-1]==1) || (wE<0 && dataEntry[i][p-1]==-1)){
            for(unsigned k=0;k<p-1;k++) weight[k]+=dataEntry[i][k]*dataEntry[i][p-1];
        }
    }
}
void Perceptron::getVectorWeight(){
    for(unsigned i=0;i<p-1;i++){
        cout << weight[i] << " ";
    }
}
float Perceptron::getResult(float comparisonData[]) {
    float aux;
    for(unsigned i=0; i<p-1;i++){
        aux+=weight[i]*comparisonData[i];
    }
    return aux;
}
