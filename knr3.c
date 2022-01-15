/*
 * The C programming language - K&R
 * Chapter 3
 */

#include <stdio.h>

/*
 * > A statement is any line terminated by a semi-colon.
 * > Braces group statements together so that they are syntactically equivalent to a single statement.
 * > if  and  else if  conditions are tests of the numeric value of the expression(s) that forms the condition. If the condition...
 *   is true, i.e. it evaluates to a non-zero value, the statement for that  if  or  else if  is executed. Testing the numeric...
 *   value allows for some shortening of conditions.
 *   - if (expression)  is the same as  if (expression != 0)
 */
/*
 * Exercise 3-1
 */
int binarysearch(int x, int nums[], int size)
{
    int low, mid, high, i;
    low = 0;
    high = size - 1;
    i = 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (x < nums[mid])
        {
            high = mid - 1;
            printf("-narrowing search, pass %d\n", i++);
        }
        else if (x > nums[mid])
        {
            low = mid + 1;
            printf("+narrowing search, pass %d\n", i++);
        }
        else
        {
            return mid;
        }
    }

    if (x <= nums[size / 10])
    {
        high = size / 10;
        low = 0;
    }
    else if (x <= nums[2 * size / 10])
    {
        high = 2 * n / 10;
        low = n / 10 + 1;
    }
    else if (x <= 3 * n / 10)
    {
        high = 3 * n / 10;
        low = 2 * n / 10 + 1;
    }
    else if (x <= 4 * n / 10)
    {
        high = 4 * n / 10;
        low = 3 * n / 10 + 1;
    }
    else if (x <= 5 * n / 10)
    {
        high = 5 * n / 10;
        low = 4 * n / 10 + 1;
    }
    else if (x <= 6 * n / 10)
    {
        high = 6 * n / 10;
        low = 5 * n / 10 + 1;
    }
    else if (x <= 7 * n / 10)
    {
        high = 7 * n / 10;
        low = 6 * n / 10 + 1;
    }
    else if (x <= 8 * n / 10)
    {
        high = 8 * n / 10;
        low = 7 * n / 10 + 1;
    }
    else if (x <= 9 * n / 10)
    {
        high = 9 * n / 10;
        low = 8 * n / 10 + 1;
    }
    else if (x <= n)
    {
        high = n;
        low = 9 * n / 10 + 1;
    }
    else // (x >= n)
    {
        printf("not found\n");
    }

    while (low <= high)
    {
        //
    }

    return -1;
}

void binarysearchinit()
{
    int a, n;
    int size = 1000;
    int nums[size];

    for (n = 0; n < size; ++n)
    {
        nums[n] = 2 * n;
    }

    while (1 < 2)
    {
        a = n = 0;
        while ((a = getchar()) != '\n' && a != EOF)
        {
            n += (a - '0');
        }
        if (a == EOF) break;
        printf("%d\n", binarysearch(n, nums, size));
    }
}

int main()
{
    binarysearchinit();
    return 0;
}
