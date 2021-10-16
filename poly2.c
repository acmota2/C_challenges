#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double defrac(char*);

int main(int argc, char* const* argv) {
    if (argv[1][1] == 'h') {
        puts("Nesta calculadora o input deve ser: poly2 a b c, em que a, b e c pode ser fracionario");
        return 0;
    }
    // a
    char* buffer = strchr(argv[1],'\0');
    double a = (!strchr(argv[1], '/')) ? strtod(argv[1], &buffer) : defrac(argv[1]);
    // b
    buffer = strchr(argv[2],'\0');
    double b = (!strchr(argv[2], '/')) ? strtod(argv[2], &buffer) : defrac(argv[2]);
    // c
    buffer = strchr(argv[3],'\0');
    double c = (!strchr(argv[3], '/')) ? strtod(argv[3], &buffer) : defrac(argv[3]);

    int nroots = 0;
    double det = pow(b, 2) - (4 * a * c);

    if (det > 0) {
        nroots = 2;
    }
    else if (!det) {
        nroots = 1;
    }
    if (nroots) {
        double roots[2] = { (0-b - sqrt(det)) / (2*a), (0-b + sqrt(det)) / (2*a) };
        while(nroots) {
            printf("%g ", roots[nroots - 1]);
            nroots--;
        }
        putchar('\n');
    }
    else {
        puts("Nao e real");
    }
    return 0;
}

double defrac(char* to_defrac) {
    char *next = strchr(to_defrac,'/');
    char *end = strchr(to_defrac,'\0');
    double a = strtod(to_defrac, &next);
    double b = strtod(next + 1, &end);
    return a / b;
}