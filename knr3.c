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
    i = 0;
    while (low <= high)
    {
        if (x == nums[high])
        {
            return x;
        }
        else
        {
            --high;
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
/*
 * > The switch statement tests whether an expression matches a number of constant integers. After testing a condition, execution...
 *   falls through to the next case unless explicit action is made to avoid that, e.g.  break;  or  return;
 * > Falling through can be used to attach several cases to the same block of actions.
 */
/*
 * Exercise 3-2
 * convert escape sequences into their literal selves and the inverse of that
 */
void escape1(char input[], char output[])
{
    int i = 0, j = 0;
    char c;

    while (input[i] != '\0')
    {
        switch (input[i])
        {
        case '\t':
            output[j++] = '\\';
            output[j++] = 't';
            break;
        case '\n':
            output[j++] = '\\';
            output[j++] = 'n';
            break;
        case '\\':
            output[j++] = '\\';
            output[j++] = '\\';
            break;
        case '\?':
            output[j++] = '\\';
            output[j++] = '?';
            break;
        case '\"':
            output[j++] = '\\';
            output[j++] = '"';
            break;
        case '\'':
            output[j++] = '\\';
            output[j++] = '\'';
            break;
        default:
            output[j++] = input[i];
            break;
        }
        ++i;
    }
    output[j] = '\0';

    printf("+++\n%s\n+++\n", output);
}

void escape2(char input[], char output[])
{
    int i = 0, j = 0;
    char c;

    while (input[i] != '\0')
    {
        if (input[i] == '\\')
        {
            switch (input[++i])
            {
            case 't':
                output[j++] = '\t';
                break;
            case 'n':
                output[j++] = '\n';
                break;
            case '\\':
                output[j++] = '\\';
                break;
            case '?':
                output[j++] = '?';
                break;
            case '"':
                output[j++] = '"';
                break;
            case '\'':
                output[j++] = '\'';
                break;
            default:    // just a single backslash
                output[j++] = '\\';
                output[j++] = input[i];
                break;
            }
        }
        else
        {
            output[j++] = input[i];
        }
        ++i;
    }
    output[j] = '\0';

    printf("---\n%s\n---\n", output);
}

/*
 * > Any of the three expressions in a for loop's control statements can be omitted. If the condition is omitted, it is always true.
 * > The comma operator separates expressions. The expressions should be closely related to each other. Expressions are evaluated...
 *   left to right. Typical usage is to process two indices in parallel. The commas that separate variable names and function...
 *   arguments are not comma operators, and do not guarantee left to right evaluation.
 */
/*
 * Exercise 3-3
 * expand shorthands like  a-z  and  0-9  into their full list
 */
#define BETWEEN(X, A, B) ((A) <= (X) && (X) <= (B))

void expand(char input[], char output[])
{
    int i = 0, j = 0, k;
    // char input[] = "Here is a4-7r-tn exaf-g-h-i-mple a-z of shorD-Ithand.";
    // char output[1000];

    while (input[i] != '\0')
    {
        if ((BETWEEN(input[i], 'a', 'z') && input[i + 1] == '-' && BETWEEN(input[i + 2], 'a', 'z'))
         || (BETWEEN(input[i], 'A', 'Z') && input[i + 1] == '-' && BETWEEN(input[i + 2], 'A', 'Z'))
         || (BETWEEN(input[i], '0', '9') && input[i + 1] == '-' && BETWEEN(input[i + 2], '0', '9')))
        {
            if (input[i + 3] != '-')    // d-k
            {
                k = 0;
                while (input[i] + k <= input[i + 2])
                {
                    output[j++] = input[i] + k++;
                }
                i += 3;    // advance past the shorthand notation
            }
            else    // input[i + 3] == '-'
            {
                if (input[i + 2] > input[i] + 1)    // c-h-
                {
                    k = 0;
                    while (input[i] + k <= input[i + 2])
                    {
                        output[j++] = input[i] + k++;
                    }
                    i += 3;
                }
                else    // c-d-e-f-g  and so on, search forward until there is a break
                {
                    for (k = 1; input[i + k] == '-' && input[i + k + 1] == input[i + k - 1] + 1; k += 2);
                    k = i + k - 1;
                    while (input[i] <= input[k])
                    {
                        output[j++] = input[i];
                        i += 2;
                    }
                    --i;
                }
            }
        }
        else
        {
            output[j++] = input[i++];
        }
    }
    output[j] = '\0';

    printf("%s\n", output);
}

void getinput()
{
    int i = 0;
    char c;
    char input[1000], output[1000];    // hard values, bad, but it's fine for this purpose

    printf("Enter text now:\n");
    while (i < 999 && (c = getchar()) != EOF)
    {
        input[i++] = c;
    }
    input[i] = '\0';

    /* printf("|||\n%s\n|||\n", input); */
    escape1(input, output);    // output is longer because escape sequences become two characters
    escape2(input, output);    // output is shorter because two characters get combined to one character
    expand(input, output);     // output is longer because shorthand gets expanded
}

int main()
{
    binarysearchinit();
    getinput();
    return 0;
}
