#include <sphere.hxx>

#include <iostream>

void sphere::draw(){
  this->draw( terminal->output, terminal->z_buffer );
}

void sphere::draw( float * output, float * z_buffer ){
  
  for ( int point_idx = 0; point_idx <= final_point; point_idx++ ){

    int evp = point_type[point_idx];

    euch_vector point = surface[point_idx];
    euch_vector norm = normal[point_idx];

    point.rotate_x( x_rotation );
    point.rotate_y( y_rotation );
    point.rotate_z( z_rotation );
    norm.rotate_x( x_rotation );
    norm.rotate_y( y_rotation );
    norm.rotate_z( z_rotation );

    point += centre;
    point += terminal->position;

    float L = light_source->light_vec * norm;
  
    float z_inv = 1/point.z;
    int x_p = (int) ((float)terminal->screen_width/2.0 + (terminal->K1)*z_inv*point.x);
    int y_p = (int) ((float)terminal->screen_height/2.0 - (terminal->K1)*z_inv*point.y);

    if ( L < 0 ) continue;
    if ( x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0 ) continue;
    if ( z_inv < z_buffer[terminal->screen_width * y_p + x_p] ) continue;
    z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
    output[terminal->screen_width * y_p + x_p] = L;

  }
}
