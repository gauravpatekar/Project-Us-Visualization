#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    ofBackground(0, 0, 0);
    ofBackground(255, 255, 255);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.end();
    
//    ofSetColor(0, 0, 0);
//    ofDrawCircle(0, 0, 100);
    for(float i = 0; i< ofGetWidth(); i++){
        scr = 10 * ofNoise(toff - (1 - i/100));
        float y = 850 + 20 * scr;
        
        // color code arousal states
        if(scr >= 6){
            ofSetColor(250, 0, 0);
        }
        else if (scr <= 3){
            ofSetColor(0, 0, 250);
        }
        else {
            ofSetColor(200, 200, 200);
        }
        ofDrawCircle(i, y, 1);
        
        // store 3 recnt SCR values
        if(i == ofGetWidth()-1){
            scr1 = scr;
            ofDrawCircle(i, y, 5);
        }
        if(i == ofGetWidth()-100){
            scr2 = scr;
            ofDrawCircle(i, y, 5);
        }
        if(i == ofGetWidth()-200){
            scr3 = scr;
            ofDrawCircle(i, y, 5);
        }
                    
        
    }
    ofSetColor(0, 0, 0);
    ofDrawBitmapString("SCR: ", 20, ofGetHeight() - 20);
    ofDrawBitmapString((int)scr, 60, ofGetHeight() - 20);
    
    
    //Map SCR to the color saturation
    int saturation1 = ofMap(scr1, 1, 8, 0, 255);
    int saturation2 = ofMap(scr2, 1, 8, 0, 255);
    int saturation3 = ofMap(scr3, 1, 8, 0, 255);

    //Map SCR to the shapes
    smoothingValue1 = ofMap(scr1, 1, 8, 1000, 200);
    smoothingValue2 = ofMap(scr2, 1, 8, 1000, 200);
    smoothingValue3 = ofMap(scr3, 1, 8, 1000, 200);
    
    
    
    cam.begin();
    
    ofPushMatrix();
    ofScale(1.7);
    ofMesh mesh3;
    mesh3.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh3.addVertex(ofPoint(0, 0, -100) );
    for(int i = 0; i < 361; i++){
        int x = r * cos(i*2*PI/360);   //calculate x & y for every degree of rotation
        int y = r * sin(i*2*PI/360);
        int newX = x + noiseAmp * ofNoise(2 + x / smoothingValue3, 2 + y / smoothingValue3, toff);
        int newY = y + noiseAmp * ofNoise(12 + x / smoothingValue3, 12 + y / smoothingValue3, toff);
        mesh3.addVertex(ofPoint(newX, newY, -100) );
        mesh3.addColor(ofColor::fromHsb(i*255/360, saturation3, 255) );
    }
    mesh3.addVertex(ofPoint(0, 0, -100) );
    mesh3.addColor(ofColor::fromHsb(255, saturation3, 255) );
    mesh3.draw();
    ofPopMatrix();

    ofPushMatrix();
    ofScale(1.4);
    ofMesh mesh2;
    mesh2.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh2.addVertex(ofPoint(0, 0, -50) );
    for(int i = 0; i < 361; i++){
        int x = r * cos(i*2*PI/360);   //calculate x & y for every degree of rotation
        int y = r * sin(i*2*PI/360);
        int newX = x + noiseAmp * ofNoise(1 + x / smoothingValue2, 1 + y / smoothingValue2, toff);
        int newY = y + noiseAmp * ofNoise(11 + x / smoothingValue2, 11 + y / smoothingValue2, toff);
        mesh2.addVertex(ofPoint(newX, newY, -50) );
        mesh2.addColor(ofColor::fromHsb(i*255/360, saturation2, 255) );
    }
    mesh2.addVertex(ofPoint(0, 0, -50) );
    mesh2.addColor(ofColor::fromHsb(255, saturation2, 255) );
    mesh2.draw();
    ofPopMatrix();
    
    
    
    ofMesh mesh;
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
    mesh.addVertex(ofPoint(0, 0, 0) );
    for(int i = 0; i < 361; i++){
        int x = r * cos(i*2*PI/360);   //calculate x & y for every degree of rotation
        int y = r * sin(i*2*PI/360);
        int newX = x + noiseAmp * ofNoise(x / smoothingValue1, y / smoothingValue1, toff);
        int newY = y + noiseAmp * ofNoise(10 + x / smoothingValue1, 10 + y / smoothingValue1, toff);
        mesh.addVertex(ofPoint(newX, newY, 0) );
        mesh.addColor(ofColor::fromHsb(i*255/360, saturation1, 255) );
//        if(i <= 180){
//            hue = ofMap(i, 0, 180, (0 + (int)colorDelta) % 255, (50 + (int)colorDelta) % 255 );
//            mesh.addColor(ofColor::fromHsb(hue, 200, 255) );
//        }
//        else{
//            hue = ofMap(i, 180, 360, (50 + (int)colorDelta) % 255, (0 + (int)colorDelta) % 255);
//            mesh.addColor(ofColor::fromHsb(hue, 200, 255) );
//        }
    }
    mesh.addVertex(ofPoint(0, 0, 0) );
    mesh.addColor(ofColor::fromHsb(hue, saturation1, 255) );
    mesh.draw();
    
    
    toff += 0.002;
    colorDelta += 0.2;
//  if(colorDelta > 205) colorDelta = 0;
    

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
