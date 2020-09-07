#pragma once

#include "ofMain.h"
#include "ofxTriangleMesh.h"

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
    
    float theta = 0; //angle of rotation
    float r = 250; //radius
    float noiseAmp = 100; //amplitude of noise
    float smoothingValue = 500;
    float smoothingValue1, smoothingValue2, smoothingValue3;
    float toff = 0;
    float colorDelta = 0;
    float hue;
    
    float scr;
    float scr1, scr2, scr3;
    
    ofEasyCam cam;
    
    //ofPolyline line;
};
