#!/bin/bash
#set path to SDK
echo "set environment variables"
JAVA_HOME="/n23/JavaSDK8/jdk1.8.0_92"
ANDROID_HOME="/n23/AndroidSDK"
ANDROID_TOOLS_VER="24.0.2"
AAPT_PATH="$ANDROID_HOME/build-tools/$ANDROID_TOOLS_VER/aapt"
DX_PATH="$ANDROID_HOME/build-tools/$ANDROID_TOOLS_VER/dx"
ANDROID_JAR="$ANDROID_HOME/platforms/android-24/android.jar"
ADB="$ANDROID_HOME/platform-tools/adb"
ANT="/n23/apache-ant-1.9.7/bin/ant"

#project
DEV_HOME="."
APK_NAME="AndroidAppAnt"
PACKAGE_NAME="com.example.testapp"

