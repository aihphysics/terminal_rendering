#include <math_funcs.hxx>

float fast_inv_square( float n ){

  const float three_halfs = 1.5F;
  float y = n;

  // clever cast
  long i = * ( long * ) &y;

  // dark magic
  i = 0x5f3759df - ( i >> 1 );

  // clever cast
  y = * ( float * ) &i;

  // iterate NR
  y = y * ( three_halfs - ( ( n * 0.5F ) * y * y ) );
  y = y * ( three_halfs - ( ( n * 0.5F ) * y * y ) );

  return y;

}

float faster_inv_square( float n ){

  const float three_halfs = 1.5F;
  float y = n;

  // clever cast
  long i = * ( long * ) &y;

  // dark magic
  i = 0x5f3759df - ( i >> 1 );

  // clever cast
  y = * ( float * ) &i;

  // iterate NR
  y = y * ( three_halfs - ( ( n * 0.5F ) * y * y ) );

  return y;

}
