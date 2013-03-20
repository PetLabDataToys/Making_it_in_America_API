#pragma once

#include "ofMain.h"
#include "ofxiPhone.h"
#include "ofxiPhoneExtras.h"

//  Thanks to Tom Carden, for ModestMaps code ( http://modestmaps.com/index.html )
//  https://github.com/RandomEtc/modestmaps-of
//
#include "Map.h"
#include "OpenStreetMapProvider.h"

//  Our happy dataBase
//
#include "MpiData.h"

#include "DragRect.h"

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
    
    Map         map;
    MpiData     dBase;
    
    vector <ofPoint> citiesPos;
    Location    myLoc;
    float       angle;
    float       apperture;
    float       distance;
    ofPolyline  areaZone;
    
    DragRect    graphView;
    
    int         TotalPop;
    
    int         TotalBlack;
    float       PctBlack;
    int         TotalAsian;
    float       PctAsian;
    int         TotalLatino;
    float       PctLatino;
    
    float       PctImm;
    
    int         TotalUnEmploy;
    float       PctUnEmploy;

};


