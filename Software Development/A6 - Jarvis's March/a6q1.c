#include <stdio.h>

/* Main method */
int main (void){

  int num_p;
  scanf("%d",&num_p);

  /* If there's less than 3 point declared, return an Error. */
  if (num_p < 3){
    printf("Error: Definition of a polygon needs 3 or more points");
    return 0;
  }

/* Creating a 2d array to store coordinates & initializing */
  int points[num_p][2];
  int convexhull[num_p][2];

/* initializing them all as zero (must loop for VLA's)*/
  for (int i =0; i < num_p; i ++){
    points[i][0] = 0;
    points[i][1] = 0;
    convexhull[i][0] = 0;
    convexhull[i][1] = 0;
  }

/* Setting the coordinates into the points array */
  for (int i = 0; i < num_p; i ++){

    int tempx,tempy;
    scanf("%d %d", &tempx,&tempy);

    points[i][0] = tempx;
    points[i][1] = tempy;

  }
  /*  Finding the largest y coordinate and putting it as first point in
  convexhull array */
  int highest;
  int pointcord;

  highest = points [0][1];
  for (int i = 0; i < num_p; i++){
    if (points[i][1] > highest){
      highest = points[i][1];
      pointcord = points[i][0];
  }
}
/* Setting the highest coordinate to be the first point in the convexhull */
convexhull[0][0] = pointcord;
convexhull[0][1] = highest;

/* Counter to keep track of # of points that make up the hull */
int pcounter;
pcounter = 1;

/* Find the next clockwise point such that it is counter clock wise to every
other directed line, formula: (x1 − x0)(y2 − y0) − (x2 − x0)(y1 − y0)  */

for (int i = 0; i < num_p; i ++){
  if (convexhull[i][0] == 0){break;}

  for (int j = 0; j < num_p; j ++){

      /* test failure handling */
      int redflag;
      redflag = 0;

      if (points[j][0] == pointcord){ continue;}
      for (int t = 0; t < num_p; t ++ ){

        /* when i & j are equal, skip this step. (No need to compute
       line direction) */
        if (t == j ){continue;}

        /* Calculating if the line is clockwise or counterCW */
        int ccwTest;
        ccwTest = (points[j][0] - convexhull[i][0])*(points[t][1]
        - convexhull[i][1]) - (points[t][0] - convexhull[i][0])*(points[j][1]
        - convexhull[i][1]);


         /* if a test line is clockwise to potential, break. */
         if (ccwTest > 0){redflag = 1; break;}
         if (convexhull[i][0] == points[j][0] &&
           convexhull[i][1] == points[j][1]){redflag = 1; break;}
       }

      /* if test case failed, try next point */
      if (redflag == 1){continue;}
      /* otherwise test success, and point belongs in convexhull */
      if (redflag == 0){
        convexhull[i+1][0] = points[j][0];
        convexhull[i+1][1] = points[j][1];
        pcounter= pcounter+1;
      }
    }
  }
  /* Printing the results */
  printf("%d\n",pcounter);

  for (int i = 0; i < pcounter; i++){
    printf("%d %d\n",convexhull[i][0],convexhull[i][1]);
  }

}
