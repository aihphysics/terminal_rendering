#include <light.hxx>

light::light(){
  x_dir = 0; y_dir = 0; z_dir = 0; 
}

light::light(float x_dir, float y_dir, float z_dir){
   float norm = sqrt( x_dir*x_dir + y_dir*y_dir + z_dir*z_dir);
   this->x_dir = x_dir/norm;//norm;
   this->y_dir = y_dir/norm;//norm;
   this->z_dir = z_dir/norm;//norm;
}
