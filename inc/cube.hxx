#include <math.h>
#include <renderable.hxx>

#ifndef cube_class
#define cube_class

class cube : public renderable{

  protected:
    float width;
    float height;
    float depth;

    euch_vector centre;
    euch_vector * surface;
    euch_vector * normal;

    float * surface_x;
    float * surface_y;
    float * surface_z;
    float * normal_x;
    float * normal_y;
    float * normal_z;
    int * point_type;
    int final_point;
    int draw_level;

  public:
    cube(screen * terminal, light * light_source, float x_centre, float y_centre, float z_centre, float width, float height, float depth ){

      centre = euch_vector( x_centre, y_centre, z_centre );

      // fill members
      this->x_centre = x_centre; 
      this->y_centre = y_centre;
      this->z_centre = z_centre;  
      this->width = width;
      this->height = height;
      this->depth = depth;
      this->light_source = light_source;
      this->terminal = terminal;
      this->draw_level = 1;
      
      int itr = width/0.005 - 1;
      int points = itr*itr*6+1;

      surface = new euch_vector[points];
      normal = new euch_vector[points];
      
      // populate surface
      surface_x = new float[points];
      surface_y = new float[points];
      surface_z = new float[points];
      normal_x = new float[points];
      normal_y = new float[points];
      normal_z = new float[points];
      point_type = new int[points];
      
      int entry = 0;
      for ( int w_ind = 0; w_ind <= itr; w_ind++ ){
        for ( int h_ind = 0; h_ind <= itr; h_ind++) {
          for ( int d_ind = 0; d_ind <= itr; d_ind++ ){

            int evp = ( ( ( w_ind == 0 ) || (w_ind == itr)) + ((h_ind == 0) || (h_ind == itr)) + ((d_ind == 0 ) + (d_ind == itr)) );
            if  ( evp < 1 ) continue;

            float w = -width/2.0f + w_ind*(width/(float) itr);
            float h = -height/2.0f + h_ind*(height/(float) itr);
            float d = -depth/2.0f + d_ind*(depth/(float) itr);              
            surface_x[entry] = w; 
            surface_y[entry] = h;
            surface_z[entry] = d;

            euch_vector point( -width/2.0f + w_ind*(width/(float) itr), 
                               -height/2.0f + h_ind*(height/(float) itr),
                               -depth/2.0f + d_ind*(depth/(float) itr) );


            euch_vector norm( (abs(w*2.0) == width) * w , (abs(h*2.0) == height) * h, (abs(d*2.0) == depth) * d );
            norm.normalise();

            surface[entry] = point;
            normal[entry] = norm;
            
            float x_norm = (abs(w*2.0) == width) * w;
            float y_norm = (abs(h*2.0) == height) * h;
            float z_norm = (abs(d*2.0) == depth) * d;
            
            float norm_len = sqrt(x_norm*x_norm + y_norm*y_norm + z_norm*z_norm);
            x_norm = x_norm/norm_len;
            y_norm = y_norm/norm_len;
            z_norm = z_norm/norm_len;

            normal_x[entry] = x_norm;
            normal_y[entry] = y_norm;
            normal_z[entry] = z_norm;

            point_type[entry] = evp;
            entry++;
          }
        }
      }
      final_point = entry;
    }

    void draw();
    void draw( float * output, float * z_buffer );

    void set_level( int draw_level ){
      
      this->draw_level = draw_level;
  
    }


};

#endif
