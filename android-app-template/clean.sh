#!/bin/bash
echo "Cleaning..."

DEV_HOME="."
rm $DEV_HOME/AndroidTest.keystore
rm $DEV_HOME/bin/*
rm -r $DEV_HOME/obj/*
rm $DEV_HOME/src/com/example/testapp/R.java
echo "Done!"
