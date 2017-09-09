//
// Created by marcus on 07/09/17.
//

#ifndef PERCEPTRON_PERCEPTRON_H
#define PERCEPTRON_PERCEPTRON_H

#include <iostream>
using namespace std;

class Perceptron {
private:
    float **dataEntry;
    unsigned n;
    unsigned p;
    float *weight;
    void create(unsigned n, unsigned p);
    void copy(const Perceptron &perceptron);
    void clean();
public:
    inline Perceptron(): dataEntry(NULL), n(0), p(0), weight(NULL){}
    inline Perceptron(unsigned n, unsigned p){create(n,p);}
    inline Perceptron(const Perceptron &perceptron){copy(perceptron);}
    inline ~Perceptron(){clean();}
    void load(unsigned Cn, unsigned Cp, float** matrixTraining);
    void train();
    void getVectorWeight();
    float  getResult(float comparisonData[]);

};


#endif //PERCEPTRON_PERCEPTRON_H
