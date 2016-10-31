//
// Created by Alexander Novinskiy on 06/09/16.
//

#ifndef CPP_PRACTICAL_LAB_XTESTPRACTICE_H
#define CPP_PRACTICAL_LAB_XTESTPRACTICE_H

#include "XTest.h"
#include "CustomStruct.h"

/*
 * Classes below represent individual test cases by extending XTest interface.
 */

/*
 * Info: TestCustomStruct_IDEQ1 verifies if CustomStruct constructor is called on creation of an object by checking
 * the id field after the first creation of the object.
 * Expected value: id=1
 */
class TestCustomStruct_IDEQ1: public XTest{
public:
    void setInput();
    void makeAssertion();
private:
    CustomStruct *customStruct;
};

/*
 * Info: TestCustomStruct_IDEQ2 verifies if CustomStruct constructor is called on creation of an object and the static
 * field is incremented correctly by checking the id field after the second creation of the object.
 * Expected value: id=2
 */
class TestCustomStruct_IDEQ2: public XTest{
public:
    void setInput();
    void makeAssertion();
private:
    CustomStruct *customStruct;
};

#endif //CPP_PRACTICAL_LAB_XTESTPRACTICE_H
