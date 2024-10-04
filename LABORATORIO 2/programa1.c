#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <math.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){

    pid_t pid1, pid2;  // procesos

    if(argc==4){
        float num1=atof(argv[1]); //transformación
        float num2=atof(argv[2]); // de los argumentos
        float num3=atof(argv[3]); // a float

        int status1, status2; 

        if( (pid1=fork())==0){

            if((pid2=fork())==0){
                printf("soy el nieto %d, hijo de %d\n",getpid(),getppid()); //3ra generación
                printf("%f\n\n", sqrt(num3));
            }
            else {
                wait(&status2);
                printf("soy el hijo %d de %d\n",getpid(),getppid()); //2da generación
                printf("%f\n\n", num1*2);
            }
            
        }   

        else {
            wait(&status1);
            printf("soy el padre %d, hijo de %d\n", getpid(), getppid()); //1ra generacion
            printf("%f\n\n", num2*num2*num2);
        }

    }
    else {
        printf("Ingrese 3 numeros");
    }
    return 0;
}