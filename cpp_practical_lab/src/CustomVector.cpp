//
// Created by Alexander Novinskiy on 02/09/16.
//

#include "CustomVector.h"

CustomVector::CustomVector(int s) :elem{new double[s]}, sz{s} { } // constr uct a Vector

double& CustomVector::operator[](int i){
    return elem[i];
} // element access: subscripting

int CustomVector::size(){
    return sz;
}

/*
 * Causes a warning: 'delete' applied to a pointer that was allocated with 'new[]'; did you mean 'delete[]'?
 */
CustomVector::~CustomVector(void){
    delete(elem);
}
