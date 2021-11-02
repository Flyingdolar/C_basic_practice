#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    FILE *fin, *fout;
    fout = fopen("out1.txt","w+t");
    int count = 0;
    int result[5] = {0,0,0,0,0};
    int input[10][3] = {{0,1,2},{0,1,3},{0,1,4},{0,2,3},{0,2,4},{0,3,4},{1,2,3},{1,2,4},{1,3,4},{2,3,4}};
    int storage[10] = {0,0,0,0,0,0,0,0,0,0} ;
    for(int a=0; a<=2; a++){
        storage[0] = input[0][a];
        for(int b=0; b<=2; b++){
            storage[1] = input[1][b];
            for(int c=0; c<=2; c++){
                storage[2] = input[2][c];
                for(int d=0; d<=2; d++){
                    storage[3] = input[3][d];
                    for(int e=0; e<=2; e++){
                        storage[4] = input[4][e];
                        for(int f=0; f<=2; f++){
                            storage[5] = input[5][f];
                            for(int g=0; g<=2; g++){
                                storage[6] = input[6][g];
                                for(int h=0; h<=2; h++){
                                    storage[7] = input[7][h];
                                    for(int i=0; i<=2; i++){
                                        storage[8] = input[8][i];
                                        for(int j=0; j<=2; j++){
                                            storage[9] = input[9][j];
                                            for(int k=0; k<10; k++){
                                                result[storage[k]]++;
                                                fprintf(fout,"%d",storage[k]);
                                                if(k == 9){
                                                    fprintf(fout,"\n");
                                                }else{
                                                    fprintf(fout," ");
                                                }
                                            }
                                            // for(int l=0; l<5; l++){
                                            //     fprintf(fout,"%d",result[l]);
                                            //     result[l] = 0;
                                            //     if(l == 4){
                                            //         fprintf(fout,"\n");
                                            //     }else{
                                            //         fprintf(fout," ");
                                            //     }
                                            // }
                                            count++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fprintf(fout,"%d\n",count);
    fclose(fout);
    return 0;
}