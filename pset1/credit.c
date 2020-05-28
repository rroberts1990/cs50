#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

void cc_check(long x);
int getlength(long x);
bool apply_luhn(long x);


int main(void)
{
    long cc_no;
    do
    {
        cc_no = get_long("Input your credit card number?\n");
    }
    while (cc_no < 0);
    cc_check(cc_no);
}

void cc_check(long i)
{
    // Apply Luhn's algorithm to determine validity
    bool isvalid = apply_luhn(i);

    // Obtain length of credit card number
    int length = getlength(i);

    // Further determine validity using credit card number length and digits
    if (isvalid == true)
    {
        if (length == 15 && (i / 10000000000000 == 34 || i / 10000000000000 == 37))
        {
            printf("AMEX\n");
        }
        else if (length == 13)
        {
            printf("VISA\n");
        }

        else if (length == 16)
        {
            if (i / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else if (i / 100000000000000 > 50 &&  i / 100000000000000 < 56)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

bool apply_luhn(long i)
{
    int fullcount = 0;
    long x;
    long z;
    int y;

    // Step 1: start from second last digit and multiply every other
    // by 2 then sum all individual digits
    for (x = i / 10; x > 0; x /= 100)
    {
        y = (x % 10) * 2;
        if (y > 9)
        {
            fullcount += y % 10;
            fullcount += y / 10;
        }
        else
        {
            fullcount += y;
        }
    }

    // Step 2: sum digits that have not been multiplied in step 1
    for (z = i; z > 0; z /= 100)
    {
        fullcount += z % 10;
    }
    // Step 3: if the value divides evenly by 10 it is valid
    if (fullcount % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getlength(long num)
{
    int count;
    for (count = 0; num > 0; count++)
    {
        num /= 10;
    }
    return count;
}
