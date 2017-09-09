#include <iostream>
#include "Perceptron.h"

using namespace std;
int main() {
    unsigned n=5;
    unsigned p=5;
    Perceptron perceptron;
    float matrixOfTrain[n][p] = {{1, -1, -1, -1,-1}, {1, 1, -1, -1,-1},{1,-1,-1,1,-1},{1, -1, 1, -1,-1},{1,1,1,1,1}};
    float comparasionDate[p-1] = {1,1,1,1};
    float** matrixRef = new float*[n];
    for(unsigned i =0; i<n;i++){
        matrixRef[i] = new float[p];
        for(unsigned j =0; j<p;j++) matrixRef[i][j] = matrixOfTrain[i][j];
    }
    perceptron.load(n,p,matrixRef);
    perceptron.train();
    perceptron.getVectorWeight();
    return 0;
}