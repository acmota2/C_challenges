#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* const* argv) {
    int result = 0;
    if (!argc) {
        puts("O comando deve ser utilizado como 'roman {number}'");
        exit(1);
    }
    for(int i = 0; argv[1][i] != '\0'; i++) {
        switch(argv[1][i]) {
            case 'C':
                if (argv[1][i+1] == 'M') {
                    result += 900;
                    i++;
                }
                else if (argv[1][i+1] == 'D') {
                    result += 400;
                    i++;
                }
                else {
                    result += 100;
                }
                break;
            case 'M':
                result += 1000;
                break;
            case 'D':
                result += 500;
                break;
            case 'L':
                result += 50;
                break;
            case 'I':
                if (argv[1][i+1] == 'X') {
                    result += 9;
                    i++;
                }
                else if (argv[1][i+1] == 'V') {
                    result += 4;
                    i++;
                }
                else {
                    result += 1;
                }
                break;
            case 'X':
                if (argv[1][i+1] == 'C') {
                    result += 90;
                    i++;
                } 
                else if (argv[1][i+1] == 'L') {
                    result += 40;
                    i++;
                }
                else {
                    result += 10;
                }
                break;
            case 'V':
                result += 5;
                break;
            default:
                puts("O input deve conter apenas os seguintes carateres:\nM, D, C, L, X, V, I");
                exit(1);
        }
    }
    printf("%d\n", result);
    return 0;
}