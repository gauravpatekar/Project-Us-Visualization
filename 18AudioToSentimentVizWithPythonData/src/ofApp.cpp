#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //font1.load("MajorMonoDisplay-Regular.ttf", 20);
    
    // Load a CSV File.
    if(csv.load("file.csv")) {
        //csv.trim(); // Trim leading/trailing whitespace from non-quoted fields.
        
        // Like with C++ vectors, the index operator is a quick way to grab row
        // & col data, however this will cause a crash if the row or col doesn't
        // exist, ie. the file didn't load.
        ofLog() << "Print out a specific CSV value";
        ofLog() << csv[0][1];
        // also you can write...
        ofLog() << csv[0].at(1);
        // or you can get the row itself...
        ofxCsvRow row = csv[0];
        ofLog() << row.getString(1);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    csv.load("file.csv");
    ofLog() << "Print out a specific CSV value";
    ofLog() << csv[0][1];


}

//--------------------------------------------------------------
void ofApp::draw(){

    
    ofSetColor(255, 255, 255);
    
        for(float i = 0; i< ofGetWidth(); i++){
            scr = 10 * ofNoise(toff - (1 - i/100));
            float y = 850 + 20 * scr;
            
            if(i == ofGetWidth()-1){
                scr1 = scr;
                ofDrawCircle(i, y, 5);
            }
        }
    
        //Map SCR to the color saturation
        int saturation1 = ofMap(scr1, 1, 8, 0, 255);
        
        //Map SCR to the color hue
        int hue1 = ofMap(scr, 0, 7, 200, 0);

        //Map SCR to the shapes
        smoothingValue1 = ofMap(scr1, 1, 8, 1000, 200);

        cam.begin();
        

        
        // BLOB 1
        ofMesh mesh;
        mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN);
        mesh.addVertex(ofPoint(0, 0, 0) );
        for(int i = 0; i < 361; i++){
            int x = r * cos(i*2*PI/360);   //calculate x & y for every degree of rotation
            int y = r * sin(i*2*PI/360);
            int newX = x + noiseAmp * ofNoise(x / smoothingValue1, y / smoothingValue1, toff);
            int newY = y + noiseAmp * ofNoise(10 + x / smoothingValue1, 10 + y / smoothingValue1, toff);
            newX = newX * scale;
            newY = newY * scale;
            mesh.addVertex(ofPoint(newX, newY, 0) );
            //mesh.addColor(ofColor::fromHsb(i*255/360, saturation1, 255) );
            if(i <= 180){
                hue = ofMap(i, 0, 180, hue1, 50 + hue1 );
                mesh.addColor(ofColor::fromHsb(hue, saturation1, 255) );
            }
            else{
                hue = ofMap(i, 180, 360, 50 + hue1, hue1);
                mesh.addColor(ofColor::fromHsb(hue, saturation1, 255) );
            }
        }
        mesh.addVertex(ofPoint(0, 0, 0) );
        mesh.addColor(ofColor::fromHsb(hue, saturation1, 255) );
        mesh.draw();
        
        
        toff += 0.002;
        colorDelta += 0.2;
    
    cam.end();
    
    //text
    float temp = 0.345;
    //font1.drawString("TESTING", ofGetWidth()/2, ofGetHeight()/2);
    //font1.drawString(to_string(temp), ofGetWidth()/2, ofGetHeight()/2);
    
    
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
