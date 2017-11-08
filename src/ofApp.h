#pragma once

#include "ofMain.h"

class Image {

public:
	Image();
	ofVec2f trans, scale;
	float	rot;
	ofImage image;
	bool bSelected;
	void draw( bool bSelectMode = false , int index = 0);
	
};



class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();
	void exit();
	void imgerase(Image *selectedImage);
	void imgsave();
	void mdraw(int x, int y);
	void renderSelection();
	void processSelection(int x, int y);

	void doMouseRotation(int x, int y);
	void doMouseTranslate(int x, int y);
	void doMouseScale(int x, int y);

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	void displaymenu();

private:
	ofEasyCam	cam;
	ofVec2f		lastMouse;
	bool		ctrlKeyDown;
	bool        tkey;
	bool		skey;
	bool		delkey;
	bool		savekey;
	bool		hit = 0;
	bool		dkey;
	bool		menukey=0;


	vector<Image *> images;
	Image *selectedImage;
	ofImage savedImage;
	ofRectangle button_rect;
	ofRectangle button_rect1;
	ofPolyline line;
	void typekey(int key);
	ofSoundPlayer welcome;
	ofTrueTypeFont myFont;
};