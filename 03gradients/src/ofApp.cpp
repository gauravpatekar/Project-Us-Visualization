#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    last = ofGetElapsedTimeMillis();
//    col.setHsb(0,255,255);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofMesh temp;
    temp.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    temp.addVertex( ofPoint(100,100) );
    temp.addColor(ofColor::fromHsb(c, 255, 255) );
    temp.addVertex( ofPoint(100,300) );
    temp.addColor(ofColor::fromHsb(c+20, 255, 255) );
    temp.addVertex( ofPoint(300,100) );
    temp.addColor(ofColor::fromHsb(c+40, 255, 255) );
    temp.addVertex( ofPoint(300,300) );
    temp.addColor(ofColor::fromHsb(c+60, 255, 255) );
    temp.addVertex( ofPoint(500,100) );
    temp.addColor(ofColor::fromHsb(c+80, 255, 255) );
    temp.addVertex( ofPoint(500,300) );
    temp.addColor(ofColor::fromHsb(c+100, 255, 255) );
    temp.addVertex( ofPoint(700,100) );
    temp.addColor(ofColor::fromHsb(c+120, 255, 255) );
    temp.addVertex( ofPoint(700,300) );
    temp.addColor(ofColor::fromHsb(c+140, 255, 255) );
    temp.addVertex( ofPoint(900,100) );
    temp.addColor(ofColor::fromHsb(c+160, 255, 255) );
    temp.addVertex( ofPoint(900,300) );
    temp.addColor(ofColor::fromHsb(c+180, 255, 255) );
    temp.draw();
    

    
    
    
    c+=0.1;
    if (c > 255) c = 0;
    
    s+=0.5;
    if (s <= 255) s = 0;
    
    b = 255;
    
//    ofBackground(col);
//    if(ofGetElapsedTimeMillis() - last > 50)
//    {
//        col.setHue(counter % 256);
//        counter ++;
//        last = ofGetElapsedTimeMillis();
//    }
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofMesh temp2;
    //temp2.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    temp2.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    temp2.addVertex( ofPoint(0,0) );
    temp2.addColor(ofColor::fromHsb(c+180, 0, 255) );
    temp2.addVertex( ofPoint(-100,0) );
    temp2.addColor(ofColor::fromHsb(c, 255, 255) );
    temp2.addVertex( ofPoint(-70,70) );
    temp2.addColor(ofColor::fromHsb(c+20, 255, 255) );
    temp2.addVertex( ofPoint(0,100) );
    temp2.addColor(ofColor::fromHsb(c+40, 255, 255) );
    temp2.addVertex( ofPoint(70,70) );
    temp2.addColor(ofColor::fromHsb(c+60, 255, 255) );
    temp2.addVertex( ofPoint(100,00) );
    temp2.addColor(ofColor::fromHsb(c+80, 255, 255) );
    temp2.addVertex( ofPoint(70,-70) );
    temp2.addColor(ofColor::fromHsb(c+100, 255, 255) );
    temp2.addVertex( ofPoint(0,-100) );
    temp2.addColor(ofColor::fromHsb(c+120, 255, 255) );
    temp2.addVertex( ofPoint(-70,-70) );
    temp2.addColor(ofColor::fromHsb(c+140, 255, 255) );
    temp2.addVertex( ofPoint(-100,0) );
    temp2.addColor(ofColor::fromHsb(c+160, 255, 255) );

    temp2.draw();
    ofPopMatrix();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
