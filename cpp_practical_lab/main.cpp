#include "TestPractice.h"

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
    testPractice->runTest(new TestCustomStruct_IDEQ1);

    /*
     * Input:
     *  TotalAmount=0.
     *  CustomStruct object created twice.
     * Expected value:
     *  id=2.
     */
    testPractice->runTest(new TestCustomStruct_IDEQ2);

    delete(testPractice);

    return 0;
}