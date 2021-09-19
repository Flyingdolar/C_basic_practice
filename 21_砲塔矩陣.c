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

    int xPos[canon+1], yPos[canon+1], level[canon+1], inPut = 0, num = 0, pos = 0, sum = 0;
    printf("請輸入該腹地砲台散佈情況與每行要升級降級的數字：（數值代表砲台等級，0 代表該區域沒有砲台）\n");
    printf("舉例來說：\n 0 0 3 1\n 0 3 0 -1\n 3 0 0 1\n表示有3台等級3的砲台在3x3的腹地分佈情況，以及每行要升級與降級的數字\n");

    for (int i = 0; i < row; i++){
        for(int j = 0; j <= col; j++){
            scanf("%d",&inPut);
            if(j == col){
                sum /= col;
                sum /= 2;
                while(pos < num){
                    level[pos] += inPut * sum;
                    level[pos] = level[pos] < 0 ? 0 : level[pos];
                    pos++;
                }
                sum = 0;
            }else if(inPut){
                xPos[num] = i;
                yPos[num] = j;
                level[num] = inPut;
                sum += inPut;
                num++;
            }
        }
    }

    printf("輸出結果：\n");
    pos = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(xPos[pos] == i && yPos[pos] == j){
                printf("%d",level[pos]);
                pos++;
            }else{
                printf("0");
            }
            if(j != col)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}