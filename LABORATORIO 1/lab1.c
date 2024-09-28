#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int main(int argc, char** argv){

  int i=0;
  int num;
  FILE* txt;
  char letra;
  srand(rand()%1000);
  float total_time=0;


   while(1){
  
    if(strcmp(argv[1],"proceso1")==0){
      txt=fopen("proceso1.txt","a");
      num=rand()%101;
      fprintf(txt,"%d ",num);

    }

    else if(strcmp(argv[1],"proceso2")==0){
      txt=fopen("proceso2.txt","a");
      num=rand()%26+65;
      letra=num;
      fprintf(txt,"%c ",letra);

    }
    else if(strcmp(argv[1],"proceso3")==0){
      txt=fopen("proceso3.txt","a");
      num=rand()%101+1;
      letra=rand()%26+65;

      fprintf(txt,"%d%c ", num,letra);
    }

    total_time=total_time+delay();
    fprintf(txt,"\n DELAY:%.2f\n", total_time);
    fclose(txt);
    
  }
  return 0;
}


double delay()
{
	double miliseg=0, segs=0;
	clock_t tiempo_inicio, tiempo_final;

	srand(time(0)+rand()%100);
	segs=(rand()%2000)+1000;

	miliseg = 1000 * segs;
	tiempo_inicio = clock();
	while (clock() < tiempo_inicio + miliseg);

	tiempo_final = clock();
	tiempo_final -= tiempo_inicio;

	return (double) tiempo_final/CLOCKS_PER_SEC;
}

