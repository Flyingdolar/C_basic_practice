#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Polynomial Struct
typedef struct{
    char *name;
    int terms;
    int *Expon;
    int *Coef;
}Polynomial;

// Display : Show List of Actions
void ActList(){
    printf("\n");
    printf("   ------- 功  能  選  項  清  單 --------\n");
    printf("  |                                       |\n");
    printf("  |  1:新增一個多項式                     |\n");
    printf("  |  2:移除一個多項式                     |\n");
    printf("  |  3:選定多項式與指數次方，查看係數值   |\n");
    printf("  |  4:選定多項式，新增/移除非零項        |\n");
    printf("  |  5:選定兩個多項式，使其相加           |\n");
    printf("  |  6:選定兩個多項式，使其相減           |\n");
    printf("  |  7:選定兩個多項式，使其相乘           |\n");
    printf("  |  8:選定兩個多項式，使其相除           |\n");
    printf("  |  9:開啟功能選單                       |\n");
    printf("  |  0:結束離開                           |\n");
    printf("  |                                       |\n");
    printf("   --------------------------------------\n\n");
}

// Display : Show all Polynomial on Screen
void showPoly(Polynomial *pX, int *amount){
    printf("------------ 多  項  式  列  表 ------------\n\n");
    for(int i = 0; i < *amount; ++i){
        printf("%d：%s =",i ,pX[i].name);
        for(int j = 0; j < pX[i].terms; j++){
            printf(" ");

            if(pX[i].Coef[j] < 0)
                printf("- ");
            else if(j)
                printf("+ ");

            if((pX[i].Coef[j] != 1 && pX[i].Coef[j] != -1) || !(pX[i].Expon[j])){
                if(pX[i].Coef[j] > 0)
                    printf("%d",pX[i].Coef[j]);
                else
                    printf("%d",0 - pX[i].Coef[j]);
            }
            
            if (pX[i].Expon[j]){
                printf("x");
                if(pX[i].Expon[j] != 1)
                    printf("^%d",pX[i].Expon[j]);
            }
        }
        printf("\n");
    }
    printf("\n共計 %d 個多項式\n",*amount);
    printf("--------------------------------------------\n\n");
}

// Action 1 : 新增一個多項式
Polynomial *newPoly(Polynomial *pX, int *amount){

    int term;
    int polyNum = *amount;  // pX[polyNum] = Current Polynomial we are Adding on

    printf("<<< 執 行 1. >>> 新 增 一 個 多 項 式 -----\n\n");

    // Reallocate Memory Space of all Polynomial of X
    *amount = *amount + 1;
    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));

    // Given a Name to Polynomial
    printf(">>  請輸入多項式名稱：");
    newPX[polyNum].name = (char*)malloc(sizeof(char*));
    scanf("%s",newPX[polyNum].name);

    // Set terms of Polynomial
    printf(">>  請輸入多項式有多少非零項：");
    scanf("%d",&term);
    newPX[polyNum].terms = term;

    // Allocate Memory Space of each Value(Coefficient & Exponential)
    newPX[polyNum].Coef = (int*)malloc(term * (sizeof(int*)));
    newPX[polyNum].Expon = (int*)malloc(term * (sizeof(int*)));

    // Read Value(Coefficient & Exponential) of Polynomial
    printf("----請由次方數高至低，依次輸入每項多項式（ex. 3 5 --> 3x^5）\n");
    for (int i = 0; i < term; i++){
        printf(">>>  請輸入第%d項：",(i+1));
        scanf("%d %d",&newPX[polyNum].Coef[i] ,&newPX[polyNum].Expon[i]);
    }
    printf("\n\n\n");

    return newPX;
}

// Action 2 : 移除一個多項式
Polynomial *remPoly(Polynomial *pX, int *amount){
    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));
    return newPX;
}

// Action 3 : 選定多項式與指數次方，查看係數值
int viewTerm(Polynomial *pX, int *amount){

    char *polyName = (char*)malloc(sizeof(char*));;
    int polyNum = -1;
    int readTerm;
    int Match;

    printf("<<< 執 行 3. >>> 選 定 多 項 式 與 指 數 次 方 ， 查 看 係 數 值 -----\n\n");
    
    // Pick the Target Polynomial
    while (polyNum < 0){
        // Read the Name of Polynomial
        printf(">>請輸入指定之多項式名稱：");
        scanf("%s",polyName);

        // Find the Specific Polynomial
        polyNum = *amount;
        while (polyNum && Match){
            polyNum--;
            printf("%d\n",polyNum);
            Match = strcmp(polyName, pX[polyNum].name);
        }
        if(Match){          // If not, Scan and Read again
            printf("---查無此多項式，請重新輸入---\n");
            polyNum = -1;
            free(polyName);
        }
    }

    // Pick the Target Term
    printf(">>請輸入指定之項之次方：");
    scanf("%d",&readTerm);
    printf("\n");
    for (int i = 0; i < pX[polyNum].terms; i++){
        if (readTerm == pX[polyNum].Expon[i]){      // Find the Coefficient in Polynomial
            printf("該項的係數值為：%d\n\n",pX[polyNum].Coef[i]);
            return 1;
        }
    }
    printf("該項的係數值為：0\n\n");        // If not, print 0 as Coefficient
    return 0;
}

// Action 4 : 選定多項式，新增/移除非零項
Polynomial *chgTerm(Polynomial *pX, int *amount){

    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));
    char *polyName = (char*)malloc(sizeof(char*));;
    int polyNum = 0;
    int Match;

    printf("<<< 執 行 4. >>> 選 定 多 項 式 ， 新 增 / 移 除 非 零 項 -----\n\n");

    // Pick the Target Polynomial
    while (!polyNum){
        // Read the Name of Polynomial
        printf(">>請輸入指定之多項式名稱：");
        scanf("%s",polyName);

        // Find the Specific Polynomial
        polyNum = *amount;
        while (polyNum-- || Match){
            if(sizeof(polyName) == sizeof(pX[polyNum].name))
                Match = strcmp(polyName, pX[polyNum].name);
        }
        if(Match){          // If not, Scan and Read again
            printf("---查無此多項式，請重新輸入---\n");
            free(polyName);
        }
    }

    return newPX;
}

// Action 5 : 選定兩個多項式，使其相加
Polynomial *addPoly(Polynomial *pX, int *amount){
    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));
    return newPX;
}

// Action 6 : 選定兩個多項式，使其相減
Polynomial *subPoly(Polynomial *pX, int *amount){
    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));
    return newPX;
}

// Action 7 : 選定兩個多項式，使其相乘
Polynomial *mtpPoly(Polynomial *pX, int *amount){
    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));
    return newPX;
}

// Action 8 : 選定兩個多項式，使其相除
Polynomial *divPoly(Polynomial *pX, int *amount){
    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));
    return newPX;
}

// Main Function
int main(){
    // Variable
    int Action = -1;        // Record which Action user take
    int polyAmount = 0;     // Amount of all Polynomial
    Polynomial *storageX = (Polynomial*)malloc(polyAmount * (sizeof(Polynomial)));  // Declare Dynamic Array for all Polynomial of X

    // First entry
    ActList();  // Show List of Actions

    // Loop
    while(Action){
        // Show all Polynomial on Screen
        showPoly(storageX, &polyAmount);

        // Read Action from User
        printf("> 請輸入要操作的功能代碼（0~9）：");
        scanf("%d",&Action);
        printf("\n");

        // Switch case to each Action
        switch (Action){
            case 1:
                storageX = newPoly(storageX, &polyAmount);
                break;
            case 2:
                storageX = remPoly(storageX, &polyAmount);
                break;
            case 3:
                viewTerm(storageX, &polyAmount);
                break;
            case 4:
                storageX = chgTerm(storageX, &polyAmount);
                break;
            case 5:
                storageX = addPoly(storageX, &polyAmount);
                break;
            case 6:
                storageX = subPoly(storageX, &polyAmount);
                break;
            case 7:
                storageX = mtpPoly(storageX, &polyAmount);
                break;
            case 8:
                storageX = divPoly(storageX, &polyAmount);
                break;
            case 9:
                ActList();
                break;
            default:
                break;
        }
    }

    // Release Memory Space before Shutdown
    free(storageX);

    return 0;
}