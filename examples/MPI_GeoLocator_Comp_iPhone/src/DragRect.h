//
//  DragRect.h
//  MPI_GeoLocator_Basic
//
//  Created by Patricio Gonzalez Vivo on 2/25/13.
//
//

#ifndef __MPI_GeoLocator_Basic__DragRect__
#define __MPI_GeoLocator_Basic__DragRect__

#include "ofMain.h"

class DragRect : public ofRectangle {
public:
    
    DragRect();
    
    void    init(int _x = -1, int _y = -1, int _width = -1, int _height = -1);
    
    void    update();
    void    draw();
    
    bool    bEditMode;
    
protected:
    void    _mouseDragged(ofMouseEventArgs &e);
    void    _mouseReleased(ofMouseEventArgs &e);
    void    _draw(ofEventArgs &e);
    
    string  objName;

};

#endif /* defined(__MPI_GeoLocator_Basic__DragRect__) */
