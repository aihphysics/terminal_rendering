#include <main.hxx>

#include <sphere.hxx>
#include <thread>
#include <torus.hxx>

using namespace std::chrono_literals;

int main(int argc, char * argv[], char * env[]){


  // create the screen, must have exported shell variables to environment;
  int screen_width  = std::atoi(std::getenv("COLUMNS"));
  int screen_height = std::atoi(std::getenv("LINES"));
  // 50 is flat, 2 is tolerable, 1.0 is dizzying
  float K2 = 1.0;
  float K1 = screen_height*K2*(1/0.8);

  screen terminal( K1, K2, screen_width, screen_height );

  // create and fill buffers
  //char * output = new char[screen_width*screen_height]();
  //float * z_buffer = new float[screen_width*screen_height]();

  // create timers
  //std::chrono::system_clock::time_point start;
  //std::chrono::system_clock::time_point check;
  //double ms;
  //3.3/25 = 0.132


  light light_source( 0.5, 1.0, -1 );
  torus o_torus( &terminal,  0.3/25.0, 6.0/25.0 );
  sphere test_sphere( &terminal, &light_source, 0.1, 0.0,  0.0,  0.0 );
  //sphere left_sphere( &terminal, &light_source, 0.1, 0.3,  0.0,  0.0 );
  //sphere br_sphere( &terminal, &light_source, 0.1, -0.6,  -0.3,  0.0 );
  //sphere fb_sphere( &terminal, &light_source, 0.1, 0.0,  -0.1, -0.3 );
  //sphere test_sphere( &terminal, &light_source, 0.1, 0.0,  0.0,  0.0 );
  //sphere test_sphere( &terminal, &light_source, 0.1, 0.0,  0.0,  0.0 );
  //sphere central_sphere(  3.3/25.0,   0.0,  0.0,  0.0,    &light_source);
  //sphere upper_sphere(    3.3/25.0,   0.0,  0.0,  0.0,    &light_source);
  //sphere lower_sphere(    3.3/25.0,  -0.5,  0.0,  0.0,    &light_source);
  //central_sphere.set_constants(K2);
  //upper_sphere.set_constants(K2);
  //lower_sphere.set_constants(K2);
  //orbiting_torus.set_constants(K2);
  //test_sphere.set_constants(K2);
  //std::vector<renderable*> objects;
  //objects.push_back(&orbiting_torus);
  //objects.push_back(&central_sphere);
  
  //std::thread ex_loop(loop, std::ref(orbiting_torus), std::ref(test_sphere), std::ref(output), std::ref(z_buffer));

  //ex_loop.join();
  //
  for ( int i = 0; i < 1e30; i++ ){
  
    o_torus.draw( i/20.0, i/20.0 );
    test_sphere.draw( );

    terminal.draw_frame();
    std::this_thread::sleep_for( 100ms );

  }

  return 0;
}


//const int screen_x = 237;
//const int screen_y = 57;

//const int screen_x = 421;
//const int screen_y = 109;


//const float K1 = screen_x*K2*3/(8*(R1+R2));
//const float K2 = 1000;

//const float K1 = screen_y*K2*1/0.4;


//void loop(torus & tor, sphere & sph, char (&out)[][], float (&z)[][]){
//void loop(torus & tor, sphere & sph, char &out, float &z){
//
//  for (int i = 0; i < 1e30; i++){
//  
//    tor.draw(out, z,i/20.0,i/20.0);
//    //sph.draw(out, z);
//
//    printf("\x1b[H");
//    for (int j = 0; j < screen_y; j++) {
//      for (int i = 0; i < screen_x; i++) {
//        putchar(out[i][j]);
//      }
//      putchar('\n');
//    }
//
//    // timing;
//    std::this_thread::sleep_for(100ms);
//    // clear
//    std::fill_n(&out[0][0], sizeof(out)/sizeof(out[0][0]), ' ');
//    std::fill_n(&z[0][0], sizeof(z)/sizeof(z[0][0]),0);
//
//  }
//
//}

// clear
    //std::fill_n(&out[0][0], sizeof(out)/sizeof(out[0][0]), ' ');
    //std::fill_n(&z[0][0], sizeof(z)/sizeof(z[0][0]),0);



  
  // start loop
//  for (int i = 0; i < 1e10; i++){
//
//    //for (renderable * obj : objects){
//    //  std::cout << "starts" << std::endl;
//    //  //obj->draw(output,z_buffer);
//    //  //orbiting_torus.draw(output,z_buffer,i/20.0,i/20.0);
//    //}
//    //central_sphere.draw(output, z_buffer);
//    //upper_sphere.draw(output, z_buffer);
//    //lower_sphere.draw(output, z_buffer);
//
//    orbiting_torus.draw(output,z_buffer,i/20.0,i/20.0);
//    test_sphere.draw(output,z_buffer);
//
//    //central_sphere.draw(output,z_buffer);
//    //upper_sphere.draw(output,z_buffer);
//    //lower_sphere.draw(output,z_buffer);
//
//    printf("\x1b[H");
//    for (int j = 0; j < screen_y; j++) {
//      for (int i = 0; i < screen_x; i++) {
//        putchar(output[i][j]);
//      }
//      putchar('\n');
//    }
//
//    // timing loop;
//    start  = std::chrono::high_resolution_clock::now();
//    do{
//      check  = std::chrono::high_resolution_clock::now();
//      ms = std::chrono::duration_cast<std::chrono::milliseconds>(check - start).count();
//    } while ( ms < 100);
//    std::fill_n(&output[0][0], sizeof(output)/sizeof(output[0][0]), ' ');
//	  std::fill_n(&z_buffer[0][0], sizeof(z_buffer)/sizeof(z_buffer[0][0]),0);
//
//  }

 


// IDEAS THAT NEED IMPLEMENTED
// PROPER HEADER GUARDS -- DONE
// DISENTANGLE THE TORUS CALCULATIONS 
// LIGHT SOURCES AS AN ARRAY
// L-BUFFER
// RE-EVALUATE CAMERA AT ORIGIN
// ADD USER CONTROL INPUT ON CAMERA
// CREATE ROTATION OBJECTS
// DO LINE ATTACHMENTS
// DO RESOLUTION CALCULATION FOR STEPS
// ADD
