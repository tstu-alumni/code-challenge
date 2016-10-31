//
// Created by Alexander Novinskiy on 31/10/2016.
//

#ifndef CHEMPROCESS_ChProcess_H
#define CHEMPROCESS_ChProcess_H

class ChProcess{
public:
    static float dropSize;
    virtual float getTotalAmount(int)=0;
};

class ChProcessAcc : public ChProcess{
public:
    ChProcessAcc();
    ChProcessAcc(float);
    float getTotalAmount(int);

private:
    float totalAmount;
    float computeTotalAmount(int);
};

class ChProcessMult : public ChProcess{
public:
    ChProcessMult();
    ChProcessMult(float);
    float getTotalAmount(int);

private:
    float totalAmount;
    float computeTotalAmount(int);
};

#endif //CHEMPROCESS_ChProcess_H