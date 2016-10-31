#!/bin/bash

if [[ -f setenv.sh ]] 
then
 source setenv.sh
else
 echo "Error: setenv.sh not found! Please copy setenv.sh.sample to setenv.sh, and set path to toolchain;"
fi

$ADB install $DEV_HOME/bin/$APK_NAME-release-signed.apk

echo "Done!"
