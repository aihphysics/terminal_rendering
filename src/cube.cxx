#include <cmath>
#include <cube.hxx>
#include <iostream>
#include <string>


void cube::draw( ){

  this->draw( terminal->output, terminal->z_buffer );

}

void cube::draw(char * output, float * z_buffer ){

  for ( int point_idx = 0; point_idx <= final_point; point_idx++ ){
    
    float x = surface_x[point_idx];
    float y = surface_y[point_idx];
    float z = surface_z[point_idx];
    float x_norm = normal_x[point_idx];
    float y_norm = normal_y[point_idx];
    float z_norm = normal_z[point_idx];
    int evp = point_type[point_idx];

    float x_t, y_t, z_t;
    float x_nt, y_nt, z_nt;

    // perform x rotation
    y_t =  y*cos(x_rotation) + z*sin(x_rotation);
    z_t = -y*sin(x_rotation) + z*cos(x_rotation);
    y_nt =  y_norm*cos(x_rotation) + z_norm*sin(x_rotation);
    z_nt = -y_norm*sin(x_rotation) + z_norm*cos(x_rotation);
    y = y_t; z = z_t;
    y_norm = y_nt; z_norm = z_nt;

    // perform y rotation
    x_t =  x*cos(y_rotation) + z*sin(y_rotation);
    z_t = -x*sin(y_rotation) + z*cos(y_rotation);
    x_nt = x_norm*cos(y_rotation) + z_norm*sin(y_rotation);
    z_nt = -x_norm*sin(y_rotation) + z_norm*cos(y_rotation);
    x = x_t; z = z_t;
    x_norm = x_nt; z_norm = z_nt;

    //// perform z rotation
    x_t =  x*cos(z_rotation) + y*sin(z_rotation);
    y_t = -x*sin(z_rotation) + y*cos(z_rotation);
    x_nt =  x_norm*cos(z_rotation) + y_norm*sin(z_rotation);
    y_nt = -x_norm*sin(z_rotation) + y_norm*cos(z_rotation);
    x = x_t; y = y_t;
    x_norm = x_nt; y_norm = y_nt;
    
    x = x + x_centre;
    y = y + y_centre;
    z = z + z_centre + terminal->K2; 
    
    float z_inv = 1/z;
    int x_p = (int) ((float)terminal->screen_width/2.0 + (terminal->K1)*z_inv*x);
    int y_p = (int) ((float)terminal->screen_height/2.0 - (terminal->K1)*z_inv*y);

    
    float L = light_source->x_dir * x_norm 
            + light_source->y_dir * y_norm
            + light_source->z_dir * z_norm;
    
    if ( L < 0 ) continue;
    if ( x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0 ) continue;
    //if ( z_inv < terminal->z_buffer[terminal->screen_width * y_p + x_p] ) continue;
    if ( z_inv < z_buffer[terminal->screen_width * y_p + x_p] ) continue;
    z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
    int L_idx = L*11;
    if  ( evp > 1 ){ L_idx = 11; }
    output[terminal->screen_width * y_p + x_p] = ".,-~:;=!*#$@"[L_idx];

  }

}

