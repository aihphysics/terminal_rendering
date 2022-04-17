#include <light.hxx>

light::light(){
  x_dir = 0; y_dir = 0; z_dir = 0; 
}

light::light(float x, float y, float z){
  x_dir = x; y_dir = y; z_dir = z; 
}
