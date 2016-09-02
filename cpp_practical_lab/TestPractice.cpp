//
// Created by Alexander Novinskiy on 02/09/16.
//
#include <assert.h>
#include "TestPractice.h"

TestPractice::TestPractice(XTest *_testObject) {
    testObject = _testObject;
}

void TestPractice::runTest() {
    testObject->setInput();
    testObject->makeAssertion();
}

TestPractice::~TestPractice() {
    if (testObject!=NULL) delete(testObject);
    testObject = NULL;
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
