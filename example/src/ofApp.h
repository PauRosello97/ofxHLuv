#pragma once

#include "ofMain.h";
#include "ofxHLuv.h";

class ofApp : public ofBaseApp{
	ofxHLuv HLuv;

	public:
		void draw();
};
