//  integ3.h contains the prototypes for integration functions
//
//  Revision History:
//    07-03-2021--- original version, based on integ_routines.h by Dick Furnstahl  furnstahl.1@osu.edu
//
//************************************************************************
 
extern double simpsons_rule ( int num_pts, double x_min, double x_max, 
                       double (*integrand) (double x) );    // Simpson's rule 

extern double milne_rule ( int num_pts, double x_min, double x_max, 
                       double (*integrand) (double x) );    // Milne's rule 
