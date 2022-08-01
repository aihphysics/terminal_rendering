#include <renderable.hxx>

#include <iostream>

#ifndef cylinder_class
#define cylinder_class

class cylinder : public renderable{
  protected:
    float radius;
    float length;
    int final_point;

  public:
    cylinder( screen * terminal, light * light_source, float x_centre, float y_centre, float z_centre, float radius, float length ){

      this->terminal = terminal;
      this->light_source = light_source;

      centre = euch_vector( x_centre, y_centre, z_centre );
      this->length = length;
      this->radius = radius;

      int theta_max = 2*M_PI/0.01; 
      int len_max = length/0.008;
      int rad_max = radius/0.01;
      int points = rad_max + ( 2 * theta_max * len_max );

      //std::cout << theta_max << std::endl;
      //std::cout << len_max << std::endl;
      //std::cout << rad_max << std::endl;
      //std::cout << points << std::endl;

      surface = new euch_vector[points];
      normal = new euch_vector[points];
      point_type = new int[points];
      
      int entry = 0;
      for ( int theta_idx = 0; theta_idx <= theta_max; theta_idx++ ){

        for ( int len_idx = 0; len_idx <= len_max; len_idx++ ){

          float radius_start = rad_max;
          bool base = false;
          if ( len_idx == 0 || len_idx == len_max ){ 
            radius_start = 0; 
            base = true;
          }

          for ( float rad_idx = radius_start; rad_idx <= rad_max; rad_idx ++ ){
            
            int evp = 1 + ( len_idx == len_max );

            float r = rad_idx*0.01;
            float theta = theta_idx*0.01;
            float l = -length/2.0 + len_idx*0.008;

            euch_vector point( r*cos(theta), r*sin(theta), l );

            euch_vector norm;
            if ( base ){ norm = euch_vector( 0, 0, point.z ); } 
            else { norm = euch_vector( point.x, point.y, 0 ); }
            norm.normalise();

            surface[entry] = point;
            normal[entry] = norm;
            point_type[entry] = evp;
            entry++;
          }
        }
      }
      final_point = entry;
      //std::cout << final_point << std::endl;
    }
    void draw( float * output, float * z_buffer );
    void draw();
};

#endif
