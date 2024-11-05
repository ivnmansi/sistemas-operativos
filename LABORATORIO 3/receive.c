#include "comunication.h"

int main(){
    
    _mensaje mensaje;
    int longitud=sizeof(mensaje)-sizeof(mensaje.tipo);
    int msqid;

    createQueue(msqid);

    /* Recepción del mensaje */
    int i=0;
    while(1){
        i++;
        printf("%d. ",i);
        readQueue(msqid, mensaje, longitud);
    }

    /* Borrado de la cola de mensajes */
    if(msgctl(msqid, IPC_RMID, 0) == -1){
        printf("Error al eliminar la cola de mensajes \n");
        exit(-1);
    }
    
    return 0;
}