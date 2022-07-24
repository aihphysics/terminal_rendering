#include <cube.hxx>

void cube::draw(char * output, float * z_buffer ){

  for ( float w = -width/2.0; w <= width/2.0; w += 0.01 ){
    for ( float h = -height/2.0; h <= height/2.0; h += 0.01 ){
      for ( float d = -depth/2.0; d <= depth/2.0; d += 0.01 ){
      
        if  ( ( (abs(w*2) == width) + (abs(h*2) == height) + (abs(d*2) == depth) ) != 1 ) continue;
        
        float x_norm = (abs(w*2) == width) * w;
        float y_norm = (abs(h*2) == height) * h;
        float z_norm = (abs(d*2) == depth) * d;
        
        float x = x_centre + w;
        float y = y_centre + h;
        float z = z_centre + d;

        float z_inv = 1/z;
        int x_p = (int) (terminal->screen_width/2.0 + terminal->K1*z_inv*x);
        int y_p = (int) (terminal->screen_height/2.0 - terminal->K1*z_inv*y);

        float L = light_source->x_dir * x_norm
                + light_source->y_dir * y_norm
                + light_source->z_dir * z_norm;

        if ( L < 0 ) continue;
        if (x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0) continue;
        if ( z_inv < z_buffer[terminal->screen_width * y_p + x_p]) continue;
        z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
        int L_idx = L*8;
        output[terminal->screen_width * y_p + x_p] = ".,-~:;=!*#$@"[L_idx];

      }
    }
  }

}

void cube::draw(){

  for ( float w = -width/2.0; w <= width/2.0; w += 0.01 ){
    for ( float h = -height/2.0; h <= height/2.0; h += 0.01 ){
      for ( float d = -depth/2.0; d <= depth/2.0; d += 0.01 ){
      
        if  ( ( (abs(w*2) == width) + (abs(h*2) == height) + (abs(d*2) == depth) ) != 1 ) continue;

        

        // Does the ordering of this need to be changed for the rotations?
        // Say we want a pi/4 rotation around the x and y axis, to bring the cube point on to the camera
        // simply leave x alone, apply rotation matrices to the full set of x and y
        // I need more paper for this

        float x_norm = (abs(w*2) == width) * w;
        float y_norm = (abs(h*2) == height) * h;
        float z_norm = (abs(d*2) == depth) * d;
        float norm_len = sqrt(abs(x_norm*x_norm + y_norm*y_norm + z_norm+z_norm));

        x_norm = x_norm/norm_len;
        y_norm = y_norm/norm_len;
        z_norm = z_norm/norm_len;

        float x = x_centre + w;
        float y = y_centre + h;
        float z = z_centre + terminal->K2 + d;
  
        float z_inv = 1/z;
        int x_p = (int) ((float)terminal->screen_width/2.0 + (terminal->K1)*z_inv*x);
        int y_p = (int) ((float)terminal->screen_height/2.0 - (terminal->K1)*z_inv*y);


        float L = light_source->x_dir * x_norm
                + light_source->y_dir * y_norm
                + light_source->z_dir * z_norm;

        if ( L < 0 ) continue;
        //std::cout << L << std::endl;
        //std::cout << "L" << std::endl;
        if (x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0) continue;
        //std::cout << "S" << std::endl;
        if ( z_inv < terminal->z_buffer[terminal->screen_width * y_p + x_p]) continue;
        //std::cout << "Z" << std::endl;
        terminal->z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
        //std::cout << "Zc" << std::endl;
        int L_idx = L*8;
        //std::cout << L << std::endl;
        //std::cout << L_idx << std::endl;
        //td::cout << "Lc" << std::endl;
        terminal->output[terminal->screen_width * y_p + x_p] = ".,-~:;=!*#$@"[L_idx];
        //std::cout << "Oc" << std::endl;


      }
    }
  }

}















//void sphere::draw(){
//
//  for ( float theta = 0; theta < 2*M_PI; theta+=0.01){
//	  float cos_theta{cos(theta)}, sin_theta{sin(theta)};
//
//	  for ( float phi = 0; phi < 2*M_PI; phi+=0.01){
//	    float cos_phi{cos(phi)}, sin_phi{sin(phi)};
// 
//      float x = x_centre + radius*cos_theta*cos_phi;
//      float y = y_centre + radius*sin_theta;
//      float z = z_centre + terminal->K2 + radius*cos_theta*sin_phi;
//      
//      
//      float z_inv = 1/z;
//      int x_p = (int) (terminal->screen_width/2.0 + terminal->K1*z_inv*x);
//      int y_p = (int) (terminal->screen_height/2.0 - terminal->K1*z_inv*y);
//
//      float L = light_source->x_dir*cos_theta*cos_phi
//              + light_source->y_dir*sin_theta
//              + light_source->z_dir*cos_theta*sin_phi;
//
//      if ( L < 0 ) continue;
//      if (x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0) continue;
//      if ( z_inv < terminal->z_buffer[terminal->screen_width * y_p + x_p]) continue;
//      terminal->z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
//      int L_idx = L*8;
//      terminal->output[terminal->screen_width * y_p + x_p] = ".,-~:;=!*#$@"[L_idx];
//
//    }
//  }
//}
