#include "ofApp.h"

void ofApp::draw(){
	
	float x = ofGetMouseX();
	float y = ofGetMouseY();
	float hue = ofMap(x, 0, ofGetWidth(), 0, 360);
	float luminance = ofMap(y, 0, ofGetHeight(), 0, 100);
	
	ofSetColor(HLuv.getColor(hue, luminance));
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

	// Text
	ofSetColor(luminance > 50 ? 0 : 255);
	ofDrawBitmapString("Hue: " + ofToString(hue), 100, 100);
	ofDrawBitmapString("Luminance: " + ofToString(luminance), 100, 120);
}
