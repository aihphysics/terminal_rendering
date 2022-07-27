#include <sphere.hxx>

void sphere::draw(){
  this->draw( terminal->output, terminal->z_buffer );
}

void sphere::draw(char * output, float * z_buffer ){
  
  for ( float theta = 0; theta < 2*M_PI; theta+=0.01){
	  float cos_theta{cos(theta)}, sin_theta{sin(theta)};

	  for ( float phi = 0; phi < 2*M_PI; phi+=0.01){
	    float cos_phi{cos(phi)}, sin_phi{sin(phi)};
 
      float x = x_centre + radius*cos_theta*cos_phi;
      float y = y_centre + radius*sin_theta;
      float z = z_centre + terminal->K2 + radius*cos_theta*sin_phi;
      
      float z_inv = 1/z;
      int x_p = (int) (terminal->screen_width/2.0 + terminal->K1*z_inv*x);
      int y_p = (int) (terminal->screen_height/2.0 - terminal->K1*z_inv*y);

      float L = light_source->x_dir*cos_theta*cos_phi
              + light_source->y_dir*sin_theta
              + light_source->z_dir*cos_theta*sin_phi;

      if ( L < 0 ) continue;
      if (x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0) continue;
      if ( z_inv < z_buffer[terminal->screen_width * y_p + x_p]) continue;
      z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
      int L_idx = L*11;
      output[terminal->screen_width * y_p + x_p] = ".,-~:;=!*#$@"[L_idx];

    }
  }
}
