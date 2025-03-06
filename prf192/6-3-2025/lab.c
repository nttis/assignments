#include <stdio.h>

#define MAX_CUSTOMERS 100

typedef struct {
  int accountNumber;
  double balance;

  char accountType[20];
  char accountHolderName[40];
} customer_account;

void print_customer_info(customer_account customer) {
  printf("== Customer %d ==\n", customer.accountNumber + 1);
  printf("Account number: %d\n", customer.accountNumber);
  printf("Account type: %s\n", customer.accountType);
  printf("Account holder name: %s\n", customer.accountHolderName);
  printf("Account balance: %lf\n", customer.balance);
}

int main() {
  customer_account customers[MAX_CUSTOMERS];

  int num_customers;
  printf("Enter number of customers: ");
  scanf("%d", &num_customers);

  if (num_customers <= 0) {
    printf("The number of customers must be greater than 0.\n");
    return 1;
  }

  for (int i = 0; i < num_customers; i++) {
    customer_account customer;

    printf("== Entering information of customer %d ==\n", i + 1);

    printf("Enter the account type: ");
    scanf("%s", customer.accountType);

    printf("Enter the account holder name: ");
    scanf("%s", customer.accountHolderName);

    printf("Enter the balance: ");
    int args = scanf("%lf", &customer.balance);

    // User may enter an invalid number
    if (args != 1) {
      printf("Entered balance is invalid. Please enter a number.\n");
      return 1;
    }

    customer.accountNumber = i;
    customers[i] = customer;
  }

  printf("\n");

  for (int i = 0; i < num_customers; i++) {
    customer_account customer = customers[i];

    // Print out customer information
    print_customer_info(customer);
  }

  printf("\n== Customers with balance greater than 1000$ ==\n");

  for (int i = 0; i < num_customers; i++) {
    customer_account customer = customers[i];
    if (customer.balance < 1000) {
      continue;
    }

    print_customer_info(customer);
  }

  return 0;
}
