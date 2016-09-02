#include <iostream>

#include "TestPractice.h"

using namespace std;

int main() {
    TestPractice *testPractice;

    /* Test
     * Input:
     *  TotalAmount=0
     *  CustomStruct object created once
     * Expected value:
     *  id=1
     */
    cout << "TestCase #" << TestPractice::getTestCaseNumber() << " ";
    testPractice = new TestPractice(new TestCustomStruct_IDEQ1);
    testPractice->runTest();
    delete(testPractice);
    cout << "Passed." << endl;

    /*
     * Input:
     *  TotalAmount=0
     *  CustomStruct object created twice
     * Expected value:
     *  id=2
     */
    cout << "TestCase #" << TestPractice::getTestCaseNumber() << " ";
    testPractice = new TestPractice(new TestCustomStruct_IDEQ2);
    testPractice->runTest();
    delete(testPractice);
    cout << "Passed." << endl;

    cout << "All tests successfully passed." << endl;

    return 0;
}