#include "XTestRunnerDaemon.h"
#include "XTestPractice.h"

int main() {
    XTestRunnerDaemon *testPractice;
    testPractice = new XTestRunnerDaemon;

    /*
     * Note: alternatively test cases could be run as follows
     */
#if 0 //these lines of code are not compiled
    testPractice->registerTest(new TestCustomStruct_IDEQ1);
    testPractice->registerTest(new TestCustomStruct_IDEQ2);
    testPractice->runAll();
#endif

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