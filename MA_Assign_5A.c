/*
Calculate pi using efficient Monte Carlo method as discussed in class:
– Estimate the number of Monte Carlo points needed to get 2, 4, 8 and 16 decimal
places of accuracy (average of several executions)
– What would be the effect of using single precision vs double precision for your
calculations?
– Comment on your results
*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    double i ;                                              //declare i
    double x,y ;                                            //declare x and y
    double N=1000 ;                                         //declare N (how many points there are)
    double C=0,S=0;                                         //declare C & S (# of points in circle/square)
    double Pi ;                                             //declare Pi (approximate value for pi from Monte Carlo)
    double Ea,Er ;                                          //declare Error (difference between pi and approx)
    double PI=4.*atan(1.) ;                                 //Declare pi
//Computations
    for (i=1;i<N;i++) {                                     //for loop to generate N points for copmutation
        x=(double)rand()/(double)RAND_MAX ;                 //Generate random numbers between 0 to 1
        y=(double)rand()/(double)RAND_MAX ;                 //Generate random numbers between 0 to 1
        if (pow(x,2)+pow(y,2)<=1) {
            C=C+1 ;                                         //Increase C by one for each point in circle
        }
    S=S+1 ;                                                 //Increase S by one for each point (all points will be in square)
    }
    Pi=4*C/S ;                                              //Approximate Pi from Monte Carlo
    Ea=fabs(PI-Pi) ;                                         //Calculate abs error in Pi
    Er=fabs(PI-Pi)/PI ;                                      //Calculate relative error in Pi

//Print Values
    printf("\nNumber of points used is %.0lf",N) ;            //Print the number of points used
    printf("\nApproximate value for Pi is %.8lf",Pi) ;      //Print the approximate value of Pi
    printf("\nAbsolute error is %.16lf",Ea) ;               //Print the absolute error
    printf("\nRelative error is %.16lf",Er) ;               //Print the relative error
    printf("\nPI is %.16lf",PI) ;               //Print the relative error
    
return 0;
}