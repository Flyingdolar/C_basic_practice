#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Input
    int a, b, c, d, e;
    int surf, volu;

    // Read
    printf("請輸入長方體的長寬高(length width height)：");
    scanf("%d %d %d",&a ,&b ,&c);
    printf("請輸入內縮寬度與深度(shortage depth)：");
    scanf("%d %d",&e ,&d);
    
    e = 2 * e;

    // Volume
    volu = a * b * c;
    volu -= ((a-e) * (c-e) + (b-e) * (c-e) + (a-e) * (b-e)) * d * 2;

    // Surface
    surf = 2 * (a*b + b*c + a*c);
    surf += 8 * ((a-e) + (b-e) + (c-e)) * d;

    // Output
    printf("它的體積是：%d\n",volu);
    printf("它的表面積是：%d\n",surf);

    return 0;
}


