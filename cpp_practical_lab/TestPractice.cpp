//
// Created by Alexander Novinskiy on 02/09/16.
//
#include <iostream>
#include <assert.h>
#include "TestPractice.h"

unsigned int TestPractice::testCaseNumber = 0;

TestPractice::TestPractice() {
    testList = new TestList;
}
/*
 * std::cout stream isn't synchronized.
 * The output order may not be identical from run to run when two std::cout writes go subsequently.
 * See how to synchronize std::cout stream.
 */
void TestPractice::runTest(XTest* testObject) {
    if (testObject!= nullptr){
        TestPractice::testCaseNumber++;
        std::cout << "TestCase #" << TestPractice::getTestCaseNumber() << " ";
        testObject->setInput();
        testObject->makeAssertion();
        std::cout << "Passed." << std::endl;
        delete(testObject);
    }
    return;
}

int TestPractice::getTestCaseNumber() {
    return TestPractice::testCaseNumber;
}

void TestPractice::finalize() {
    std::cout << "All tests successfully passed." << std::endl;
    return;
}

TestPractice::~TestPractice() {
    this->finalize();
    delete(testList);
}

void TestPractice::runAll() {
    /*
     * ToDo: Here goes an implementation of "run all test cases" routine.
     */
    for (TestList::iterator it=testList->begin(); it != testList->end(); ++it)
        this->runTest(*it);
    return;
}

void TestPractice::registerTest(XTest *_testCase) {
    /*
     * ToDo: Here goes an implementation of "register a test" routine.
     */
    this->testList->push_back(_testCase);
    return;
}

void TestCustomStruct_IDEQ1::setInput() {
    CustomStruct::TotalAmount=0;
    customStruct = new CustomStruct;
    return;
}
/*
 * Function assert from assert.h provides good basic functionality, but causes the program to halt if an assertion fails.
 * Custom method for making assertions shall be created to extend testing capabilities of the framework.
 */
void TestCustomStruct_IDEQ1::makeAssertion() {
    int id = customStruct->getId();
    assert(id==1);
    delete(customStruct);
    return;
}

void TestCustomStruct_IDEQ2::setInput() {
    CustomStruct::TotalAmount=0;
    customStruct = new CustomStruct;
    delete(customStruct);
    customStruct = new CustomStruct;
    return;
}

void TestCustomStruct_IDEQ2::makeAssertion() {
    int id = customStruct->getId();
    assert(id==1);
    delete(customStruct);
    return;
}
