#!/bin/bash

if [[ -f setenv.sh ]] 
then
 source setenv.sh
else
 echo "Error: setenv.sh not found! Please copy setenv.sh.sample to setenv.sh, and set path to toolchain;"
fi

#project
DEV_HOME="."
PACKAGE_PATH="com/example/testapp"
PACKAGE="com.example.testapp"
MAIN_CLASS="MainActivity"

if [[ -f clean.sh ]]
then
 source clean.sh
else
 echo "clean.sh not found!"
fi

mkdir $DEV_HOME/bin
mkdir $DEV_HOME/obj

echo "generate R.java"
$AAPT_PATH package -f -m -S $DEV_HOME/res -J $DEV_HOME/src -M $DEV_HOME/AndroidManifest.xml -I $ANDROID_JAR

echo "compile"
$JAVA_HOME/bin/javac -d $DEV_HOME/obj -cp $ANDROID_JAR -sourcepath $DEV_HOME/src $DEV_HOME/src/$PACKAGE_PATH/*.java -source 1.7 -target 1.7

echo "ganerate dex classes"
$DX_PATH --dex --output=$DEV_HOME/bin/classes.dex $DEV_HOME/obj

echo "generate unsigned apk"
$AAPT_PATH package -f -M $DEV_HOME/AndroidManifest.xml -S $DEV_HOME/res -I $ANDROID_JAR -F $DEV_HOME/bin/AndroidTest.unsigned.apk $DEV_HOME/bin

if [[ ! -f $DEV_HOME/AndroidTest.keystore ]]
then
 echo "create new $DEV_HOME/AndroidTest.keystore"
$JAVA_HOME/bin/keytool -genkey -validity 10000 -dname "CN=AndroidDebug, O=Android, C=US" -keystore $DEV_HOME/AndroidTest.keystore -storepass android -keypass android -alias androiddebugkey -keyalg RSA -v -keysize 2048
else
 echo "use existing $DEV_HOME/AndroidTest.keystore"
fi

echo "signing apk"
$JAVA_HOME/bin/jarsigner -sigalg SHA1withRSA -digestalg SHA1 -keystore $DEV_HOME/AndroidTest.keystore -storepass android -keypass android -signedjar $DEV_HOME/bin/AndroidTest.signed.apk $DEV_HOME/bin/AndroidTest.unsigned.apk androiddebugkey

echo "done"
