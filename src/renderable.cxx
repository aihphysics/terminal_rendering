#include <renderable.hxx>

euch_vector renderable::project( euch_vector point, screen * terminal ){

  float z_inv = 1/point.z;
  int x_p = (int) ((float)terminal->screen_width/2.0 + (terminal->K1)*z_inv*point.x);
  int y_p = (int) ((float)terminal->screen_height/2.0 - (terminal->K1)*z_inv*point.y);
  return euch_vector( x_p, y_p, z_inv ); 

}
