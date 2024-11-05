#include "comunication.h"

int main(int argc, char *argv[]){

    srand(time(0));

    /*La cantidad de datos enviados se envian como argumento*/
    int NDATOS=atoi(argv[1]);

    _mensaje mensaje;
    int longitud=sizeof(mensaje)-sizeof(mensaje.tipo);
    int msqid; /*identificador de la cola de mensajes*/

    createQueue(msqid);

    for(int i=0; i<NDATOS; i++){
        printf("%d. ",i+1);
        sendMessage(msqid, mensaje, longitud);
    }

    return 0;
}