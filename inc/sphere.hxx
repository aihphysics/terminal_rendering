#include <math.h>
#include <renderable.hxx>

#include <iostream>

#ifndef sphere_class
#define sphere_class

class sphere : public renderable{
  protected:
    float radius;
    int final_point;

  public:
    sphere(screen * terminal, light * light_source, float radius, float x_centre, float y_centre, float z_centre ){

      this->radius = radius; 
      this->light_source = light_source;
      this->terminal = terminal;

      this->centre = euch_vector( x_centre, y_centre, z_centre );

      int theta_max = (2*M_PI)/0.01;
      int phi_max   = (M_PI)/0.01;
      int points = theta_max * phi_max * 2;

      surface = new euch_vector[points];
      normal = new euch_vector[points];
      point_type = new int[points];

      int entry = 0;
      for ( int theta_idx = 0; theta_idx <= theta_max; theta_idx++){

        float theta = 0.01 * theta_idx;
	      float cos_theta{cos(theta)}, sin_theta{sin(theta)};

        for ( int phi_idx = 0; phi_idx <= phi_max; phi_idx++){

          float phi = 0.01 * phi_idx;
	        float cos_phi{cos(phi)}, sin_phi{sin(phi)};
          
          euch_vector point = euch_vector( radius*cos_theta*cos_phi,
                                           radius*sin_theta,
                                           radius*cos_theta*sin_phi );

          euch_vector norm( point );
          norm.normalise();

          surface[entry] = point;
          normal[entry] = norm;
          point_type[entry] = 1;
          entry++;
        }
      }
      final_point = entry;

    }

    void draw( float * output, float * z_buffer );
    void draw();

};

#endif
