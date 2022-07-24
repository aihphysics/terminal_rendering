#include <main.hxx>



using namespace std::chrono_literals;

int main(int argc, char * argv[], char * env[]){

  // Advised to add exports to your .bashrc for expediancy, getopt inbound
  int screen_width  = std::atoi(std::getenv("COLUMNS"));
  int screen_height = std::atoi(std::getenv("LINES"));

  // Depth and projection constants
  // 50 is flat, 2 is tolerable, 1.0 is dizzying
  float K2 = 20.0;
  float K1 = screen_height*K2*(1/0.8);

  // Screen object, essentially a canvas.
  screen terminal( K1, K2, screen_width, screen_height );

  // light source, not implemented in all objects
  // no distance checks or spread, just a simple vector
  light light_source( 0, 0, -1 );

  // A few object definitions
  torus o_torus( &terminal,  0.3/25.0, 6.0/25.0 );
  sphere test_sphere( &terminal, &light_source, 0.1, 0.2,  0.0,  0.0 );
  cube test_cube( &terminal, &light_source, 0.0,  0.0,  0.0, 0.1, 0.1, 0.1 );
  
  // Draw loop, probably could be done better
  for ( int i = 0; i < 1e5; i++ ){
  
    // draw objects ( should compress these to an array )
    //o_torus.draw( i/20.0, i/20.0 );
    test_sphere.draw( );
    test_cube.draw( );

    if ( i == 50 ){
      test_cube.set_rotation(i/20.0,0,0);  
    }

    // draw the 'frame'
    terminal.draw_frame();

    //10fps lol
    std::this_thread::sleep_for( 100ms );

  }

  return 0;
}

// IDEAS THAT NEED IMPLEMENTED
// >> I SPENT HOURS REFACTORING AND TOUCHED NONE OF THESE
// PROPER HEADER GUARDS -- DONE
// DISENTANGLE THE TORUS CALCULATIONS 
// LIGHT SOURCES AS AN ARRAY
// L-BUFFER
// RE-EVALUATE CAMERA AT ORIGIN
// ADD USER CONTROL INPUT ON CAMERA
// CREATE ROTATION OBJECTS
// DO LINE ATTACHMENTS
// DO RESOLUTION CALCULATION FOR STEPS
