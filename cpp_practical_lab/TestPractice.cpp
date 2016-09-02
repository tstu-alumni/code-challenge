//
// Created by Alexander Novinskiy on 02/09/16.
//
#include <assert.h>
#include "TestPractice.h"

unsigned int TestPractice::testCaseNumber = 1;

TestPractice::TestPractice(XTest *_testObject) {
    testObject = _testObject;
}

void TestPractice::runTest() {
    testCaseNumber++;
    testObject->setInput();
    testObject->makeAssertion();
}

TestPractice::~TestPractice() {
    if (testObject!=NULL) delete(testObject);
    testObject = NULL;
}

int TestPractice::getTestCaseNumber() {
    return testCaseNumber;
}

void TestPractice::setTestCaseNumber(unsigned int _testCaseNumber) {
    testCaseNumber = _testCaseNumber;
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
