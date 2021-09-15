// // Automata finito determinista 2
#include <string.h>
#include <stdio.h>

// int operar (int decimal, int decimal2 , char digito ){
//    int suma, resta, multiplicacion;
//    suma = decimal + decimal2;
//    resta = decimal - decimal2;
//    multiplicacion = decimal * decimal2;
// }


int main() {
  char operator;
  int firstNumber, secondNumber;

  printf("Enter an operator (+, -, *, /) : ");
  scanf("%c", &operator);

  printf("Enter two operands: ");
  scanf("%d %d", &firstNumber, &secondNumber);

  switch(operator)
  {
    case '+':
      printf("%.1d + %.1d = %.1d\n", firstNumber, secondNumber, firstNumber + secondNumber);
      break;
    case '-':
      printf("%.1d - %1.d = %.1d\n", firstNumber, secondNumber, firstNumber - secondNumber);
      break;
    case '*':
      printf("%.1d * %.1d = %.1d\n", firstNumber, secondNumber, firstNumber * secondNumber);
      break;
    case '/':
      printf("%.1d / %.1d = %.1d\n", firstNumber, secondNumber, firstNumber / secondNumber);
      break;
    default:
      printf("Operator is not correct");
  }
  
  return 0;
}