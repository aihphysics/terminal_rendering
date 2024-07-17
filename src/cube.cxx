#include <cmath>
#include <cube.hxx>


void cube::draw( ){

  this->draw( terminal->output, terminal->z_buffer );

}

void cube::draw( float * output, float * z_buffer ){

  for ( int point_idx = 0; point_idx <= final_point; point_idx++ ){

    int evp = point_type[point_idx];
    if ( evp < this->draw_level ){ continue; }

    euch_vector point = surface[point_idx];
    euch_vector norm = normal[point_idx];

    point.rotate_x( x_rotation );
    point.rotate_y( y_rotation );
    point.rotate_z( z_rotation );
    norm.rotate_x( x_rotation );
    norm.rotate_y( y_rotation );
    norm.rotate_z( z_rotation );

    point.boost_x( beta_x );

    point += centre;
    point += terminal->position;

    float L = light_source->light_vec * norm;
 
    euch_vector proj_point = project( point, terminal );
  
    int x_p = proj_point.x;
    int y_p = proj_point.y;
    float z_inv = proj_point.z;
    
    if ( L < 0 ) continue;
    if ( x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0 ) continue;
    if ( z_inv < z_buffer[terminal->screen_width * y_p + x_p] ) continue;
    z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
    output[terminal->screen_width * y_p + x_p] = L;

  }

}
