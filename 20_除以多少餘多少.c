#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    int n;
    printf("請輸入資料庫有多少數字：");
    scanf("%d",&n);

    int data[n];
    printf("請依序輸入資料庫的數字：");
    for (int i = 0; i < n; i++)
        scanf("%d",&data[i]);
    
    int target;
    printf("請輸入目標除數：");
    scanf("%d",&target);

    int ans[target];
    for (int i = 0; i < target; ans[i]=0, i++);
    for (int i = 0; i < n; ans[(data[i]%target)]++, i++);

    for (int i = 0; i < target; i++)
        printf("除以 %d 餘 %d 的有 %d 個數\n",target ,i ,ans[i]);
    
    return 0;
}