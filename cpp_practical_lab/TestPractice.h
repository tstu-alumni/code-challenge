//
// Created by Alexander Novinskiy on 02/09/16.
//

#ifndef PRACTICE_TESTPRACTICE_H
#define PRACTICE_TESTPRACTICE_H

/*
 * These classes are made to implement test cases for custom classes and their methods.
 */

#include "XTest.h"
#include "CustomStruct.h"

/*
 * TestPractice: Main testing class running custom tests defined as extensions of XTest interface
 * Methods:
 *  TestPractice(XTest*): initializes TestPractice class by an object of a class which extends XTest basic interface
 *  void runTest(): runs a test case by setting up inputs and making a corresponding assertion. Particular implementation
 *                  of setInput and makeAssertion methods depends on the particular test-case class.
 *  ~TestPractice(): destroys test case object.
 */
class TestPractice {
public:
    TestPractice(XTest*);
    void runTest();
    ~TestPractice();
private:
    XTest *testObject;
};

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

#endif //PRACTICE_TESTPRACTICE_H
