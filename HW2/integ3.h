//  file: integ_routines.h
// 
//  Header file for integ_routines.cpp
//
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision History:
//    05-Jan-2004 --- original version, based on C version
//    08-Jan-2005 --- function to be integrated now passed, changed names
//    09-Jan-2011 --- changed function names
//
//  To do:
//
//************************************************************************

//  begin: function prototypes 
 
extern double simpsons_rule ( int num_pts, double x_min, double x_max, 
                       double (*integrand) (double x) );    // Simpson's rule 

//  end: function prototypes 
