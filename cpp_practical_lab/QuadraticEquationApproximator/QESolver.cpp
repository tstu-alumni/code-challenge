//
// Created by Alexander Novinskiy on 06/11/2016.
//

#include "QESolver.h"
#include <sstream>
#include <math.h>


std::string QESolution::toSTring(){
    std::ostringstream _string;
    if (this->status == NOT_DEFINED){
        _string << "NOT DEFINED";
    }
    else if (this->status == SINGLE){
        _string << "X1 = X2 = " << this->x[0];
    }
    else{
        _string << "X1 = " << this->x[0] << "; X2 = " << this->x[1] ;
    }
    return _string.str();
}

/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

QESolver::QESolver(float _a, float _b, float _c){
    this->setA(_a);
    this->setB(_b);
    this->setC(_c);
}
void QESolver::setA(float _a){
    this->a = _a;
}
void QESolver::setB(float _b){
    this->b = _b;
}
void QESolver::setC(float _c){
    this->c = _c;
}
float QESolver::getA(void){
    return this->a;
}
float QESolver::getB(void){
    return this->b;
}
float QESolver::getC(void){
    return this->c;
}
QESolution QESolver::solveQE(){
    QESolution solution;
    float descriminant = this->getDescriminant();
    if (descriminant > 0){
        solution.status = GENERAL;
        solution.x[0] = (-this->getB() - (float)sqrt(descriminant))/(2*this->getA());
        solution.x[1] = (-this->getB() + (float)sqrt(descriminant))/(2*this->getA());
    }
    else if (descriminant == 0){
        solution.status = SINGLE;
        solution.x[0] = solution.x[1] = -this->getB()/(2*this->getA());
    }
    else{
        solution.status = NOT_DEFINED;
    }
    return solution;
}
QESolver::~QESolver(){}

/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

QEPreciseSolver::QEPreciseSolver(float _a, float _b, float _c) : QESolver(_a, _b, _c){}
float QEPreciseSolver::getDescriminant(){
    return (float)pow(this->getB(),2) - 4*this->getA()*this->getC();
}
QEPreciseSolver::~QEPreciseSolver(){};

/*
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 */

QEApproxSolver::QEApproxSolver(float _a, float _b, float _c) : QESolver(_a, _b, _c){}
float QEApproxSolver::getDescriminant(){
    return (float)pow(this->getB(),2);
}
QEApproxSolver::~QEApproxSolver(){};