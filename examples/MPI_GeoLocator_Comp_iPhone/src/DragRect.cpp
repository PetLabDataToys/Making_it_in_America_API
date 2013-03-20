//
//  DragRect.cpp
//  MPI_GeoLocator_Basic
//
//  Created by Patricio Gonzalez Vivo on 2/25/13.
//
//

#include "DragRect.h"

DragRect::DragRect(){
    objName = "none";
    
    bEditMode = false;
    
    //  Eventos de Mouse
    //
    ofAddListener(ofEvents().mouseDragged, this, &DragRect::_mouseDragged);
    ofAddListener(ofEvents().mouseReleased, this, &DragRect::_mouseReleased);
    ofAddListener(ofEvents().draw, this, &DragRect::_draw);
}

void DragRect::init(int _x, int _y, int _width, int _height){
    
    if (_x == -1)
        _x = this->x;
    
    if (_y == -1)
        _y = this->y;
    
    if (_width == -1)
        _width = this->width;
    
    if (_height == -1)
        _height = this->height;
    
    //  Setea las propiedades del rectangulo que contiene Graffiti
    //
    ofRectangle::set(_x, _y, _width, _height);
    
}

void DragRect::_draw(ofEventArgs &e){
    //  Draggable area-boxes for Edit modes
    //
    if ( bEditMode ){
        ofPushStyle();
        ofPushMatrix();
        ofTranslate(x, y);
        
        //  Graffiti Area
        //
        ofNoFill();
        ofSetColor(100,200);
        ofRect(0,0,width,height);
        ofFill();
        ofSetColor(100,150);
        ofRect(-7,-7,14,14);
        ofRect(width-7,height-7,14,14);
        
        ofPopMatrix();
        ofPopStyle();
    }
}

//----------------------------------------------------------- Mouse
void DragRect::_mouseDragged(ofMouseEventArgs &e){
    ofPoint mouse = ofPoint(e.x,e.y);
    
    if (bEditMode){
        //  Drag coorners of graffitiArea
        //
        ofPoint A = ofPoint(x,y);
        
        ofPoint B = ofPoint(x+width,y+height);
        
        if ( A.distance(mouse) < 20 ){
            x += e.x - x;
            y += e.y - y;
            
            this->init(x,y, width, height);
        }
        
        if ( B.distance(mouse) < 20 ){
            width += e.x - x - width;
            height += e.y - y - height;
            
            this->init(x,y, width, height);
        }
    }
}

void DragRect::_mouseReleased(ofMouseEventArgs &e){
    if (bEditMode){
        init(x, y, width, height);
    }
}