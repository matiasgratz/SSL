// // Automata finito determinista 2
#include <string.h>
#include <stdio.h>

int nuevaTransicion (char);

 /* tabla de transiciones para todos los posibles estados */
static int tablaDeEstado [3][2] =
    { /* TO} */
      /* 0-9} */

/*0-*/  {1,2}, /*0: Estado inicial */
/*1*/   {1,2}, /*1: Se leyo '+' o '-'  */
/*2+*/  {2,2}, /*2: Estado de aceptacion decimal */

};

/* Funcion que asigna los distintos caracteres a los eventos del automata */
int nuevaTransicion (char nuevoCaracter) {
   if ((nuevoCaracter >= '0') || (nuevoCaracter <= '9')) return 0;
   else return 1;
}

int main() {
    /*      3+4*7+3-5     */
int estadoActual = 0;
char str[80];

printf("Ingrese la cadena: \n");
scanf("%s", &str);
 for(int i=0; i < strlen(str);i++){
         estadoActual = tablaDeEstado[estadoActual][nuevaTransicion(str[i])];
      }
  if (estadoActual == 1){
        printf("La cadena %s ingresada es decimal \n",str);    
     }
  else printf("La cadena %s ingresada es erronea \n",str);
  
  return 0;
}
