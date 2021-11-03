1
Thomas
3
5 5
4 4
3 3
1
Mark
2
-3 6
-2.5 4
1
John
4
6 6
7 4
5 1
-2 0

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
