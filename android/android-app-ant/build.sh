#TODO add build options - debug/release
if [[ -f setenv.sh ]]
then
 source setenv.sh
else
 echo "Error: setenv.sh not found! Please copy setenv.sh.sample to setenv.sh, and set path to toolchain;"
fi

#build native code
$NDK_BUILD

#generate unsigned apk
$ANT release

#apk signing
if [[ ! -f $DEV_HOME/$APK_NAME.keystore ]]
then
 echo "create new $DEV_HOME/$APK_NAME.keystore"
$JAVA_HOME/bin/keytool -genkey -validity 10000 -dname "CN=AndroidRelease, O=Android, C=US" -keystore $DEV_HOME/$APK_NAME.keystore -storepass android -keypass android -alias androidreleasekey -keyalg RSA -v -keysize 2048
else
 echo "use existing $DEV_HOME/$APK_NAME.keystore"
fi

echo "signing apk"
$JAVA_HOME/bin/jarsigner -sigalg SHA1withRSA -digestalg SHA1 -keystore $DEV_HOME/$APK_NAME.keystore -storepass android -keypass android -signedjar $DEV_HOME/bin/$APK_NAME-release-signed.apk $DEV_HOME/bin/$APK_NAME-release-unsigned.apk androidreleasekey

echo "Done!"
