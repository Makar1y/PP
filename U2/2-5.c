#include <stdio.h>
#include <math.h>


int main() {
    double x = 1;
    double y = 1;
    double z = 1;

    while (1) {
        if (!x && !y && !z) break;
        double result_1 = 0, result_2 = 0;

        printf("Please Enter 3 numbers(x y z (all zeros to exit)): ");
        if((scanf("%lf %lf %lf", &x, &y, &z) == 3) && (getchar() == '\n')) {
            double z_module = (z<0) ? z + z * -2 : z;
            double z3 = z * z * z;
            double z4 = z * z * z * z;

            result_1 = x + 4 * y + z3;
            result_2 = (x + sqrt(y)) * (z4 - z_module + 46.3);

            printf("x + 4y + z^3 = %lf\n", result_1);
            (y >= 0) ? printf("(x + y^0.5)(z^4 - |z| + 46.3) = %lf\n\n\n", result_2) : printf("(x + y^0.5)(z^4 - |z| + 46.3) = Error(A square root cannot be negative : sqrt(%lf))\n\n\n", y) ;
        } else {
            printf("    Invalid input, try again...\n");
            while(getchar() != '\n')
                ;
        }
    }
    
    return 0;
}