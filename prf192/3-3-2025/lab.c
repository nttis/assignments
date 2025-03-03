#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

double getDouble(double lower_limit, double upper_limit) {
  char buffer[100 + 1]; // an extra 1 for the null terminator

  while (1) {
    printf("Enter a number between %.2lf and %.2lf: ", lower_limit,
           upper_limit);

    if (fgets(buffer, 100, stdin) == NULL) {
      // According to the C standard:
      //    Upon successful completion, fgets() shall return s.
      // Thus if fgets return NULL, then it was not a succesful read.

      printf("Failed to read input.\n");
      continue;
    };

    // strtod will read the null-terminated string in buffer and convert it into
    // a double. If there are no digits (ie. no conversion was made), endptr
    // will be set to buffer.
    char *endptr;
    double converted = strtod(buffer, &endptr);

    // Check if there are digits here.
    if (endptr == buffer) {
      printf("No digits were found.\n");
      continue;
    }

    // When strtod successfully converts a string to a double, it will set
    // endptr to the character AFTER the last character used in the conversion.
    //
    // In our case, our string is null-terminated, so under normal circumstances
    // the endptr will be set to \0 (NUL).
    //
    // However, if the user intentionally input a string with invalid trailing
    // characters, we have to check for them.
    //
    // Thus, input is only considered valid if:
    //    1. endptr = '\0', that is, the endptr points to a NUL character.
    //    2. endptr is checked with isspace(). isspace() will tell us if endptr
    //       is pointing at a line feed character (\n, \r, \t, \f) or a space
    //       (0x20 ASCII). Since fgets() only terminate at any line feed
    //       character, endptr will almost always point to a line feed character
    //       instead of a NUL character. Thus, we ignore these line feed
    //       characters.
    //    3. The endptr is not pointing to a space (0x20 ASCII). While we ignore
    //       line feed characters we cannot ignore spaces, because there can
    //       potentially be extra input after a space.
    if ((*endptr != '\0' && !isspace(*endptr)) || *endptr == 0x20) {
      printf("There were trailing characters in your input.\n");
      continue;
    }

    if (converted < lower_limit || converted > upper_limit) {
      printf("Your input is out of bounds.\n");
      continue;
    }

    return converted;
  }

  return 0;
}

int main() {
  double lower_limit = -50000; // +-1.7e+308 are the limits of double values
  double upper_limit = 50000;
  double validated = getDouble(lower_limit, upper_limit);

  printf("Your input of %.2lf is valid!", validated);
}
