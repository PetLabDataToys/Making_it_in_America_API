#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	
	// initialize the accelerometer
	ofxAccelerometer.setup();
	
	//If you want a landscape oreintation 
	//iPhoneSetOrientation(OFXIPHONE_ORIENTATION_LANDSCAPE_RIGHT);
	
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetDrawBitmapMode(OF_BITMAPMODE_SIMPLE );
    ofEnableSmoothing();
    ofToggleFullscreen();
    
    cam.rotate(180, 1.0, 0, 0);
    
    //  SETUP of the DABA BASE
    //  --------------------------------------
    //
    dBase.loadCities( "cities.csv");
    dBase.loadYear(2000, "2000.csv");
    dBase.loadYear(2010, "2010.csv");
    dBase.loadYear(2005, "2005.csv");
    
    //  EXAMPLES
    //  --------------------------------------
    //
    
    //  Asking for the first and last registered years on the data base
    //
    cout << "The first year is: " << dBase.getFirstYear() << endl;
    cout << "The last year is: " << dBase.getLastYear() << endl;
    
    //  Asking for the total population of Boston
    //
    cout << "The population of Boston on 2010 was " << dBase.getNumVal(MPI_NUM_POPULATION, dBase.getCityId("Boston"), dBase.getYearId(2010)) << endl;
    
    
    //  Convertions
    //
    cout << "The percentage of the creative class in Miami is %" << dBase.getPctVal(MPI_PCT_CREATIVE_CLASS, dBase.getCityId("Miami") ) << endl;
    cout << "Witch means the total of " << dBase.getNumVal(MPI_PCT_CREATIVE_CLASS, dBase.getCityId("Miami") ) << " individuals" << endl;
    
    //  Geting a list of cities
    //
    vector<mpiCity> activeCities;
    activeCities = dBase.getCitiesBy(MPI_CITY_ACTIVE_RECRUITING);
    cout << "The cities that actively recruit more are: ";
    for (int i = 0; i < activeCities.size(); i++) {
        cout << activeCities[i].name << ", ";
    }
    cout << endl;
    
    //  Searching for the maximum value
    //
    cout << "The city with highiest number of immigrants is " << dBase.getCity( dBase.getCityIdMaxVal(MPI_NUM_IMMIGRANTS ) ) << endl;
    cout << "The city with highiest unemployment percent is " << dBase.getCity( dBase.getCityIdMaxVal(MPI_PCT_UNEMPLOYMENT) ) << endl;
    
    //  Get index
    //
    cout << "Los Angeles well-being index is " << dBase.getWellBeing( dBase.getCityId("Los Angeles")) << endl;
    cout << "Detroit best-performance index is " << dBase.getBestPerforming( dBase.getCityId("Detroit") ) << endl;
    
    //  GRAPHICS: MAKING A BASIC CHART
    //  --------------------------------------
    //
    
    //  Chart position
    //
    frame.set(0,0,600,100);
    city = "Detroit";
    
    //  Asking for the max values of population and number of immigrants in a particular city
    //
    maxPop = MAX(dBase.getMaxNumVal( MPI_NUM_POPULATION, dBase.getCityId(city)), dBase.getMaxNumVal( MPI_NUM_IMMIGRANTS, dBase.getCityId(city) ) );
    
    //  Asking for the min values of population and number of immigrants in all cities
    //
    minPop = MIN(dBase.getMinNumVal( MPI_NUM_POPULATION ), dBase.getMinNumVal( MPI_NUM_IMMIGRANTS ) );
    
    //  Making a chard with the population of a city during this 10 years
    //
    pop = makeChart( dBase.getCityId(city) , MPI_NUM_POPULATION , frame, minPop, maxPop );
    popImm = makeChart( dBase.getCityId(city) , MPI_NUM_IMMIGRANTS , frame, minPop, maxPop );
}

//--------------------------------------------------------------
ofPolyline  testApp::makeChart( int _cityId, mpiNumValue _mpiValue, ofRectangle _rect, float _minVal,  float _maxVal ){
    ofPolyline line;
    
    line.addVertex( ofPoint(_rect.x, _rect.y+_rect.height) );
    
    //  Construct the mesh
    //
    for (int i = 0; i < dBase.getTotalYears(); i++) {
        int val = dBase.getNumVal(_mpiValue, _cityId, i);
        
        ofPoint vertex;
        vertex.x = ofMap( dBase.getYear(i) , dBase.getFirstYear(), dBase.getLastYear() , _rect.x, _rect.width, true);
        vertex.y = ofMap(val, _minVal, _maxVal, _rect.y+_rect.height, _rect.y);
        
        line.curveTo( vertex );
        line.addVertex( vertex );
    }
    
    line.addVertex( ofPoint(_rect.x+_rect.width,_rect.y+_rect.height) );
    
    return line;
}

//--------------------------------------------------------------
void testApp::update(){
	
    
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackgroundGradient(ofColor::gray, ofColor::black);
    
    cam.begin();
    ofPushMatrix();
    ofTranslate(-frame.width*0.5,-frame.height*0.5);
    
    //  Draw Frame
    //
    ofNoFill();
    ofSetColor(255);
    ofLine( ofPoint(0,0), ofPoint(0,frame.height));
    ofLine( ofPoint(0,frame.height), ofPoint(frame.width,frame.height));
    ofDrawBitmapString( city + " Population and Immigran Population",ofPoint(frame.width*0.5-200,-10) );
    
    ofDrawBitmapString( ofToString(maxPop), ofPoint(-100,0));
    ofDrawBitmapString( ofToString(minPop), ofPoint(-100,frame.height));
    
    ofPushMatrix();
    ofTranslate( 0 , frame.height );
    ofRotate(90, 0, 0, 1);
    ofDrawBitmapString( ofToString(dBase.getYear(0) ), ofPoint(0,0));
    ofDrawBitmapString( ofToString(dBase.getYear(1) ), ofPoint(0,-frame.width*0.5));
    ofDrawBitmapString( ofToString(dBase.getYear(2) ), ofPoint(0,-frame.width));
    ofPopMatrix();
    
    // Draw population
    //
    ofFill();
    ofSetColor(255,0,0,100);
    ofBeginShape();
    for(int i = 0; i < pop.size(); i++){
        ofVertex(pop[i]);
    }
    ofEndShape();
    
    //  Draw population of immigration
    //
    ofTranslate(0, 0, 1);
    ofSetColor(0,0,255,100);
    ofBeginShape();
    for(int i = 0; i < popImm.size(); i++){
        ofVertex(popImm[i]);
    }
    ofEndShape();
    
    ofPopMatrix();
    cam.end();
}

//--------------------------------------------------------------
void testApp::exit(){

}

//--------------------------------------------------------------
void testApp::touchDown(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void testApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void testApp::lostFocus(){

}

//--------------------------------------------------------------
void testApp::gotFocus(){

}

//--------------------------------------------------------------
void testApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void testApp::deviceOrientationChanged(int newOrientation){

}

