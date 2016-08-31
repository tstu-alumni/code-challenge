#!/bin/bash
#set path to SDK
echo "set environment variables"
JAVA_HOME="/n23/JavaSDK8/jdk1.8.0_92"
ANDROID_HOME="/n23/AndroidSDK"
DEV_HOME="."
ANDROID_TOOLS_VER="24.0.2"
AAPT_PATH="$ANDROID_HOME/build-tools/$ANDROID_TOOLS_VER/aapt"
DX_PATH="$ANDROID_HOME/build-tools/$ANDROID_TOOLS_VER/dx"
ANDROID_JAR="$ANDROID_HOME/platforms/android-24/android.jar"
ADB="$ANDROID_HOME/platform-tools/adb"

#project
PACKAGE_PATH="com/example/testapp"
PACKAGE="com.example.testapp"
MAIN_CLASS="MainActivity"

echo "clean"
rm $DEV_HOME/AndroidTest.keystore
rm -r $DEV_HOME/bin
rm -r $DEV_HOME/obj
rm $DEV_HOME/src/com/example/testapp/R.java

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

echo "signing apk"
$JAVA_HOME/bin/keytool -genkey -validity 10000 -dname "CN=AndroidDebug, O=Android, C=US" -keystore $DEV_HOME/AndroidTest.keystore -storepass android -keypass android -alias androiddebugkey -keyalg RSA -v -keysize 2048
$JAVA_HOME/bin/jarsigner -sigalg SHA1withRSA -digestalg SHA1 -keystore $DEV_HOME/AndroidTest.keystore -storepass android -keypass android -signedjar $DEV_HOME/bin/AndroidTest.signed.apk $DEV_HOME/bin/AndroidTest.unsigned.apk androiddebugkey

echo "done"
