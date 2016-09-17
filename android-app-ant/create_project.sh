#!/bin/bash

if [[ -f setenv.sh ]] 
then
 source setenv.sh
else
 echo "Error: setenv.sh not found! Please copy setenv.sh.sample to setenv.sh, and set path to toolchain;"
fi

$ANDROID_SDK/tools/android create project --target $ANDROID_TARGET --name AndroidAppAnt --path . --activity MainActivity --package com.example.testapp

echo "Done!"
