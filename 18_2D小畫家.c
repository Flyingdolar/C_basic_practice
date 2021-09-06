#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int wallPaper, actions;
    int acts, p1, p2;
    int upcount, decount, set;

    printf("請輸入畫布尺寸：");
    scanf("%d",&wallPaper);
    printf("請輸入操作次數：");
    scanf("%d",&actions);

    int arr[wallPaper];
    for(int i = 0; i < wallPaper; arr[i] = 0, i++);
    printf("請開始操作（1 畫筆 2 橡皮擦 3 顏料桶）");

    while(actions--){
        p1 = 0;
        p2 = 0;
        printf("操作方式：");
        scanf("%d",&acts);
        if(acts < 3){
            scanf(" %d %d",&p1,&p2);
            p1--;
            p2--;
            p1 = p1 < 0 ? 0 : p1;
            p2 = p2 > wallPaper-1 ? wallPaper-1 : p2;
            if (acts - 1)
                for(int i = p1; i <= p2; arr[i] = 0, i++);
            else
                for(int i = p1; i <= p2; arr[i] = 1, i++);
        }else{
            scanf(" %d",&p1);
            p1--;
            if(!(arr[p1])){
                arr[p1] = 1;
                set = p1;
                while(!(arr[++set]) && set < (wallPaper-1))
                    arr[set] = 1;
                set = p1;
                while(!(arr[--set]) && set > 0)
                    arr[set] = 1;
            }
        }
    }
    for (int i = 0; i < (wallPaper-1); i++)
        printf("%d ",arr[i]);
    printf("%d\n",arr[wallPaper-1]);

    return 0;
}