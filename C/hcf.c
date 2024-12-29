#include <stdio.h>

int hcf(int number1, int number2)
{
    // checks whether is one of the 2 numbers is zero
    if (!number1 || !number2)
        return 0;
    while (number2 != 0)
    {
        int temp = number1 % number2;
        number1 = number2;
        number2 = temp;
    }
    return number1;
}

int main(void)
{
    int num1, num2, result;
    printf("Input your desired numbers: ");
    scanf("%d %d", &num1, &num2);
    result = hcf(num1, num2);
    printf("HCF (Highest Common Factor) is %d", result);
}