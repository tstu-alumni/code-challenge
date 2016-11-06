#include <iostream>
#include "QESolver.h"

int main() {
    float a, b, c;
    std::cout << "Define a quadratic equation as follows: ax^2 + bx + c = 0" << std::endl;
    std::cout << "Define [a]: ";
    std::cin >> a;
    std::cout << "Define [b]: ";
    std::cin >> b;
    std::cout << "Define [c]: ";
    std::cin >> c;

    QESolver *preciseSolver = new QEPreciseSolver(a, b, c);
    std::cout << "Precise scheme solution is:" << std::endl;
    std::cout << "    " << preciseSolver->solveQE().toSTring() << std::endl;
    delete(preciseSolver);

    QESolver *approxSolver = new QEApproxSolver(a, b, c);
    std::cout << "Approximation scheme solution is:" << std::endl;
    std::cout << "    " <<   approxSolver->solveQE().toSTring() << std::endl;
    delete(approxSolver);

    return 0;
}