//
// Created by Alexander Novinskiy on 02/09/16.
//
#include <iostream>
#include "XTestRunnerDaemon.h"

unsigned int XTestRunnerDaemon::testCaseNumber = 0;

XTestRunnerDaemon::XTestRunnerDaemon() {
    testList = new TestList;
}
/*
 * std::cout stream isn't synchronized.
 * The output order may not be identical from run to run when two std::cout writes go subsequently.
 * See how to synchronize std::cout stream.
 */
void XTestRunnerDaemon::runTest(XTest* testObject) {
    if (testObject!= nullptr){
        XTestRunnerDaemon::testCaseNumber++;
        std::cout << "TestCase #" << XTestRunnerDaemon::getTestCaseNumber() << " ";
        testObject->setInput();
        testObject->makeAssertion();
        std::cout << "Passed." << std::endl;
        delete(testObject);
    }
    return;
}

int XTestRunnerDaemon::getTestCaseNumber() {
    return XTestRunnerDaemon::testCaseNumber;
}

void XTestRunnerDaemon::finalize() {
    std::cout << "All tests successfully passed." << std::endl;
    return;
}

XTestRunnerDaemon::~XTestRunnerDaemon() {
    this->finalize();
    delete(testList);
}

void XTestRunnerDaemon::runAll() {
    /*
     * ToDo: Here goes an implementation of "run all test cases" routine.
     */
    for (TestList::iterator it=testList->begin(); it != testList->end(); ++it)
        this->runTest(*it);
    return;
}

void XTestRunnerDaemon::registerTest(XTest *_testCase) {
    /*
     * ToDo: Here goes an implementation of "register a test" routine.
     */
    this->testList->push_back(_testCase);
    return;
}

