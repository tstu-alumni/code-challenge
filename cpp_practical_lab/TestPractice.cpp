//
// Created by Alexander Novinskiy on 02/09/16.
//
#include <iostream>
#include <assert.h>
#include "TestPractice.h"

unsigned int TestPractice::testCaseNumber = 0;

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
    assert(id==2);
    delete(customStruct);
    return;
}
