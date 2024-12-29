#include <stdio.h>
#define SIZE 6
void ArrayElements(int array[], int end);

int main(void)
{
    int elements[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        printf("Element - %d: ", i);
        scanf("%d", &elements[i]);
    }
    printf("-------------- Your Data Output --------------");
    ArrayElements(elements, SIZE);
}
void ArrayElements(int array[], int end)
{
    if (end > SIZE || end < 0)
        return;

    printf("Element %d is: %d\n", end, array[end]);

    ArrayElements(array, end - 1);
}