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
   
   for (int n=2; n<num_pts; n+=2)                // loop for even points  
   {
     double x = x_min + interval * double(n-1);
     sum += (4./3.)*interval * integrand(x);
   }
   for (int n=3; n<num_pts; n+=2)                // loop for odd points  
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
   double interval = ((x_max - x_min)/double(num_pts -1));  // called h in notes
   double sum=  0.;  // initialize integration sum to zero		 
   
   for (int n=2; n<num_pts; n+=4)               //loop for first odds
   {
     double x = x_min + (interval) * double(n-1);
     sum += (24./45.)*interval * integrand(x);
   }

   for (int n=4; n<num_pts; n+=4)               //loop for second odds
   {
     double x = x_min + (interval) * double(n-1);
     sum += (28./45.)*interval * integrand(x);
   }

   for (int n=2; n<num_pts; n+=2)                // loop for even points  
   {
     double x = x_min + interval * double(n-1);
     sum += (64./45.)*interval * integrand(x);
   }   
   sum +=  (14./45.)*interval *(integrand(x_min) + integrand(x_max));   //endpoints
   return (sum);
}      

//************************************************************************
