//
// Created by Alexander Novinskiy on 02/09/16.
//

#ifndef PRACTICE_XTEST_H
#define PRACTICE_XTEST_H

/*
 * This abstract class represents an interface for test-cases which are supposed to implement input data setup
 * and perform an assertion of a logical statement comprising the test.
 * Test cases might contain several test steps, i.e. steps which verify a certain (complex) property/functionality
 * in compound with each other. Test steps definition functionality shall be also declared in XTest abstract class.
 * Each test case and test step shall be described in terms of input data, expected values and some general information.
 * XTest abstract class shall provide declarations of methods dedicated for managing descriptive information.
 * Assertion capabilities shall be extended.
 */
class XTest {
public:
    virtual void setInput() = 0;
    virtual void makeAssertion() = 0;
    virtual ~XTest(){};
};

/*
 * TestDaemon runs individual test cases.
 * This is the core abstract class which declares functionality for running test cases, reporting results per test case,
 * and generating summary report by the end of proceeding.
 * Test cases can be run individually, but there should also be a mechanism to register desired test cases in a queue
 * to run later on.
 * ToDo: conditional test runs.
 */
class TestDaemon {
public:
    virtual void runTest(XTest*) = 0;
    virtual void finalize() = 0;
    virtual void runAll() = 0;
    virtual void registerTest(XTest*) = 0;

};
#endif //PRACTICE_XTEST_H
