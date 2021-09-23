// // Automata finito determinista 1
#include <string.h>
#include <stdio.h>
int nuevaTransicion (char);

 /* tabla de transiciones para todos los posibles estados */
static int tablaDeEstado [8][7] =
    { /* TO, T1, T2, T3, T4, T5, T6} */
      /* +-, 0, 17, 89, xX, afAF, Otro} */

/*0-*/  {1, 3, 2, 2, 7, 7, 7}, /*0: Estado inicial */
/*1*/   {7, 7, 2, 2, 7, 7, 7}, /*1: Se leyo '+' o '-'  */
/*2+*/  {7, 2, 2, 2, 7, 7, 7}, /*2: Estado de aceptacion decimal */
/*3*/   {7, 4, 4, 7, 5, 7, 7}, /*3: Se leyo un '0' */
/*4+*/  {7, 4, 4, 7, 7, 7, 7}, /*4: Estado de aceptacion OCTAL */
/*5*/   {7, 6, 6, 6, 7, 6, 7}, /*5: Se leyeron caracteres 'x, X' */
/*6+*/  {7, 6, 6, 6, 7, 6, 7}, /*6: Estado de aceptacion HEXADECIMAL */
/*7+*/  {7, 7, 7, 7, 7, 7, 7} /*7: Estado de 'ERROR', o rechazo */
   };

/* Funcion que asigna los distintos caracteres a los eventos del automata */
int nuevaTransicion (char nuevoCaracter) {
   if ((nuevoCaracter == '+') || (nuevoCaracter == '-')) return 0;
   else if (nuevoCaracter == '0') return 1;
   else if ((nuevoCaracter >= '1') && (nuevoCaracter <= '7')) return 2;
   else if ((nuevoCaracter >= '8') && (nuevoCaracter <= '9')) return 3;
   else if ((nuevoCaracter == 'x') || (nuevoCaracter == 'X')) return 4;
   else if (((nuevoCaracter >= 'A') && (nuevoCaracter <= 'F')) || ((nuevoCaracter >= 'a') && (nuevoCaracter <= 'f'))) return 5;
   else return 6;
}

 int main (void) {
   int estadoActual = 0, contadorDecimal = 0, contadorHexadecimal = 0, contadorOctal = 0;
   char str[80];
   const char s[2] = "&";
   char *token;
   
   printf("Ingrese la cadena: \n");
   scanf("%s", &str);

   /* Función: Dividir la cadena str en una serie de tokens usando el delimitador delim . */
   token = strtok(str, s);

   /* Clasifica los tokens y resetea el token y el estadoActual */
   while( token != NULL ) {
      for(int i=0; i < strlen(token);i++){
         estadoActual = tablaDeEstado[estadoActual][nuevaTransicion(token[i])];
      }
      
      if (estadoActual == 2){
        printf("La cadena %s ingresada es decimal \n",token);
        contadorDecimal++;    
     }
     else if (estadoActual == 4){
        printf("La cadena %s ingresada es octal \n",token);
        contadorHexadecimal++;
     }
     else if (estadoActual == 6){
        printf("La cadena %s ingresada es hexadecimal \n",token);
        contadorOctal++;
     }
     else printf("La cadena %s ingresada es erronea \n",token);

     token = strtok(NULL, s);
     estadoActual = 0;
   }

   printf("El total de cadenas decimales ingresadas es: %d\n",contadorDecimal);
   printf("El total de cadenas octales ingresadas es: %d\n",contadorOctal);
   printf("El total de cadenas hexadecimales ingresadas es: %d\n",contadorHexadecimal);
  
   return 0;
}

