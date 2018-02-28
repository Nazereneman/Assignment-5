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
    double N=1 ;                                            //declare N (how many points there are)
    double C=0,S=0;                                         //declare C & S (# of points in circle/square)
    double Pi ;                                             //declare Pi (approximate value for pi from Monte Carlo)
    double Ea=1,Er ;                                        //declare Error (difference between pi and approx)
    double PI=4.*atan(1.) ;                                 //Declare pi
    double var=0 ;                                          //Declare variable to check for first time correct decimal places
//Computations
while (Ea>=pow(10,-16)){
    for (i=0;i<N;i++) {                                     //for loop to generate N points for copmutation
        x=(double)rand()/(double)RAND_MAX ;                 //Generate random numbers between 0 to 1
        y=(double)rand()/(double)RAND_MAX ;                 //Generate random numbers between 0 to 1
        if (pow(x,2)+pow(y,2)<=1) {
            C=C+1 ;                                         //Increase C by one for each point in circle
        }
    S=S+1 ;                                                 //Increase S by one for each point (all points will be in square)
    }
    Pi=4*C/S ;                                              //Approximate Pi from Monte Carlo
    Ea=fabs(PI-Pi) ;                                        //Calculate abs error in Pi
    Er=fabs(PI-Pi)/PI ;                                     //Calculate relative error in Pi
    if (Ea<=pow(10,-3) & var<=0){                                       //Condition to get 2 decimal points of accuracy
    printf("\nNumber of points to get 2 decimal places is %.0lf",N);    //Print the Number of points to get 2 decimal points
    var=var+1 ;                                                         //Increase variable as to only show the first time 2 decimal points of accuracy
    }
    else if (Ea <= pow(10,-5) & var<=1){                                //Condition to get 4 decimal points of accuracy
    printf("\nNumber of points to get 4 decimal places is %.0lf",N);    //Print the Number of points to get 4 decimal points
    var=var+1 ;                                                         //Increase variable as to only show the first time 4 decimal points of accuracy
    }
    else if (Ea <= pow(10,-9) & var<=2) {                               //Condtiion to get 8 decimal points of accuracy
    printf("\nNumber of points to get 8 decimal places is %.0lf",N);    //Print the number of points to get 8 decimal points
    var=var+1 ;                                                         //Increase variable as to only show the first time 8 decimal points of accuracy
    }
    else if (Ea <= pow(10,-17) & var<=3){                               //Condtion to get 16 decimal points of accuracy
    printf("\nNumber of points to get 16 decimal places is %.0lf",N);   //Print the number of points to get 16 decimal points
    var=var+1 ;                                                         //Increase variable as to only show the first time 16 decimal points of accuracy
    }
N=N+1 ;                                                     //Increase N by one every loop
}
//Print Values
    printf("\nApproximate value for Pi is %.8lf",Pi) ;      //Print the approximate value of Pi
    printf("\nAbsolute error is %.16lf",Ea) ;               //Print the absolute error
    printf("\nRelative error is %.16lf",Er) ;               //Print the relative error
    printf("\nPI is %.16lf",PI) ;               //Print the relative error
    
return 0;
}



