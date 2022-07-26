#include <cmath>
#include <cube.hxx>
#include <iostream>
#include <string>

void cube::draw(char * output, float * z_buffer ){

  for ( float w = -width/2.0; w <= width/2.0; w += width/20.0 ){
    for ( float h = -height/2.0; h <= height/2.0; h += height/20.0 ){
      for ( float d = -depth/2.0; d <= depth/2.0; d += depth/20.0 ){
      
        if  ( ( (abs(w*2) == width) + (abs(h*2) == height) + (abs(d*2) == depth) ) < 1 ) continue;
        
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

  //for ( float w = -width/2.0f; w <= (width/2.0); w += width/20.0 ){
  //  for ( float h = -height/2.0f; h <= (height/2.0); h += height/20.0 ){
  //    for ( float d = -depth/2.0f; d <= (depth/2.0); d += depth/20.0 ){
  
  for ( float w_ind = 0; w_ind <= 20; w_ind++ ){
    for ( float h_ind = 0; h_ind <= 20; h_ind++) {
      for ( float d_ind = 0; d_ind <= 20; d_ind++ ){

        float w = -width/2.0f + w_ind*(width/20.0);
        float h = -height/2.0f + h_ind*(height/20.0);
        float d = -depth/2.0f + d_ind*(depth/20.0);

      
        int evp = ( ( (w_ind == 0 ) || (w_ind == 20)) + ((h_ind == 0) || (h_ind == 20)) + ((d_ind == 0 ) + (d_ind == 20)) );

        if  ( evp < 1 ) continue;

        float x_norm = (abs(w*2.0) == width) * w;
        float y_norm = (abs(h*2.0) == height) * h;
        float z_norm = (abs(d*2.0) == depth) * d;

        float x = w;
        float y = h;
        float z = d;

        float x_t, y_t, z_t;
        float x_nt, y_nt, z_nt;
        
        float norm_len = sqrt(x_norm*x_norm + y_norm*y_norm + z_norm*z_norm);
        x_norm = x_norm/norm_len;
        y_norm = y_norm/norm_len;
        z_norm = z_norm/norm_len;

        // perform x rotation
        y_t =  y*cos(x_rotation) + z*sin(x_rotation);
        z_t = -y*sin(x_rotation) + z*cos(x_rotation);
        y_nt =  y_norm*cos(x_rotation) + z_norm*sin(x_rotation);
        z_nt = -y_norm*sin(x_rotation) + z_norm*cos(x_rotation);
        y = y_t; z = z_t;
        y_norm = y_nt; z_norm = z_nt;

        // perform y rotation
        x_t =  x*cos(y_rotation) + z*sin(y_rotation);
        z_t = -x*sin(y_rotation) + z*cos(y_rotation);
        x_nt = x_norm*cos(y_rotation) + z_norm*sin(y_rotation);
        z_nt = -x_norm*sin(y_rotation) + z_norm*cos(y_rotation);
        x = x_t; z = z_t;
        x_norm = x_nt; z_norm = z_nt;

        //// perform z rotation
        x_t =  x*cos(z_rotation) + y*sin(z_rotation);
        y_t = -x*sin(z_rotation) + y*cos(z_rotation);
        x_nt =  x_norm*cos(z_rotation) + y_norm*sin(z_rotation);
        y_nt = -x_norm*sin(z_rotation) + y_norm*cos(z_rotation);
        x = x_t; y = y_t;
        x_norm = x_nt; y_norm = y_nt;
        
        x = x + x_centre;
        y = y + y_centre;
        z = z + z_centre + terminal->K2; 
        
        float z_inv = 1/z;
        int x_p = (int) ((float)terminal->screen_width/2.0 + (terminal->K1)*z_inv*x);
        int y_p = (int) ((float)terminal->screen_height/2.0 - (terminal->K1)*z_inv*y);

        
        float L = light_source->x_dir * x_norm 
                + light_source->y_dir * y_norm
                + light_source->z_dir * z_norm;
        
        if ( L < 0 ) continue;
        if ( x_p > terminal->screen_width || y_p > terminal->screen_height || x_p < 0 || y_p < 0 ) continue;
        if ( z_inv < terminal->z_buffer[terminal->screen_width * y_p + x_p] ) continue;
        terminal->z_buffer[terminal->screen_width * y_p + x_p] = z_inv;
        int L_idx = L*11;
        if  ( evp > 1 ){ L_idx = 11; }
        terminal->output[terminal->screen_width * y_p + x_p] = ".,-~:;=!*#$@"[L_idx];
      }
    }
  }

}

