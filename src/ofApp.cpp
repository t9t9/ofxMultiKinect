#include "ofApp.h"

int nKinect = 0;

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(50, 50, 50);
	
	nKinect = kinect[0].numTotalDevices();
	ofLogNotice() << nKinect;

	// enable depth->video image calibration
	for(int i=0; i<nKinect; i++){	
		kinect[i].setRegistration(true);
		kinect[i].init(false, false);	// disable video image (faster fps)
		kinect[i].open();				// opens first available kinect
	}
    
}

//--------------------------------------------------------------
void ofApp::update() {

	for(int i=0; i<nKinect; i++){	
		kinect[i].update();
	}

}

//--------------------------------------------------------------
void ofApp::draw() {

	for(int i=0; i<nKinect; i++){	
		kinect[i].drawDepth(i*400,0,400,300);
	}

}

//--------------------------------------------------------------
void ofApp::exit() {

	for(int i=0; i<nKinect; i++){	
		kinect[i].close();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed (int key) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{}
