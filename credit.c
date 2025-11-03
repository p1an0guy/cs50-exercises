#include <stdio.h>

int length(long);
long extract1(long);
long extract2(long);
int first_digit(long);
int first_2_digits(long);

int main()
{
    long n;
    do
    {
        printf("Number: ");
        scanf("%li", &n);
    } while (n < 0);
    int len;
    len = length(n);
    printf("Length: %i\n", len);
    if (length(n) != 13 && length(n) != 15 && length(n) != 16)
    {
        printf("INVALID LENGTH FOR CREDIT CARD\n");
        return 0;
    }

    long sum1 = extract1(n);
    long sum2 = extract2(n);

    printf("Sum1 = %li\n", sum1);
    printf("Sum2 = %li\n", sum2);
    if ((sum1 + sum2) % 10 == 0)
    {
        if (first_digit(n) == 4 && (length(n) == 13 || length(n) == 16))
        {
            printf("VISA\n");
            return 0;
        }

        if ((first_2_digits(n) == 34 || first_2_digits(n) == 37) && length(n) == 15)
        {
            printf("AMERICAN\n");
            return 0;
        }
        if ((first_2_digits(n) == 51 ||
             first_2_digits(n) == 52 ||
             first_2_digits(n) == 53 ||
             first_2_digits(n) == 54 ||
             first_2_digits(n) == 55) &&
            length(n) == 16)
        {
            printf("MASTERCARD\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

int length(long num)
{
    int len = 0;
    while (num > 0)
    {
        num = num / 10;
        len++;
    }
    return len;
}

long extract1(long n)
{
    long result = 0;
    n = n / 10;
    while (n > 0)
    {

        printf("Current number %li\n", n);
        long curr_digits = 2 * (n % 10);
        printf("Curr_digits = %li\n", curr_digits);
        while (curr_digits > 0)
        {
            result += curr_digits % 10;
            curr_digits = curr_digits / 10;
        }
        printf("Current result = %li\n", result);
        n = n / 10 / 10;
    }
    return result;
}
long extract2(long n)
{
    long result = 0;
    while (n > 0)
    {
        result += n % 10;
        n = n / 10 / 10;
    }
    return result;
}

int first_digit(long n)
{
    while (n > 10)
    {
        n = n / 10;
    }
    return n;
}
int first_2_digits(long n)
{
    while (n > 100)
    {
        n = n / 10;
    }
    return n;
}