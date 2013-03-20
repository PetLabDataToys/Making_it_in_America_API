/**
 *
 * OFDevCon Example Code Sprint
 * Quaternion Example for plotting latitude and longitude onto a sphere
 *
 * Created by James George on 2/23/2012
 */

#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofEnableAlphaBlending();
    ofNoFill();
	
    mesh.setMode(OF_PRIMITIVE_LINES);
    mesh.clear();
    
    loadSegments( rivers, "africa-riv.txt" );
    loadSegments( rivers, "asia-riv.txt" );
    loadSegments( rivers, "europe-riv.txt" );
    loadSegments( rivers, "namer-riv.txt" );
    loadSegments( rivers, "samer-riv.txt" );
    addToMesh(rivers, ofFloatColor(0.0,0.3,0.6));
    
    loadSegments( coast, "africa-cil.txt" );
    loadSegments( coast, "asia-cil.txt" );
    loadSegments( coast, "europe-cil.txt" );
    loadSegments( coast, "namer-cil.txt" );
    loadSegments( coast, "samer-cil.txt" );
    addToMesh( coast, ofFloatColor(1.0) );
    
    loadSegments(borders, "africa-bdy.txt");
    loadSegments(borders, "asia-bdy.txt");
    loadSegments(borders, "europe-bdy.txt");
    loadSegments(borders, "namer-bdy.txt");
    loadSegments(borders, "samer-bdy.txt");
    addToMesh( borders, ofFloatColor(0.7) );
    
    loadSegments( states, "namer-pby.txt" );
    addToMesh( states, ofFloatColor(0.7,0,0) );
    
    dBase.loadCities("cities.csv");
    dBase.loadYear(2000, "2000.csv");
    dBase.loadYear(2005, "2005.csv");
    dBase.loadYear(2010, "2010.csv");
    
    cam.rotate(180, 0, 1, 0);
    ofSetVerticalSync(true);
}

void testApp::loadSegments( vector< vector<GeoPoint> > &segments, string _file){
    
    ifstream fileIn;
	
    fileIn.open( ofToDataPath( _file ).c_str());
    if(fileIn.is_open()) {
        
        int lineCount = 0;
        
        vector<GeoPoint> newPoints;
        
        while(fileIn != NULL) {
            string temp;
            getline(fileIn, temp);
            
            // Skip empty lines.
            if(temp.length() != 0) {
                
                vector<string> values = ofSplitString(temp, " ");
                
                if ( values[0] == "segment"){
                    
                    if (lineCount != 0){
                        segments.push_back( newPoints );
                    }
                    
                    newPoints.clear();
                } else {
                    GeoPoint newPoint;
                    newPoint.latitude = ofToFloat( values[0] );
                    newPoint.longitude = ofToFloat( values[1] );
                    
                    newPoints.push_back(newPoint);
                }
                
                lineCount++;
            }
        }
    }

}

void testApp::addToMesh( vector< vector<GeoPoint> > & segments, ofFloatColor _color ){
    ofVec3f center = ofVec3f(0,0,-300);
    
    for(int i = 0; i < segments.size(); i++){
		
        ofVec3f lastPoint;
        
        for (int j = 0; j < segments[i].size(); j++){
            
            ofQuaternion latRot, longRot;
            latRot.makeRotate(segments[i][j].latitude, 1, 0, 0);
            longRot.makeRotate(segments[i][j].longitude, 0, 1, 0);
            
            ofVec3f worldPoint = latRot * longRot * center;
            
            if ( j > 0 ){
                mesh.addColor( _color );
                mesh.addVertex(lastPoint);
                mesh.addColor( _color );
                mesh.addVertex(worldPoint);
            }
            
            lastPoint = worldPoint;
        }
    }
}

//--------------------------------------------------------------
void testApp::update(){
	ofSetWindowTitle(ofToString(ofGetFrameRate()));
}

//--------------------------------------------------------------
void testApp::draw(){
	ofBackground(0);
	
    cam.begin();

    ofPushMatrix();
    ofRotateY(ofGetFrameNum()*0.01);
	ofSetColor(255, 20);
	ofSphere(0, 0, 0, 300);
	
    ofSetColor(255);
	mesh.draw();
    
    ofVec3f center = ofVec3f(0,0,300);
    for (int i = 0; i < dBase.getTotalCities(); i++){
        ofQuaternion latRot, longRot;
        latRot.makeRotate(dBase.getLatitud(i), 1, 0, 0);
        longRot.makeRotate(dBase.getLongitud(i), 0, 1, 0);
        ofVec3f worldPoint = latRot * longRot * -center;
        
        ofSetColor(200,0,10);
        ofSphere(worldPoint, 1);
    }
    
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