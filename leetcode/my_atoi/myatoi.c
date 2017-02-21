#include <stdio.h>
#include <math.h>

int my_atoi(char* str)
{
    unsigned int output = 0, max = 0x7fffffff;
    int i = 0;
    char *p = str;
    int integer_flag = 1;

    while (*p) {
        if ( *p == ' ' && i == 0) {
            p++;
            continue;
        }
        if ( 0 == i ) {
            if ( *p == '-') {
                integer_flag = -1;
                max = 0x80000000;
                i++;
                p++;
                continue;
            }
            else if ( *p == '+' ) {
                i++; p++;
                continue;
            }
        }

        if (*p >= '0' && *p <= '9') {
            if ( output > max/10 ) {
                output = max;
                return (int)output;
            }
            else if ( output == max/10 && ((unsigned int)(*p - '0') > max%10)) {
                output = max;
                return (int)output;
            }
            else {
                int temp;
                temp = (unsigned int)(*p - '0');
                output = output*10 + temp;
            }
        }
        else
            break;

        p++; i++;
    }
    return ((int)output)*(integer_flag);
}

int main()
{
    unsigned int a = 0x80000000;
    char str[]="2147483648";
    printf("1234 = %d; \n", my_atoi(str));
    printf("1234 = %d; \n", atoi(str));
    printf("0x7fffffff = %d; \n", 0x7fffffff);
    printf("0x7fffffff = %d; \n", (int)a);
    return 0;
}
