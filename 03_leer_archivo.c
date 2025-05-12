// Basicamente quiero imprimir el contenido especifico de un archivo.
// Autor: d a n
#include <stdio.h>
#include <stdlib.h>

typedef struct Proceso{
    int pid;
    char name[50];
}Proceso;

void leerArchivo(const char * str);

int main(){
    leerArchivo("./status");
    return 0;
}

void leerArchivo(const char * str){
    FILE * fptr = fopen(str, "r");
    if(!fptr){
        fprintf(stderr, "No se pudo abrir el archivo %s\n", str);
        exit(EXIT_FAILURE);
    }
    char * line = malloc(100);
    Proceso p;
    while(fgets(line, 100,fptr) != NULL){
        if((sscanf(line,"Name:\t%s", p.name)) == 1){
            printf("Proceso: %s\n", p.name);
        }
        if((sscanf(line,"Pid:\t%d", &p.pid)) == 1){
            printf("PID: %i\n", p.pid);
        }
    }
    fclose(fptr);
    free(line);
}

    // Lineas de código que al final no uso.
    //char * processName = "Name";
    //char * processPid = "Pid";
    //char * searched;
    /*
    while(fgets(line, 100, fptr) != NULL){
        if((searched = strstr(line, processName)) != NULL){
            sscanf(line,"Name:\t%s", name);
        }
        if((searched = strstr(line, processPid)) != NULL){
            sscanf(line,"Pid:\t%d", &pid);
        }
    }
    */