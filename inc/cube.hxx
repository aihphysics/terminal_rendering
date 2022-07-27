#include <math.h>
#include <renderable.hxx>

#include <iostream>

#ifndef cube_class
#define cube_class

class cube : public renderable{

  protected:
    float width;
    float height;
    float depth;
    float * surface_x;
    float * surface_y;
    float * surface_z;
    float * normal_x;
    float * normal_y;
    float * normal_z;
    int * point_type;
    int final_point;

  public:
    cube(screen * terminal, light * light_source, float x_centre, float y_centre, float z_centre, float width, float height, float depth ){

      // fill members
      this->x_centre = x_centre; 
      this->y_centre = y_centre;
      this->z_centre = z_centre;  
      this->width = width;
      this->height = height;
      this->depth = depth;
      this->light_source = light_source;
      this->terminal = terminal;

      // populate surface
      std::cout << "start alloc" << std::endl;
      surface_x = new float[400*7];
      surface_y = new float[400*7];
      surface_z = new float[400*7];
      normal_x = new float[400*7];
      normal_y = new float[400*7];
      normal_z = new float[400*7];
      point_type = new int[400*7];
      std::cout << "end alloc" << std::endl;
      
      int entry = 0;
      for ( int w_ind = 0; w_ind <= 20; w_ind++ ){
        for ( int h_ind = 0; h_ind <= 20; h_ind++) {
          for ( int d_ind = 0; d_ind <= 20; d_ind++ ){

            int evp = ( ( (w_ind == 0 ) || (w_ind == 20)) + ((h_ind == 0) || (h_ind == 20)) + ((d_ind == 0 ) + (d_ind == 20)) );
            if  ( evp < 1 ) continue;

            float w = -width/2.0f + w_ind*(width/20.0);
            float h = -height/2.0f + h_ind*(height/20.0);
            float d = -depth/2.0f + d_ind*(depth/20.0);              
            surface_x[entry] = w; 
            surface_y[entry] = h;
            surface_z[entry] = d;
            
            float x_norm = (abs(w*2.0) == width) * w;
            float y_norm = (abs(h*2.0) == height) * h;
            float z_norm = (abs(d*2.0) == depth) * d;
            
            float norm_len = sqrt(x_norm*x_norm + y_norm*y_norm + z_norm*z_norm);
            x_norm = x_norm/norm_len;
            y_norm = y_norm/norm_len;
            z_norm = z_norm/norm_len;

            normal_x[entry] = x_norm;
            normal_y[entry] = y_norm;
            normal_z[entry] = z_norm;

            point_type[entry] = evp;
            entry++;
            std::cout << "entry: " << entry << std::endl;
          }
        }
      }
      final_point = entry;
    }

    void draw();
    void draw( char * output, float * z_buffer );
    void set_rotation( float x_rotation, float y_rotation, float z_rotation ){
      this->x_rotation = x_rotation;
      this->y_rotation = y_rotation;
      this->z_rotation = z_rotation;
    }


};

#endif
