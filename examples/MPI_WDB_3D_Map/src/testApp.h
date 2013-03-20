#pragma once

#include "ofMain.h"

//  Our happy dataBase
//
#include "MpiData.h"

/*
/   World DataBank, ASCII text version
/   http://www.evl.uic.edu/pape/data/WDB/
/   Dave Pape, dave.pape@acm.org
/
/
/   These files are a plain text version of the CIA World DataBank II.
/   They are derived from the highly compressed binary version of the
/   files created by Brian Reid and formerly available from
/   spectrum.xerox.com.
/
/   The format of the files is very simple-minded.  Each "segment" begins
/   with a line of text similar to the following:
/
/   segment 1  rank 1  points 991
/
/   The segment number is just an ID for the segment.  The rank is some sort
/   of ranking of the size or significance of the segment, with 1 being
/   the highest rank, 2 the next, and so on; map-drawing software typically
/   uses this number to control the amount of detail in a map.  The last
/   number is the number of points forming the segment.  The points themselves
/   are then listed on the following lines, one per line.  The values for a
/   point are its latitude and longitude, expressed as a floating point number
/   of degrees; positive latitude is north of the equator, positive longitude
/   is east of the prime meridian.  Note that using floating point degrees
/   rather than the original integer degrees and arc minutes means that some
/   slight loss of accuracy has been incurred for the sake of convenience.
/
/   The files are split up by continent and by the type of data they contain.
/   The files' contents are:
/
/       africa-bdy	Africa, national boundaries
/       africa-cil	Africa, coastlines, islands, and lakes
/       africa-riv	Africa, rivers
/       asia-bdy	Asia, national boundaries
/       asia-cil	Asia, coastlines, islands, and lakes
/       asia-riv	Asia, rivers
/       europe-bdy	Europe, national boundaries
/       europe-cil	Europe, coastlines, islands, and lakes
/       europe-riv	Europe, rivers
/       namer-bdy	North America, national boundaries
/       namer-cil	North America, coastlines, islands, and lakes
/       namer-pby	North America, US state & Canadian province boundaries
/       namer-riv	North America, rivers
/       samer-bdy	South America, national boundaries
/       samer-cil	South America, coastlines, islands, and lakes
/       samer-riv	South America, rivers
/
/   Note that the political boundaries are those of the time that the DataBank
/   was originally created, sometime in the 1980s.  Also, whoever created the
/   DataBank considered North America to consist solely of the US and Canada.
*/

typedef struct {
	float latitude;
	float longitude;
} GeoPoint;

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
    
    void loadSegments( vector< vector<GeoPoint> > &segments, string _file);
    void addToMesh( vector< vector<GeoPoint> > &segments , ofFloatColor _color );
    
    vector< vector<GeoPoint> > coast;
    vector< vector<GeoPoint> > rivers;
    vector< vector<GeoPoint> > borders;
    vector< vector<GeoPoint> > states;
    
    ofMesh  mesh;
    
    MpiData     dBase;
    
    ofEasyCam   cam;
};
