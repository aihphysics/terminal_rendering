#include <torus.hxx>


void torus::draw(char (&output)[237][57], float (&z_buffer)[237][57], float A, float B){

  float cos_A{cos(A)}, sin_A{sin(A)};
  float cos_B{cos(B)}, sin_B{sin(B)};

  for ( float theta = 0; theta < 2*M_PI; theta+=0.01){
	  float cos_theta{cos(theta)}, sin_theta{sin(theta)};

	  // iterate around torus axis
	  for ( float phi = 0; phi < 2*M_PI; phi+=0.01){
	    float cos_phi{cos(phi)}, sin_phi{sin(phi)};
	
	    // circle x and y before z
	    float circle_x = r_2 + r_1*cos_theta;
	    float circle_y = r_1*sin_theta;

	    // apply the A, B rotation
	    float x = circle_x*(cos_B*cos_phi + sin_A*sin_B*sin_phi) - circle_y*cos_A*sin_B;	
	    float y = circle_x*(sin_B*cos_phi - sin_A*cos_B*sin_phi) + circle_y*cos_A*cos_B;
      float z = s_K2 + cos_A*circle_x*sin_phi + circle_y*sin_A;
      //float x = circle_x;
      //float y = circle_y;
      //float z = K2 + circle_x + circle_y;
      
      float z_inv = 1/z;
      // peform projection
      int x_p = (int) (((float) screen_x)/2 + s_K1*z_inv*x);
      int y_p = (int) (((float) screen_y)/2 - s_K1*z_inv*y);
      
      // calculate luminance
      float L =  cos_phi*cos_theta*sin_B - cos_A*cos_theta*sin_phi - sin_A*sin_theta + cos_B*(cos_A*sin_theta - cos_theta*sin_A*sin_phi);

      // luminance and z buffer checks
      if ( L < 0 ) continue;
      //if (x_p > screen_x ||  y_p > screen_y ) continue;
      if (x_p > 237 || y_p > 57 || x_p < 0 || y_p < 0) continue;
      if (z_inv < z_buffer[x_p][y_p] ) continue;
      z_buffer[x_p][y_p] = z_inv;
      int L_idx = L*8;
      output[x_p][y_p] = ".,-~:;=!*#$@"[L_idx];
  	}
  }
}


