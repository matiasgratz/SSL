#include <stdio.h>

int main() {
  char Operador;
  int primerNumero, segundoNumero;

  printf("Ingrese un operador (+, -, *, /) : ");
  scanf("%c", &Operador);

  printf("Ingrese Operandos: ");
  scanf("%d %d", &primerNumero, &segundoNumero);

  switch(Operador)
  {
    case '+':
      printf("%.1d + %.1d = %.1d\n", primerNumero, segundoNumero, primerNumero + segundoNumero);
      break;
    case '-':
      printf("%.1d - %1.d = %.1d\n", primerNumero, segundoNumero, primerNumero - segundoNumero);
      break;
    case '*':
      printf("%.1d * %.1d = %.1d\n", primerNumero, segundoNumero, primerNumero * segundoNumero);
      break;
    case '/':
      printf("%.1d / %.1d = %.1d\n", primerNumero, segundoNumero, primerNumero / segundoNumero);
      break;
    default:
      printf("Operador incorrecto");
  }

  return 0;
}