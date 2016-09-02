#include <iostream>

#include "TestPractice.h"

using namespace std;

int main() {
    TestPractice *testPractice;
    testPractice = new TestPractice;

    /* Test
     * Input:
     *  TotalAmount=0.
     *  CustomStruct object created once.
     * Expected value:
     *  id=1.
     */
    cout << "TestCase #" << TestPractice::getTestCaseNumber() << " ";
    testPractice->runTest(new TestCustomStruct_IDEQ1);
    cout << "Passed." << endl;

    /*
     * Input:
     *  TotalAmount=0.
     *  CustomStruct object created twice.
     * Expected value:
     *  id=2.
     */
    cout << "TestCase #" << TestPractice::getTestCaseNumber() << " ";
    testPractice->runTest(new TestCustomStruct_IDEQ2);
    cout << "Passed." << endl;

    cout << "All tests successfully passed." << endl;

    delete(testPractice);

    return 0;
}