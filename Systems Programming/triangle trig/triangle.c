/* Stephen Terrio, B00755443 */

#include <stdio.h>
#include <math.h>
#include "triangle.h"

// Order: Opp. Adj. Hyp. Angle X, Angle Y ;
double findOppositePyth(double x, double y, double z, double k){
  // a^2 + b^2 = c^2 .. therefore, a^2 = c^2 - b^2
  double opposite = pow(y,2) - pow(x,2);
  opposite = sqrt(opposite);
  printS(opposite, x, y, z, k);
}

double findAdjacentPyth(double x, double y, double z, double k){
  // b^2= c^2 - a^2...
  double adjacent = pow(y,2) - pow(x,2);
  adjacent = sqrt(adjacent);
  printS(x, adjacent, y, z, k);
}

double findHypotenusePyth(double x, double y, double z, double k){
  double hyp = pow(x,2) + pow(y,2);
  hyp = sqrt(hyp);
  printS(x, y, hyp, z, k);
}

/* Switching to Trig identities, SOHCAHTOA */
double findOppositeTrig(double x, double y, double z, double k){
  // SOH
  double opposite = sin(z)*y;
  printS(opposite, x, y, z, k);
}

double findAdjacentTrig(double x, double y, double z, double k){
  // CAH
  double adjacent = cos(z)*y;
  printS(x, adjacent, y, z, k);
}


double findHypotenuseTrig(double x, double y, double z, double k){
  // SOH
  double hyp = x/sin(z);
  printS(x, y, hyp, z, k);
}

/* Creating function for universal use of printf */
double printS(double opp, double adj, double hyp, double x, double y){
  printf("\nopposite = %.2f\nadjacent = %.2f\nhypotenuse = %.2f\nx = %.2f\ny = %.2f\n\n", opp, adj, hyp, x, y);
}
