#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include <vector>
#include "boid.h"
#include "newBoid.h"

class testApp : public ofBaseApp{    // class testapp inherits from ofBaseApp (all the stuff in public) 
    // to use it we need to redefine in header file and make the code in cpp -> this is polymorhpic. The function is in the parent (?) class but not the code in the function we use here  

public:
    ~testApp();      // creates a destructor - because of the thilda in front 
	
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);

    // these are the original boids 
    std::vector<Boid *> boids;   // creates standard vecor of boids. One boid is one bird 
    //* is the pointer to boid

    // these are the new boids
    std::vector<Boid *> newBoids; 
};

#endif	
