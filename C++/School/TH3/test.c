#include <stdio.h>
#include <math.h>

/* Arrange systems of linear
   equations to be solved in
   diagonally dominant form
   and form equation for each
   unknown and define here
*/
/* In this example we are solving
   3x + 20y - z = -18
   2x - 3y + 20z = 25
   20x + y - 2z = 17
*/
/* Arranging given system of linear
   equations in diagonally dominant
   form:
   20x + y - 2z = 17
   3x + 20y -z = -18
   2x - 3y + 20z = 25
*/
/* Equations:
   x = (17-y+2z)/20
   y = (-18-3x+z)/20
   z = (25-2x+3y)/20
*/
/* Defining function */
#define f1(x, y, z, t) (5.9 - 1.6 * y - 1.2 * z - 1.3 * t) / 1.4
#define f2(x, y, z, t) (5.8 - 1.5 * x - 1.3 * z - 1.2 * t) / 1.4
#define f3(x, y, z, t) (5.81 - 1.2 * x - 1.3 * y - 1.5 * t) / 1.4
#define f4(x, y, z, t) (6.06 - 1.3 * x - 1.2 * y - 1.7 * z) / 1.4
#define e 0.00001

/* Main function */
int main()
{
   float x0 = 0, y0 = 0, z0 = 0, t0 = 0, x1, y1, z1, t1, e1, e2, e3, e4;
   int count = 1;
   system("clear");
   printf("Tolerable error: %f", e);

   printf("\nCount\tx\ty\tz\tt\n");
   do
   {
      /* Calculation */
      x1 = f1(x0, y0, z0, t0);
      y1 = f2(x1, y0, z0, t0);
      z1 = f3(x1, y1, z0, t0);
      t1 = f4(x1, y1, z1, t0);
      printf("%d\t%0.4f\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1, t1);

      /* Error */
      e1 = fabs(x0 - x1);
      e2 = fabs(y0 - y1);
      e3 = fabs(z0 - z1);
      e3 = fabs(t0 - t1);

      count++;

      /* Set value for next iteration */
      x0 = x1;
      y0 = y1;
      z0 = z1;
      t0 = t1;

   } while (e1 > e && e2 > e && e3 > e && e4 > e);

   printf("\nSolution: x=%0.3f, y=%0.3f, z = %0.3f and t = %0.3f\n", x1, y1, z1, t1);
   return 0;
}