#ifndef COMUNICATION_H
#define COMUNICATION_H

    
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/msg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <time.h>

    #define clave 666

    typedef struct{
        long tipo;
        char cadena[256];
    } _mensaje;

    
    char* generateRandomWord();

    void createQueue(int msqid);

    void readQueue(int msqid, _mensaje mensaje, int longitud);

    void sendMessage(int msqid, _mensaje mensaje, int longitud);

    
#endif