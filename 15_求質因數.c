#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int n, target, total;
    int count = 0;
    printf("請輸入測試次數：");
    scanf("%d",&n);

    while(n--){
        printf("目標數字：");
        scanf("%d",&target);
        total = 0;

        for (int i = 2; i < target; i+=i%2+1)
        {
            if (target % i == 0){

                for (int j = 1; j <= i; j++){
                    count = i % j == 0 ? count+1 : count;
                    if(count > 2){
                        break;
                    }
                }
                if(count == 2){
                    printf("%d ",i);
                    total ++;
                }
                count = 0;
            }
        }
        if(total == 0){
            printf("%d ",target);
            total++;
        }

        printf("總共有 %d 個\n",total);
    }
}