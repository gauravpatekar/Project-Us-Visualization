#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    ofSetWindowShape(1024,768);
    leftMouseButtonPressed = false;
    minDistance = 10.0;
    
    //ofxgui code
    gui.setup();
    gui.add(intSlider.setup("int slider", 4, 1, 10));
    gui.add(colorSlider.setup("color slider", 200, 0, 255));
    
    //serial
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    int baud = 9600;
    serial.setup(2, baud); //open the first device
    
    //averaging values
    for(int i = 0; i<100; i++){
        cumulativeValue[i] = 0;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (leftMouseButtonPressed) {
            ofPoint mousePos(ofGetMouseX(), ofGetMouseY());
            if (lastPoint.distance(mousePos) >= minDistance) {
                // a.distance(b) calculates the Euclidean distance between point a and b.  It's
                // the straight line distance between the points.
                currentPolyline.curveTo(mousePos);
                lastPoint = mousePos;
            }
        }
        
        //jitteryness
        for (int i=0; i<polylines.size(); i++) {
            for (auto &vert : polylines[i].getVertices()){
                if(i == polylines.size() -1){
                    vert.x += ofRandom(-1,1);
                    vert.y += ofRandom(-1,1);
                }
            }
         }
    
    //serial
    if(serial.available()){
        serial.readBytes(receivedData, 3); // Getting the data from Arduino
        printf("receivedData is %d \n", receivedData);    // Printing in ASCII format
        ofSetColor(0, 255, 255);
        ofDrawCircle(300, 300, 10);
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    

    ofColor colorA(255, 0, 0);
    
    ofSetColor(colorSlider);
    ofSetLineWidth(intSlider);
    
    for (int i=0; i<polylines.size(); i++) {
        ofPolyline polyline = polylines[i];
        ofSetColor(tempColor[i]);
        ofSetLineWidth(lineWidth[i]);
        polyline.draw();
    }
    //ofSetColor(255,0,0);  // Orange color for active polyline
    currentPolyline.draw();
    
    gui.draw();
    
    //serial
    string msg;
    msg += receivedData;
    int value = atoi(msg.c_str());
    
    //value averaging
//    if(count < 1000 || count2 > 10){
        for(int i = 0; i<999; i++){
            cumulativeValue[i] = cumulativeValue[i+1];
        }
        count++;
        count2 = 0;
//    }
    cumulativeValue[999] = value;
    int sum = 0;
    for(int i = 0; i<1000; i++){
        sum = sum + cumulativeValue[i];
    }
    int baseline = sum/1000;
    
    
//    gsrColor.r = 120 - 10*(baseline-value);
//    gsrColor.g = 120 + 5*(baseline-value);
//    gsrColor.b = 0;
    
    gsrColor.r = ofMap(value, baseline-5, baseline+5, 0, 250);
    gsrColor.g = ofMap(value, baseline-5, baseline+5, 255, 0);
    gsrColor.b = ofMap(value, baseline-5, baseline+5, 255, 0);
    
    ofSetColor(gsrColor);
    ofDrawCircle(50, 200, 40);
    ofDrawCircle(50, 300, baseline-value);
    
    count2++;
    
    ofSetColor(255, 255, 255);
    ofDrawBitmapString(msg, 50, 200); // Write the data on the output window
    ofDrawBitmapString(baseline, 50, 300); // Write the data on the output window
    
    
    
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
    
    lineWidth[l] = intSlider;
    //tempColor[l] = colorSlider;
    tempColor[l] = gsrColor;
    l++;
    
    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = true;
        currentPolyline.curveTo(x, y);  // Remember that x and y are the location of the mouse
        currentPolyline.curveTo(x, y);  // Necessary duplicate for first control point
        lastPoint.set(x, y);  // Set the x and y of a ofVec2f in a single line
    }

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

    if (button == OF_MOUSE_BUTTON_LEFT) {
        leftMouseButtonPressed = false;
        currentPolyline.curveTo(x, y);   // Necessary duplicate for last control point
        polylines.push_back(currentPolyline);
        currentPolyline.clear();  // Erase the vertices, allows us to start a new brush stroke
    }
    
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
