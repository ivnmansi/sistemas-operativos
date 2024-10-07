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

    if(argc==4){
        float num1=atof(argv[1]); //transformación
        float num2=atof(argv[2]); // de los argumentos
        float num3=atof(argv[3]); // a float

        if( ((num2*num2)-(4*num1*num3))<0 ){
                    printf("No hay soluciones reales\n");
        }

        
        printf("solución 1: %f\n", (-num2 + sqrt((num2 * num2) - (4 * num1 * num3))) / (2 * num1));
  
        printf("solución 2: %f\n", (-num2 - sqrt((num2 * num2) - (4 * num1 * num3))) / (2 * num1));
        tiempo_final=clock()-tiempo_inicio;
        printf("Tiempo de ejecución: %f segundos\n", (float)tiempo_final/CLOCKS_PER_SEC);

    }
    else {
        printf("Ingrese 3 numeros");
    }


    return 0;
}