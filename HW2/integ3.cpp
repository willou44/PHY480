//  integ3.cpp contains three integration functions, simpson, milne, and 
//
//  Revision History:
//    07-03-2021--- original version, based on integ_routines.cpp by Dick Furnstahl  furnstahl.1@osu.edu
//
//************************************************************************

#include <cmath>
#include "integ3.h"	// prototypes for integration routines

// Integration using Simpson's rule
double simpsons_rule ( int num_pts, double x_min, double x_max, 
                      double (*integrand) (double x) )
{  
   double interval = ((x_max - x_min)/double(num_pts - 1));  // called h in notes
   double sum=  0.;  // initialize integration sum to zero		 
   
   for (int n=2; n<num_pts; n+=2)                // loop for odd points  
   {
     double x = x_min + interval * double(n-1);
     sum += (4./3.)*interval * integrand(x);
   }
   for (int n=3; n<num_pts; n+=2)                // loop for even points  
   {
     double x = x_min + interval * double(n-1);
     sum += (2./3.)*interval * integrand(x);
   }   
   // add in the endpoint contributions   
   sum +=  (interval/3.) * (integrand(x_min) + integrand(x_max));	
   
   return (sum);
}  

double milne_rule ( int num_pts, double x_min, double x_max, 
                       double (*integrand) (double x) )
{
   double interval = ((x_max - x_min)/double(num_pts + 2));  // called h in notes
   double sum=  0.;  // initialize integration sum to zero		 
   
   for (int n=0; n<num_pts; n+=2)                // loop for odd points  
   {
     double x = x_min + (interval + 1.) * double(n+1);
     sum += (8./3.)*interval * integrand(x);
   }
   for (int n=1; n<num_pts; n+=2)                // loop for even points  
   {
     double x = x_min + interval * double(n-1);
     sum -= (4./3.)*interval * integrand(x);
   }   
   //sum +=  (4*interval/3.) * 2*(integrand(x_min) + integrand(x_max));   
   return (sum);
}      

//************************************************************************
