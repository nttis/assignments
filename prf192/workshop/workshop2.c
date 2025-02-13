#include <stdio.h>

float input_basic_salary() {
  float salary = 0;

  printf("Input the basic salary: ");

  while (1) {
    scanf("%f", &salary);

    if (salary < 0) {
      printf("Invalid salary. Salary must be at least 0. Try again: ");
      continue;
    }

    break;
  }

  return salary;
}

int allowance_category(float basic_salary) {
  if (basic_salary < 6e6) {
    return 0;
  } else if (basic_salary >= 6e6 && basic_salary <= 15e6) {
    return 1;
  } else {
    return 2;
  }
}

double calculate_allowance(float basic_salary) {
  int allowance_type = allowance_category(basic_salary);
  float allowance = 0;

  switch (allowance_type) {
  case 0:
    allowance = 0.25;
    break;
  case 1:
    allowance = 0.15;
    break;
  case 2:
    allowance = 0.1;
    break;
  }

  return allowance;
}

float calculate_tax(float salary) {
  float income_tax = 0;

  if (salary > 8e6) {
    float amount_exceeding = salary - 8e6;
    income_tax = amount_exceeding * 0.1;
  }

  return income_tax;
}

int main() {
  int num_employees = 0;
  int count_25 = 0, count_15 = 0, count_10 = 0;
  float company_salary = 0;

  // Input the number of employees and validate it
  printf("Input the number of employees: ");

  while (1) {
    scanf("%d", &num_employees);

    if (num_employees < 1) {
      printf("There must be at least 1 employee. Try again: ");
      continue;
    }

    break;
  }

  // Process each employee
  for (int i = 0; i < num_employees; i++) {
    printf("== Processing employee %d ==\n", i);

    // Function to input basic salary
    float basic_salary = input_basic_salary();

    // Function to calculate allowance
    float allowance_multiplier = calculate_allowance(basic_salary);
    float total_salary = basic_salary + (basic_salary * allowance_multiplier);

    // Count allowance category
    int allowance_type = allowance_category(basic_salary);

    switch (allowance_type) {
    case 0:
      count_25 += 1;
      break;
    case 1:
      count_15 += 1;
      break;
    case 2:
      count_10 += 1;
      break;
    }

    // Calculate net income and income tax
    float income_tax = calculate_tax(total_salary);
    float net_income = total_salary - income_tax;

    // Update total company salary
    company_salary += net_income;

    // Display employee details
    printf("Basic salary: %.2f\n", basic_salary);
    printf("Allowance: %.2f\n", basic_salary * allowance_multiplier);
    printf("Tax deduction: %.2f\n", income_tax);
    printf("Net income: %.2f\n", net_income);
    printf("\n");
  }

  // Display salary statistics
  printf("Total salary cost of the company: %.2f\n", company_salary);
  printf("Employees with allowance of 25%%: %d\n", count_25);
  printf("Employees of allowance of 15%%: %d\n", count_15);
  printf("Employees of allowance of 10%%: %d\n", count_10);

  return 0;
}

