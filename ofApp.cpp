#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetRectMode(ofRectMode::OF_RECTMODE_CENTER);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);

	float size = 1;
	float noise_value;
	ofColor rect_color;
	for (int y = size / 2; y < ofGetHeight() / 2 + size;) {

		for (int x = size / 2; x < ofGetWidth() / 2 + size / 2; x += size) {

			noise_value = ofNoise(x * 0.005, y * 0.005 - ofGetFrameNum() * 0.005);
			ofSetColor(noise_value * 255);

			ofDrawRectangle(ofPoint(x, y), size, size);
			ofDrawRectangle(ofPoint(x, -y), size, size);
			ofDrawRectangle(ofPoint(-x, y), size, size);
			ofDrawRectangle(ofPoint(-x, -y), size, size);
		}

		y += size * 1.25;
		size *= 1.5;
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}