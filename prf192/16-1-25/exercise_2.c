#include <stdio.h>

int main() {
  int a, b;

  printf("Enter a: ");
  scanf("%i", &a);

  printf("Enter b: ");
  scanf("%i", &b);
  printf("-----\n");

  printf("Sum of a & b: %i\n", a + b);
  printf("Difference of a & b: %i\n", a - b);
  printf("Product of a & b: %i\n", a * b);

  if (b == 0) {
    printf("Cannot divide by zero");
  } else {
    printf("Quotient of a & b: %lf\n", (double)a / (double)b);
  }

  return 0;
}
