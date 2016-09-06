//
// Created by Alexander Novinskiy on 06/09/16.
//

#include <assert.h>
#include "XTestPractice.h"

/*
 * Here goes implementation of individual test cases
 */

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
/*
 * Change to assert(id==1) to fail the test case
 */
void TestCustomStruct_IDEQ2::makeAssertion() {
    int id = customStruct->getId();
    assert(id==2);
    delete(customStruct);
    return;
}
