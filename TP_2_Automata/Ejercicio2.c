// // Automata finito determinista 2
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
 /* tabla de transiciones para todos los posibles estados */
static int tablaDeEstado [5][3] =
    { /* TO} */
      /* 0-9 +,-,*, \0 */

/*0-*/  {1,4,4}, /*0: Estado inicial */
/*1+*/  {1,2,4}, /*1: Estado de aceptacion decimal  */
/*2*/   {3,4,4}, /*2: Se leyo '+' o '-' o '*' '\' */
/*3+*/  {3,2,4}, /*3: Se leyo un nuevo operando */
/*4*/   {4,4,4}, /*4: Estado de ERROR */
};

/* Funcion que asigna los distintos caracteres a los eventos del automata */
int nuevaTransicion (char nuevoCaracter) {
   if ((nuevoCaracter >= '0') && (nuevoCaracter <= '9')) return 0;

   if ((nuevoCaracter == '+') || (nuevoCaracter == '-') || (nuevoCaracter == '*') || (nuevoCaracter == '\0')) return 1;
   
   else return 2;
}

int realizarOperacion(int acumulador, char operadorActual , int valorActual){
   int resultado = 0;
   switch(operadorActual)
  {
   case '+':
      resultado = acumulador + valorActual;
      printf("%d + %d = %d\n", acumulador, valorActual, acumulador + valorActual);
      break;
   case '-':
      resultado = acumulador - valorActual;
      printf("%d - %d = %d\n", acumulador, valorActual, acumulador - valorActual);
      break;
   case '*':
      resultado = acumulador * valorActual;
      printf("%d * %d = %d\n", acumulador, valorActual, acumulador * valorActual);
      break;
   default:
      printf("Operador incorrecto");
  }
  return resultado;
}

int main() {
    /*      3+4*7+3-5     */
   int estadoActual = 0, primeraEjecucion = 1, acumulador;
   char str[80], operadorActual, valorActual[80] = "", operadorSiguiente;
 
   printf("Ingrese la cadena: \n");
   scanf("%s", &str);

   for(int i=0; i < strlen(str);i++) {
      estadoActual = tablaDeEstado[estadoActual][nuevaTransicion(str[i])];

      char charAStr[2];
      charAStr[0] = str[i];
      charAStr[1] = '\0';

      strcat(valorActual, charAStr);

      if (estadoActual == 2){
      
         strcat(valorActual, "\0");
         
         operadorActual = operadorSiguiente;  
         operadorSiguiente = valorActual[strlen(valorActual)-1];
         valorActual[strlen(valorActual)-1] = '\0';
         printf("%s\n",valorActual);

         if (primeraEjecucion == 1){
            acumulador = atoi(valorActual);  
            printf("%s\n",valorActual);
            primeraEjecucion = 0;

         }
         else {
            int valorActual2;
            valorActual2 = atoi(valorActual);
            acumulador = realizarOperacion(acumulador, operadorActual ,valorActual2); 
            printf("%d\n",acumulador);
      
  
         }
         valorActual[0] = '\0';
      }
      
      
   }
      
      return 0;
}


  

