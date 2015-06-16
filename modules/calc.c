#include <stdio.h>
#include <stdlib.h>

int main ( int argc, char **argv )
{
    int x = 26;
    puts("Hello CMake");
    fprintf(stdout, "Square of %d is %d\n", x, x*x);

    exit(EXIT_SUCCESS);
}
