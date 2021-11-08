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
char *showPoly(poly *data, int stdPt, int num){

    // Variables
    float *expon, *coef;
    char *stg = (char*)malloc(1000 * sizeof(char));
    char *str = (char*)malloc(50 * sizeof(char));
    // memset(stg, 0, 1000);

    // Print the Polynomials
    for (int polyNum = stdPt; polyNum < (stdPt + num); polyNum++){

        // Setting Polynomial's Property
        sprintf(str, "%d : %s = ", polyNum, data[polyNum].Name);
        strcat(stg, str);
        coef = data[polyNum].Coef;
        expon = data[polyNum].Expon;

        // Print Terms of Polynomial
        for (int termNum = 0; termNum < data[polyNum].terms; termNum++){

            // Notation +
            if(termNum)
                if(coef[termNum] > 0){
                    sprintf(str, " + ");
                    strcat(stg, str);
                }

            // Notation -
            if (coef[termNum] < 0){
                sprintf(str, " - ");
                strcat(stg, str);
            }   
            
            // Coefficient
            if(coef[termNum] != 1 || !expon[termNum]){
                sprintf(str, "%g", absPos(coef[termNum]));
                strcat(stg, str);
            }
                

            // Exponential
            if(expon[termNum]){
                sprintf(str, "x");
                strcat(stg, str);
                if(expon[termNum] > 1){
                    sprintf(str, "^%g", expon[termNum]);
                    strcat(stg, str);
                }
            }
        } 
        sprintf(str, "\n");
        strcat(stg, str);
    }
    return stg;
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
    num = (-1) - num;
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

// >>  4  Element Resize
float *eResize(float *fArray, int count){
    float *newArray = (float*)realloc(fArray, count * sizeof(float));
    return newArray;
}

// >>  5  Element Multiply
poly eMulti(poly fArray, float coef, float expon){

    poly newArrary;

    newArrary.Name = fArray.Name;
    newArrary.terms = fArray.terms;
    newArrary.Coef = (float*)malloc(fArray.terms * sizeof(float));
    newArrary.Expon = (float*)malloc(fArray.terms * sizeof(float));

    for (int num = 0; num < newArrary.terms; num++){
        newArrary.Coef[num] = fArray.Coef[num] * coef;
        newArrary.Expon[num] = fArray.Expon[num] + expon;
    }

    return newArrary;
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

// >>  5  Polynomial Combine
poly pCom(poly *data, int a, int b, int mode){

    poly pA, pB, pRslt;
    int numA = 0, numB = 0, numR = 0;

    // eResize(pA.Coef, data[a].terms);
    // eResize(pA.Expon, data[a].terms);
    // eResize(pB.Coef, data[b].terms);
    // eResize(pB.Expon, data[b].terms);

    pA = data[a];
    pB = data[b];

    // (A) Set Result Polynomial and Combine Mode
    pRslt.Name = (char*)malloc(sizeof(char));
    if(mode){
        // case A -- Positive Mode
        sprintf(pRslt.Name,"(ADD)%s_%s", pA.Name, pB.Name);
    }else{
        // case B -- Negative Mode
        sprintf(pRslt.Name,"(SUB)%s_%s", pA.Name, pB.Name);
        for (int num = 0; num < pB.terms; num++){
            pB.Coef[num] = rvs(pB.Coef[num]);
        }
    }
    
    pRslt.terms = pA.terms + pB.terms;
    pRslt.Coef = (float*)malloc(pRslt.terms * sizeof(float));
    pRslt.Expon = (float*)malloc(pRslt.terms * sizeof(float));

    // (B) Compare & Sequential Input
    while(numA < pA.terms && numB < pB.terms){
        if (pA.Expon[numA] == pB.Expon[numB]){
            pRslt.Coef[numR] = pA.Coef[numA] + pB.Coef[numB];
            pRslt.Expon[numR] = pA.Expon[numA];
            numA++, numB++;
        }else if (pA.Expon[numA] > pB.Expon[numB]){
            pRslt.Coef[numR] = pA.Coef[numA];
            pRslt.Expon[numR] = pA.Expon[numA];
            numA++;
        }else{
            pRslt.Coef[numR] = pB.Coef[numB];
            pRslt.Expon[numR] = pB.Expon[numB];
            numB++;
        }
        numR++;
    }
    
    // (C) Input Remain
    while(numA < pA.terms){
        pRslt.Coef[numR] = pA.Coef[numA];
        pRslt.Expon[numR] = pA.Expon[numA];
        numA++, numR++;
    }
    while(numB < pB.terms){
        pRslt.Coef[numR] = pB.Coef[numB];
        pRslt.Expon[numR] = pB.Expon[numB];
        numB++, numR++;
    }

    pRslt.terms = numR;
    pRslt.Coef = eResize(pRslt.Coef, numR);
    pRslt.Expon = eResize(pRslt.Expon, numR);

    return pRslt;
}

// >>  6  Polynomial Multiply
poly pMulti(poly *data, int a, int b){

    // (1) -- Polynomial Setting
    poly *stor = (poly*)malloc(2 * sizeof(poly));

    stor[0].terms = data[a].terms;
    stor[0].Coef = (float*)malloc(stor[0].terms * sizeof(float));
    stor[0].Expon = (float*)malloc(stor[0].terms * sizeof(float));

    stor[1].terms = 2 * data[a].terms;
    stor[1].Coef = (float*)malloc(stor[1].terms * sizeof(float));
    stor[1].Expon = (float*)malloc(stor[1].terms * sizeof(float));

    // (2) -- Multiply by Terms
    for (int num = 0; num < data[b].terms; num++){
        if(!num){
            stor[1] = eMulti(data[a], data[b].Coef[num], data[b].Expon[num]);
        }else{
            stor[0] = eMulti(data[a], data[b].Coef[num], data[b].Expon[num]);
            stor[1] = pCom(stor, 0, 1, 1);
        }
    }
    stor[1].Name = (char*)malloc(100 * sizeof(char));
    sprintf(stor[1].Name, "(Multi)%s_%s", data[a].Name, data[b].Name);
    return stor[1];
}

// >>  7  Polynomial Subtract
poly *pSubtr(poly *data, int a, int b){
    poly *stor = (poly*)malloc(3 * sizeof(poly));
    stor[1] = data[a];

    int num = 0;
    while(stor[1].Expon[0] >= data[b].Expon[0] && num < 100){
        stor[0].Coef = (float*)malloc((num+1) * sizeof(float));
        stor[0].Expon = (float*)malloc((num+1) * sizeof(float));

        stor[0].Coef[num] = stor[1].Coef[0] / data[b].Coef[0];
        stor[0].Expon[num] = stor[1].Expon[0] - data[b].Expon[0];

        stor[2] = eMulti(data[b], stor[0].Coef[num], stor[0].Expon[num]);
        stor[1] = pCom(stor, 1, 2, 0);
        num++;
    }

    stor[0].Name = (char*)malloc(sizeof(char));
    sprintf(stor[1].Name, "(QUO)%s_%s", data[a].Name, data[b].Name);
    stor[1].Name = (char*)malloc(sizeof(char));
    sprintf(stor[1].Name, "(REM)%s_%s", data[a].Name, data[b].Name);

    return stor;
}

// Main : IO and Interface ===============================================================================
int main(int argc, char const *argv[]){

    // Variables
    poly *Database = (poly*)malloc(sizeof(poly));       // Database : Collection of all Polynomial
    poly inPoly;                                        // Input Polynomial : Storage Insert Polynomial
    poly *inPoly2 = (poly*)malloc(2 * sizeof(poly));
    char *inNam = (char*)malloc(sizeof(char));          // Input Name
    float inCf, inExp;                                  // Input Coefficient & Exponential
    int polyAmount = 0;                                 // Polynomial Amount : Total Amount of Polynomial
    int seNumP1, seNumP2, seNumE1, seNumE2;             // Serial Number : Tagged the Specific Term or Polynomial
    int userChoice = -1;                                // User Choice : Record User's Choice
    char Message[1000];                                 // Message

    // 1. -- First Entry
    showIntro();            // Show Introduction
    memset(Message, 0, 1000);

    // 2. -- Loop
    while(userChoice){

        // Show Polynomial (All)
        printf("------------ 多  項  式  列  表 ------------\n");
        printf("%s",showPoly(Database, 0, polyAmount));                              
        printf("--------------------------------------------\n\n");

        printf("%s\n\n",Message);
        memset(Message, 0, 1000);

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
            if (seNumE1 >= 0){
                // case A : Remove if Existed
                Database = eRemove(Database, seNumP1, inExp);
                sprintf(Message, "   (--- 已移除指定項次：%gx^%g ---)", inCf, inExp);
            }else{
                // case B : Add if Not Existed
                Database = eAdd(Database, seNumP1, inCf, inExp);
                sprintf(Message, "   (--- 已新增指定項次：%gx^%g ---)", inCf, inExp);
            }  
        }
        
        if (userChoice == 5){
            printf("<<< 執 行 5. >>> 多 項 式 加 法\n\n");

            // A -- Find both 2 Polynomial
            printf(">>請輸入第一個多項式名稱：");
            scanf("%s",inNam);
            seNumP1 = pFind(Database, polyAmount, inNam);
            printf(">>請輸入第二個多項式名稱：");
            scanf("%s",inNam);
            seNumP2 = pFind(Database, polyAmount, inNam);

            // B -- Execute Polynomial Combination
            inPoly.Coef = (float*)malloc(sizeof(float));
            inPoly.Expon = (float*)malloc(sizeof(float));
            inPoly = pCom(Database, seNumP1, seNumP2, 1);

            // C -- Add to Database & Display
            Database = pAdd(Database, &polyAmount, inPoly);
            sprintf(Message, "   (--- 得到結果如下---)\n %s", showPoly(Database, polyAmount-1, 1));
            printf("\n");
        }

        if (userChoice == 6){    
            printf("<<< 執 行 6. >>> 多 項 式 減 法\n\n");

            // A -- Find both 2 Polynomial
            printf(">>請輸入第一個多項式名稱：");
            scanf("%s",inNam);
            seNumP1 = pFind(Database, polyAmount, inNam);
            printf(">>請輸入第二個多項式名稱：");
            scanf("%s",inNam);
            seNumP2 = pFind(Database, polyAmount, inNam);

            // B -- Execute Polynomial Combination
            inPoly.Coef = (float*)malloc(sizeof(float));
            inPoly.Expon = (float*)malloc(sizeof(float));
            inPoly = pCom(Database, seNumP1, seNumP2, 0);            

            // C -- Add to Database & Display
            Database = pAdd(Database, &polyAmount, inPoly);
            sprintf(Message, "   (--- 得到結果如下---)\n %s", showPoly(Database, polyAmount-1, 1));
            printf("\n");
            
    }

        if (userChoice == 7){
            printf("<<< 執 行 7. >>> 多 項 式 乘 法\n\n");

            // A -- Find both 2 Polynomial
            printf(">>請輸入第一個多項式名稱：");
            scanf("%s",inNam);
            seNumP1 = pFind(Database, polyAmount, inNam);
            printf(">>請輸入第二個多項式名稱：");
            scanf("%s",inNam);
            seNumP2 = pFind(Database, polyAmount, inNam);

            // B -- Execute Polynomial Multiply
            inPoly.Coef = (float*)malloc(sizeof(float));
            inPoly.Expon = (float*)malloc(sizeof(float));
            inPoly = pMulti(Database, seNumP1, seNumP2);
            
            // C -- Add to Database & Display
            Database = pAdd(Database, &polyAmount, inPoly);
            sprintf(Message, "   (--- 得到結果如下---)\n %s", showPoly(Database, polyAmount-1, 1));
            printf("\n");
        }

        if (userChoice == 8){
            printf("<<< 執 行 8. >>> 多 項 式 除 法\n\n");

            // A -- Find both 2 Polynomial
            printf(">>請輸入第一個多項式名稱：");
            scanf("%s",inNam);
            seNumP1 = pFind(Database, polyAmount, inNam);
            printf(">>請輸入第二個多項式名稱：");
            scanf("%s",inNam);
            seNumP2 = pFind(Database, polyAmount, inNam);

            // B -- Execute Polynomial Subtraction
            inPoly2 = pSubtr(Database, seNumP1, seNumP2);

            // C -- Add to Database & Display
            Database = pAdd(Database, &polyAmount, inPoly2[0]);
            Database = pAdd(Database, &polyAmount, inPoly2[1]);
            sprintf(Message, "   (--- 得到結果如下---)\n %s", showPoly(Database, polyAmount-2, 2));
            printf("\n");
        }

        if (userChoice == 9){
            printf("<<< 執 行 9. >>> 顯 示 說 明\n\n");
            showIntro();
        }

    }
    free(Database);
    return 0;
}
//========================================================================================================
