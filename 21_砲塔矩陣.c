#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){

    int row, col;
    int canon;
    printf("請輸入腹地大小（有幾行/有幾列）：");
    scanf("%d %d",&row ,&col);
    printf("請輸入腹地中有幾座炮台：");
    scanf("%d",&canon);

    int xPos[canon+1], yPos[canon+1], level[canon+1], inPut = 0, num = 0;
    printf("請輸入該腹地砲台散佈情況：（數值代表砲台等級，0 代表該區域沒有砲台）\n");
    printf("舉例來說：\n 0 0 3\n 0 3 0\n 3 0 0\n表示有3台等級3的砲台在3x3的腹地分佈情況\n");

    for (int i = 0; i < row; i++){
        for(int j = 0; j <= col; j++){
            scanf("%d",&inPut);
            if(j == col){
                switch (i){
                case 0:
                    xPos[canon] = inPut;
                    break;
                case 1:
                    yPos[canon] = inPut;
                    break;
                case 2:
                    level[canon] = inPut;
                    break;
                }
            }else if(inPut){
                xPos[num] = i;
                yPos[num] = j;
                level[num] = inPut;
                num++;
            }
        }
    }
    
    return 0;
}