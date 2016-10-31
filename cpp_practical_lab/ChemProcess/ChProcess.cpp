//
// Created by Alexander Novinskiy on 31/10/2016.
//

#include "ChProcess.h"

float ChProcess::dropSize = 0.9389; //ml

/*
 * ChProcessAcc implementation
 */

ChProcessAcc::ChProcessAcc(float _totalAmount){
    totalAmount = _totalAmount;
}

ChProcessAcc::ChProcessAcc(){
    ChProcessAcc(0.0);
}

float ChProcessAcc::computeTotalAmount(int _numberOfIterations){
    float _totalAmount = 0.0;
    for (int i=0; i<_numberOfIterations; i++){
        _totalAmount += dropSize;
    }
    return _totalAmount;
}

float ChProcessAcc::getTotalAmount(int _numberOfIterations){
    return computeTotalAmount(_numberOfIterations);
}

/*
 * ChProcessMult implementation
 */

ChProcessMult::ChProcessMult(float _totalAmount){
    totalAmount = _totalAmount;
}

ChProcessMult::ChProcessMult(){
    ChProcessMult(0.0);
}

float ChProcessMult::computeTotalAmount(int _numberOfIterations){
    return _numberOfIterations * dropSize;
}

float ChProcessMult::getTotalAmount(int _numberOfIterations){
    return computeTotalAmount(_numberOfIterations);
}
