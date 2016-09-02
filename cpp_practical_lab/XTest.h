//
// Created by Alexander Novinskiy on 02/09/16.
//

#ifndef PRACTICE_XTEST_H
#define PRACTICE_XTEST_H

class XTest {
public:
    virtual void setInput() = 0;
    virtual void makeAssertion() = 0;
    virtual ~XTest(){};
};

#endif //PRACTICE_XTEST_H
