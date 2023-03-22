#pragma once

#include "ofMain.h"

// generic graphical shape base class
//
class Shape {
public:
	// virtual methods to be overloaded by subclass
	//
	virtual void draw() {};
	virtual void update() {};
	virtual bool inside(glm::vec3) { return false; };
	//glm::mat4 getMatrix() {
	// glm::mat4 m1 = glm::translate(glm::mat4(1.0), pos);
	// glm::mat4 m2 = glm::rotate(m1, glm::radians(rot), glm::vec3(0, 0, 1));
	// glm::mat4 M = glm::scale(m2, scale);      // added this scale if you want to change size of object
		// return M;
		//}
	glm::mat4 getMatrix() {
		glm::mat4 T = glm::translate(glm::mat4(1.0), pos);
		glm::mat4 R = glm::rotate(glm::mat4(1.0), glm::radians(rot),
			glm::vec3(0, 0, 1));
		glm::mat4 S = glm::scale(glm::mat4(1.0), scale);      // added this scale if you want to change size of object
		glm::mat4 M = T * R * S;
		return (M);
	}
	//  data 
	//
	glm::vec3 pos;
	glm::vec3 scale = glm::vec3(1, 1, 1);
	float rot = 0;    // degrees
};

class Clock : public Shape {
public:
	Clock() {
		pos = glm::vec4(300, 300, 0, 1);
	}
	// class methods
	//
	void draw();
	void update();
	bool inside(glm::vec3 p) {
		glm::vec3 localOrigin = glm::vec3(0, 0, 0);
		glm::vec3 p0 = glm::inverse(getMatrix()) * glm::vec4(p, 1);
		// return (glm::length(p - pos) < radius);
		return (glm::distance(p0, localOrigin) < radius);
	}

	bool inside2(glm::vec3 p) {
		glm::vec3 localOrigin = glm::vec3(0, 0, 0);
		glm::vec3 p0 = glm::inverse(getMatrix()) * glm::vec4(p, 1);
		// return (glm::length(p - pos) < radius);
		return (glm::distance(p0, localOrigin) < radius2);
	}
	
	void setBackgroundImage(ofImage image) {
		background = image;
		bBackGroundImage = true;
	}


	float radius = 162;
	float radius2 = 152;
	float lastTime = -9999;
	int second;   // elapsed time
	bool bBackGroundImage = false;
	ofImage background;
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		// the clock 
//
		Clock clock;
		// app-specific data
		//
		glm::vec3 mouseLast;
		bool bDragging = false;
		bool bShiftKey = false;
		ofImage clockBackground;
};
