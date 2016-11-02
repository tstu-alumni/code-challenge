#!/bin/bash

if [[ -f setenv.sh ]]
then
 source setenv.sh
else
 echo "Error: setenv.sh not found! Please copy setenv.sh.sample to setenv.sh, and set path to toolchain;"
fi

$NDK_BUILD
 
$ANDROID_HOME/tools/android update project --target $ANDROID_TARGET --name $APK_NAME --path $DEV_HOME --subprojects

echo "Done!"
