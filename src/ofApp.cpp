// Code based on an example **"Bouncing Particles"**//

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(100);
    ofEnableSmoothing();
    CGDisplayHideCursor(0);
  
}

//--------------------------------------------------------------
void ofApp::update(){
    mouse.set(mouseX,mouseY);
    for(int i=0; i<myParticle.size();i++){
        myParticle[i].update();
        collisionDetection(i);
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofColor colorOne(255,255,255,255);
    ofColor colorTwo (200,210,255,255);
    ofBackgroundGradient(colorOne,colorTwo,OF_GRADIENT_CIRCULAR);
    
  for(int i=0;i<myParticle.size();i++){
      ofSetColor(204,204,255,ofRandom(200,255));
      
    ofSetLineWidth(ofRandom(0.2,3));
     
  if(i>0)ofDrawLine(myParticle[i].location,myParticle[i-1].location);
      
      
                
       
      myParticle[i].draw();
    
}
    
    ofSetColor(200,180,255,255);
    ofDrawBitmapString("Get and Hide cursor pressing c. Undo one particle with spacebar", 250,760);
}

void ofApp::collisionDetection(int i){
    for(int k=0;k<i;k++){
        float distance = myParticle[i].location.distance(myParticle[k].location);
        if(distance<myParticle[i].radius){
          
            myParticle[i].velocity*=-1;
            myParticle[k].velocity*=-1;
            
        }
    }
   
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==' ' && myParticle.size()>0) myParticle.pop_back();
    if(key== 'c') CGDisplayShowCursor(0);
   

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key== 'c') CGDisplayHideCursor(0);

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    Particle newParticle;
    mouse.set(x+newParticle.radius,y);
    newParticle.setup(mouse);
    newParticle.velocity.x = 4 ;
    //newParticle.velocity.y = 5 ;
    myParticle.push_back(newParticle);
    
    Particle newParticle1;
    mouse.set(x-newParticle.radius,y);
    newParticle1.setup(mouse);
    newParticle1.velocity.x = -3;
 
    myParticle.push_back(newParticle1);
    
    Particle newParticle2;
    mouse.set(x-newParticle.radius*2,y);
    newParticle2.setup(mouse);
    newParticle2.velocity.x = 5;
    myParticle.push_back(newParticle2);
    
     
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
   
   
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
