//  file: quadratic_equation_1a.cpp
// 
//  Program to calculate roots of a quadratic equation:
//      a*x^2 + b*x + c = 0
//   as an illustration of subtractive cancellation errors
//   [THIS VERSION IS NOT DEBUGGED OR FORMATTED!!!!]
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      01/04/04  original version, converted quadratic_equation_1.c
//
//  Notes:
//   * Based on discussion in section 3.4 of Landau/Paez, "Computational
//      Physics"
//   * First pass: no subroutine, calculate all roots, read in a,b,c
//   * Use single precision
//
//  To do:
//   * pick out the best roots
//   * make it into a subroutine
//   * add double precision
//************************************************************************ 


// include files
#include <iostream>		// note that .h is omitted
#include <cmath>
#include <iomanip> //Error fixed, missing import
using namespace std;	// we need this when .h is omitted

//*********************************************************************//

main () {
float a, b, c;                // coefficients of quadratic equation 

cout << endl
  << "Calculation of quadratic equation roots in single precision"
  << endl << endl;

cout << "Enter a, b, c: [with spaces between, followed by <return>] ";
  cin >> a >> b >> c;

cout << "a = " << a << ", b = " << b << ", c = " << c << endl; //Error fixed, added the c in cout

float disc = pow (b * b - 4. * a * c, 0.5); // definition of discriminant 
											//Error fixed, needed the float to make it a declaration

float x1 = (-b + disc) / (2. * a);      // first root, standard formula 
float x1p = -2. * c / (b + disc);    // first root, new formula 
float x2 = (-b - disc) / (2. * a);        // second root, standard formula 
float x2p = (-2. * c) / (b - disc);   // second root, new formula 

cout << "     first root             second root  " << endl;
cout << fixed << setprecision (16) << x1 << "   " << x2 << endl;
cout << fixed << setprecision (16) << x1p << "   " << x2p << endl;//Error fixed, added the p's to show both values, also spruced up formatting

return (0);
}
