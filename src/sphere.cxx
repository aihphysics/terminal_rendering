#include <sphere.hxx>

class sphere{
  private:
    float rad;
    float x_c, y_c, z_c;
    float v_x, v_y, v_z;
    float a_x, a_y, a_z;
    float c_K1, c_K2;
    light c_light;

  public:

    sphere(float r, float x, float y, float z){
      rad = r; x_c = x; y_c = y; z_c = z;  
      c_light = light(0,1,-1);
    }
    void set_contants(float K1, float K2){
      c_K1 = K1; c_K2 = K2;
    }

    void draw(char (&output)[237][57], char (&z_buffer)[237][57]){
      for ( float theta = 0; theta < 2*M_PI; theta+=0.01){
		    float cos_theta{cos(theta)}, sin_theta{sin(theta)};

		    for ( float phi = 0; phi < 2*M_PI; phi+=0.01){
			    float cos_phi{cos(phi)}, sin_phi{sin(phi)};
 
          float x = x_c + rad*sin_theta*cos_phi;
          float y = y_c + rad*sin_theta*sin_phi;
          float z = z_c + rad*cos_theta; // + K2?
          
          int x_p = (c_K1*x)/(c_K2+z);
          int y_p = (c_K1*y)/(c_K2+z);
          
          float L = c_light.x_dir*rad*sin_theta*cos_phi
                    + c_light.y_dir*rad*sin_theta*sin_phi
                    + c_light.z_dir*rad*cos_theta;
          if (L>0){
            float z_inv = 1/z;
            if ( z_inv > z_buffer[x_p][y_p]){
              z_buffer[x_p][y_p] = z_inv;
              int L_idx = L*8;
              output[x_p][y_p] = ".,-~:;=!*#$@"[L_idx];
            }
          }
        }
      }
    }

};
