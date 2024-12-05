#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int values, count, numberOfElements, help = 0;
int main(int argc, char *argv[])
{
    // Checkin for the -i and -c flags and their functions
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "-i"))
            values = 1;
        else if (!strcmp(argv[i], "-c"))
            numberOfElements = (argv[i + 1] != NULL) ? atoi(argv[i + 1]) : 0;
        else if (!strcmp(argv[i], "-h"))
            help = 1;
    }
    if (help)
    {
        printf("Usage: index [OPTION]... [DATA]...\n");
        printf("Prints the number of triples in the array\n");
        printf("  -i\t\t\tprint the triples\n");
        printf("  -c\t\t\tset the number of array values - [3, +1000]\n");
        printf("  -h\t\t\tprint this help and exit\n");
        return 0;
    }
    // Fetch the number of elements and the elements of the array
    while (numberOfElements < 3)
    {
        printf("Enter the number of elements: [3, +1000]: ");
        scanf("%d", &numberOfElements);
    }
    // Fetch the elements of the array
    int arr[numberOfElements];
    for (int i = 0; i < numberOfElements; i++)
    {
        printf("Enter the element %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Print the array after being sorted
    printf("[");
    for (int i = 0; i < numberOfElements - 1; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("%d]\n", arr[numberOfElements - 1]);
    printf("\n--------------------------------\n");

    // Check for the triplet
    for (int i = 0; i < numberOfElements; i++)
    {
        for (int j = i + 1; j < numberOfElements; j++)
        {
            for (int k = j + 1; k < numberOfElements; k++)
            {
                // Ensure that the same number isn't used twice
                if (arr[i] != arr[j] && arr[j] != arr[k] && arr[i] != arr[k])
                {
                    // Check if the triplet is valid
                    if (arr[i] + arr[j] > arr[k] && arr[i] + arr[k] > arr[j] && arr[j] + arr[k] > arr[i])
                    {
                        count++;
                        if(values) printf("(%d, %d, %d)\t", arr[i], arr[j], arr[k]);
                        if (count % 3 == 0)
                            printf("\n");
                    }
                }
            }
        }
    }
    if (count < 1)
        printf("No triples found\n");
    else
        printf("\n- The number of triples found: %d\n", count);
    return 0;
}
