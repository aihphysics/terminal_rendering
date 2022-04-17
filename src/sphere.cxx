#include <sphere.hxx>

void sphere::draw(char (&output)[237][57], float (&z_buffer)[237][57]){

  for ( float theta = 0; theta < 2*M_PI; theta+=0.01){
	  float cos_theta{cos(theta)}, sin_theta{sin(theta)};

	  for ( float phi = 0; phi < 2*M_PI; phi+=0.01){
	    float cos_phi{cos(phi)}, sin_phi{sin(phi)};
 
      //float x = x_c + rad*sin_theta*cos_phi;
      //float y = y_c + rad*sin_theta*sin_phi;
      //float z = z_c + rad*cos_theta; // + K2?
      float x = rad*cos_theta*cos_phi;
      float y = rad*sin_theta;
      float z = c_K2 + rad*cos_theta*sin_phi;
      
      //int x_p = (c_K1*x)/(c_K2+z);
      //int y_p = (c_K1*y)/(c_K2+z);
      
      
      float z_inv = 1/z;
      int x_p = (int) (237.0/2.0 + c_K1*z_inv*x);
      int y_p = (int) (57.0/2.0 - c_K1*z_inv*y);
      //std::cout << x << std::endl;
      //std::cout << y << std::endl;
      //std::cout << z << std::endl;
      //std::cout << z_inv << std::endl;
      //std::cout << x_p << std::endl;
      //std::cout << y_p << std::endl;


      //float L = c_light.x_dir*rad*sin_theta*cos_phi
      //          + c_light.y_dir*rad*sin_theta*sin_phi
      //          + c_light.z_dir*rad*cos_theta;
      float L = c_light.x_dir*cos_theta*cos_phi
              + c_light.y_dir*sin_theta
              + c_light.z_dir*cos_theta*sin_phi;

      if ( L < 0 ) continue;
      if ( z_inv < z_buffer[x_p][y_p]) continue;
      z_buffer[x_p][y_p] = z_inv;
      int L_idx = L*8;
      //std::cout << L_idx << std::endl;
      output[x_p][y_p] = ".,-~:;=!*#$@"[L_idx];

    }
  }
}

