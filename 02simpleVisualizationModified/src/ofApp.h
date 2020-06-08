#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
//    //ofxgui code
//    ofxPanel gui;
//    ofxIntSlider intSlider;
//    ofxColorSlider colorSlider;
    
    ofColor tempColor[10000];
    ofColor gsrColor;
    
    
    //serial
    bool serialMessage;            // a flag for sending serial
    char receivedData[3];        // for storing incoming data
    char sendData = 1;    // for sending data
    ofSerial serial;
    
    //baseline
    int baselineCount = 0;
    int baselineSum = 0;
    int baseline = 0;
        
    int differenceGsr = 0;
    int oldDifferenceGsr = 0;
    int oldOldDifferenceGsr = 0;
    
    bool rise;
    bool fall;
    bool peak;
    int peakCount = 0;
    int peakTime = 0;
    int peaksPerThirty = 0;
    
    vector<int> peaks;
    
};

