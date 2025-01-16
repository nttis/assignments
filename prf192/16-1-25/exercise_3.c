#include <stdio.h>

int main() {
  int check_num;

  printf("Enter an integer: ");
  scanf("%i", &check_num);

  if (check_num == 0) {
    printf("0 is neither odd nor even");
  } else {
    if (check_num % 2 == 0) {
      printf("%i is even", check_num);
    } else {
      printf("%i is odd", check_num);
    }
  }

  return 0;
}
