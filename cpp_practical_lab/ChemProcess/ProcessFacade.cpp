//
// Created by Alexander Novinskiy on 31/10/2016.
//

#include "ProcessFacade.h"
#include <iostream>


/*
 * ProcessFacade implementation
 */

void ProcessFacade::setChProcess(ChProcess* _chProcess){
    chProcess = _chProcess;
}

ChProcess* ProcessFacade::getChProcess(void){
    return chProcess;
}

void ProcessFacade::releaseChProcess(){
    delete(chProcess);
}

/*
 * ProcessFacadeDefault implementation
 */

ProcessFacadeDefault::ProcessFacadeDefault(int _dropsNumber){
    setDropsNumber(_dropsNumber);
}

void ProcessFacadeDefault::setDropsNumber(int _dropsNumber){
    dropsNumber = _dropsNumber;
}
int ProcessFacadeDefault::getDropsNumber(){
    return dropsNumber;
}

void ProcessFacadeDefault::runProcess(){
    std::cout << "The total amount of chemical is: " << this->getChProcess()->getTotalAmount
            (dropsNumber)
              << std::endl;
}