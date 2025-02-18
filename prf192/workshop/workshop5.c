#include <stdio.h>

#define MAX_SIZE 100

int read_file_to_array(const char *filename, int arr[], int *size) {
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    // file failed to open
    printf("Failed to open file.");
    return 1;
  }

  int count = 0;

  while (1) {
    int read = fscanf(file, "%d", &arr[count]);
    if (read < 0) {
      // fscanf returns negative value -> failed to read a number
      break;
    }

    count += 1;
  }

  (*size) = count;

  return 0;
}

void display_array(int arr[], int size) {
  printf("Data in the array:\n");

  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
}

void calculate_statistics(int arr[], int size, int *sum, int *max, int *min,
                          float *average) {
  *sum = 0; // Initilize the values to 0 to avoid undefined behavior errors
  *min = arr[0];
  *max = 0;

  for (int i = 0; i < size; i++) {
    *sum += arr[i];

    if (*max < arr[i]) {
      *max = arr[i];
    }

    if (*min > arr[i]) {
      *min = arr[i];
    }
  }

  *average = (float)*sum / size;

  printf("Statistics:\n");
  printf("Sum: %d\n", (*sum));
  printf("Average: %.2f\n", *average);
  printf("Maximum: %d\n", *max);
  printf("Minimum: %d\n", *min);
}

int write_results_to_file(const char *filename, int sum, int min, int max,
                          float average) {
  FILE *file = fopen(filename, "w+");

  if (file == NULL) {
    printf("Failed to open file");
    return 1;
  }

  fprintf(file, "Sum: %d\nAverage: %.2f\nMaximum: %d\nMinimum: %d", sum,
          average, max, min);

  return 0;
}

int main() {
  int arr[MAX_SIZE], size = 0;
  int sum, max, min;
  float average;

  // Read data from file
  int success = read_file_to_array("data.txt", arr, &size);
  if (success != 0) {
    // Return code not 0 -> error encountered
    return success;
  }

  // Display the array
  display_array(arr, size);

  // Calculate statistics
  printf("\n\n");
  calculate_statistics(arr, size, &sum, &max, &min, &average);

  // Write results to file
  int success_write =
      write_results_to_file("results.txt", sum, min, max, average);

  if (success_write == 0) {
    printf("Results written to file successfully\n");
  }

  return success_write;
}
