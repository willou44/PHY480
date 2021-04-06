//  file: gsl_spline_test_class.cpp
// 
//  Test program for the gsl spline routines using the Spline class
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02/10/09 -- created from gsl_cubic_spline_test.cpp
//
//  Notes:
//   * uses the GSL interpolation functions (see online documentation) 
//
//*****************************************************************
// include files
#include <iostream>    // cout and cin
#include <iomanip>     // manipulators like setprecision
#include <cmath>
#include <string>     // C++ strings                                 
using namespace std;    
#include "GslSpline.h"  // Header file for the GSL Spline class
#include <fstream>
inline double sqr (double z) {return z*z;}  // inline function for z^2

int
main(void)
{

    int npts = 9;
    double x_values[npts] = { 0., 25., 50., 75., 100., 125., 150., 175., 200. };
    double y_values[npts] = { 10.6, 16.0, 45.0, 85.5, 52.8, 19.9, 10.8, 8.25, 4.7 };
    double x_calc[40];
    double y_calc[40];
    double sigma_0 = 63900.;

    x_calc[0] = 0.;
    y_calc[0] = sigma_0 / ((-78.) * (-78.) + 756.25);

    for (int i = 1; i < 41; i++) {
        x_calc[i] = i*5.;
        y_calc[i] = sigma_0 / ((x_calc[i] - 78.) * (x_calc[i] - 78.) + 756.25);
        //                   E_r      E_r     gamma^2/4
        //cout << x_calc[i] << endl; //testing print
    }

  // Make the spline object
  string type = "cubic";
  Spline my_cubic_spline (x_values, y_values, npts, type);
  Spline my_theo_cubic_spline(x_calc, y_calc, 40, type);

  //double x;
  //cout << "Enter x: ";
 // cin >> x;    // test point 
  cout << x_calc[0] << endl;
  ofstream spline_file;
  spline_file.open("Theoretical_spline_data.dat", ofstream::trunc);
  spline_file << "x" << "       " << "y theoretical" << endl;
  double y[40];
  for (int i = 0; i < 41; i++) {
      y[i] = my_theo_cubic_spline.y(x_calc[i]);
          spline_file << x_calc[i] << "      " << y[i] << endl;

  }

  //spline_file.close();



  // Evaluate the spline and derivatives
  /*double y = my_cubic_spline.y (x);
  double y_deriv = my_cubic_spline.yp (x);
  double y_deriv2 = my_cubic_spline.ypp(x);
  double x_sq = sqr(x);
  cout << "    x     y_exact   y_spline   y'_exact  y'_spline";
  cout << "  y''_exact  y''_spline" << endl;
  cout << fixed << setprecision(6) 
       << x << "  " << sin(x_sq) << "  " <<  y << "  "
       <<  2.*x*cos(x_sq) << "  " << y_deriv << "  "
       <<  -4.*x_sq* sin(x_sq) + 2.*cos(x_sq) << "  " <<  y_deriv2
       << endl;
*/

  return (0);      // successful completion 
}
