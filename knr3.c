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

    /* while (low <= high)
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
    } */

    for (i = 0; i < 100; ++i)
    {
        if (x <= nums[(i + 1) * size / 100])
        {
            high = (i + 1) * nums[size / 100];
            low = (i == 0) ? 0 : i * nums[size / 100 + 1];
            break; // or  i = 100;
        }
    }

    while (low <= high)
    {
        if (x == nums[high])
        {
            return x;
        }
        else
        {
            high -= 1;
            printf("narrowing search, pass %d\n", i++);
        }
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
        printf("%d\n", n);
        printf("%d\n", binarysearch(n, nums, size));
    }
}

int main()
{
    binarysearchinit();
    return 0;
}
