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
    myLoc = Location(40.257,-98.7689);
    map.setCenter(myLoc);
	map.setZoom(5);
    
    //  Loads cities positions
    //
    for (int i = 0; i < dBase.getTotalCities(); i++){
        citiesPos.push_back( map.getLocation( dBase.getLatitud(i), dBase.getLongitud(i) ) );
    }
    
    angle = 0;
    distance = 0;
    apperture = 30;
    
    ofPoint point = map.locationPoint(myLoc);
    areaZone.clear();
    areaZone.addVertex(point);
    areaZone.arc(point, distance, distance, angle-apperture*0.5, angle+apperture*0.5, true,60);
    areaZone.addVertex(point);
    
    graphView.init(25,25,160,300);
    graphView.bEditMode = true;
}

//--------------------------------------------------------------
void testApp::update(){
	map.update();
    
    int tmpPop = 0;
    int tmpBlack = 0;
    int tmpAsian = 0;
    int tmpLatino = 0;
    
    int tmpUnEmp = 0.0f;
    
    for (int i = 0; i < citiesPos.size(); i++){
        citiesPos[i] = map.getLocation( dBase.getLatitud(i), dBase.getLongitud(i) );
        
        if (areaZone.inside( citiesPos[i] )){
            
            tmpPop += dBase.getNumVal(MPI_NUM_POPULATION, i);
            
            tmpBlack += dBase.getNumVal(MPI_PCT_ETHNIC_BLACK, i);
            tmpAsian += dBase.getNumVal(MPI_PCT_ETHNIC_ASIAN, i);
            tmpLatino += dBase.getNumVal(MPI_PCT_ETHNIC_LATINO, i);

            tmpUnEmp += dBase.getNumVal(MPI_PCT_UNEMPLOYMENT, i);
            
        }
    }
    
    TotalPop = ofLerp(TotalPop, tmpPop, 0.1);
    
    TotalBlack  = ofLerp(TotalBlack, tmpBlack, 0.1);
    PctBlack    = (float)TotalBlack/(float)TotalPop;
    TotalAsian  = ofLerp(TotalAsian, tmpAsian, 0.1);
    PctAsian    = (float)TotalAsian/(float)TotalPop;
    TotalLatino = ofLerp(TotalLatino, tmpLatino, 0.1);
    PctLatino   = (float)TotalLatino/(float)TotalPop;
    
    PctImm      = (float)(TotalBlack+TotalAsian+TotalLatino)/(float)TotalPop;
    TotalUnEmploy = ofLerp(TotalUnEmploy, tmpUnEmp, 0.1);
    PctUnEmploy = (float)TotalUnEmploy/(float)TotalPop;
}

//--------------------------------------------------------------
void testApp::draw(){    
    map.draw();
    
    ofPushStyle();

    ofSetColor(0,200,0);
    ofCircle( map.locationPoint(myLoc), map.getZoom() );
    
    ofSetColor(0,200,0,100);
    ofBeginShape();
    for(int i = 0; i < areaZone.size(); i++){
        ofVertex(areaZone[i]);
    }
    ofEndShape();
    
    for (int i = 0; i < citiesPos.size(); i++){
        
        if (areaZone.inside( citiesPos[i] )){
            ofSetColor(0,50,0,200);
            ofDrawBitmapString(dBase.getCity(i), citiesPos[i] + ofPoint(10,5));

            ofFill();
        } else {
            ofNoFill();
        }
        
        ofSetColor(150,0,0,200);
        ofCircle(citiesPos[i], map.getZoom() * 2);
        ofSetColor(200,0,0,200);
        ofCircle(citiesPos[i], map.getZoom());
        
        ofFill();
        ofSetColor(255,0,0,200);
        ofCircle(citiesPos[i], 2);
        
    }
    
    ofSetColor(0,180);
    ofFill();
    ofRect(graphView);
    
    ofPushMatrix();
    float pct = 0.7;
    ofRectangle white = graphView;
    white.width = graphView.width*pct;
    white.height = graphView.height * (1.0-PctImm);
    ofSetColor(255,50);
    ofRect(white);
    
    ofRectangle black = graphView;
    black.width = graphView.width*pct;
    black.y = white.y + white.height;
    black.height = graphView.height * PctBlack;
    ofSetColor(0,200,0,200);
    ofRect(black);
    ofSetColor(255);
    ofDrawBitmapString(ofToString( (int)(PctBlack*100) )+ "% african a.", black.x+5, black.y+15);
    
    ofRectangle latin = graphView;
    latin.width = graphView.width*pct;
    latin.y = black.y + black.height;
    latin.height = graphView.height * PctLatino;
    ofSetColor(0,150,0,200);
    ofRect(latin);
    ofSetColor(255);
    ofDrawBitmapString(ofToString( (int)(PctLatino*100) )+ "% latin", latin.x+5, latin.y+15);
    
    ofRectangle asian = graphView;
    asian.width = graphView.width*pct;
    asian.y = latin.y + latin.height;
    asian.height = graphView.height * PctAsian;
    ofSetColor(0,100,0,200);
    ofRect(asian);
    ofSetColor(255);
    ofDrawBitmapString(ofToString( (int)(PctAsian*100) )+ "% asian", asian.x+5, asian.y+15);

    ofRectangle unEmp = graphView;
    unEmp.width = graphView.width*(1.0-pct);
    unEmp.x += graphView.width*pct;
    unEmp.height = graphView.height * PctUnEmploy;
    ofSetColor(255,50);
    ofRect(unEmp);
    
    ofRectangle emp = graphView;
    emp.width = graphView.width*(1.0-pct);
    emp.x += graphView.width*pct;
    emp.y = unEmp.y + unEmp.height;
    emp.height = graphView.height * (1.0-PctUnEmploy);
    ofSetColor(0,50,0,200);
    ofRect(emp);
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString( (int)(PctUnEmploy*100)) + "%", unEmp.x+5, unEmp.y+15 );
    ofDrawBitmapString("unEmp", unEmp.x+5, unEmp.y+30);
    
    ofPopMatrix();
    
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
	// TODO: change mouse cursor if over map?
//    Location loc = map.pointLocation(ofPoint(x,y));
//    cout << "Lat: "<< loc.lat << " , Lon: " << loc.lon << endl;
//    
//    cout << map.getZoom() << endl;
    
    ofPoint mouse = ofPoint(x,y);
    ofPoint point = map.locationPoint(myLoc);
    ofPoint diff = mouse - point;
    
    distance = diff.length();
    angle = ofRadToDeg(atan2(diff.y,diff.x));
    
    areaZone.clear();
    areaZone.addVertex(point);
    areaZone.arc(point, distance, distance, angle-apperture*0.5, angle+apperture*0.5, true,60);
    areaZone.addVertex(point);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	// TODO: check if we're over the map
    ofPoint mouse = ofPoint(x,y);
    
    if ( graphView.inside(mouse)){
        
    } else if (ofGetKeyPressed()){
        map.mouseDragged(x,y,button);
    }
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    ofPoint mouse = ofPoint(x,y);
    
    if ( graphView.inside(mouse)){
        
    } else if (ofGetKeyPressed()){
        map.mousePressed(x,y,button);
    } else {
        myLoc = map.pointLocation(mouse);
    }
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    ofPoint mouse = ofPoint(x,y);
    
    if ( graphView.inside(mouse)){
        
    } else if (ofGetKeyPressed()){
        map.mouseReleased(x,y,button);
    }
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	// TODO: map.setSize(w,h)?
	map.width = w;
	map.height = h;
}

