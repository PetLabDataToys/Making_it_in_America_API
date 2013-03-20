
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
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
    
    //  Get the maximum value of ALL THE CITIES (-1) but in a SPECIFIC YEAR (dBase.getYearId( INT ) )
    cout << "The maximum unemployment was " << dBase.getMaxNumVal( MPI_PCT_UNEMPLOYMENT, -1, dBase.getYearId(2005) ) << endl;
    
    //  Get the Growth Immigran/native population of Chicago between 2000 and 2005
    cout << "The Growth Immigrant population of Chicago between 2000-2005 " << dBase.getGrowthImmPop(dBase.getCityId("Chicago"), dBase.getYearId(2000), dBase.getYearId(2005)) << endl;
    cout << "The Growth Native population of Chicago between 2000-2005 " << dBase.getGrowthNatPop(dBase.getCityId("Chicago"), dBase.getYearId(2000), dBase.getYearId(2005)) << endl;
    
    //  Get Unemploy among loweducated immigrant and native on New York (2010)
    cout << "The unemploy on low education of immigrants on New York " << dBase.getPctVal(MPI_PCT_UNEMPLOY_IMMIGRANTS_NO_DEGREE, dBase.getCityId("New York")) << endl;
    cout << "The unemploy on low education of native on New York " << dBase.getPctVal(MPI_PCT_UNEMPLOY_NATIVE_NO_DEGREE, dBase.getCityId("New York")) << endl;
    
    
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
void testApp::keyPressed(int key){
	if (key == 'f'){
        ofToggleFullscreen();
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
	
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
	
}