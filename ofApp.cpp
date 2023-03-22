#include "ofApp.h"

void Clock::draw() {
	float angle = glm::radians(6.0 * second);
	glm::vec3 hand = glm::normalize(glm::vec3(glm::sin(angle), -glm::cos(angle),
		0));
	ofPushMatrix();
	ofMultMatrix(getMatrix());
	// Draw clock in "object space" around it's local
	// origin and let the transform move it into it's
	// position
	//
	glm::vec3 localOrigin = glm::vec3(0, 0, 0);
	ofFill();
	ofSetCircleResolution(50);
	ofSetColor(ofColor::darkBlue);
	ofDrawCircle(localOrigin, radius);
	// draw background image
	//
	ofSetColor(ofColor::white);
	if (bBackGroundImage) {
		float w = background.getWidth();
		float h = background.getHeight();
		background.draw(-w/2, -h/2);
	}
	// draw hand
	//
	// r(t) = o + t*d
	ofSetColor(ofColor::black);
	ofDrawLine(localOrigin, localOrigin + radius2 * hand);
	ofPopMatrix();
}

void Clock::update() {
	float curTime = ofGetElapsedTimeMillis();
	if ((curTime - lastTime) > 1000) {
		second++;
		if (second > 59) second = 0;
		lastTime = curTime;
	}
	
	
}


//--------------------------------------------------------------
void ofApp::setup(){
	clock.scale = glm::vec3(1, 1, 1);
	if (!clockBackground.load("images/clock-cartoon4.png")) // images file stored in bin/data
	{
		cout << "Can't find image" << endl;
		ofExit();
	}
	clock.setBackgroundImage(clockBackground);
}

//--------------------------------------------------------------
void ofApp::update(){
	clock.update();
	clock.rot = 45.0;	// if you wanna rotate the image
}

//--------------------------------------------------------------
void ofApp::draw(){
	clock.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'C':
	case 'c':
	case 'F':
	case 'f':
		ofToggleFullscreen();
		break;
	case 'H':
	case 'h':
		break;
	case 'r':
		break;
	case 's':
		break;
	case 't':
		break;
	case 'u':
		break;
	case 'v':
		break;
	case 'V':
		break;
	case 'w':
		break;
	case OF_KEY_ALT:
		break;
	case OF_KEY_CONTROL:
		break;
	case OF_KEY_SHIFT:
		bShiftKey = true;
		break;
	case OF_KEY_DEL:
		break;
	case OF_KEY_F1:
		break;
	case OF_KEY_F2:
		break;
	default:
		break;
	}
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	switch (key) {
	case 'C':
	case 'c':
	case 'F':
	case 'f':
		break;
	case 'H':
	case 'h':
		break;
	case 'r':
		break;
	case 's':
		break;
	case 't':
		break;
	case 'u':
		break;
	case 'v':
		break;
	case 'V':
		break;
	case 'w':
		break;
	case OF_KEY_ALT:
		break;
	case OF_KEY_CONTROL:
		break;
	case OF_KEY_SHIFT:
		bShiftKey = false;
		break;
	case OF_KEY_DEL:
		break;
	case OF_KEY_F1:
		break;
	case OF_KEY_F2:
		break;
	default:
		break;
	}
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (bDragging) {
		glm::vec3 mouseCurrent = glm::vec3(x, y, 0);
		glm::vec3 delta = mouseCurrent - mouseLast;
		if (!bShiftKey)
			clock.pos += delta;
		else
			clock.radius += delta.x;
		mouseLast = mouseCurrent;
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (clock.inside(glm::vec3(x, y, 0))) {
		bDragging = true;
		cout << "The point is inside the boundaries of the image" << endl;
		if (!clock.inside2(glm::vec3(x, y, 0))) {
			cout << "The point is in the non-transparent part of the image" << endl;
		}
		mouseLast = glm::vec3(x, y, 0);
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	bDragging = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
