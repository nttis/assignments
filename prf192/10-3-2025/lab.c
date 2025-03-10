#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
  char input[MAX_LENGTH];

  printf("Input a string (max 100 characters): ");
  char *success = fgets(input, MAX_LENGTH, stdin);

  if (success == NULL) {
    // fgets returns a null pointer on failure
    printf("Failed to read input.");
    return 1;
  }

  // Length of the string
  printf("Length of the string (including spaces): %lu\n",
         strlen(input) - 1); // -1 because we don't count the NULL terminator

  // Some statistics
  int num_spaces = 0;
  int num_uppercase_chars = 0;
  int num_lowercase_chars = 0;

  for (int i = 0; i < MAX_LENGTH; i++) {
    if (input[i] == '\0') {
      // Encountered a NULL terminator, which means the end of the string
      // Abort the loop
      break;
    }

    if (isspace(input[i])) {
      num_spaces += 1;
    }

    if (isupper(input[i])) {
      num_uppercase_chars += 1;
    }

    if (islower(input[i])) {
      num_lowercase_chars += 1;
    }
  }

  // fgets reads the input file until it finds a newline character.
  // The newline character \n is also considered a "space" by isspace(),
  // therefore we subtract 1 to discount the newline character.
  printf("The number of spaces in the string: %d\n", num_spaces - 1);
  printf("The number of uppercase characters: %d\n", num_uppercase_chars);
  printf("The number of lowercase characters: %d\n", num_lowercase_chars);

  return 0;
}
