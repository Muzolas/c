#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int main()
{
    int result, digit1, digit2, x = 0, j, bas = 1, digitR, i, get, process = 0, get1 = 0, temp, number1, number2, number3, digitA, digitD, check;
    printf("First value how many digits does it have: ");
    scanf("%d", &digit1);
    printf("Second value how many digits does it have: ");
    scanf("%d", &digit2);
    char rslt[digit1 + digit2];
    if (digit1 < digit2)
    {
        digitR = digit2;
        digitD = digit2 - digit1;
        check = 1;
    }
    else if (digit1 == digit2)
    {
        digitR = digit2;
        digitD = 0;
    }
    else
    {
        digitR = digit1;
        digitD = digit1 - digit2;
        check = 0;
    }
    char numb1[digitR];
    char numb2[digitR];
    char sayi3[digitR + 1];
    printf("Enter first value: ");
    for (i = digit1 - 1; i >= 0; i--)
    {
        numb1[i] = getche();
    }
    printf("\nEnter second value: ");
    for (i = digit2 - 1; i >= 0; i--)
    {
        numb2[i] = getche();
    }
    if (digitD != 0)
    {
        if (check == 0)
        {
            for (i = digit1 - 1; i < digitR; i++)
            {
                numb2[i] = 0 + '0';
            }
        }
        else
        {
            for (i = digit2 - 1; i < digitR; i++)
            {
                numb1[i] = 0 + '0';
            }
        }
    }
    do
    {
        printf("\n-----------------\n     Process\n-----------------\n1-Addition\n2-Subtraction\n3-Multiplication\n4-Exit\n-----------------\n>>>");
        scanf("%d", &process);
        switch (process)
        {
        case 1:
            for (i = 0; i < digitR; i++)
            {
                number1 = numb1[i] - '0';
                number2 = numb2[i] - '0';
                temp = number1 + number2 + get1;
                if (temp > 9)
                {
                    get1 = 1;
                    temp = temp % 10;
                }
                else
                {
                    get1 = 0;
                    temp = temp % 10;
                }
                sayi3[i] = temp + '0';
            }
            if (get1 == 1)
            {
                digitA = 1;
                sayi3[i] = 1 + '0';
            }
            else
            {
                digitA = 0;
            }
            for (i = digitR - 1 + digitA; i >= 0; i--)
            {
                number3 = sayi3[i] - '0';
                printf("%d", number3);
            }
            break;
        case 2:
            if (digit2 > digit1)
            {
                check = 1;
            }
            else if (digit2 == digit1)
            {
                check = 0;
            }
            else
            {
                check = 0;
            }
            for (i = 0; i < digitR; i++)
            {
                if (check == 1)
                {
                    number2 = numb1[i] - '0';
                    number1 = numb2[i] - '0';
                }
                else
                {
                    number1 = numb1[i] - '0';
                    number2 = numb2[i] - '0';
                }
                temp = number1 - number2 - get;
                if (temp < 0)
                {
                    temp += 10;
                    get = 1;
                }
                else
                {
                    get = 0;
                }
                sayi3[i] = temp + '0';
            }
            if (check == 1)
            {
                printf("-");
            }
            for (i = digitR - 1; i >= 0; i--)
            {
                number3 = sayi3[i] - '0';
                printf("%d", number3);
            }
            break;
        case 3:
            for (i = 0; i < digit1 + digit2; i++)
            {
                rslt[i] = 0;
            }
            for (i = 0; i < digit1; i++)
            {
                for (j = 0; j < digit2; j++)
                {
                    number1 = numb1[i] - '0';
                    number2 = numb2[j] - '0';
                    temp = number1 * (pow(10, i)) * number2 * (pow(10, j));
                    result += temp;
                }
            }
            for (i = 0; i < digit1 + digit2; i++)
            {
                if (result < 10)
                {
                    rslt[i] = (result % 10) + '0';
                    i = digit1 + digit2;
                }
                else
                {
                    rslt[i] = (result % 10) + '0';
                    result /= 10;
                }
                x++;
            }
            for (i = x - 1; i >= 0; i--)
            {
                printf("%c", rslt[i]);
            }
            break;
        case 4:
            return 0;
        default:
            printf("Incorrect operation...");
        }
    } while (process != 4);
}