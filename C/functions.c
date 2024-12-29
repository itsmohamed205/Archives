#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_VALUE 1000000 // ONLY USED FOR THE DISTINCT VALUES FUNCTION

int showValues, numberOfElements, help, minArrySize, choice = 0;

int distinct_values(int * array, int size, int showValues) {

  char * seen = calloc(2 * MAX_VALUE + 1, sizeof(char)); // Defines a pointer to a boolean array

  if (seen == NULL) { // Check if the calloc function works
    printf("Memory allocation failed?\n");
    exit(1);
  }

  int count = 0;
  printf("\n");
  for (int i = 0; i < size; i++) {
    int value = array[i] + MAX_VALUE; // Shift values to positive range
    if (!seen[value]) {
      seen[value] = 1;
      if (showValues) printf("%d\t", array[i]);
      count++;
    }
  }
  printf("\n");
  free(seen); // Frees the memory allocated for the array
  return count;
}

int checkTriples(int * arr, int size, int showValues) {
  int count = 0;
  for (int i = 0; i < numberOfElements; i++) {
    for (int j = i + 1; j < numberOfElements; j++) {
      for (int k = j + 1; k < numberOfElements; k++) {
        // Ensure that the same number isn't used twice
        if (arr[i] != arr[j] && arr[j] != arr[k] && arr[i] != arr[k]) {
          // Check if the triplet is valid
          if (arr[i] + arr[j] > arr[k] && arr[i] + arr[k] > arr[j] && arr[j] + arr[k] > arr[i]) {
            count++;
            if (showValues) printf("(%d, %d, %d)\t", arr[i], arr[j], arr[k]);
            if (count % 3 == 0)
              printf("\n");
          }
        }
      }
    }
  }
  return count;

}

// ONLY USED BY THE TRIPLETS FUNCTION
void insertionSort(int * array, int n) {
  for (int i = 1; i < n; i++) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
}

int main(int argc, char * argv[]) {
  // Checkin for the -i and -c flags and their functions
  for (int i = 0; i < argc; i++) {
    if (!strcmp(argv[i], "-i"))
      showValues = 1;
    else if (!strcmp(argv[i], "-c"))
      numberOfElements = (argv[i + 1] != NULL) ? atoi(argv[i + 1]) : 0;
    else if (!strcmp(argv[i], "-h"))
      help = 1;
  }
  if (help) {
    printf("Usage: index [OPTION]... [DATA]...\n");
    printf("Prints the number of triples or the distinct values in an array\n");
    printf("  -i\t\t\tprint the triples\n");
    printf("  -c\t\t\tset the number of array values - [3, +1000]\n");
    printf("  -h\t\t\tprint this help and exit\n");
    return 0;
  }

  printf("Choose which function you willing to use:\n1- Triples\n2- Distinct Values\nInput: ");
  scanf("%d", & choice);

  if (choice == 2) minArrySize = 2;
  else minArrySize = 3;

  printf("Hint: You can set the size of an array with the -c flag directly\n");
  while (numberOfElements < minArrySize) {

    printf("Enter the number of elements: [%d, 2000000]: ", minArrySize);
    scanf("%d", & numberOfElements);
  }
  // Fetch the elements of the array
  int input[numberOfElements];
  for (int i = 0; i < numberOfElements; i++) {
    printf("Enter the element %d: ", i);
    scanf("%d", & input[i]);
  }
  #ifdef _WIN32
  system("cls");
  #elif __linux__
  system("clear");
  #else
  printf("------")
  #endif
  // Print the array after being sorted
  printf("[");
  for (int i = 0; i < numberOfElements - 1; i++) {
    printf("%d, ", input[i]);
  }
  printf("%d]\n", input[numberOfElements - 1]);
  printf("\n--------------------------------\n");

  // Main functions executes in here
  int output;
  if (choice == 1) {
    insertionSort(input, numberOfElements);
    output = checkTriples(input, numberOfElements, showValues);
  } else output = distinct_values(input, numberOfElements, showValues);

  if (output < 1)
    printf("No %s found\n", choice == 1 ? "triples" : "distinct values");
  else
    printf("\n- The number of %s found: %d\n", choice == 1 ? "triples" : "distinct values", output);

  return 0;
}