#include "ofApp.h"

#include "ofxNI2.h"

ofxNI2::Device *device;
ofxNI2::IrStream ir;
ofxNI2::ColorStream color;
ofxNI2::DepthStream depth;

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofBackground(0);
	
	device = new ofxNI2::Device;
	device->setup();
	
	if (depth.setup(*device))
	{
		depth.setSize(320, 240);
		depth.setFps(30);
		depth.start();
	}

	if (ir.setup(*device)) // only for xtion device (OpenNI2-FreenectDriver issue)
	{
		ir.setSize(320, 240);
		ir.setFps(30);
		ir.start();
	}
	
//	if (color.setup(*device)) // only for kinect device
//	{
//		color.setSize(320, 240);
//		color.setFps(60);
//		color.start();
//	}
}

void ofApp::exit()
{
	device->exit();
	delete device;
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
	ir.draw();
//	color.draw();
	depth.draw(320, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}