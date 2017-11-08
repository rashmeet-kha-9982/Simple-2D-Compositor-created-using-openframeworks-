
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	welcome.load("sounds/welcome.mp3");
	welcome.play();
	myFont.load("fonts/xyz.ttf", 65, true, true);
	ofSetVerticalSync(true);
	ofEnableDepthTest();
	ofEnableAlphaBlending();
	ofBackground(0, 0, 0);
	button_rect.set(ofPoint(0,0),200,50);
	button_rect1.set(ofPoint(0, 20), 200, 300);


	cam.setDistance(1000);
	cam.disableMouseInput();

	cam.setFarClip(-100);

	selectedImage = NULL;


	ctrlKeyDown = false;
	tkey = false;
	skey = false;
	delkey = false;
	savekey = false;

}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255, 255, 255);
	myFont.drawString("Welcome to Your Canvas",200,30);
	cam.begin();
	ofBackground(0);
	ofFill();

	for (int i = images.size() - 1; i >= 0; i--)
		images[i]->draw();
	cam.end();

	if (!hit) 
		ofSetColor(0, 100, 200);

	else ofSetColor(200, 0, 0);
	ofDrawRectangle(button_rect);
	ofSetColor(255, 255, 255);
	ofDrawBitmapString("Menu",15, 25);

	if (menukey) {
		ofSetColor(0, 0, 150);
		ofDrawRectangle(button_rect1);
		ofSetColor(255, 255, 255);
		ofDrawBitmapString("t/T - Translate", 15, 65);
		ofDrawBitmapString("s/S - Scale", 15, 85);
		ofDrawBitmapString("ctrl - rotate(2D)", 15, 105);
		ofDrawBitmapString("alt - move(3D)", 15, 125);
		ofDrawBitmapString("delete - delete", 15, 145);
		ofDrawBitmapString("v/V - Save", 15, 165);
		ofDrawBitmapString("d/D - Draw using mouse", 15, 185);
		ofDrawBitmapString("x/X - Clear drawn shape", 15, 205);
		ofDrawBitmapString("tab - full screen", 15, 225);
		ofDrawBitmapString("r/R - reset 3D movement", 15, 245);
	
	}

	

	line.draw();
	}

void ofApp::exit() {
	for (int i = 0; i < images.size(); i++) {
		delete images[i];
	}
}


void ofApp::keyPressed(int key) {
	switch (key) {
	case 'C':
	case 'c':
		if (cam.getMouseInputEnabled()) cam.disableMouseInput();
		else cam.enableMouseInput();
		break;

	case OF_KEY_TAB:
		ofToggleFullscreen();
		break;

	case 'R':
	case 'r':
		cam.reset();
		break;
	case OF_KEY_ALT:
		cam.enableMouseInput();
		break;
	case OF_KEY_CONTROL:
		ctrlKeyDown = true;
		break;
	case 'T':
	case 't':
		tkey = true;
		break;
	case 's':
	case 'S':
		skey = true;
		break;
	case OF_KEY_DEL :
		delkey = true;
		if (delkey == true) imgerase(selectedImage);
		break;
	case 'v':
	case 'V':
		savekey = true;
		break;
	case 'd':
	case 'D':
		dkey = true;
		break;
	case 'x':
	case 'X':
		line.clear();
		break;

	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	switch (key) {

	case OF_KEY_ALT:
		cam.disableMouseInput();
		break;
	case OF_KEY_CONTROL:
		ctrlKeyDown = false;
		break;
	case 't':
	case'T':
		tkey = false;
	case 's':
	case'S':
		skey = false;
	case OF_KEY_DEL:
		delkey = false;
	case 'v':
	case 'V':
		savekey = false;
	case'd':
	case 'D':
		dkey = false;
	
		
	

	}
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	if (button_rect.inside(x, y)) {
		SetCursor(::LoadCursor(NULL, IDC_HELP));
		
	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

	if (ctrlKeyDown == true) doMouseRotation(x, y);
	if (tkey == true) doMouseTranslate(x, y);
	if (skey == true) doMouseScale(x, y);
	if (savekey == true) imgsave();
	if (dkey == true) mdraw(x, y);

}
	



void ofApp::doMouseRotation(int x, int y) {

	SetCursor(::LoadCursor(NULL, IDC_CROSS));

	if (images.size() == 0) return;

	float rotation;
	ofVec2f mouse = ofVec2f(x, y);
	ofVec2f delta = mouse - lastMouse;
	float dist = delta.length();


	if (mouse.x < lastMouse.x)
		rotation = -dist;
	else
		rotation = dist;

	lastMouse = mouse;


	images[images.size() - 1]->rot += rotation;
}

//--------------------------------------------------------------

void ofApp::mdraw(int x, int y) {
		
		ofVec2f mouse = ofVec2f(x, y);
		ofSetColor(0, 255, 255);
		line.addVertex(mouse);
		line.begin();
		

}


void ofApp::doMouseTranslate(int x, int y) {

	SetCursor(::LoadCursor(NULL, IDC_HAND));

	if (images.size() == 0) return;
	

	ofVec2f mouse = ofVec2f(x, y);
	ofVec2f delta = mouse - lastMouse;
	images[images.size() - 1]->trans.x = images[images.size() - 1]->trans.x + delta.x ;
	images[images.size() - 1]->trans.y = images[images.size() - 1]->trans.y - delta.y;

	lastMouse = mouse;


}


//----------------------------------------------------------------

void ofApp::doMouseScale(int x, int y) {

	SetCursor(::LoadCursor(NULL, IDC_SIZENWSE));

	if (images.size() == 0) return;

	float scaling;
	ofVec2f mouse = ofVec2f(x, y);
	ofVec2f delta = mouse - lastMouse;
	float dist = delta.length();


	if (mouse.x < lastMouse.x)
		scaling = -dist;
	else
		scaling = dist;

	lastMouse = mouse;

	images[images.size() - 1]->scale += scaling * 0.01;

}



void ofApp::mousePressed(int x, int y, int button) {
	lastMouse = ofVec2f(x, y);
	renderSelection();
	processSelection(x, y);

	if (button_rect.inside(x, y)) menukey = 1;
	
	
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	if (button_rect.inside(x, y)) {
		hit = !hit;
		menukey = false;
	}

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------

void ofApp::dragEvent(ofDragInfo dragInfo) {

	Image *imageObj = new Image();
	imageObj->trans = cam.screenToWorld(dragInfo.position);
	if (imageObj->image.load(dragInfo.files[0]) == true)
		images.push_back(imageObj);
	else {
		cout << "Can't load image: " << dragInfo.files[0] << endl;
		delete imageObj;
	}
}

void ofApp::renderSelection() {
	cam.begin();
	ofBackground(0);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	for (int i = 0; i < images.size(); i++) {
		images[i]->draw(true, i);
	}

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	cam.end();
}

void ofApp::processSelection(int x, int y) {
	unsigned char res[4];
	GLint viewport[4];

	
	glGetIntegerv(GL_VIEWPORT, viewport);
	glReadPixels(x, viewport[3] - y, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, &res);

	if (selectedImage) {
		selectedImage->bSelected = false;
		selectedImage = NULL;
	}


	if (res[0] > 0 && res[0] <= images.size()) {
		Image *image = images[res[0] - 1];
		image->bSelected = true;
		selectedImage = image;

		images.erase(images.begin() + (res[0] - 1));
		images.push_back(image);
	}

}
void ofApp::imgerase(Image *slctimg) {

	if (selectedImage != nullptr) {
		for (int i = 0; i <= images.size(); i++) {

			if (images[i] == selectedImage) {
				images.erase(images.begin() + i);
				delete selectedImage;
				selectedImage = NULL;
			}
		}

	}
}

	


void ofApp::imgsave() {
	savedImage.grabScreen(0,0, ofGetWidth(), ofGetHeight());
	savedImage.save("snapshot.jpg");

}


Image::Image()
{
	trans.x = 0;
	trans.y = 0;
	scale.x = 1.0;
	scale.y = 1.0;
	rot = 0;
}


void Image::draw(bool bSelectMode, int index) {
	ofPushMatrix();
	ofTranslate(trans);
	ofScale(scale);
	ofRotate(rot);

	if (!bSelectMode) {

		
		if (bSelected) {
			ofNoFill();
			ofSetColor(0, 255, 255);
			ofSetLineWidth(2);
			ofDrawRectangle(-image.getWidth() / 2.0, -image.getHeight() / 2.0,
				image.getWidth(), image.getHeight());
		}
		ofSetColor(255, 255, 255, 255);
		image.draw(-image.getWidth() / 2.0, -image.getHeight() / 2.0);

	}
	
	else {
		ofFill();
		ofSetColor(index + 1, 0, 0);

		ofDrawRectangle(-image.getWidth() / 2.0, -image.getHeight() / 2.0,
		image.getWidth(), image.getHeight());
		
	}



	ofPopMatrix();
}



