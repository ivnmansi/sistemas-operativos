#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <math.h>
#include <sys/wait.h>
#include <time.h>


int main(int argc, char *argv[]){
    clock_t tiempo_inicio, tiempo_final;
    tiempo_inicio=clock();
    pid_t pid1,pid2;  // procesos

    if(argc==4){
        float num1=atof(argv[1]); //transformación
        float num2=atof(argv[2]); // de los argumentos
        float num3=atof(argv[3]); // a float

        int status2;


        if( (pid1=fork())==0){

            if((pid2=fork())==0){
                //verificar si hay soluciones reales
                if( ((num2*num2)-(4*num1*num3))<0 ){
                    printf("No hay soluciones reales\n");
                }
            }
            else {
                
                wait(&status2);
                    printf("solución 1: %f\n", (-num2 + sqrt((num2 * num2) - (4 * num1 * num3))) / (2 * num1));

            }
        }   

        else {
            wait(&status2);
                printf("solución 2: %f\n", (-num2 - sqrt((num2 * num2) - (4 * num1 * num3))) / (2 * num1));
                tiempo_final=clock()-tiempo_inicio;
                printf("Tiempo de ejecución: %f segundos\n", (float)tiempo_final/CLOCKS_PER_SEC);
        }

    }
    else {
        printf("Ingrese 3 numeros");
    }

    

    return 0;
}