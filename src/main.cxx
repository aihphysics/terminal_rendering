#include <main.hxx>



using namespace std::chrono_literals;

int main(int argc, char * argv[], char * env[]){

  // Advised to add exports to your .bashrc for expediancy, getopt inbound
  int screen_columns  = std::atoi(std::getenv("COLUMNS"));
  int screen_lines = std::atoi(std::getenv("LINES"));

  int screen_height = screen_lines*2;
  int screen_width = screen_columns;

  // Depth and projection constants
  // 50 is flat, 2 is tolerable, 1.0 is dizzying
  float K2 = 5.0;
  float K1 = screen_height*K2*(1/0.8);

  // Screen object, essentially a canvas.
  screen terminal( K1, K2, screen_width, screen_height );

  // light source, not implemented in all objects
  // no distance checks or spread, just a simple normalised vector
  light light_source( 0.0, 0, -1 );

  // A few object definitions
  torus o_torus( &terminal,  0.3/25.0, 6.0/25.0 );
  //sphere test_sphere( &terminal, &light_source, 0.1, 0.2,  0.0,  0.0 );
  float cube_size = 0.2;
  cube test_cube( &terminal, &light_source, 0.5,  0.0,  0.0, cube_size, cube_size, cube_size );
  //cube test_cube( &terminal, &light_source, 0.0,  0.0,  0.0, cube_size, cube_size, cube_size );

  cylinder test_cylinder( &terminal, &light_source, -0.5, 0.0, 0.0, 0.1, 0.3 );


  //cube test_cube( &terminal, &light_source, 0.0,  0.0,  0.0, 0.3, 0.05, 0.1 );
  
  //test_cube.set_rotation( M_PI/4.0, M_PI/4.0 , M_PI/4.0 );
  //test_cube.set_rotation( 0,0,0 );

  // Draw loop, probably could be done better
  for ( int i = 0; i < 1e5; i++ ){
  
    // draw objects ( should compress these to an array )
    //test_sphere.draw( );
    //test_cube.set_rotation( i/20.0, 0.0, 0.0);  
    
    o_torus.draw( i/20.0, i/20.0 );
    //test_cube.set_rotation( i/20.0, i/20.0, 0.0);  
    test_cube.set_rotation( i/20.0, i/20.0, 0.0);  
    test_cube.draw();
    test_cylinder.set_rotation( i/20.0, i/20.0, 0.0);  
    test_cylinder.draw();

    // draw the 'frame'
    //terminal.draw_frame();
    terminal.draw_block_frame();

    std::this_thread::sleep_for( 25ms );
    //std::this_thread::sleep_for( 25ms );
    //std::this_thread::sleep_for( 16ms );


  }

  return 0;
}

// ONLY NEED TO GENERATE SURFACE POINTS ONCE, CAN BE DONE AT CREATION TIME AND THEN 
// THE OBJECT SHOULD JUST ITERATE THROUGH THOSE POINTS THAT MATCH >> MASSIVE SPEEDUP
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
