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
    
    ofPolyline currentPolyline;
    ofVec2f lastPoint;
    vector <ofPolyline> polylines;
    bool leftMouseButtonPressed;
    float minDistance;
    
    //ofxgui code
    ofxPanel gui;
    ofxIntSlider intSlider;
    ofxColorSlider colorSlider;
    
    int lineWidth[10000];
    int l = 0;
    ofColor tempColor[10000];
    ofColor gsrColor;
    
    
    //serial
    bool serialMessage;            // a flag for sending serial
    char receivedData[3];        // for storing incoming data
    char sendData = 1;    // for sending data
    ofSerial serial;
    int cumulativeValue[1000];
    
    int count = 0;
    int count2 = 0;
    
    //baseline
    int baselineCount = 0;
    int baselineSum = 0;
    int baseline = 0;
        
    
};
