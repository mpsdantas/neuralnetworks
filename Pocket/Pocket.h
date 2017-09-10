//
// Created by marcus on 09/09/17.
//

#ifndef POCKET_POCKET_H
#define POCKET_POCKET_H

#include <iostream>
using namespace std;

class Pocket {
private:
    float **dataEntry;
    unsigned n;
    unsigned p;
    float *weight;
    float *weightPocket;
    unsigned stepEstimated;
    void create(unsigned Cn, unsigned Cp);
    void copy(const Pocket &pocket);
    void clean();
public:
    inline Pocket(): dataEntry(NULL), n(0), p(0), weight(NULL), weightPocket(NULL), stepEstimated(0){}
    inline Pocket(unsigned n, unsigned p){create(n,p);}
    inline Pocket(const Pocket &pocket){copy(pocket);}
    inline ~Pocket(){clean();}
    void load(unsigned Cn, unsigned Cp, unsigned step_estimated, float** matrixTraining);
    void train();
    void getVectorWeight();
    void getVectorWeightPocket();
    void  getResult(float comparisonData[]);
};


#endif //POCKET_POCKET_H
