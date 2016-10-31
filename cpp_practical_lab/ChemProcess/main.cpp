//
// Created by Alexander Novinskiy on 31/10/2016.
//

#include <iostream>
//#include <limits>
#include "ChProcess.h"

int main() {
    int dropsNumber=0;
    std::cout.precision(10);
    std::cout << "Input the number of chemical drops" << std::endl;
    std::cin >> dropsNumber;
    std::cout << "The number of chemical drops is: " << dropsNumber << std::endl;

    ChProcessAcc *chProcessAcc = new ChProcessAcc();
    std::cout << "The total amount of chemical is: " << chProcessAcc->getTotalAmount(dropsNumber)
              << std::endl;
    delete(chProcessAcc);

    ChProcessMult *chProcessMult = new ChProcessMult();
    std::cout << "The total amount of chemical is: " << chProcessMult->getTotalAmount
            (dropsNumber) << std::endl;
    delete(chProcessMult);

    return 0;
}