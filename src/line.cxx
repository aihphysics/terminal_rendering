#include <line.hxx>
#include <iostream>

void line::draw(){
  this->draw( terminal->output, terminal->z_buffer );
}

void line::draw(float * output, float * z_buffer ){
  
  int len_max = length/0.01;
  for ( int len_idx = 0; len_idx <  len_max; len_idx++ ){


    euch_vector increment = step*len_idx;
    euch_vector point = start + increment;

    point.rotate_x( x_rotation );
    point.rotate_y( y_rotation );
    point.rotate_z( z_rotation );

    point += terminal->position;

    float z_inv = 1/point.z;
    int x_p = (int) ((float)terminal->screen_width/2.0 + (terminal->K1)*z_inv*point.x);
    int y_p = (int) ((float)terminal->screen_height/2.0 - (terminal->K1)*z_inv*point.y);


    if ( x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0 ) continue;
    if ( z_inv < z_buffer[terminal->screen_width * y_p + x_p] ) continue;
    z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
    output[terminal->screen_width * y_p + x_p] = 0.5;

  }

  return;
}
