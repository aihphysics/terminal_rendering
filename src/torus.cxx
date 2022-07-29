#include <torus.hxx>


void torus::draw(){
  
  this->draw( terminal->output, terminal->z_buffer );

}


void torus::draw( float * output, float * z_buffer ){

  for ( float theta = 0; theta < 2*M_PI; theta+=0.01){
	  float cos_theta{cos(theta)}, sin_theta{sin(theta)};

	  // iterate around torus axis
	  for ( float phi = 0; phi < 2*M_PI; phi+=0.01){
	    float cos_phi{cos(phi)}, sin_phi{sin(phi)};
	
	    // circle x and y before z
	    float circle_x = r_inner + r_tube*cos_theta;
	    float circle_y = r_tube*sin_theta;

      float x = circle_x*cos_phi;
      float y = circle_y;
      float z = terminal->K2 + circle_x*sin_phi;
      
      float z_inv = 1/z;
      // peform projection
      int x_p = (int) (((float) terminal->screen_width)/2 + terminal->K1*z_inv*x);
      int y_p = (int) (((float) terminal->screen_height)/2 - terminal->K1*z_inv*y);
      
      float L = light_source->x_dir * cos_theta*cos_phi
              + light_source->y_dir * sin_theta
              + light_source->z_dir * cos_theta*sin_phi;

      if ( L < 0 ) continue;
      if (x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0) continue;
      if (z_inv < z_buffer[terminal->screen_width * y_p + x_p] ) continue;
      z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
      int L_idx = L*8;
  	}
  }
}

void torus::draw( float A, float B ){

  float cos_A{cos(A)}, sin_A{sin(A)};
  float cos_B{cos(B)}, sin_B{sin(B)};

  for ( float theta = 0; theta < 2*M_PI; theta+=0.01){
	  float cos_theta{cos(theta)}, sin_theta{sin(theta)};

	  // iterate around torus axis
	  for ( float phi = 0; phi < 2*M_PI; phi+=0.01){
	    float cos_phi{cos(phi)}, sin_phi{sin(phi)};
	
	    // circle x and y before z
	    float circle_x = r_inner + r_tube*cos_theta;
	    float circle_y = r_tube*sin_theta;

	    // apply the A, B rotation
	    float x = circle_x*(cos_B*cos_phi + sin_A*sin_B*sin_phi) - circle_y*cos_A*sin_B;	
	    float y = circle_x*(sin_B*cos_phi - sin_A*cos_B*sin_phi) + circle_y*cos_A*cos_B;
      float z = terminal->K2 + cos_A*circle_x*sin_phi + circle_y*sin_A;
      
      float z_inv = 1/z;
      int x_p = (int) (((float) terminal->screen_width)/2 + terminal->K1*z_inv*x);
      int y_p = (int) (((float) terminal->screen_height)/2 - terminal->K1*z_inv*y);
      
      // calculate luminance
      float L =  cos_phi*cos_theta*sin_B - cos_A*cos_theta*sin_phi - sin_A*sin_theta + cos_B*(cos_A*sin_theta - cos_theta*sin_A*sin_phi);

      // luminance and z buffer checks
      if ( L < 0 ) continue;
      if (x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0) continue;
      if (z_inv < terminal->z_buffer[terminal->screen_width * y_p + x_p] ) continue;
      terminal->z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
      terminal->output[terminal->screen_width * y_p + x_p] = L;
  	}
  }
}


