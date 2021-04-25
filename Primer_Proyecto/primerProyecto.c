#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    int edad;
    char nombre[20];
    printf("%s", "Ingrese edad \n");
    scanf("%d",&edad);
    printf("%s","Ingrese nombre \n");
    scanf("%s",nombre);
    printf("Hola su edad es %d y su nombre %s \n", edad,nombre);
    system("pause");
    return 0;
}