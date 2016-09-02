//
// Created by Alexander Novinskiy on 02/09/16.
//
#include <assert.h>
#include "TestPractice.h"

unsigned int TestPractice::testCaseNumber = 1;

void TestPractice::runTest(XTest* _testObject) {
    if (_testObject!= nullptr){
        testCaseNumber++;
        _testObject->setInput();
        _testObject->makeAssertion();
        delete(_testObject);
    }
    return;
}

int TestPractice::getTestCaseNumber() {
    return testCaseNumber;
}

void TestCustomStruct_IDEQ1::setInput() {
    CustomStruct::TotalAmount=0;
    customStruct = new CustomStruct;
    return;
}

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
