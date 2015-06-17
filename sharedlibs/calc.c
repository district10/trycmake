#include <stdio.h>
#include <stdlib.h>
#include "square.h"
#include "cubic.h"

int main ( int argc, char **argv )
{
    double x = 9.8;
    fprintf(stdout, "Square of %5.2f is %10.6f\n", x, square(x));
    fprintf(stdout, "Cubic  of %5.2f is %10.6f\n", x, cubic(x));

    getchar();
    exit(EXIT_SUCCESS);
}