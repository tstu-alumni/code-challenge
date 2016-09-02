#include <iostream>

#include "TestPractice.h"

using namespace std;

int main() {
    TestPractice *testPractice;

    testPractice = new TestPractice(new TestCustomStruct_IDEQ1);
    testPractice->runTest();
    delete(testPractice);

    testPractice = new TestPractice(new TestCustomStruct_IDEQ2);
    testPractice->runTest();
    delete(testPractice);

    cout << "All tests successfully passed." << endl;

    return 0;
}