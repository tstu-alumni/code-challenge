//
// Created by Alexander Novinskiy on 06/11/2016.
//

#ifndef QUADRATICEQUATIONAPPROXIMATOR_QESOLVER_H
#define QUADRATICEQUATIONAPPROXIMATOR_QESOLVER_H

#include <iostream>

typedef enum{
    NOT_DEFINED,
    SINGLE,
    GENERAL
} QESolutionStatus;

struct QESolution{
    QESolutionStatus status;
    float x[2];
public:
    std::string toSTring();
};

class QESolver {
public:
    QESolver(float, float, float);
    void setA(float);
    void setB(float);
    void setC(float);
    float getA(void);
    float getB(void);
    float getC(void);
    virtual QESolution solveQE();
    virtual float getDescriminant() = 0;
    virtual ~QESolver() = 0;
private:
    float a, b, c;
};

class QEPreciseSolver : public QESolver{
public:
    QEPreciseSolver(float, float, float);
    float getDescriminant();
    ~QEPreciseSolver();
};

class QEApproxSolver : public QESolver{
public:
    QEApproxSolver(float, float, float);
    float getDescriminant();
    ~QEApproxSolver();
};


#endif //QUADRATICEQUATIONAPPROXIMATOR_QESOLVER_H
