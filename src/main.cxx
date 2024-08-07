#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <chrono>
#include <math.h>
#include <thread>

#include <obj.hxx>
#include <screen.hxx>
#include <vec.hxx>

#include <getopt.h>

using namespace std::chrono_literals;

int main(int argc, char * argv[], char * env[]){

  static struct option long_options[] = {
    { "fps",      required_argument,    0,    'f' },
    { "level",    required_argument,    0,    'l' },
    { "K1",       required_argument,    0,    'r' },
    { "K2",       required_argument,    0,    'z' },
    { "height",   required_argument,    0,    'h' },
    { "width",    required_argument,    0,    'w' },
    { "objects",  required_argument,    0,    'o' }
  };



  int option_index{0}, option{0};
	int frame_goal = 10;

  // 1 for surfaces, 2 for edges, 3 for vertices;
  int draw_level = 1;

  // Advised to add exports to your .bashrc for expediancy, getopt inbound
  int screen_columns  = std::atoi(std::getenv("COLUMNS"));
  int screen_lines = std::atoi(std::getenv("LINES"));

  // doubled height for half block rendering
  int screen_height = screen_lines*2;
  int screen_width = screen_columns;

  // constants for projection 
  // 50 is flat, 2 is tolerable, 1.0 is dizzying
  float K2 = 25.0;
  float K1 = screen_height*K2*(1/0.8);
  
  std::string obj_filepath = "";

	do {
		option = getopt_long( argc, argv, "f:l:r:z:h:w:o:", long_options, &option_index);
		switch (option){
    	case 'f':
				frame_goal    = atoi(optarg);
				break;
    	case 'l':
        draw_level    = atoi(optarg);
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
      case 'o':
        obj_filepath = std::string(optarg);
				break;
		}
  } while ( option != -1 );

	float max_pause_length = 1000.0/frame_goal;

  // Screen object, essentially a canvas.
  screen terminal( K1, K2, screen_width, screen_height );

  // test box
  obj box = obj( obj_filepath );
  box.set_position( 0, 0, 100 );


  // Draw loop, probably could be done better
  auto goal_time = std::chrono::milliseconds( (int) max_pause_length);
  for ( int i = 0; i < 1e5; i++ ){
  
		auto start = std::chrono::high_resolution_clock::now();

    // rotate the box
    box.set_rotation( i/20.0, i/20.0, 0 );

    // draw the box
    terminal.draw( box );

    // draw the 'frame'
    terminal.draw_frame();

    // accumulator reduction
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::high_resolution_clock::now() - start) ;
    if ( ( goal_time - duration ).count() > 0 ){
      std::this_thread::sleep_for( goal_time - duration );
    }
  
	}

  return 0;
}
