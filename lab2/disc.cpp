#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;

    scanf("%f %f %f", &a, &b, &c);
    // a = 4;
    // b = 10;
    // c = 25;

    double first_root, second_root;

    double d = pow(b, 2) - 4 * a * c;

    if (d == 0)
    {
        first_root = -b / (2 * a);

        printf("roots = %0.1f\n", first_root);
    }
    else if (d > 0)
    {
        first_root = (-b + sqrt(d)) / (2 * a);
        second_root = (-b - sqrt(d)) / (2 * a);

        printf("first root = %0.1f and second root = %0.1f\n", first_root, second_root);
    }
    else
    {
        double complex_discriminant = -pow(b, 2) + 4 * a * c;
        double complex_part = sqrt(complex_discriminant) / (2 * a);
        double number_part = (-b) / (2 * a);

        printf("first root = %0.1f + %0.1fi\n", number_part, complex_part);
        printf("second root = %0.1f - %0.1fi\n", number_part, complex_part);
    }
    return 0;
}