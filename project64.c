#include <stdio.h>
#include <math.h>

void input(int *a, int *b, int *c);
void computeRoots(int a, int b, int c);

int main() 
{
    int a, b, c;
    input(&a, &b, &c);
    computeRoots(a, b, c);
    return 0;
}

    void input(int *a, int *b, int *c) 
    {
        printf("Enter (a, b, c) of the quadratic equation (ax^2 + bx + c = 0)\n");
        printf("a: ");
        scanf("%d", a);
        printf("b: ");
        scanf("%d", b);
        printf("c: ");
        scanf("%d", c);
    }

    void computeRoots(int a, int b, int c) 
    {
        if (a == 0 && b == 0) {
            printf("No solution: Both a and b are zero.\n");
        } else if (a == 0) {
        //only one root (-c / b)
        double root = -(double)c / b;
        printf("One root: x = %lf\n", root);
        } else {
        //calculate discriminant
        double discriminant = b * b - 4 * a * c;
        if (discriminant < 0) {
            printf("No real roots: Discriminant is negative.\n");
        } else {
            //calculate roots using the quadratic formula
            double sqrt_discriminant = sqrt(discriminant);
            double x1 = (-b + sqrt_discriminant) / (2 * a);
            double x2 = (-b - sqrt_discriminant) / (2 * a);

            printf("Root 1 = %.2lf\nRoot 2 = %.2lf\n", x1, x2);
            }
        }
    }
