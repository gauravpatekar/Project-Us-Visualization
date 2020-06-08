#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    
//    //ofxgui code
//    gui.setup();
//    gui.add(intSlider.setup("int slider", 4, 1, 10));
//    gui.add(colorSlider.setup("color slider", 200, 0, 255));
    
    //serial
    serial.listDevices();
    vector <ofSerialDeviceInfo> deviceList = serial.getDeviceList();
    int baud = 9600;
    serial.setup(2, baud); //open the first device
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //serial
    if(serial.available()){
        serial.readBytes(receivedData, 3); // Getting the data from Arduino
        printf("receivedData is %d \n", ofToInt(receivedData));    // Printing in ASCII format
        ofSetColor(0, 255, 255);
        ofDrawCircle(300, 300, 10);
        
        // the log file will be created in the data directory
        ofLogToFile("myLogFile.txt", true);
        // now logs to the file
        ofLog(OF_LOG_NOTICE) << "a test";
        //ofLog(OF_LOG_NOTICE, "the number is " + ofToString(10));
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    

//    ofSetColor(colorSlider);
//    ofSetLineWidth(intSlider);
//    gui.draw();
    
    //serial
    string msg;
    msg += receivedData;
    int value = atoi(msg.c_str());
    
    //value averaging
    if(baselineCount < 1000){
        baselineSum += value;
        baselineCount++;
    }
    if(baselineCount >= 1000){
        baseline = baselineSum/1000;
    }
    oldOldDifferenceGsr = oldDifferenceGsr;
    oldDifferenceGsr = differenceGsr;
    differenceGsr = value - baseline;
    
    //peak identification
    if(differenceGsr > oldDifferenceGsr){            //detect a rise in value
        rise = true;
    }
    if(rise & (differenceGsr < oldDifferenceGsr)){   //detect a fall in value if rise is detected
        fall = true;
    }
    if(rise & fall){                                 //peak identified with a fall followed by a rise
        peak = true;
        peakTime = ofGetElapsedTimef();
        peakCount++;
        rise = false;
        fall = false;
        ofDrawCircle(50, 200, 40);
        //add peak to the file
        ofFile floats("peaks.txt", ofFile::Append);
        floats << ofToString(peakTime) << endl;
        // add peak to the vector array
        peaks.push_back(peakTime);
        peaksPerThirty = peaks.size();

    }

    //calculate peaks per 30 seconds
    if(peaks.size() != 0){
        if( peaks[0] < (ofGetElapsedTimef() -30) ){ //checks if the oldest item is older than 30 seconds
            peaks.erase( peaks.begin() );
        }
    }
    
    
    // CORNER INFORMATION
    ofDrawBitmapStringHighlight("incoming value: " + msg, 20, 50);
    //during caliberation
    if(baselineCount < 1000){
        ofDrawBitmapStringHighlight("baseline count: " + ofToString(baselineCount) + " / 1000", 20, 70);
    }
    //post caliberation
    if(baselineCount >= 1000){
        
        ofDrawBitmapStringHighlight("baseline: " + ofToString(baseline), 20, 70);
        ofDrawBitmapStringHighlight("difference: " + ofToString(differenceGsr), 20, 90);
        ofDrawBitmapStringHighlight("peak count: " + ofToString(peakCount), 20, 110);
        ofDrawBitmapStringHighlight("peaks every thirty seconds: " + ofToString(peaksPerThirty), 20, 130);
        if(peaksPerThirty < 3){
            ofDrawBitmapStringHighlight("arousal: LOW", 20, 150);
            ofSetColor(0, 250, 250);
            ofDrawCircle(50, 200, 25);
        }
        if(peaksPerThirty > 10){
            ofDrawBitmapStringHighlight("arousal: HIGH", 20, 150);
            ofSetColor(250, 250, 0);
            ofDrawCircle(50, 200, 25);
        }
        else{
            ofSetColor(150, 150, 150);
            ofDrawCircle(50, 200, 25);
        }
        
//        //circle indicator
//        if(differenceGsr > 0){    ofSetColor(250, 250, 0);   }
//        else{                     ofSetColor(0, 250, 250);   }
//        ofDrawCircle(50, 250, differenceGsr);
        
        //bargraph
        ofSetColor(10*differenceGsr, 150, 255 - 10*differenceGsr);
        ofDrawRectangle(50, 450, 50, -2 * differenceGsr);
        //reference line
        ofSetColor(200);
        ofDrawRectangle(25, 450, 100, 1);

    }
    
    ofDrawBitmapStringHighlight("time: " + ofToString(ofGetElapsedTimef()), 20, ofGetHeight() - 20);
    
    
    //DATA VISUALIZATION
//    ofDrawCircle(ofNoise(xoff), ofNoise(xoff + 20), 100);
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
