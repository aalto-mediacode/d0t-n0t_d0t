#include "Particle.hpp"

//--------------------------------------------------------------
void Particle::setup(ofVec2f origin){

    location = origin;
    maxSpeed=5;
    velocity.set(ofRandom(-maxSpeed,maxSpeed),ofRandom(-maxSpeed,maxSpeed));
    radius = 15;
    myText = "d0t_";
    
}

//--------------------------------------------------------------
void Particle::update(){

    
    location+=velocity;
    //check x or y window boundaries, invert x or y velocity if hit
    if(location.x<0 || location.x>ofGetWidth()){
      
        velocity.x*=-1;
        radius= 0;
       
        ofSetColor(255,0,0,180);
        myText = "_n0t";
       
    }
    
    if(location.y<0 || location.y>ofGetHeight()){
       
        velocity.y*=-1;
        radius= 0;
        
        ofSetColor(255,0,0,180);
       myText = "_n0t";
        
    
        
    }
    
    
  counter +=0.05;
}

//--------------------------------------------------------------
void Particle::draw(){

    
    ofSetColor(204,204,255,70);
    ofDrawCircle(location,radius);
    //inside circle
    ofSetColor(204,204,255,250);
   ofDrawCircle(location,ofMap(sin(counter),-1,1,radius*0.18,radius*0.48));
    
    ofSetColor(0,0,255,180);
    ofDrawBitmapString(myText,location);
    
}
