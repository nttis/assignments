#define MAX_SIZE 100

#include <stdio.h>

void input_array(int arr[], int *size) {
  int input_size = 0;

  while (1) {
    printf("Input the number of elements to input into the array [1-%d]: ",
           MAX_SIZE);

    scanf("%d", &input_size);

    if (input_size < 1 || input_size > 100) {
      printf("Number of elements is invalid. Please try again.\n");
      continue;
    }

    break;
  }

  for (int i = 0; i < input_size; i++) {
    int element = 0;

    printf("Input number %d: ", i + 1);
    scanf("%d", &element);

    arr[i] = element;
  }

  (*size) = input_size;

  printf("Data input complete.\n");
}

void display_array(int arr[], int size) {
  printf("[ ");

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  printf("]\n");
}

int search_value(int arr[], int size, int value) {
  int found_index = -1;

  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      found_index = i;
      break; // Return early if the value is found early
    }
  }

  return found_index;
}

void calculate_statistics(int arr[], int size) {
  int sum = 0;
  int max = 0;
  int min = arr[0]; // Initialize to the first value of the array2
  float average;

  for (int i = 0; i < size; i++) {
    sum += arr[i];

    if (max < arr[i]) {
      max = arr[i];
    }

    if (min > arr[i]) {
      min = arr[i];
    }
  }

  average = (float)sum / size;

  printf("Sum: %d\n", sum);
  printf("Maximum: %d\n", max);
  printf("Minimum: %d\n", min);
  printf("Average: %.2f\n", average);
}

int main() {
  int choice = -1; // -1 is default value before the user chooses a program

  int arr_size = 0;
  int arr[MAX_SIZE] = {};

  while (1) {
    // Display the menu
    printf("\n-- Menu --\n");
    printf("1. Input data\n");
    printf("2. Display array\n");
    printf("3. Search for a number\n");
    printf("4. Calculate statistics\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch (choice) {
    case 1:
      // Input data
      input_array(arr, &arr_size);
      break;

    case 2:
      // Display data
      if (arr_size <= 0) {
        printf("There is no data in the array. Please input data first.\n");
        break;
      }

      display_array(arr, arr_size);

      break;

    case 3:
      // Search for a number
      if (arr_size <= 0) {
        printf("There is no data in the array. Please input data first.\n");
        break;
      }

      int num_to_search = 0;

      printf("Enter the number to search for: ");
      scanf("%d", &num_to_search);

      int index = search_value(arr, arr_size, num_to_search);

      if (index == -1) {
        printf("The number %d was not found in the array.\n", num_to_search);
      } else {
        printf("The number %d was found at index %d.\n", num_to_search, index);
      }

      break;
    case 4:
      // Calculate statistics
      if (arr_size <= 0) {
        printf("There is no data in the array. Please input data first.\n");
        break;
      }

      calculate_statistics(arr, arr_size);

      break;
    case 5:
      // Exit
      printf("Exiting the program.\n");
      return 0;

    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
