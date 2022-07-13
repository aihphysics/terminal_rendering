#include <sphere.hxx>

void sphere::draw(char (&output)[(int) screen_width][(int) screen_height], float (&z_buffer)[(int) screen_width][(int) screen_height]){

  for ( float theta = 0; theta < 2*M_PI; theta+=0.01){
	  float cos_theta{cos(theta)}, sin_theta{sin(theta)};

	  for ( float phi = 0; phi < 2*M_PI; phi+=0.01){
	    float cos_phi{cos(phi)}, sin_phi{sin(phi)};
 
      float x = x_c + rad*cos_theta*cos_phi;
      float y = y_c + rad*sin_theta;
      float z = z_c + s_K2 + rad*cos_theta*sin_phi;
      
      
      float z_inv = 1/z;
      int x_p = (int) (421.0/2.0 + s_K1*z_inv*x);
      int y_p = (int) (109.0/2.0 - s_K1*z_inv*y);

      float L = light_source->x_dir*cos_theta*cos_phi
              + light_source->y_dir*sin_theta
              + light_source->z_dir*cos_theta*sin_phi;

      if ( L < 0 ) continue;
      if (x_p > screen_width || y_p > screen_height || x_p < 0 || y_p < 0) continue;
      if ( z_inv < z_buffer[x_p][y_p]) continue;
      z_buffer[x_p][y_p] = z_inv;
      int L_idx = L*8;
      output[x_p][y_p] = ".,-~:;=!*#$@"[L_idx];

    }
  }
}

