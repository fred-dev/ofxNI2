#include "ofApp.h"

void ofApp::setup(){
    
	ofBackground(0);
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
    ofEnableDepthTest();
    
    cam.setDistance(4000);
    cam.setFarClip(10000);
    
    device.setup();
	tracker.setup(device);
    
    model.loadModel("test.dae");
    model.setupBones();
}

void ofApp::exit(){
    
	tracker.exit();
	device.exit();
}

void ofApp::update(){
    
	device.update();
	for (int i = 0; i < tracker.getNumUser(); i++){
		ofxNiTE2::User::Ref user = tracker.getUser(i);
        model.transformBones(user);
	}
}

void ofApp::draw(){
    
    depthImage.setFromPixels(tracker.getPixelsRef(100, 4000));
    depthImage.draw(0, 0, 320, 240);
    
	cam.begin();
    
    ofPushMatrix();
    ofTranslate(0, -800, 0);
    ofRotate(90, 0, 0, 1);
    ofDrawGridPlane(3000, 10);
    ofPopMatrix();
    
    tracker.draw();
    
    ofPushMatrix();
    ofRotate(90, 0, 0, 0);
    light.enable();
    ofSetColor(255);
    model.draw(OF_MESH_FILL);
    ofDisableLighting();
    ofPopMatrix();
    
	cam.end();
}
