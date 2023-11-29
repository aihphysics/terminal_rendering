#include <main.hxx>

//#include <iostream>

using namespace std::chrono_literals;

int main(int argc, char * argv[], char * env[]){

  static struct option long_options[] = {
    { "fps",    required_argument,    0,    'f' },
    { "level",  required_argument,    0,    'l' },
    { "K1",     required_argument,    0,    'r' },
    { "K2",     required_argument,    0,    'z' },
    { "height", required_argument,    0,    'h' },
    { "width",  required_argument,    0,    'w' }
  };

  int option_index{0}, option{0};
	int frame_goal = 24;


  // Advised to add exports to your .bashrc for expediancy, getopt inbound
  int screen_columns  = std::atoi(std::getenv("COLUMNS"));
  int screen_lines = std::atoi(std::getenv("LINES"));

  // doubled height for half block rendering
  int screen_height = screen_lines*2;
  int screen_width = screen_columns;

  // constants for projection 
  // 50 is flat, 2 is tolerable, 1.0 is dizzying
  float K2 = 5.0;
  float K1 = screen_height*K2*(1/0.8);

	do {
		option = getopt_long( argc, argv, "f:r:z:h:w:", long_options, &option_index);
		switch (option){
    	case 'f':
				frame_goal    = atoi(optarg);
				break;
      case 'r':
        K1            = atof(optarg);
				break;
      case 'z':
        K2            = atof(optarg);
				break;
      case 'w':
        screen_width  = atoi(optarg);
				break;
      case 'h':
        screen_height = atoi(optarg);
				break;
		}
  } while ( option != -1 );

	float max_pause_length = 1000.0/frame_goal;

  // Screen object, essentially a canvas.
  screen terminal( K1, K2, screen_width, screen_height );

  auto goal_time = std::chrono::milliseconds( (int) max_pause_length);
  for ( int i = 0; i < 1e5; i++ ){
  
		auto start = std::chrono::high_resolution_clock::now();

    // draw the 'frame'
    terminal.draw_frame();

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::high_resolution_clock::now() - start) ;
    if ( ( goal_time - duration ).count() > 0 ){
      std::this_thread::sleep_for( goal_time - duration );
    }


	}

	//double iteration_time = std::accumulate( timings.begin(), timings.end(), 0 );
	//double average_time = iteration_time/(double) timings.size();
  //std::cout << "Total iteration time: " << iteration_time << " (us)" << std::endl;
  //std::cout << "Avg frame :           " << average_time << " (us)" << std::endl;

  return 0;
}














// ONLY NEED TO GENERATE SURFACE POINTS ONCE, CAN BE DONE AT CREATION TIME AND THEN 
// THE OBJECT SHOULD JUST ITERATE THROUGH THOSE POINTS THAT MATCH >> MASSIVE SPEEDUP
// IDEAS THAT NEED IMPLEMENTED
// >> I SPENT HOURS REFACTORING AND TOUCHED NONE OF THESE
// PROPER HEADER GUARDS -- DONE
// DISENTANGLE THE TORUS CALCULATIONS -- DONE
// LIGHT SOURCES AS AN ARRAY
// IMPLEMENT LINE -- DONE
// L-BUFFER
// RE-EVALUATE CAMERA AT ORIGIN
// ADD USER CONTROL INPUT ON CAMERA
// CREATE ROTATION OBJECTS -- DONE
// DO LINE ATTACHMENTS
// DO RESOLUTION CALCULATION FOR STEPS -- DONE (ISH)
// for actual stuff, this should be abandoned in favour of opengl
// this is just a toy
//
//// A few object definitions
  //torus o_torus( &terminal, &light_source, 0.4/25.0, 3.0/25.0 );
  //sphere test_sphere( &terminal, &light_source, 0.1, 0.0,  0.0,  0.0 );
  //float cube_size = 0.2;
  ////cube test_cube( &terminal, &light_source, 0.5,  0.0,  0.0, cube_size, cube_size, cube_size );
  //cube test_cube( &terminal, &light_source, 0.0,  0.0,  0.0, cube_size, cube_size, cube_size );

  ////cylinder test_cylinder( &terminal, &light_source, -0.5, 0.0, 0.0, 0.1, 0.3 );
  //cylinder test_cylinder( &terminal, &light_source, 0.0, 0.0, 0.0, 0.1, 0.3 );

  //test_cube.set_level( 1 );
  //cube test_cube( &terminal, &light_source, 0.0,  0.0,  0.0, 0.3, 0.05, 0.1 );
  
  //test_cube.set_rotation( M_PI/4.0, M_PI/4.0 , M_PI/4.0 );
  //test_cube.set_rotation( 0,0,0 );
  
  //line test_line1 = line( &terminal, 0, 0, 0,  0.2,  0.2,  0.2 );  
  //line test_line2 = line( &terminal, 0, 0, 0,  0.2, -0.2,  0.2 );  
  //line test_line3 = line( &terminal, 0, 0, 0, -0.2,  0.2,  0.2 );  
  //line test_line4 = line( &terminal, 0, 0, 0, -0.2, -0.2,  0.2 );  
  //line test_line5 = line( &terminal, 0, 0, 0,  0.2,  0.2, -0.2 );  
  //line test_line6 = line( &terminal, 0, 0, 0,  0.2, -0.2, -0.2 );  
  //line test_line7 = line( &terminal, 0, 0, 0, -0.2,  0.2, -0.2 );  
  //line test_line8 = line( &terminal, 0, 0, 0, -0.2, -0.2, -0.2 ); 
  //line line2 = line( &terminal, 0, 0, 0, 1, -1, -1 );  
  

  //double delta_t = 0;
  //while ( true ){
  //  auto now = std::chrono::high_resolution_clock::now();
  //  now.min
  //}


    //test_sphere.draw();
    
    //test_cylinder.draw();

    //o_torus.draw();

    //test_cube.draw();


    // draw objects ( should compress these to an array )
    //o_torus.draw( i/20.0, i/20.0 );
    //o_torus.draw( );
    //test_cube.set_rotation( i/20.0, i/20.0, 0.0);  
    //o_torus.set_rotation( i/20.0, i/20.0, 0.0);  
    //test_cylinder.set_rotation( i/20.0, i/20.0, 0.0);  
    //test_sphere.set_rotation( i/20.0, i/20.0, 0.0);  
    //test_sphere.draw();
    
    //test_line1.set_rotation( i/20.0, i/20.0, 0.0);
    //test_line2.set_rotation( i/20.0, i/20.0, 0.0);
    //test_line3.set_rotation( i/20.0, i/20.0, 0.0);
    //test_line4.set_rotation( i/20.0, i/20.0, 0.0);
    //test_line5.set_rotation( i/20.0, i/20.0, 0.0);
    //test_line6.set_rotation( i/20.0, i/20.0, 0.0);
    //test_line7.set_rotation( i/20.0, i/20.0, 0.0);
    //test_line8.set_rotation( i/20.0, i/20.0, 0.0);

    //test_line1.draw(); 
    //test_line2.draw();
    //test_line3.draw();
    //test_line4.draw();
    //test_line5.draw();
    //test_line6.draw();
    //test_line7.draw();
    //test_line8.draw();

    // boost oscillation
    //int hundreds = ( i / ( (int) 100 ) );
    //if ( hundreds % 2 == 0 ){
    //  test_cube.set_beta(  (i - 100*hundreds)/100.0 );
    //} else  {
    //  test_cube.set_beta(  ( 99 - ( i - 100*hundreds ) )/100.0 );
    //}

    //test_cube.draw();
