//
// Created by Alexander Novinskiy on 02/09/16.
//

#ifndef PRACTICE_XTESTRUNNERDAEMON_H
#define PRACTICE_XTESTRUNNERDAEMON_H

#include "XTest.h"
#include "XTestRunner.h"
#include <list>

/*
 * XTestRunnerDaemon: Main testing class running custom tests defined as extensions of XTest interface
 * Methods:
 *  void runTest(XTest*): runs a test case by setting up inputs and making a corresponding assertion. Particular
 *                  implementation of setInput and makeAssertion methods depends on the particular test-case class.
 *                  Destroys the test-case class after running the test.
 *  int getTestCaseNumber(): a static method returning the number of the current test case.
 *  void finalize(): Outputs summary information about test run into the standard output flow.
 *  void runAll(): Runs all registered test cases (not implemented).
 * ToDo: Extend the class to provide overwhelming testing capabilities.
 */
typedef std::list<XTest*> TestList;
class XTestRunnerDaemon: public XTestRunner{
public:
    XTestRunnerDaemon();
    static int getTestCaseNumber();
    void runTest(XTest*);
    void finalize();
    void registerTest(XTest*);
    void runAll();
    ~XTestRunnerDaemon();
private:
    static unsigned int testCaseNumber;
    TestList *testList;
};

#endif //PRACTICE_XTESTRUNNERDAEMON_H

