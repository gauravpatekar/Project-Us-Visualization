#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    cam.setDistance(100);
    
    gui.setup();
    gui.add(uiAmount.set("amount", 0, 0, 6));
    
    for(int x = 0; x < size; x++){
        for(int y = 0; y < size; y++){
            mesh.addVertex(ofPoint(x - size / 2, y - size / 2));
        }
    }
    
    for(int x = 0; x < size - 1; x++){
        for(int y = 0; y < size - 1; y++){
            mesh.addIndex(x + y * size);
        }
    }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

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
