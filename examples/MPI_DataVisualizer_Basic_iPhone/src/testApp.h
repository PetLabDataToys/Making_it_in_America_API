#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

#include "MpiData.h"

class testApp : public ofxiPhoneApp{
public:
    void setup();
    void update();
    void draw();
    void exit();
	
    void touchDown(ofTouchEventArgs & touch);
    void touchMoved(ofTouchEventArgs & touch);
    void touchUp(ofTouchEventArgs & touch);
    void touchDoubleTap(ofTouchEventArgs & touch);
    void touchCancelled(ofTouchEventArgs & touch);

    void lostFocus();
    void gotFocus();
    void gotMemoryWarning();
    void deviceOrientationChanged(int newOrientation);
    
    ofPolyline  makeChart( int _cityId, mpiNumValue _mpiValue, ofRectangle _rect, float _minVal,  float _maxVal );
    
    MpiData     dBase;
    
    ofEasyCam   cam;
    
    ofRectangle frame;
    
    string      city;
    ofPolyline  pop, popImm;
    int         minPop,maxPop;

};


