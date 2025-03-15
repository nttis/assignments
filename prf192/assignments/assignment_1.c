#include <stdio.h>
#include <string.h>

// The assignment requires reading/writing data from a binary file, but did not
// specify how the binary data should look like. Because of this, I hereby
// define the data format:
//
// The sole purpose of the binary file is to store a list of Products. Because
// we know ahead of time exactly how much data each Product struct takes, we can
// very simply store all Products contiguously. This essentially forms a series
// of "blocks", where each block is sizeof(struct Product) bytes long.
//
// Note: Product.product_name is a NUL-terminated string. All bytes after the
// NUL-terminator are undefined.

#define PRODUCT_NAME_MAX 50

// Define the structure for product information
struct Product {
  int product_id;
  char product_name[PRODUCT_NAME_MAX];
  float price;
  int quantity;
};

// This will return 0 on success, 1 on failure
int writeProductsToFile(FILE *output_file, int numProducts) {
  for (int i = 0; i < numProducts; i++) {
    struct Product input_product;

    printf("\nEnter details for product %d\n", i + 1);

    printf("Product ID: ");
    scanf("%d", &input_product.product_id);

    printf("Product Name: ");
    scanf("%s", input_product.product_name);

    printf("Price: ");
    scanf("%f", &input_product.price);

    printf("Quantity: ");
    scanf("%d", &input_product.quantity);

    // Write the entire struct to the output file at once
    // sizeof(struct Product) is to tell C to write that many bytes
    // 1 means only 1 element (1 struct) is written
    int num_written =
        fwrite(&input_product, sizeof(struct Product), 1, output_file);

    if (num_written < 1) {
      // fwrite() returns the number of elements written successfully.
      // In our case, we are only writing 1 element, so if num_written < 1,
      // nothing was written and the operation failed.
      return 1;
    }
  }

  if (fclose(output_file) != 0) {
    // fclose() returns 0 on success
    // If it returns something different, just print out a message
    // to the user but don't abort the program, because by this point
    // all data should have been written to file.
    printf("Warning: failed to close file!\n");
  }

  return 0;
}

void writeProducts(const char *filename, int numProducts) {
  // w: open file for writing, creating the file if it does
  // not already exist; truncates the file otherwise
  // b: only exists to maintain ISO C compatibility, has no actual effects.
  // Supposed to signify that the file is opened as binary.
  FILE *output_file = fopen(filename, "wb");
  if (output_file == NULL) {
    // If we fail to open the file just abort and return early
    printf("Failed to open %s file!\n", filename);
    return;
  }

  int success = writeProductsToFile(output_file, numProducts);
  if (success != 0) {
    printf("Failed to write to file!\n");
    return;
  }

  printf("\nProducts have been written to the file successfully.\n\n");
}

void appendProducts(const char *filename, int numProducts) {
  // a: open file for writing at the end.
  // b: binary file
  FILE *output_file = fopen(filename, "ab");
  if (output_file == NULL) {
    // If we fail to open the file just abort and return early
    printf("Failed to open %s file!\n", filename);
    return;
  }

  int success = writeProductsToFile(output_file, numProducts);
  if (success != 0) {
    printf("Failed to write to file!\n");
    return;
  }

  printf("\nProducts have been appended to the file successfully.\n\n");
}

int readNextProduct(FILE *file, struct Product *product) {
  int num_read = fread(product, sizeof(struct Product), 1, file);

  if (num_read != 1) {
    // fread() returns the number of items read. If it returns less than what
    // was expected, there is a possibilty of errors.
    // However, it could either have reached the end of file, or there was a
    // genuine error. Check for that here.
    if (feof(file) != 0) {
      // feof() != 0 if the file reached the end
      return 2;
    } else {
      return 1;
    }
  }

  return 0;
}

void readProducts(const char *filename) {
  // r: open for reading
  // b: binary
  FILE *product_file = fopen(filename, "rb");
  if (product_file == NULL) {
    // If we fail to open the file just abort and return early
    printf("Failed to open %s file!\n", filename);
    return;
  }

  printf("\nReading products from file:\n");

  // // Extreme maths:tm: to calculate a properly formatted table
  // // define the maximum lengths for each column
  int space_between_column = 3;

  int max_id_length = strlen("Product ID");
  int max_name_length = strlen("Product Name");
  int max_price_length = strlen("Price");
  int max_quantity_length = strlen("Quantity");

  while (1) {
    // continuously read Products from the file until we fail to read more
    struct Product product;

    int success = readNextProduct(product_file, &product);
    if (success == 1) {
      printf("Failed to read products from file!\n");
      return;
    } else if (success == 2) {
      break;
    }

    // calculate max product id length
    int id_length = snprintf(NULL, 0, "%d", product.product_id);
    if (id_length < 0) {
      printf("Failed to read products!\n");
      return;
    }

    if (id_length > max_id_length) {
      max_id_length = id_length;
    }

    // calculate max product name length
    if (strlen(product.product_name) > max_name_length) {
      max_name_length = strlen(product.product_name);
    }

    // calculate max price length
    int price_length = snprintf(NULL, 0, "%.2f", product.price);
    if (price_length < 0) {
      printf("Failed to read products!\n");
      return;
    }

    if (price_length > max_price_length) {
      max_price_length = price_length;
    }

    // calculate max quantity length
    int quantity_length = snprintf(NULL, 0, "%d", product.quantity);
    if (quantity_length < 0) {
      printf("Failed to read products!\n");
      return;
    }

    if (quantity_length > max_quantity_length) {
      max_quantity_length = quantity_length;
    }
  }

  max_id_length += space_between_column;
  max_name_length += space_between_column;
  max_price_length += space_between_column;
  max_quantity_length += space_between_column;

  int total_length =
      max_id_length + max_name_length + max_price_length + max_quantity_length;

  for (int i = 0; i < total_length; i++) {
    printf("-");
  }

  // Each heading uses the format: %-*s, which means:
  // %: starter
  // -: right-pad the string
  // *: pad to the number provided
  // s: a string
  printf("\n%-*s%-*s%-*s%-*s\n", max_id_length, "Product ID", max_name_length,
         "Product Name", max_price_length, "Price", max_quantity_length,
         "Quantity");

  for (int i = 0; i < total_length; i++) {
    printf("-");
  }
  printf("\n");

  if (fseek(product_file, 0, SEEK_SET) != 0) {
    printf("Failed to read products file!\n");
  };

  while (1) {
    // continuously read Products from the file until we fail to read more
    struct Product product;

    int success = readNextProduct(product_file, &product);
    if (success == 1) {
      printf("Failed to read products from file!\n");
      return;
    } else if (success == 2) {
      break;
    }

    // print product data
    printf("%-*d%-*s%-*.2f%-*d\n", max_id_length, product.product_id,
           max_name_length, product.product_name, max_price_length,
           product.price, max_quantity_length, product.quantity);
  }

  printf("\n");
  fclose(product_file);
}

void modifyProduct(const char *filename) {
  // r+: read and write and does NOT truncate the file
  FILE *product_file = fopen(filename, "r+b");
  if (product_file == NULL) {
    // If we fail to open the file just abort and return early
    printf("Failed to open %s file!\n", filename);
    return;
  }

  int product_id;

  printf("\nEnter the Product ID to modify: ");
  scanf("%d", &product_id);

  struct Product product;
  int found_product = 0;

  while (1) {
    int success = readNextProduct(product_file, &product);
    if (success == 0) {
      if (product.product_id == product_id) {
        found_product = 1;
        break;
      }
    } else {
      break;
    }
  }

  if (found_product != 1) {
    // didn't find any matching product
    printf("Could not find Product with ID %d!\n\n", product_id);
    return;
  }

  // rewind the file's cursor backwards sizeof(struct Product)
  // so we would be writing to the correct position later on
  if (fseek(product_file, -sizeof(struct Product), SEEK_CUR) != 0) {
    printf("Failed to operate on file!\n");
    return;
  };

  printf("Product found. Enter new details:\n");

  printf("New Product Name: ");
  scanf("%s", product.product_name);

  printf("New Price: ");
  scanf("%f", &product.price);

  printf("New Quantity: ");
  scanf("%d", &product.quantity);

  if (fwrite(&product, sizeof(struct Product), 1, product_file) < 1) {
    printf("Failed to write new product to file!\n");
    return;
  };

  fclose(product_file);
}

int main() {
  const char *filename = "products.bin";
  int choice, numProducts;

  do {
    printf("-- Product management system --\n");
    printf("1. Write products\n");
    printf("2. Append products\n");
    printf("3. Read products\n");
    printf("4. Modify products\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter the number of products to write: ");
      scanf("%d", &numProducts);

      writeProducts(filename, numProducts);
      break;

    case 2:
      printf("Enter the number of products to append: ");
      scanf("%d", &numProducts);

      appendProducts(filename, numProducts);
      break;

    case 3:
      readProducts(filename);
      break;

    case 4:
      modifyProduct(filename);
      break;

    case 5:
      printf("Exiting...\n");
      break;

    default:
      printf("Invalid choice. Please try again.\n");
      break;
    }
  } while (choice != 5);

  return 0;
}
