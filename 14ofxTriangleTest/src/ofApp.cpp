#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(50, 50, 50);
    ofSetFrameRate(60);
    ofSetWindowShape(600, 500);
    
    buffer.allocate(640, 480, GL_RGBA);
    
    loadVertices();

}

//--------------------------------------------------------------
void ofApp::update(){

        fillBuffer();
        
        //Triangulate the points
        triangle.clear();
        triangle.triangulate(line.getVertices());
        
}

//--------------------------------------------------------------
void ofApp::draw(){
    drawSolidFillShape();
    drawBufferFillShape();
    drawInfo();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}


void ofApp::loadVertices(){
    //A rectangle with a chunk taken out, making a concave shape
    line.addVertex(ofPoint(0, 0));
    line.addVertex(ofPoint(200, 0));
    line.addVertex(ofPoint(200, 300));
    line.addVertex(ofPoint(0, 300));
    line.addVertex(ofPoint(0, 220));
    line.addVertex(ofPoint(75, 150));
    line.addVertex(ofPoint(0, 80));
}

void ofApp::fillBuffer(){
    buffer.begin();
    ofClear(0, 0, 0);
    
    //Draw anything you like inside the buffer
    ofSetHexColor(0xFF0000);
    ofFill();
    for (int i = 0; i < 480; i += 30){
        ofRect(0, ofGetFrameNum()%30+i, 640, 10);
    }
    buffer.end();
}

void ofApp::drawSolidFillShape(){
    ofPushMatrix();
    ofTranslate(70, 125);
    ofBeginShape();
    ofSetColor(255, 192, 64);
    auto vertices = line.getVertices();
    for(int i = 0; i < vertices.size(); i++){
        ofVertex(vertices[i]);
    }
    ofEndShape();
    ofPopMatrix();
}

void ofApp::drawBufferFillShape(){
    
    //Render the buffer inside the shape by drawing as individual triangles
    ofPushMatrix();
    ofTranslate(340, 125);
    buffer.getTextureReference().bind();
    glBegin(GL_TRIANGLES);
    for (int i = 0; i < triangle.nTriangles; i++){
        glTexCoord2f(triangle.triangles[i].a.x, triangle.triangles[i].a.y);
        glVertex2f(triangle.triangles[i].a.x, triangle.triangles[i].a.y);
        
        glTexCoord2f(triangle.triangles[i].b.x, triangle.triangles[i].b.y);
        glVertex2f(triangle.triangles[i].b.x, triangle.triangles[i].b.y);
        
        glTexCoord2f(triangle.triangles[i].c.x, triangle.triangles[i].c.y);
        glVertex2f(triangle.triangles[i].c.x, triangle.triangles[i].c.y);
    }
    glEnd();
    buffer.getTextureReference().unbind();
    ofPopMatrix();
}

void ofApp::drawInfo(){
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("FPS : " + ofToString(ofGetFrameRate()), 10, 20);
    ofDrawBitmapString("nb Triangles : " + ofToString(triangle.nTriangles), 10, 40);
    ofDrawBitmapString("Buffer filled shape:", 340, 109);
    ofDrawBitmapString("Solid filled shape:", 70, 109);
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
