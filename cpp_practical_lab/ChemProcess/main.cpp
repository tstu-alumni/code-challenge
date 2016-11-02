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
    ChProcess *chProcess;

    processFacade->setChProcess(chProcess = new ChProcessAcc);
    processFacade->runProcess();
    delete(chProcess);

    processFacade->setChProcess(chProcess = new ChProcessMult);
    processFacade->runProcess();
    delete(chProcess);

    delete(processFacade);

    return 0;
}