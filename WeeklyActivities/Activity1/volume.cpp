//  file: volume.cpp
//
//  This program calculates the volume of a sphere given the radius.
//
//  Programmer:  Cameron Willoughby, based on area.cpp by Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02-Jan-2004  original version of area.cpp, for 780.20 Computational Physics
//      01-Jan-2010  updates to "To do" wishlist
//      12-Jan-2016  comment out "using namespace std;"
//	20-Jan-2021  Modified into volume.cpp
//
//  Notes:  
//   * compile with:  g++ -o volume.exe volume.cpp
//
//  To do:

//
//*********************************************************************// 

// include files
#include <iostream>	     // this has the cout, cin definitions
using namespace std;     // if omitted, then need std::cout, std::cin 

//*********************************************************************//

const double pi = 3.1415926535897932385;   // define pi as a constant 

int
main ()
{
  double radius;    // every variable is declared as int or double or ...

  cout << "Enter the radius of a sphere: ";	// ask for radius
  cin >> radius;

  double area = pi * radius * radius;	// standard area formula

  double volume = 4.0 * radius * area / 3.0; // standard volume formula

  cout << "radius = " << radius << ",  volume = " << volume << endl;

  return 0;			// "0" for successful completion
}

//*********************************************************************//
