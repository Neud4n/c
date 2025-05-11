// Basicamente quiero imprimir el contenido de un archivo
// Autor: d a n
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void leerArchivo(const char * str);

int main(){
    leerArchivo("./01_rope.c");
    return 0;
}

void leerArchivo(const char * str){
    FILE * fptr = fopen(str, "r");
    if(!fptr){
        fprintf(stderr, "No se pudo abrir el archivo %s\n", str);
        exit(EXIT_FAILURE);
    }
    char * line = malloc(100);
    while(fgets(line, 100, fptr) != NULL){
        printf("%s", line);
    }
    fclose(fptr);
    free(line);
}