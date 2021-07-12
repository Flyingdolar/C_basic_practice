#include <stdio.h>

int main(int argc, char const *argv[])
{
    int Ason, Bson, Cson;
    int onlywinner = 0;
    int Awin, Bwin, Cwin;
    int result;

    printf("請輸入A B C 三人分別出的手勢：\n");
    printf("0 = 剪刀，1 = 石頭，2 = 布\n");
    scanf("%d %d %d",&Ason ,&Bson ,&Cson);
    
    //有人贏則輸出1，沒有則輸出0
    onlywinner = ((Ason + Bson + Cson) % 3) % 2;
    //A勝利+1，B勝利+2，C勝利+3
    Awin = (((Ason + 3) - Bson) % 3) % 2;
    Bwin = ((((Bson + 3) - Cson) % 3) % 2) * 2;
    Cwin = ((((Cson + 3) - Ason) % 3) % 2) * 3;

    result = (-1) + (Awin + Bwin + Cwin) * onlywinner;
    printf("最後的結果是： %d\n", result);
    printf("如果是 -1 則代表勝負未曉，A贏則顯示 0 ；B贏則顯示 1 ；C贏則顯示 2\n");

    return 0;
}
