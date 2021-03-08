#include <iostream>
#include <iomanip>
#include <fstream>
//  integ3_test.cpp contains testing code for integ3.cpp
//
//  Revision History:
//	07-03-2021: original version, based on integ_test.cpp by Dick Furnstahl  furnstahl.1@osu.edu
//	08-03-2021: Added full milne function	
//************************************************************************


#include <cmath>

using namespace std;

#include "integ3.h"	// prototypes for integration routines

double my_integrand (double x);

//************************************************************************

int
main ()
{
  // set up the integration specifiction
  const int max_intervals = 501;	// maximum number of intervals
  const double lower = 0.0;	// lower limit of integration
  const double upper = 1.0;	// upper limit of integration

  double result = 0.;  // approximate answer

  // open the output file stream
  ofstream integ_out ("integ3.dat");	// save data in integ3.dat
  integ_out << "#  N   Simpsons      Milnes" << endl;
  integ_out << "#-----------------------------------------" << endl;

  //Both Simpson's and Milne's rule requires an odd number of intervals  
  for (int i = 3; i <= max_intervals; i += 2)
  {
    integ_out << setw(4) << i;

    result = simpsons_rule (i, lower, upper, &my_integrand);
    integ_out << "  " << scientific << fabs (result);

    result = milne_rule (i, lower, upper, &my_integrand);
    integ_out << "  " << scientific << fabs (result);

    integ_out << endl;
  }

  cout << "data stored in integ3.dat\n";
  integ_out.close ();

  return (0);
}

//************************************************************************

// the function we want to integrate 
double
my_integrand (double x)
{
  return (exp(exp(4*x/3)));
}
