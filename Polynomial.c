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

// >>  1  Reverse Number
float rvs(float num){
    num = 0.000000 - num;
    return num;
}

// >>  2  Absolute Positive
float absPos(float num){
    if(num < 0)
        num = rvs(num);
    return num;
}

// >>  3  Compare
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

    // Print the Polynomials
    for (int polyNum = stdPt; polyNum < endPt; polyNum++){

        // Setting Polynomial's Property
        printf("%d : %s = ", polyNum, data[polyNum].Name);
        coef = data[polyNum].Coef;
        expon = data[polyNum].Expon;

        // Print Terms of Polynomial
        for (int termNum = 0; termNum < data[polyNum].terms; termNum++){

            // Notation +
            if(termNum)
                if(coef[termNum] > 0)
                    printf(" + ");

            // Notation -
            if (coef[termNum] < 0)
                printf(" - ");
            
            // Coefficient
            if(coef[termNum] != 1 || !expon[termNum])
                printf("%g", absPos(coef[termNum]));

            // Exponential
            if(expon[termNum]){
                printf("x");
                if(expon[termNum] > 1)
                    printf("^%g", expon[termNum]);
            }
        } 
        printf("\n");
    }
}

// =======================================================================================================

// >>  1  Element Search
int eSearch(poly data, float expon){
    int num;
    for (num = 0; data.Expon[num] > expon; num++);
    if (data.Expon[num] != expon)
        num = (-1) - num;
    return num;
}

// >>  2  Element Addition
poly *eAdd(poly *data, int pick, float coef, float expon){
    int num = 0;
    num  = eSearch(data[pick], expon);

    // (case A) If Existed, Add Coefficient
    if (num > 0){
        data[pick].Coef[num] += coef;
        return data;
    }
    
    // (case B) If Not, Add Term
    num = 1 - num;
    poly *newData = data;
    newData[pick].terms ++;
    newData[pick].Coef = (float*)realloc(data[pick].Coef, newData[pick].terms * sizeof(float));
    newData[pick].Expon = (float*)realloc(data[pick].Expon, newData[pick].terms * sizeof(float));

    for (int i = newData[pick].terms - 1; i > num; i--){
        newData[pick].Coef[i] = newData[pick].Coef[i-1];
        newData[pick].Expon[i] = newData[pick].Expon[i-1];
    }
    newData[pick].Coef[num] = coef;
    newData[pick].Expon[num] = expon;

    return newData;
}

// >>  3  Element Remove
poly *eRemove(poly *data, int pick, float expon){
    int num = 0;
    num  = eSearch(data[pick], expon);

    for (int i = num; i < data[pick].terms - 1; i++){
        data[pick].Coef[i] = data[pick].Coef[i+1];
        data[pick].Expon[i] = data[pick].Expon[i+1];
    }

    poly *newData = data;
    newData[pick].terms --;
    newData[pick].Coef = (float*)realloc(data[pick].Coef, newData[pick].terms * sizeof(float));
    newData[pick].Expon = (float*)realloc(data[pick].Expon, newData[pick].terms * sizeof(float));

    return newData;
}

// =======================================================================================================

// >>  1  Polynomial Search
int pSearch(poly *data, int count, char *typeName){

    int num;
    int Match = 1;

    // (1) -- Find the Polynomial
    while(count-- & Match){
        num = count - 1;
        Match = strcmp(data[num].Name, typeName);
    }

    //  (2) -- Print the Polynomial Serial Number out
    if(Match)
        num = -1;
    
    return num;
}

// >>  2  Polynomial Resize
poly *pResize(poly *data, int count){
    poly *newData = (poly*)realloc(data, count * (sizeof(poly)));
    return newData;
}

// >>  3  Polynomial Addition
poly *pAdd(poly *data, int *count, poly newP){
    
    // (1) -- Add 1 Memory Space for New Polynomial
    data = pResize(data, (*count)+1);

    // (2) -- Place New Polynomial in Data Space
    data[*count] = newP;

    (*count)++; 
    return data;
}

// >>  4  Polynomial Find
int pFind(poly *data, int count, char *tarName){
    for (int pick = 0; pick < count; pick++){
        if(!(strcmp(data[pick].Name, tarName)))
            return pick;
    }
    return -1;
}

// Main : IO and Interface ===============================================================================
int main(int argc, char const *argv[]){

    // Variables
    poly *Database = (poly*)malloc(sizeof(poly));       // Database : Collection of all Polynomial
    poly inPoly;                                        // Input Polynomial : Storage Insert Polynomial
    char *inNam = (char*)malloc(sizeof(char));          // Input Name
    float inCf, inExp;                                  // Input Coefficient & Exponential
    int polyAmount = 0;                                 // Polynomial Amount : Total Amount of Polynomial
    int seNumP1, seNumP2, seNumE1, seNumE2;             // Serial Number : Tagged the Specific Value or Polynomial
    int userChoice = -1;                                // User Choice : Record User's Choice
    char Message[100];        // Input Name

    // 1. -- First Entry
    showIntro();            // Show Introduction
    memset(Message, 0, 100);

    // 2. -- Loop
    while(userChoice){

        // Show Polynomial (All)
        printf("------------ 多  項  式  列  表 ------------\n\n");
        showPoly(Database, 0, polyAmount);                              
        printf("--------------------------------------------\n\n");

        printf("%s\n\n",Message);
        memset(Message, 0, 100);

        // Scan User's Input
        printf("> 請輸入要操作的功能代碼（0~9）：");
        scanf("%d", &userChoice);
        printf("\n");

        if (userChoice == 1){
            printf("<<< 執 行 1. >>> 新 增 一 個 多 項 式 -----\n\n");
                
            // A -- Set the Name and Terms
            printf(">>  請輸入多項式名稱：");
            inPoly.Name = (char*)malloc(sizeof(char));
            scanf("%s", inPoly.Name);
            printf(">>  請輸入多項式有多少非零項：");
            scanf("%d", &(inPoly.terms));

            printf("\n         ------請輸入多項式內容------\n\n");
            printf("(--請由次方數高至低，依次輸入每項多項式（ex. 3 5 --> 3x^5）--)\n");
            
            // B -- Set each element Property
            inPoly.Coef = (float*)malloc(inPoly.terms * sizeof(float));
            inPoly.Expon = (float*)malloc(inPoly.terms * sizeof(float));
            for (int num = 0; num < inPoly.terms; num++){
                printf(">>>  請輸入第%d項：",(num + 1));
                scanf("%f %f", &inPoly.Coef[num], &inPoly.Expon[num]);
            }

            // C -- Add Polynomial to Database
            Database = pAdd(Database,&polyAmount,inPoly);

            sprintf(Message, "   (--- 已新增多項式 : %s ---)",inPoly.Name);
            printf("\n");
        }
        
        if (userChoice == 2){
            printf("<<< 執 行 2. >>> 移 除 一 個 多 項 式\n\n");

            // A -- Find out the Specific Polynomial
            printf(">>請輸入指定之多項式名稱：");
            scanf("%s",inNam);
            printf("\n");

            seNumP1 = pFind(Database, polyAmount, inNam);

            // B -- Remove Polynomial if Found
            if(seNumP1 < 0){
                // Case A : Not Found     
                sprintf(Message, "   (---查無此多項式---)");
            }else{
                // Case B : Found and Removed
                polyAmount--;
                sprintf(Message, "   (--- 已移除多項式 : %s ---)",inPoly.Name);
                for (int num = seNumP1; num < polyAmount; num++)
                    Database[seNumP1] = Database[seNumP1+1];

                Database = pResize(Database, polyAmount);
            }
            printf("\n");
        }
        
        if (userChoice == 3){
            printf("<<< 執 行 3. >>> 查 看 係 數 值\n\n");

            // A -- Find out the Specific Polynomial
            printf(">>請輸入指定之多項式名稱：");
            scanf("%s",inNam);
            seNumP1 = pFind(Database, polyAmount, inNam);

            // B -- Find out the Specific Term
            printf(">>請輸入指定之項數次方：");
            scanf("%f",&inExp);
            seNumE1 = eSearch(Database[seNumP1], inExp);

            // C -- Print out Coefficient
            if(seNumE1 >= 0)
                sprintf(Message, "   (---所查詢之係數值為 %g ---)", Database[seNumP1].Coef[seNumE1]);
            else
                sprintf(Message, "   (---所查詢之係數值為 0 ---)");
        }
        
        if (userChoice == 4){
            printf("<<< 執 行 4. >>> 增 減 指 定 項 次\n\n");

            // A -- Find out the Specific Polynomial
            printf(">>請輸入指定之多項式名稱：");
            scanf("%s",inNam);
            seNumP1 = pFind(Database, polyAmount, inNam);

            // B -- Find out the Specific Term
            printf(">>請輸入指定項係數與次方（ex. 5 5 -> 5x^5）：");
            scanf("%f %f", &inCf, &inExp);

            // C -- Add or Remove
            seNumE1 = eSearch(Database[seNumP1], inExp);
            if (eSearch >= 0){
                // case A : Remove if Existed
                Database = eRemove(Database, seNumP1, inExp);
                sprintf(Message, "   (--- 已移除指定項次：%fx^%f ---)", inCf, inExp);
            }else{
                // case B : Add if Not Existed
                Database = eAdd(Database, seNumP1, inCf, inExp);
                sprintf(Message, "   (--- 已新增指定項次：%fx^%f ---)", inCf, inExp);
            }  
        }
        
    }

    free(Database);
    return 0;
}
//========================================================================================================
