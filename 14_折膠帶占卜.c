#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
    int p1, p2, q1, q2;
    int n, x, temp, result;

    printf("請輸入我選的號碼（P1 P2）：");
    scanf("%d %d", &p1, &p2);
    printf("請輸入你選的號碼（Q1 Q2）：");
    scanf("%d %d", &q1, &q2);
    printf("將 P1 to Q1，P2 to Q2 塗成紅色，請輸入折膠帶的次數：");
    scanf("%d", &n);

    if(p1 > q1){
        temp = p1;
        p1 = q1;
        q1 = temp;
    }

    if (p2 > q2){
        temp = p2;
        p2 = q2;
        q2 = temp;
    }

    while (n--) {
        printf("要折膠帶的點是：");
        scanf("%d", &x);

        if (p1 < x && x < q1){
            p1 = x - p1;
            q1 = q1 - x;
            q1 = p1 > q1 ? p1 : q1;
            p1 = 0;
        }else{
            p1 = p1 - x > 0 ? p1-x : x-p1;
            q1 = q1 - x > 0 ? q1-x : x-q1;
            p1 = p1 - x > 0 ? p1 : x;
            q1 = q1 - x > 0 ? q1 : x;
        }

        if (p2 < x && x < q2){
            p2 = x - p2;
            q2 = q2 - x;
            q2 = p2 > q2 ? p2 : q2;
            p2 = 0;
        }else{
            p2 = p2 - x > 0 ? p2-x : x-p2;
            q2 = q2 - x > 0 ? q2-x : x-q2;
            p2 = p2 - x > 0 ? p2 : x;
            q2 = q2 - x > 0 ? q2 : x;
        }

        if(p1 > q1){
        temp = p1;
        p1 = q1;
        q1 = temp;
        }

        if (p2 > q2){
            temp = p2;
            p2 = q2;
            q2 = temp;
        }
    }

    if(p1 > p2) {
        temp = p1;
        p1 = p2;
        p2 = p1;
        temp = q1;
        q1 = q2;
        q2 = temp;
    }

    if(q1 >= p2){
        result = q2 - p1;
    }else{
        result = (q1 - p1) + (q2 - p2);
    }

    printf("塗色部分的長度是 %d\n", result);
}