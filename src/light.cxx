#include <light.hxx>

light::light(){

  light_vec = euch_vector( 0, 0, 0 );

}

light::light(float x_dir, float y_dir, float z_dir){

  light_vec = euch_vector( x_dir, y_dir, z_dir ); 
   
}
