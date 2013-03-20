
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofSetDrawBitmapMode(OF_BITMAPMODE_SIMPLE );
    ofEnableSmoothing();
    
    dBase.loadCities("cities.csv");
    dBase.loadYear(2000, "2000.csv");
    dBase.loadYear(2005, "2005.csv");
    dBase.loadYear(2010, "2010.csv");
    
    frame.set(0,0,600,100);
    
    cities.setup("Cities");
    for(int i = 0; i < dBase.getTotalCities(); i++){
        ofxToggle newCityButton;
        newCityButton.setup( dBase.getCity(i), false );
        selectedCities.push_back(newCityButton);
    }
    
    for(int i = 0; i < dBase.getTotalCities(); i++){
        cities.add( &selectedCities[i] );
        selectedCities[i].addListener(this, &testApp::generateCharts);
    }
    cities.loadFromFile("settings.xml");
    
    bool b;
    generateCharts( b );
    
    cam.rotate(160, 1.0, 0, 0);
}

void testApp::generateCharts(bool &_bool){
    max = MAX(dBase.getMaxNumVal( MPI_NUM_POPULATION), dBase.getMaxNumVal( MPI_NUM_IMMIGRANTS ) );
    min = MIN(dBase.getMinNumVal( MPI_NUM_POPULATION), dBase.getMinNumVal( MPI_NUM_IMMIGRANTS ) );
    
    charts.clear();
    
    //  Population
    //
    vector<ofPolyline> mpiValCharts;
    for(int i = 0; i < selectedCities.size(); i++){
        bool selected = selectedCities[i];
        if ( selected == true ){
            
            ofPolyline chart = makeChart(i, MPI_NUM_POPULATION, frame, min, max);
            
            mpiValCharts.push_back(chart);
        }
    }
    charts.push_back(mpiValCharts);
    
    //  Population
    //
    mpiValCharts.clear();
    for(int i = 0; i < selectedCities.size(); i++){
        if ( selectedCities[i] == true ){
            
            ofPolyline chart = makeChart(i, MPI_NUM_IMMIGRANTS, frame, min, max);
            
            mpiValCharts.push_back(chart);
        }
    }
    charts.push_back(mpiValCharts);
    
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
    
    ofDrawBitmapString( ofToString(max), ofPoint(-100,0));
    ofDrawBitmapString( ofToString(min), ofPoint(-100,frame.height));
    
    ofPushMatrix();
    ofTranslate( 0 , frame.height );
    ofRotate(90, 0, 0, 1);
    ofDrawBitmapString( ofToString(dBase.getYear(0) ), ofPoint(0,0));
    ofDrawBitmapString( ofToString(dBase.getYear(1) ), ofPoint(0,-frame.width*0.5));
    ofDrawBitmapString( ofToString(dBase.getYear(2) ), ofPoint(0,-frame.width));
    ofPopMatrix();
    
    int margin = 20;
    
    for (int v = 0; v < charts.size(); v++){
        ofPushStyle();
        ofColor color = ofColor(255,0,0,100);
        color.setHue( (255/charts.size())*v );
        ofSetColor(color);
        ofFill();
        
        for (int c = 0; c < charts[v].size(); c++){
            
            ofPushMatrix();
            
            ofTranslate(0, 0, -margin*(charts[v].size()*0.5) );
            ofTranslate(0, 0, margin*c);
            
            ofBeginShape();
            for(int i = 0; i < charts[v][c].size(); i++){
                ofVertex( charts[v][c][i] );
            }
            
            ofEndShape();
            ofPopMatrix();
            
        }
        ofPopStyle();
    }
    ofPopMatrix();
    
    
    ofPushMatrix();
    ofTranslate(-frame.width*0.5,-frame.height*0.5);
    int counter = 0;
    for (int i = 0; i < selectedCities.size(); i++){
        bool selected = selectedCities[i];
        
        if ( selected ){
            ofPushMatrix();
            
            ofSetColor(255);
            ofTranslate(0, 0,-margin*(charts[0].size()*0.5) );
            ofTranslate(0,0, margin*counter);
            ofDrawBitmapString( dBase.getCity(i), ofPoint(frame.width,frame.height));
            counter++;
            
            ofPopMatrix();
        }
        
    }
    ofPopMatrix();
    
    cam.end();
    
    cities.draw();
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