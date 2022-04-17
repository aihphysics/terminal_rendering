#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <chrono>

#include <light.hxx>

class sphere{
  private:
    float rad;
    float x_c, y_c, z_c;
    float v_x, v_y, v_z;
    float a_x, a_y, a_z;
    float c_K1, c_K2;
    light c_light;

  public:
    sphere(float r, float x, float y, float z){
      rad = r; x_c = x; y_c = y; z_c = z;  
      c_light = light(0.0,1.0,-1.0);
    }
    void set_contants(float K2){
      c_K2 = K2;
      c_K1 = 57*K2*1/(8*(rad));
    }
    void draw(char (&output)[237][57], float (&z_buffer)[237][57]);
};
