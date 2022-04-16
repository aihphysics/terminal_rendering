#include <cstdlib>
#include <main.hxx>

const int screen_x = 237;
const int screen_y = 57;

const float theta_spacing = 0.01;
const float phi_spacing = 0.01;

const float R1 = 0.3;
const float R2 = 2;
const float K2 = 1000;

//const float K1 = screen_x*K2*3/(8*(R1+R2));
const float K1 = screen_y*K2*1/(4*(R1+R2));

// K1 based of screen size
// VERY QUESTIONABLE {
// screen size can be found from environment variables
// $COLUMNS, $LINES, just echo these, take the smallest
// carrahae-arch alacritty terminal outputs 237 and 61
// taking the smallest of these being 61
// }
// maximal x distance at edge of object, R1 + R2
// want this displaced towards the edge of the screen


void render_frame(float A, float B){
  

  float cos_A{cos(A)}, sin_A{sin(A)};
  float cos_B{cos(B)}, sin_B{sin(B)};

  //float z_buffer[screen_x][screen_y] ={ { [0 ... screen_x-1]=0}, {[0 ... screen_y-1] = 0}} ;
  float z_buffer[screen_x][screen_y];
  char output[screen_x][screen_y];
	std::fill_n(&output[0][0], sizeof(output)/sizeof(output[0][0]), ' ');
	std::fill_n(&z_buffer[0][0], sizeof(z_buffer)/sizeof(z_buffer[0][0]),0);

	// iterate around circle	
	for ( float theta = 0; theta < 2*M_PI; theta+=theta_spacing){
		float cos_theta{cos(theta)}, sin_theta{sin(theta)};

		// iterate around torus axis
		for ( float phi = 0; phi < 2*M_PI; phi+=phi_spacing){
			float cos_phi{cos(phi)}, sin_phi{sin(phi)};
			
			// circle x and y before z
			float circle_x = R2 + R1*cos_theta;
			float circle_y = R1*sin_theta;

			// apply the A, B rotation
			float x = circle_x*(cos_B*cos_phi + sin_A*sin_B*sin_phi) - circle_y*cos_A*sin_B;	
			float y = circle_x*(sin_B*cos_phi - sin_A*cos_B*sin_phi) + circle_y*cos_A*cos_B;
      float z = K2 + cos_A*circle_x*sin_phi + circle_y*sin_A;
      //float x = circle_x;
      //float y = circle_y;
      //float z = K2 + circle_x + circle_y;
      
      float z_inv = 1/z;
      // peform projection
      int xp = (int) (((float) screen_x)/2 + K1*z_inv*x);
      int yp = (int) (((float) screen_y)/2 - K1*z_inv*y);
      
      // calculate luminance
      float L =  cos_phi*cos_theta*sin_B - cos_A*cos_theta*sin_phi - sin_A*sin_theta + cos_B*(cos_A*sin_theta - cos_theta*sin_A*sin_phi);
      //float L = sin_theta + cos_theta*sin_phi;


      // luminance and z buffer checks
      if ( L > 0 ){
        if (z_inv > z_buffer[xp][yp] ){
          z_buffer[xp][yp] = z_inv;
          int L_idx = L*8;
          output[xp][yp] = ".,-~:;=!*#$@"[L_idx];
          //std::cout << "output" << std::endl;
        }
      }
		}
	}
  printf("\x1b[H");
  for (int j = 0; j < screen_y; j++) {
    for (int i = 0; i < screen_x; i++) {
      putchar(output[i][j]);
    }
    putchar('\n');
  }
}


int main(int argc, char * argv[], char * env[]){

  std::chrono::system_clock::time_point start;
  std::chrono::system_clock::time_point check;
  double ms;
  
  for (int i = 0; i < 1e10; i++){
      //render_frame(i/100.0,i/100.0);
      render_frame(i/100.0,i/100.0);
      start  = std::chrono::high_resolution_clock::now();
      do{
        check  = std::chrono::high_resolution_clock::now();
        ms = std::chrono::duration_cast<std::chrono::milliseconds>(check - start).count();
      } while ( ms < 10);
  }

 
  return 0;
}
