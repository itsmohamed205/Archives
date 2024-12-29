#include <stdio.h>
 int main () {
    int Rows, AstrisksCount = 1;
    printf("Enter the number of rows: ");
    scanf("%d", &Rows);
    for (int i = 1; i <= Rows; i++)
    {
        for(int x = Rows; x >= i; x--)
        {
            printf(" ");
        }
        for(int y = 1; y <= AstrisksCount; y++)
        {
            printf("*");
        }
        printf("\n");
        AstrisksCount += 2;
    }
    return 0;
 }