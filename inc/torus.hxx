#include <math.h>
#include <stdio.h>
#include <renderable.hxx>

#ifndef torus_class
#define torus_class

class torus : public renderable {

  private:
    float r_1;
    float r_2;

  public:
    torus(screen * terminal, float r_tube, float r_inner){
      this->terminal = terminal;
      r_1 = r_tube; r_2 = r_inner;
    }

    void draw(char * output, float * z_buffer) override;
    void draw(char * output, float * z_buffer, float A, float B);

};

#endif
