#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// >>  Structure Define
typedef struct{
    char *Name;         // Name of Polynomial
    int terms;          // Terms of Elements
    float *Coef;        // Coefficient of Element
    float *Expon;       // Exponential of Element
}poly;

// =======================================================================================================

// >>  1  Absolute Positive
float absPos(float num){
    if(num < 0)
        num = 0 - num;
    return num;
}

// >>  2  Compare
int compare(float a, float b){
    if(a > b)
        return 1;
    else if(a < b)
        return -1;
    return 0;
}

// =======================================================================================================

// >>  1  Introduction
void showIntro(void){
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

// >>  2  Polynomial Display
void showPoly(poly *data, int stdPt, int endPt){

    // Variables
    float *expon, *coef;
    float printNum;

    // Print the Polynomials
    for (int polyNum = stdPt; polyNum < endPt; polyNum++){

        // Setting Polynomial's Property
        printf("%d : %s =", polyNum, data[polyNum].Name);
        coef = data[polyNum].Coef;
        expon = data[polyNum].Expon;

        // Print Terms of Polynomial
        for (int termNum = 0; termNum < data[polyNum].terms; termNum++){

            // Notation +
            if(termNum)
                if(coef[termNum] > 0)
                    printf(" +");

            // Notation -
            if (coef[termNum] < 0)
                printf(" -");
            
            // Coefficient
            if(coef[termNum] != 1 || !expon[termNum]){
                printNum = absPos(coef[termNum]);
                printf(" %f ", printNum);
            }

            // Exponential
            if(expon[termNum]){
                printf("x");
                if(expon[termNum] > 1)
                    printf("^%f", expon[termNum]);
            }
            printf("\n");
        } 
    } 
}


// =======================================================================================================

// >>  1  Polynomial Search
int pSearch(poly *data, int count, char *typeName){

    int num;
    int Match = 1;

    // 1. -- Find the Polynomial
    while(count-- & Match){
        num = count - 1;
        Match = strcmp(data[num].Name, typeName);
    }

    // 2. -- Print the Polynomial Serial Number out
    if(Match)
        num = -1;
    
    return num;
}

// >>  2  Polynomial Resize
poly *pResize(poly *data, int count){
    poly *newData = (poly*)realloc(data, count * (sizeof(poly)));
    return newData;
}

// >>  3  Polynomial Add
poly *pAdd(poly *data, int *count, poly newP){
    
    // 1. -- Add 1 Memory Space for New Polynomial
    data = pResize(data, (*count)+1);

    // 2. -- Place New Polynomial in Data Space
    data[*count] = newP;
    
    (*count)++; 
    return data;
}

// Main : IO and Interface ===============================================================================
int main(int argc, char const *argv[]){

    // Variables
    poly *Database = (poly*)malloc(sizeof(poly));       // Database : Collection of all Polynomial
    poly inPoly;                                     // Input Polynomial : Storage Insert Polynomial
    int polyAmount = 0;                                 // Polynomial Amount : Total Amount of Polynomial
    int userChoice = -1;                                // User Choice : Record User's Choice

    // 1. -- First Entry
    showIntro();                                        // Show Introduction
    showPoly(Database, 0, polyAmount);                  // Show Polynomial (All)

    // 2. -- Loop
    while(userChoice){

        // Scan User's Input
        printf("> 請輸入要操作的功能代碼（0~9）：");
        scanf("%d", &userChoice);
        printf("\n");

        switch (userChoice){
            case 1: //-----------------------------------------------------------------------------------

                printf("<<< 執 行 1. >>> 新 增 一 個 多 項 式 -----\n\n");
                
                // A -- Set the Name and Terms
                printf(">>  請輸入多項式名稱：");
                scanf("%s", inPoly.Name);
                printf(">>  請輸入多項式有多少非零項：");
                scanf("%d", &(inPoly.terms));

                printf("            ------請輸入多項式內容------");
                printf("(--請由次方數高至低，依次輸入每項多項式（ex. 3 5 --> 3x^5）--)");
                
                // B -- Set each element Property
                inPoly.Coef = (float*)malloc(inPoly.terms * sizeof(float));
                inPoly.Expon = (float*)malloc(inPoly.terms * sizeof(float));
                for (int num = 0; num < inPoly.terms; num++){
                    printf(">>>  請輸入第%d項：",(num + 1));
                    scanf("%f %f", &inPoly.Coef[num], &inPoly.Expon[num]);
                }

                // C -- Add Polynomial to Database
                Database = pAdd(Database,&polyAmount,inPoly);

                free(inPoly.Coef);
                free(inPoly.Expon);
                printf("\n");
                break;
            case 2: //--------------------------------------- 移除一個多項式
                
                break;
            case 3: //--------------------------------------- 選定多項式與指數次方，查看係數值

                break;
            case 4: //--------------------------------------- 選定多項式，新增/移除非零項

                break;
            case 5: //--------------------------------------- 選定兩個多項式，使其相加

                break;
            case 6: //--------------------------------------- 選定兩個多項式，使其相減

                break;
            case 7: //--------------------------------------- 選定兩個多項式，使其相乘

                break;
            case 8: //--------------------------------------- 選定兩個多項式，使其相除

                break;
            case 9: //--------------------------------------- 開啟功能選單
                showIntro();
                break;
        }
        showPoly(Database, 0, polyAmount);                  // Show Polynomial (All)
    }

    free(Database);
    return 0;
}
//========================================================================================================
