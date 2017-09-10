#include <iostream>
#include "Pocket.h"

using namespace std;
int main() {
    unsigned n=4;
    unsigned p=4;
    Pocket pocket;
    float matrixOfTrain[n][p] = {{1, -1, -1, -1},{1, -1, 1, 1},{1, 1, -1, 1},{1, 1, 1, -1}};
    float comparasionDate[p-1] = {1,1,1};
    float** matrixRef = new float*[n];
    for(unsigned i =0; i<n;i++){
        matrixRef[i] = new float[p];
        for(unsigned j =0; j<p;j++) matrixRef[i][j] = matrixOfTrain[i][j];
    }
    pocket.load(n,p,15,matrixRef);
    pocket.train();
    pocket.getVectorWeight();
    cout << endl;
    pocket.getVectorWeightPocket();
    cout << endl;
    pocket.getResult(comparasionDate);
    return 0;
}