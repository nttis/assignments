#include <stdbool.h>
#include <stdio.h>

#define MAX_DAYS 100

typedef struct {
  int sales[MAX_DAYS];
  int days[MAX_DAYS];
  int count;
} sales_data;

sales_data input_sales() {
  int num_days;

  while (1) {
    printf("Enter the number of days to input data: ");
    scanf("%d", &num_days);

    if (num_days < 1 || num_days > MAX_DAYS) {
      printf("Invalid number of days. Please try again.\n");
      continue;
    }

    break;
  }

  sales_data data = {
      .sales = {},
      .days = {},
      .count = num_days,
  };

  for (int i = 0; i < num_days; i++) {
    int input;

    printf("Enter sales data for day %d: ", i + 1);
    scanf("%d", &input);

    data.sales[i] = input;
    data.days[i] = i + 1;
  }

  return data;
}

void display_sales(sales_data data) {
  printf("Sales data:\n");

  for (int i = 0; i < data.count; i++) {
    printf("Day %d: %d\n", i + 1, data.sales[i]);
  }
}

// Sort using the bubble sort algorithm
sales_data sort_ascending(sales_data data) {
  while (1) {
    bool swapped = false;

    for (int i = 1; i < data.count; i++) {
      if (data.sales[i - 1] > data.sales[i]) {
        // Swap both the actual sales number and the day that the sales
        // corresponds to
        int temp = data.sales[i - 1];
        int days_temp = data.days[i - 1];

        data.sales[i - 1] = data.sales[i];
        data.sales[i] = temp;

        data.days[i - 1] = data.days[i];
        data.days[i] = days_temp;

        swapped = true;
      }
    }

    if (swapped == false) {
      break;
    }
  }

  return data;
}

// Sort using the bubble sort algorithm
sales_data sort_descending(sales_data data) {
  while (1) {
    bool swapped = false;

    for (int i = 1; i < data.count; i++) {
      if (data.sales[i - 1] < data.sales[i]) {
        // Swap both the actual sales number and the day that the sales
        // corresponds to
        int temp = data.sales[i - 1];
        int days_temp = data.days[i - 1];

        data.sales[i - 1] = data.sales[i];
        data.sales[i] = temp;

        data.days[i - 1] = data.days[i];
        data.days[i] = days_temp;

        swapped = true;
      }
    }

    if (swapped == false) {
      break;
    }
  }

  return data;
}

void search_greater_than(sales_data data, int target) {
  printf("Sales greater than %d:\n", target);

  for (int i = 0; i < data.count; i++) {
    if (data.sales[i] > target) {
      printf("Day %d: %d\n", data.days[i], data.sales[i]);
    }
  }
}

int main() {
  sales_data data = {};
  int choice, target;

  while (1) {
    // Display the menu
    printf("\nEnhanced Sales Data Management Menu ==\n");
    printf("1. Input sales data\n");
    printf("2. Display sales data\n");
    printf("3. Sort sales data in ascending order\n");
    printf("4. Sort sales data in descending order\n");
    printf("5. Search for sales data greater than a target\n");
    printf("6. Exit program\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);
    printf("\n");

    switch (choice) {
    case 1:
      data = input_sales();
      printf("Data input complete.\n");

      break;

    case 2:
      if (data.count <= 0) {
        printf("There is no data. Please input data first.\n");
        break;
      }

      display_sales(data);

      break;

    case 3:
      if (data.count <= 0) {
        printf("There is no data. Please input data first.\n");
        break;
      }

      data = sort_ascending(data);

      printf("Sales data sorted in ascending order:\n");
      for (int i = 0; i < data.count; i++) {
        printf("Sales of day %d: %d\n", data.days[i], data.sales[i]);
      }

      break;

    case 4:
      if (data.count <= 0) {
        printf("There is no data. Please input data first.\n");
        break;
      }

      data = sort_descending(data);

      printf("Sales data sorted in descending order:\n");
      for (int i = 0; i < data.count; i++) {
        printf("Sales of day %d: %d\n", data.days[i], data.sales[i]);
      }

      break;

    case 5:
      if (data.count <= 0) {
        printf("There is no data. Please input data first.\n");
        break;
      }

      int target;

      printf("Input the target to search for: ");
      scanf("%d", &target);

      search_greater_than(data, target);
      break;

    case 6:
      printf("Exiting program.\n");
      return 0;
    }
  }

  return 0;
}
