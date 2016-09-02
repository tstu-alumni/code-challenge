//
// Created by Alexander Novinskiy on 02/09/16.
//

#include <tcl.h>
#include "CustomStruct.h"

int CustomStruct::TotalAmount=0;

CustomStruct::CustomStruct(void) {
    TotalAmount++;
    id = TotalAmount;
}

int CustomStruct::getId(void) {
    return id;
}