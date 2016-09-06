//
// Created by Alexander Novinskiy on 06/09/16.
//

#ifndef CPP_PRACTICAL_LAB_TESTRUNNER_H_H
#define CPP_PRACTICAL_LAB_TESTRUNNER_H_H

#include "XTest.h"

/*
 * XTestRunner runs individual test cases.
 * This is the core abstract class which declares functionality for running test cases, reporting results per test case,
 * and generating summary report by the end of proceeding.
 * Test cases can be run individually, but there should also be a mechanism to register desired test cases in a queue
 * to run later on.
 * ToDo: conditional test runs.
 */
class XTestRunner {
public:
    virtual void runTest(XTest*) = 0;
    virtual void finalize() = 0;
    virtual void registerTest(XTest*) = 0;
    virtual void runAll() = 0;
};

#endif //CPP_PRACTICAL_LAB_TESTRUNNER_H_H
