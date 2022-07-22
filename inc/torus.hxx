#include <math.h>
#include <stdio.h>
#include <renderable.hxx>

#ifndef torus_class
#define torus_class

class torus : public renderable {

  private:
    float r_tube;
    float r_inner;

  public:
    torus(screen * terminal, float r_tube, float r_inner){
      this->terminal = terminal;
      this->r_tube = r_tube; 
      this->r_inner = r_inner;
    }

    void draw() override;
    void draw( float A, float B );
    void draw( char * output, float * z_buffer ) override;
    void draw( char * output, float * z_buffer, float A, float B);

};

#endif
