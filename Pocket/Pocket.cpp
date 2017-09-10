//
// Created by marcus on 09/09/17.
//
#include <stdlib.h>
#include <time.h>
#include "Pocket.h"

void Pocket::create(unsigned Cn, unsigned Cp) {
    n = Cn;
    p = Cp;
    stepEstimated = 0;
    weight = new float[p-1];
    weightPocket = new float[p-1];
    dataEntry  = new float*[n];
    for(unsigned i=0; i<n;i++){
        dataEntry[i] = new float[p];
        for(unsigned j=0; j<p; j++) dataEntry[i][j] = 0;
    }
    for(unsigned j=0; j<p-1;j++){
        weight[j] = 0;
        weightPocket[j] = 0;
    }
}
void Pocket::copy(const Pocket &pocket) {
    create(pocket.n,pocket.p);
    for(unsigned i=0;i<n;i++){
        for(unsigned j=0; j<p;j++) dataEntry[i][j] = pocket.dataEntry[i][j];
    }
    for(unsigned j=0; j<p-1;j++){
        weight[j] = pocket.weight[j];
        weightPocket[j] = pocket.weightPocket[j];
    }

}
void Pocket::clean() {
    delete[] weight;
    delete[] weightPocket;
    for(unsigned i=0;i<n;i++) delete[] dataEntry[i];
    delete[] dataEntry;
    n = 0;
    p = 0;
    stepEstimated = 0;
}
void Pocket::load(unsigned Cn, unsigned Cp, unsigned step_estimated, float **matrixTraining) {
    create(Cn, Cp);
    stepEstimated = step_estimated;
    for(unsigned i=0; i<n;i++){
        for(unsigned j =0; j<p;j++) dataEntry[i][j] = matrixTraining[i][j];
    }
}
void Pocket::train() {
    unsigned runWeight = 0;
    unsigned runWeightPocket = 0;
    unsigned stepTravel = 0;
    unsigned i;
    float wE = 0;
    for(unsigned j = 0; j<p-1; j++) weightPocket[j] = weight[j];
    wE = 0;
    srand((unsigned)time(NULL));
    while(stepTravel<stepEstimated){
        i = rand()%n;
        for(int j =0; j<p-1; j++) wE+=dataEntry[i][j]*weight[j];
        if((wE>0 && dataEntry[i][p-1]==1) || (wE<0 && dataEntry[i][p-1]==-1)){
            runWeight++;
            if(runWeight>runWeightPocket){
                for(unsigned j = 0; j<p-1; j++) weightPocket[j] = weight[j];
                runWeightPocket = runWeight;
            }
        }else{
            for(int j =0; j<p-1;j++) weight[j] += dataEntry[i][j]*dataEntry[i][p-1];
            runWeight = 0;
        }
        stepTravel++;
        wE = 0;
    }
}
void Pocket::getVectorWeight(){
    for(unsigned i=0;i<p-1;i++){
        cout << weight[i] << " ";
    }
}
void Pocket::getVectorWeightPocket(){
    for(unsigned i=0;i<p-1;i++){
        cout << weightPocket[i] << " ";
    }
}
void Pocket::getResult(float comparisonData[]){
    float aux = 0;
    for(unsigned i=0; i<p-1;i++) aux+=weight[i]*comparisonData[i];
    cout << "Result fo weight: " << aux << endl;
    aux = 0;
    for(unsigned i=0; i<p-1;i++) aux+=weightPocket[i]*comparisonData[i];
    cout << "Result fo weightPocket: " << aux << endl;
}