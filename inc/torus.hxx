#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <chrono>

class torus{
  private:
    const float theta_spacing = 0.01;
    const float phi_spacing = 0.01;
    const float screen_x = 237;
    const float screen_y = 57;
    float r_1;// = 0.3;
    float r_2;// = 2;
    const float K2 = 1000;
    float K1;

  public:
    torus(float r_tube, float r_inner){
      r_1 = r_tube; r_2 = r_inner;
      K1 = screen_y*K2*1/(4*(r_1+r_2));
    }
    void draw(char (&output)[237][57], float (&z_buffer)[237][57], float A, float B);
  
};
