#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct : Polynomial ===================================================================================
typedef struct{
    char *Name;         // Name of Polynomial
    int terms;          // Terms of Elements
    float *Coef;        // Coefficient of Element
    float *Expon;       // Exponential of Element
}poly;
//========================================================================================================

// Print : Introduction ==================================================================================
void showIntro(){
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
//========================================================================================================

// Print : Polynomial ==================================================================================
void showPoly(poly *data, int stdPt, int endPt){

    // Variables
    float *expon, *coef;

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
            if(coef[termNum] != 1 || !expon[termNum])
                printf(" %f ", absPos(coef[termNum]));

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
//========================================================================================================

// Function : Polynomial Resize ==========================================================================
poly *pResize(poly *data, int count){
    poly *newData = (poly*)realloc(data, count * (sizeof(poly)));
    return newData;
}
//========================================================================================================

// Function : Absolute Positive ==========================================================================
float absPos(float num){
    if(num < 0)
        num = 0 - num;
    return num;
}
//========================================================================================================

// Function : Compare ====================================================================================
int compare(float a, float b){
    if(a > b)
        return 1;
    else if(a < b)
        return -1;
    return 0;
}
//========================================================================================================

// Main : IO and Interface ===============================================================================
int main(int argc, char const *argv[]){

    // Variables
    poly *Database = (poly*)malloc(sizeof(poly));       // Database : Collection of all Polynomial
    int polyAmount = 0;                                 // Polynomial Amount : Total Amount of Polynomial
    int userChoice = -1;                                // User Choice : Record User's Choice

    // 1. -- First Entry
    showIntro();                                        // Show Introduction
    showPoly(Database, 0, polyAmount);                  // Show Polynomial (All)

    // 2. -- Loop
    while(userChoice){

        // Scan User's Input
        scanf("%d", &userChoice);

        switch (userChoice){
            case 1: //---------------------------------------
                
                break;
            case 2: //---------------------------------------
                
                break;
            case 3: //----------------------------------------

                break;
        }
    }

    return 0;
}
//========================================================================================================
