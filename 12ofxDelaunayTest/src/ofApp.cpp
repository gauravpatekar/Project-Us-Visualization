#include "ofApp.h"

ofEasyCam camera;

//--------------------------------------------------------------
void ofApp::setup(){
    
    for (int i=0; i<300; i++)
    {
        float x = ofRandom(ofGetWidth());
        float y = ofRandom(ofGetHeight());
        ofPoint randomPoint(x, y);
        delaunay.addPoint(randomPoint);
        
    }
    delaunay.triangulate();
    
    //delaunay.triangleMesh.addColor(ofColor(100,200,0));
    float triCount = delaunay.triangleMesh.getNumIndices();
    for(int i = 0; i < triCount-2; i++){
        int m = ofMap(i, 0, triCount, 0, 255);
        
        delaunay.triangleMesh.setColorForIndices(i, i+2, ofColor(m, 255-m, 250-2*m));
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    camera.begin();
    ofTranslate(-ofGetWidth()/2, -ofGetHeight()/2, 0);//center mesh
    delaunay.triangleMesh.drawFaces();
    camera.end();

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
