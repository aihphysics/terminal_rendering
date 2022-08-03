#include <math.h>
#include <stdio.h>
#include <renderable.hxx>

#include <iostream>

#ifndef torus_class
#define torus_class

class torus : public renderable {

  private:
    float r_tube;
    float r_inner;

    int final_point;

  public:
    torus(screen * terminal, light * light_source, float r_tube, float r_inner){
     
      this->terminal = terminal;
      this->light_source = light_source;
      this->r_tube = r_tube; 
      this->r_inner = r_inner;

      int theta_points = ( 2*M_PI ) /0.2;
      int phi_points = (2*M_PI)/0.05;
      int points = theta_points * phi_points;
      
      surface = new euch_vector[points];
      normal = new euch_vector[points];
      point_type = new int[points];

      std::cout << theta_points << std::endl;
      std::cout << phi_points << std::endl;
      std::cout << points << std::endl;
     
      int entry = 0;
      for ( int theta_idx = 0; theta_idx < theta_points; theta_idx++ ){
        float theta = theta_idx * ( (2*M_PI )/theta_points );
      
        for ( int phi_idx = 0; phi_idx < phi_points; phi_idx++ ){
          float phi = phi_idx * ( (2*M_PI )/phi_points );

          euch_vector point = euch_vector( r_inner + r_tube * cos(theta), r_tube*sin(theta), 0 );
          euch_vector norm = euch_vector( r_tube * cos(theta), r_tube*sin(theta), 0 );
          norm.normalise();

          point.rotate_y( phi );
          norm.rotate_y( phi );

          surface[entry] = point;
          normal[entry] = norm;
          point_type[entry] = 1;

          entry++;

        }
      }
      final_point = entry;

      std::cout << final_point << std::endl;
    }

    void draw() override;
    void draw( float * output, float * z_buffer ) override;

};

#endif
