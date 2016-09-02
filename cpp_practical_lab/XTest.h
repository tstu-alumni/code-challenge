//
// Created by Alexander Novinskiy on 02/09/16.
//

#ifndef PRACTICE_XTEST_H
#define PRACTICE_XTEST_H

/*
 * This abstract class represents an interface for test-cases which are supposed to implement input data setup
 * and perform an assertion of a logical statement comprising the test.
 */
class XTest {
public:
    virtual void setInput() = 0;
    virtual void makeAssertion() = 0;
    virtual ~XTest(){};
};

class TestDaemon {
public:
    virtual void runTest() = 0;
};
#endif //PRACTICE_XTEST_H
