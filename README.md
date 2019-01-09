Setup
========
This version is forked from https://github.com/satoruhiga/ofxNI2

I have made changes to support kinectV2 on mac and windows using libfreenect2 (https://github.com/OpenKinect/libfreenect2/) (cant test on linux but if you have the libs it should work). 
This is working with openframeworks 0.10.1

I built libfreenect2 to work with openCL depth processing to be faster, there is currently no way to select an openCL device.

OSX
--------
Use project generator and then in xcode:

Add to Run Script

cp -R ../../../addons/ofxNI2/libs/OpenNI2/lib/osx/ "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/";
cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/libNiTE2.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/libNiTE2.dylib";
cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/NiTE.ini "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/NiTE.ini";
cp -R ../../../addons/ofxNI2/libs/NiTE2/lib/osx/NiTE2 "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Resources/";
install_name_tool -change libOpenNI2.dylib @executable_path/../MacOS/libOpenNI2.dylib "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/MacOS/$PRODUCT_NAME";


Visual Studio
--------



This should just work with the project generator.
