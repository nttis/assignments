#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Function to compute Greatest Common Divisor using the Euclidean algorithm
int gcd(int a, int b) {
  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }

  return abs(a);
}

// Function to compute Least Common Multiple
int lcm(int a, int b) {
  // Calculate GCD first
  int gcd_ab = gcd(a, b);

  // The GCD being 0 must be considered a special case
  if (gcd_ab == 0) {
    return 0;

  } else {
    // Calculate LCM using the formula
    // We use abs to ensure the result is non-negative
    int lcm = abs(a * b) / gcd_ab;
    return lcm;
  }
}

// Function to determine whether a number is a prime number
bool determine_prime(int num) {
  for (int i = 2; i <= sqrt(num); i++) {
    if (num % i == 0) {
      // num is divisible by this number, therefore it is not prime
      return false;
    }
  }

  return true;
}

int main() {
  int choice;

  while (1) {
    // Ask for choice
    printf("\n-- Menu --\n");
    printf("1. Calculate Least Common Multiple\n");
    printf("2. Calculate Greatest Common Divisor\n");
    printf("3. Find the smallest and largest primes from 1-n\n");

    printf("Your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    // Brackets to scope each of these cases
    case 1: {
      int a, b;

      printf("Enter a: ");
      scanf("%d", &a);

      printf("Enter b: ");
      scanf("%d", &b);

      printf("LCM of %d and %d: %d\n", a, b, lcm(a, b));
      break;
    }

    case 2: {
      int a, b;

      printf("Enter a: ");
      scanf("%d", &a);

      printf("Enter b: ");
      scanf("%d", &b);

      printf("GCD of %d and %d: %d\n", a, b, gcd(a, b));
      break;
    }

    case 3: {
      int n;

      printf("Enter n: ");
      scanf("%d", &n);

      if (n < 2) {
        printf("n must be at least 2. Please try again.\n");
        break;
      }

      if (n < 3) {
        // 3 is the smallest possible prime number in [1, n]
        printf("There are no prime numbers in this range.\n");
        break;
      }

      int smallest_prime = 3;
      int largest_prime = 3;

      for (int i = 2; i <= n; i++) {
        bool is_prime = determine_prime(i);
        if (is_prime && i > largest_prime) {
          largest_prime = i;
        }
      }

      printf("The smallest prime found: %d\n", smallest_prime);
      printf("The largest prime found: %d\n", largest_prime);
    }

    default:
      printf("Invalid choice.\n");
      break;
    }
  }

  return 0;
}
