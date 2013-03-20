#pragma once

#include "ofMain.h"

#include "ofxGui.h"
#include "MpiData.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void        generateCharts(bool &_bool);
    ofPolyline  makeChart( int _cityId, mpiNumValue _mpiValue, ofRectangle _rect, float _minVal,  float _maxVal );
    
    MpiData     dBase;
    
    ofEasyCam   cam;
    
    ofRectangle frame;
    
    ofxPanel    cities;
    vector<ofxToggle>   selectedCities;
    vector<mpiNumValue>    selectedValues;
    vector< vector<ofPolyline> > charts;
    
    int         min, max;
};
