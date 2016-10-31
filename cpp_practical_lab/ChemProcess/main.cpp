//
// Created by Alexander Novinskiy on 31/10/2016.
//

#include <iostream>
#include "ChProcess.h"
#include "ProcessFacade.h"


int main() {

    int dropsNumber=0;
    std::cout.precision(10);
    std::cout << "Input the number of chemical drops" << std::endl;
    std::cin >> dropsNumber;

    ProcessFacade *processFacade = new ProcessFacadeDefault(dropsNumber);

    processFacade->setChProcess(new ChProcessAcc);
    processFacade->runProcess();
    processFacade->releaseChProcess();

    processFacade->setChProcess(new ChProcessMult);
    processFacade->runProcess();
    processFacade->releaseChProcess();

    delete(processFacade);

    return 0;
}