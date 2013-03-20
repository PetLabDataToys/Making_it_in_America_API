#include "testApp.h"
#include "OpenStreetMapProvider.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableAlphaBlending();
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetFullscreen(true);
    
    dBase.loadCities("cities.csv");
    dBase.loadYear(2000, "2000.csv");
    dBase.loadYear(2005, "2005.csv");
    dBase.loadYear(2010, "2010.csv");
    
    map.setup(new OpenStreetMapProvider(), (double)ofGetWidth(), (double)ofGetHeight());
    map.setCenter(Location(40.257,-98.7689));
	map.setZoom(5);
    
    //  Loads cities positions
    //
    for (int i = 0; i < dBase.getTotalCities(); i++){
        citiesPos.push_back( map.getLocation( dBase.getLatitud(i), dBase.getLongitud(i) ) );
    }
}

//--------------------------------------------------------------
void testApp::update(){
	map.update();
    
    for (int i = 0; i < citiesPos.size(); i++){
        citiesPos[i] = map.getLocation( dBase.getLatitud(i), dBase.getLongitud(i) );
    }
}

//--------------------------------------------------------------
void testApp::draw(){    
    map.draw();
    
    ofPushStyle();
    
    for (int i = 0; i < citiesPos.size(); i++){
        
        ofNoFill();
        ofSetColor(150,0,0,200);
        ofCircle(citiesPos[i], map.getZoom() * 2);
        ofSetColor(200,0,0,200);
        ofCircle(citiesPos[i], map.getZoom());
        
        ofFill();
        ofSetColor(255,0,0,200);
        ofCircle(citiesPos[i], 2);
        
        ofSetColor(50,200);
        ofDrawBitmapString(dBase.getCity(i), citiesPos[i] + ofPoint(map.getZoom() * 2 + 5, map.getZoom() * 2));
        
    }
    
    ofSetColor(0);
    ofDrawBitmapString("Zoom width +/-", 25,25);
    
    ofPopStyle();
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	map.keyPressed(key);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
	map.keyReleased(key);
	
	if (key == 'f' || key == 'F') {
		ofToggleFullscreen();
	}
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	// TODO: check if we're over the map
	map.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	map.mousePressed(x,y,button);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	map.mouseReleased(x,y,button);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	// TODO: map.setSize(w,h)?
	map.width = w;
	map.height = h;
}

