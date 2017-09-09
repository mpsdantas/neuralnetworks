#include <iostream>
#include "Perceptron.h"

using namespace std;
int main() {
    unsigned n=5;
    unsigned p=5;
    float matrixOfTrain[n][p] = {{1, -1, -1, -1,-1}, {1, 1, -1, -1,-1},{1,-1,-1,1,-1},{1, -1, 1, -1,-1},{1,1,1,1,1}};
    float comparasionDate[4] = {1,-1,1,1};
    float** matrixRef = new float*[n];
    for(unsigned i =0; i<n;i++){
        matrixRef[i] = new float[p];
        for(unsigned j =0; j<p;j++) matrixRef[i][j] = matrixOfTrain[i][j];
    }
    Perceptron perceptron;
    perceptron.load(n,p,matrixRef);
    perceptron.train();
    if(perceptron.getResult(comparasionDate)>0) cout << "True";
    else cout << "False";
    return 0;
}