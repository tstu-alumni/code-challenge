# cpp-practical-lab/test_frame

This project is dedicated to collecting C++ usage examples.

In order to facilitate C++ practices a custom testing framework is being developed as part of the project. Contributors are also welcome to use any other 3rd party testing framework such as boost or google-test to test their modules.

The custom testing framework is organized as follows:

XTest.h contains the XTest abstract class as a basis for particular test-cases. Each test-case is supposed to implement methods setInput and makeAssertion.

XTestPractice.h contains declarations of particular test-cases which inherit methods from XTest abstract class.

XTestPractice.cpp contains implementation of particular test-cases declared in XTestPractice.h.

XTestRunner.h contains the XTestRunner abstract class declaration as a basis for particular implementation of a test runner - core class of the framework which is responsible for running test-cases which implement XTest abstract class.

XTestRunnerDaemon.h and XTestRunnerDaemon.cpp contain declaration and implementation of particular test runner class.
