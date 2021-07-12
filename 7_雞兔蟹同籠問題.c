#include <stdio.h>

int main(int argc, char const *argv[])
{
    // Input
    int animalNum, animalFoot, animalTail;
    int chicken, rabbit, crab;

    // Read
    printf("一個籠子關了公雞、兔子、螃蟹...\n");
    printf("動物總數：");
    scanf("%d",&animalNum);
    printf("腳的數量：");
    scanf("%d",&animalFoot);
    printf("尾巴數量：");
    scanf("%d",&animalTail);

    // Crab
    crab = animalNum - animalTail;

    // Rabbit Chicken
    animalNum -= crab;
    animalFoot -= (crab * 8);
    rabbit = (animalFoot / 2) - animalNum;
    chicken = animalNum - rabbit;

    // Output
    printf("雞的數量：%d\n",chicken);
    printf("兔子數量：%d\n",rabbit);
    printf("螃蟹數量：%d\n",crab);
    
    return 0;
}
