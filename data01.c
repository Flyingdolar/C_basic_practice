#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct : Polynomial
typedef struct{
    char *name;
    int terms;
    int *Expon;
    int *Coef;
}Polynomial;

// Function : Compare
int Compare(int A, int B){
    if (A == B)
        return 0;
    else if (A > B)
        return 1;
    else
        return -1;
    
}

// Display : List of Actions
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

// Display : All Polynomial
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

    // Variables
    int term;               // Terms of new Polynomial
    int polyNum = *amount;  // Serial Number of new Polynomail

    printf("<<< 執 行 1. >>> 新 增 一 個 多 項 式 -----\n\n");

    // Step 1 -- Reallocate Memory Space of all Polynomial of X
    *amount = *amount + 1;
    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));

    // Step 2 -- Give a Name to Polynomial
    printf(">>  請輸入多項式名稱：");
    newPX[polyNum].name = (char*)malloc(sizeof(char*));
    scanf("%s",newPX[polyNum].name);

    // Step 3 -- Set terms of Polynomial
    printf(">>  請輸入多項式有多少非零項：");
    scanf("%d",&term);
    newPX[polyNum].terms = term;

    // Step 4 -- Allocate Memory Space of each Value(Coefficient & Exponential)
    newPX[polyNum].Coef = (int*)malloc(term * (sizeof(int*)));
    newPX[polyNum].Expon = (int*)malloc(term * (sizeof(int*)));

    // Step 5 -- Read Value(Coefficient & Exponential) of Polynomial
    printf("----請由次方數高至低，依次輸入每項多項式（ex. 3 5 --> 3x^5）\n");
    for (int i = 0; i < term; i++){
        printf(">>>  請輸入第%d項：",(i+1));
        scanf("%d %d",&newPX[polyNum].Coef[i] ,&newPX[polyNum].Expon[i]);
    }
    printf("\n\n\n");

    return newPX;
}

// Action 2 : 移除一個多項式(X)
Polynomial *remPoly(Polynomial *pX, int *amount){

    // Variables
    char *polyName = (char*)malloc(sizeof(char*));;     // Name of Target Polynomial 
    int polyNum = -1;           // Serial Number of Target Polynomial
    int Match;                  // Mark show whether it's Match ?


    // Step 1 -- Pick the Target Polynomial
    while (polyNum < 0){
        // step 1.1 Read the Name of Polynomial
        printf(">>請輸入指定之多項式名稱：");
        scanf("%s",polyName);

        // step 1.2 Find the Specific Polynomial
        polyNum = *amount;
        while (polyNum && Match){
            polyNum--;
            Match = strcmp(polyName, pX[polyNum].name);
        }
        if(Match){          // If not, Scan and Read again
            printf("(---查無此多項式，請重新輸入---)\n");
            polyNum = -1;
            free(polyName);
        }
    }

    // Step 2 -- Remove the Target Polynomial
    (*amount) --;
    for (int i = polyNum; i < *amount; i++)
        pX[i] = pX[i+1];

    printf("\n\n");
    
    // Step 3 -- Redomain the Structure
    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));
    return newPX;
}

// Action 3 : 選定多項式與指數次方，查看係數值
int viewTerm(Polynomial *pX, int *amount){

    // Variables
    char *polyName = (char*)malloc(sizeof(char*));;     // Name of Target Polynomial 
    int polyNum = -1;           // Serial Number of Target Polynomial
    int readExpon;              // Exponential of Target Term
    int Match;                  // Mark show whether it's Match ?

    printf("<<< 執 行 3. >>> 選 定 多 項 式 與 指 數 次 方 ， 查 看 係 數 值\n\n");
    
    // Step 1 -- Pick the Target Polynomial
    while (polyNum < 0){
        // step 1.1 Read the Name of Polynomial
        printf(">>請輸入指定之多項式名稱：");
        scanf("%s",polyName);

        // step 1.2 Find the Specific Polynomial
        polyNum = *amount;
        while (polyNum && Match){
            polyNum--;
            printf("%d\n",polyNum);
            Match = strcmp(polyName, pX[polyNum].name);
        }
        if(Match){          // If not, Scan and Read again
            printf("(---查無此多項式，請重新輸入---)\n");
            polyNum = -1;
            free(polyName);
        }
    }

    // Step 2 -- Pick the Target Term (from Exponential)
    printf(">>請輸入指定之項之次方：");
    scanf("%d",&readExpon);
    printf("\n");

    // Step 3 -- Find the Target Coefficient from Exponential
    // case A : Find the Coefficient and Print
    for (int i = 0; i < pX[polyNum].terms; i++){
        if (readExpon == pX[polyNum].Expon[i]){
            printf("該項的係數值為：%d\n\n",pX[polyNum].Coef[i]);
            return 1;
        }
    }
    // case B : If not, print 0 as Coefficient
    printf("該項的係數值為：0\n\n");        
    return 0;
}

// Action 4 : 選定多項式，新增/移除非零項
Polynomial *chgTerm(Polynomial *pX, int *amount){

    // Pointer for Polynomial to Return
    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));

    // Variables
    char *polyName = (char*)malloc(sizeof(char*));;
    int polyNum = -1;
    int Match;
    int readExpon, readCoef;
    int curExpon;

    printf("<<< 執 行 4. >>> 選 定 多 項 式 ， 新 增 / 移 除 非 零 項\n\n");

    // Step 1 -- Pick the Target Polynomial
    while (polyNum < 0){
        // step 1.1 Read the Name of Polynomial
        printf(">>請輸入指定之多項式名稱：");
        scanf("%s",polyName);

        // step 1.2 Find the Specific Polynomial
        polyNum = *amount;
        while (polyNum && Match){
            polyNum--;
            Match = strcmp(polyName, pX[polyNum].name);
        }
        if(Match){          // If not, Scan and Read again
            printf("(---查無此多項式，請重新輸入---)\n");
            polyNum = -1;
            free(polyName);
        }
    }

    // Step 2 -- Pick the Target Term
    printf(">>請輸入要新增/移除之指定項次（ex. 3 5 --> 3x^5）：");
    scanf("%d %d", &readCoef, &readExpon);
    printf("\n");

    // Step 3 -- Find Target Term exist or not
    for (curExpon = 0; readExpon <= pX[polyNum].Expon[curExpon]; curExpon++){
        if (readExpon == pX[polyNum].Expon[curExpon]){          // Find the Coefficient in Polynomial

            // case A : "Delete"  when Found it!
            printf("(--於多項式發現此項，進行刪除--)\n\n");   

            pX[polyNum].terms--;        // Delete Space from Terms

            for (int j = curExpon; j < pX[polyNum].terms; j++){
                pX[polyNum].Expon[j] = pX[polyNum].Expon[j+1];
                pX[polyNum].Coef[j] = pX[polyNum].Coef[j+1];
            }

            // Redomain the Structure
            newPX[polyNum].Expon = (int*)realloc(pX[polyNum].Expon, pX[polyNum].terms * (sizeof(int)));
            newPX[polyNum].Coef = (int*)realloc(pX[polyNum].Coef, pX[polyNum].terms * (sizeof(int)));
            
            return newPX;   // End Action, Return
        }
    }
    // case B : "Add"  when Not Found!
    printf("(--多項式未存在此項，進行增加--)\n\n");

    pX[polyNum].terms++;        // Add Space from Terms

    // Redomain the Structure
    newPX[polyNum].Expon = (int*)realloc(pX[polyNum].Expon, pX[polyNum].terms * (sizeof(int)));
    newPX[polyNum].Coef = (int*)realloc(pX[polyNum].Coef, pX[polyNum].terms * (sizeof(int)));

    for (int i = newPX[polyNum].terms - 1; i > curExpon; i--){
        newPX[polyNum].Expon[i] = newPX[polyNum].Expon[i-1];
        newPX[polyNum].Coef[i] = newPX[polyNum].Coef[i-1];
    }

    newPX[polyNum].Expon[curExpon] = readExpon;
    newPX[polyNum].Coef[curExpon] = readCoef;
    
    return newPX;
}

// Action 5 : 選定兩個多項式，使其相加
Polynomial *addPoly(Polynomial *pX, int *amount){

    // Variables
    char *polyName = (char*)malloc(sizeof(char*));;     // Name of Target Polynomial 
    int polyNumA = -1, polyNumB = -1;                   // Serial Number of Target Polynomial
    int Match;                                          // Mark show whether it's Match ?
    int remTermA = 0, remTermB = 0;                     // Remain Terms of A and B
    int resultTerm;                                     // Terms of Result
    int resultValu = 0;                                 // Value of Result

    // Step 1 -- Redomain the Structure (Expand Memory Space)
    (*amount)++;
    Polynomial *newPX = (Polynomial*)realloc(pX, (*amount) * (sizeof(Polynomial)));

    // Step 2A -- Pick the Target Polynomial A
    while (polyNumA < 0){
        // step 2A.1 Read the Name of Polynomial
        printf(">>請輸入指定之多項式名稱：");
        scanf("%s",polyName);

        // step 2A.2 Find the Specific Polynomial
        polyNumA = *amount;
        while (polyNumA && Match){
            polyNumA--;
            printf("%d\n",polyNumA);
            Match = strcmp(polyName, pX[polyNumA].name);
        }
        if(Match){          // If not, Scan and Read again
            printf("(---查無此多項式，請重新輸入---)\n");
            polyNumA = -1;
            free(polyName);
        }
    }

    // Step 2B -- Pick the Target Polynomial B
    while (polyNumB < 0){
        // step 2B.1 Read the Name of Polynomial
        printf(">>請輸入指定之多項式名稱：");
        scanf("%s",polyName);

        // step 2B.2 Find the Specific Polynomial
        polyNumB = *amount;
        while (polyNumB && Match){
            polyNumB--;
            printf("%d\n",polyNumB);
            Match = strcmp(polyName, pX[polyNumB].name);
        }
        if(Match){          // If not, Scan and Read again
            printf("(---查無此多項式，請重新輸入---)\n");
            polyNumB = -1;
            free(polyName);
        }
    }

    // Step 3 -- Given a Name to Polynomial
    // newPX[(*amount)-1].name = (char*)malloc(sizeof(char*));
    sprintf(newPX[(*amount)-1].name, "(Add) %c %c", polyNumA, polyNumB);
    resultTerm = newPX[polyNumA].terms + newPX[polyNumB].terms;

    // Step 4 -- Allocate Memory Space of each Value(Coefficient & Exponential)
    newPX[(*amount)-1].Coef = (int*)malloc(resultTerm * (sizeof(int*)));
    newPX[(*amount)-1].Expon = (int*)malloc(resultTerm * (sizeof(int*)));

    // Step 5 -- Compare A and B, Insert Value
    while (remTermA <= newPX[polyNumA].terms && remTermB <= newPX[polyNumB].terms){
        switch (Compare(newPX[polyNumA].Expon[remTermA], newPX[polyNumB].Expon[remTermB])){
            
            case 1:
                newPX[(*amount)-1].Coef[resultValu] = newPX[polyNumA].Coef[remTermA];
                newPX[(*amount)-1].Expon[resultValu] = newPX[polyNumA].Expon[remTermA];
                remTermA++;
                resultValu++;
                break;

            case 0:
                if (newPX[polyNumA].Coef[remTermB] + newPX[polyNumB].Coef[remTermB]){
                    newPX[(*amount)-1].Coef[resultValu] = newPX[polyNumA].Coef[remTermA] + newPX[polyNumB].Coef[remTermB];
                    newPX[(*amount)-1].Expon[resultValu] = newPX[polyNumA].Expon[remTermA];
                    resultValu++;
                }
                remTermA++;
                remTermB++;
                resultTerm--;
                break;
            
            case -1:
                newPX[(*amount)-1].Coef[resultValu] = newPX[polyNumB].Coef[polyNumB];
                newPX[(*amount)-1].Expon[resultValu] = newPX[polyNumB].Expon[remTermB];
                remTermB++;
                resultValu++;
                break;
        }
    }

    // Step 6A -- Adding Remain Object of A
    if (remTermA <= newPX[polyNumA].terms){
        while (remTermA <= newPX[polyNumA].terms){
            newPX[(*amount)-1].Coef[resultValu] = newPX[polyNumA].Coef[remTermA];
            newPX[(*amount)-1].Expon[resultValu] = newPX[polyNumA].Expon[remTermA];
            remTermA++;
            resultValu++;
        }
    }

    // Step 6B -- Adding Remain Object of B
    if (remTermB <= newPX[polyNumB].terms){
        while (remTermB <= newPX[polyNumB].terms){
            newPX[(*amount)-1].Coef[resultValu] = newPX[polyNumB].Coef[remTermB];
            newPX[(*amount)-1].Expon[resultValu] = newPX[polyNumB].Expon[remTermB];
            remTermA++;
            resultValu++;
        }
    }
    
    
    // Step 7 -- Allocate new Memory Space of each Value(Coefficient & Exponential)
    newPX[(*amount)-1].Coef = (int*)malloc(resultTerm * (sizeof(int*)));
    newPX[(*amount)-1].Expon = (int*)malloc(resultTerm * (sizeof(int*)));

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