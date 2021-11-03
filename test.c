#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a = 3.14;
    scanf("%f",&a);
    if(a<0)
        a = 0.000000 - a;
    printf("%f\n",a);
    return 0;
}
