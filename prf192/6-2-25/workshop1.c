#include <stdio.h>

int main() {
  int number_of_students = 0;

  printf("Enter the number of students: ");

  // Loop forever and try to read input until a valid input is given
  while (1) {
    scanf("%d", &number_of_students);

    if (number_of_students <= 0) {
      printf(
          "The number of students must be larger than 0. Please try again: ");
      continue;
    }

    break;
  }

  float total_score = 0;
  int num_students_passed = 0;

  for (int i = 0; i < number_of_students; i++) {
    float student_score = 0;

    printf("Input score for student %d: ", i + 1);

    // Loop forever and try to read input until a valid input is given
    while (1) {
      scanf("%f", &student_score);

      if (student_score < 0 || student_score > 10) {
        printf("Score must be between 0 and 10. Please try again: ");
        continue;
      }

      if (student_score >= 5) {
        num_students_passed += 1;
      }

      total_score += student_score;
      break;
    }
  }

  printf("Total score of the class: %.2f\n", total_score);
  printf("Average score of the class: %.2f\n",
         (double)total_score / number_of_students);
  printf("Number of students who passed: %d\n", num_students_passed);

  return 0;
}
