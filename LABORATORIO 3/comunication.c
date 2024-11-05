#include "comunication.h"

void createQueue(int msqid){
    if((msqid=msgget(clave, IPC_CREAT | 0600)) == -1){
        printf("Error al crear la cola de mensajes \n");
        exit(-1);
    }
}

void readQueue(int msqid, _mensaje mensaje, int longitud){
    if(msgrcv(msqid, &mensaje, longitud, 1, 0) == -1){
        printf("Error al leer un mensaje de la cola de mensajes \n");
        exit(-1);
    }
    printf("El mensaje leido en RECEIVE es: %s\n", mensaje.cadena);
}

char* generateRandomWord() {
    int length = rand() % 10 + 1;
    char* word = (char*)malloc(length + 1);
    if (!word) {
        printf("Error: No se pudo asignar memoria para la palabra generada\n");
        return NULL;
    }
    for (int i = 0; i < length; i++) {
        word[i] = 'a' + rand() % 26;
    }
    word[length] = '\0';
    return word;
}

void sendMessage(int msqid, _mensaje mensaje, int longitud){
    /*preparacion del mensaje*/
    mensaje.tipo=1;
    strcpy(mensaje.cadena,generateRandomWord());
    printf("Mensaje enviado desde SEND: %s\n", mensaje.cadena);

    /*envio del mensaje*/
    if(msgsnd(msqid,&mensaje,longitud,0)==-1){
        printf("Error al enviar el mensaje \n");
        exit(1);
    }
}