/*
 * The C programming language - K&R
 * Chapter 3
 */

#include <stdio.h>

/*
 * > A statement is any line terminated by a semi-colon.
 * > Braces group statements together so that they are syntactically equivalent to a single statement.
 * > if  and  else if  conditions are tests of the numeric value of the expression(s) that forms the condition. If...
 *   the condition is true, i.e. it evaluates to a non-zero value, the statement for that  if  or  else if  is...
 *   executed. Testing the numeric value allows for some shortening of conditions.
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
 * > The switch statement tests whether an expression matches a number of constant integers. After testing a...
 *   condition, execution falls through to the next case unless explicit action is made to avoid that, e.g.
 *   - break;  or  return;
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
 * > Any of the three expressions in a for loop's control statements can be omitted. If the condition is omitted, it...
 *   is always true.
 * > The comma operator separates expressions. The expressions should be closely related to each other. Expressions...
 *   are evaluated left to right. Typical usage is to process two indices in parallel. The commas that separate...
 *   variable names and function arguments are NOT comma operators, and do not guarantee left to right evaluation.
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
/*
 * Exercise 3-4
 */
void inttostr()
{
    short a, n = -32768;    // a short's range is -32768 to 32767
    int sign, i, j, c;     // changing the sign of the lower limit results in 32768
    char str[10];         // 32768 is 1 above the upper limit
    i = j = 0;           // hence, the version in the book screws up

    if ((sign = n) < 0)
    {
        a = -(n % 10);    // isolate the first digit, then...
        n /= 10;          // make it smaller so that changing the sign doesn't go out of range
        n = -n;
        str[i++] = a + '0';
    }
    while (n > 0)
    {
        str[i++] = n % 10 + '0';
        n /= 10;
    }
    if (sign < 0)
    {
        str[i++] = '-';
    }
    str[i] = '\0';

    for (--i, j = 0; j < i; --i, ++j)
    {
        c = str[j];
        str[j] = str[i];
        str[i] = c;
    }

    printf("%s\n", str);
}
/*
 * Exercise 3-5
 * convert integer to a base character representation in a string
 */
void inttobase()
{
    int n = 30974;
    short base = 16;
    int a;
    short i, j, sign;                 // use shorts to save on memory hehe
    char basechars[base], str[21];    // the upper limit of an unsigned long is 20 digits long

    i = j = 0;
    a = base > 10 ? 10 : base;

    while (i < a)
    {
        basechars[i] = i + '0';
        ++i;
    }
    if (base > 10)
    {
        while (i < base)
        {
            basechars[i] = j + 'A';
            ++i;
            ++j;
        }
    }

    i = j = 0;

    if ((sign = n) < 0)
    {
        a = -(n % base);
        n /= base;
        n = -n;
        str[i++] = basechars[a];
    }
    while (n > 0)
    {
        a = n % base;
        str[i++] = basechars[a];
        n /= base;
    }
    if (sign < 0)
    {
        str[i++] = '-';
    }
    str[i] = '\0';

    for (--i, j = 0; j < i; --i, ++j)
    {
        a = str[j];
        str[j] = str[i];
        str[i] = a;
    }

    printf("%s\n", str);
}
/*
 * > break;  causes immediate exit from the loop that it is in
 * > continue;  causes the next iteration of the loop to begin, i.e. skip any statements after the  continue;  and...
 *   perform the test to see if the loop body should be entered again.
 *   - The increment of a for loop still occurs when a  continue;  is used.
 * > goto ____;  jumps out of all loops and goes straight to ____:
 *   - To jump completely out of deeply nested code, use  goto  rather than  break;  because break applies to one loop.
 *   - The scope of the label to escape to is the function that it is in, exactly like automatic variables.
 */
void continuedemo()
{
    char line[1000];

    while(readinput(line) > 0)
    {
		if(line[0] == '#')
        {
            continue;
        }
        // some lines that
        // do whatever
        // you want doing
    }
}

void gotodemo()
{
    int i, j;

    for (i = 0; i < 10; ++i)
    {
        for (j = 0; j < 50; ++j)
        {
            printf("ayup\n");
            if (i == 6 && j == 42)
            {
                goto ayylmao;
            }
        }
    }

ayylmao:
    printf("yeah boi\n");
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
    inttostr();
    inttobase();
    gotodemo();
    return 0;
}
