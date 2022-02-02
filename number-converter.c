/*
 * Convert numbers from one base to another
 */

#include <stdio.h>

/*
 * function declarations
 */
void getinput(char input[]);
void inttobase(long num, short outbase, char numasstr[]);
short parsebase(char input[]);
long strtoint(char numasstr[], short inbase);

/*
 * function definitions
 */
void getinput(char input[])
{
    int i = 0;
    char c;

    while ((c = getchar()) != '\n')
    {
        input[i++] = c;
    }
    input[i] = '\0';
}

void inttobase(long num, short outbase, char numasstr[])
{
    char basechars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};    // why waste computation?
    int a;
    short i, j, sign;

    i = j = 0;
    a = (num % outbase < 0) ? (num % outbase) * -1 : num % outbase;    // isolate the first digit, then...
    num /= outbase;    // make the number smaller so that flipping the sign doesn't go out of range

    if ((sign = num) < 0)
    {
        num = -num;
    }
    numasstr[i++] = basechars[a];
    while (num > 0)
    {
        a = num % outbase;
        numasstr[i++] = basechars[a];
        num /= outbase;
    }
    if (sign < 0)
    {
        numasstr[i++] = '-';
    }
    numasstr[i] = '\0';

    for (--i, j = 0; j < i; --i, ++j)
    {
        a = numasstr[j];
        numasstr[j] = numasstr[i];
        numasstr[i] = a;
    }
}

short parsebase(char input[])
{
    short n;

    switch (input[0])
    {
    case '1':
        n = 2;
        break;
    case '2':
        n = 8;
        break;
    case '3':
        n = 10;
        break;
    case '4':
        n = 16;
        break;
    default:
        n = -1;
        break;    // all hail K&R
    }

    return n;
}

long strtoint(char numasstr[], short inbase)
{
    char sign = '+';
    short i = 0;
    long n = 0;

    if (numasstr[i] == '-')
    {
        sign = '-';
        ++i;
    }
    for (; numasstr[i] != '\0'; ++i)
    {
        n = (inbase * n) + numasstr[i] - (numasstr[i] < 'A' ? '0' : 'A' - 10);    // numbers come before capitals in ascii character set
    }

    return sign == '+' ? n : -n;
}

int main()
{
    char string[66];           // a 64 bit binary string should be the longest input to deal with
    short inbase, outbase;    // use shorts to save on memory hehe
    long num;                // account for the worst case

    printf("1     2 - binary\n"
           "2     8 - octal\n"
           "3    10 - decimal\n"
           "4    16 - hexadecimal\n"
           "Select base of input number:\n");
    getinput(string);
    if ((inbase = parsebase(string)) == -1)
    {
        printf("try again\n");
        return 1;
    }

    printf("Select base of output number:\n");
    getinput(string);
    if ((outbase = parsebase(string)) == -1)
    {
        printf("try again\n");
        return 1;
    }

    printf("Enter number to convert:\n");
    getinput(string);
    num = strtoint(string, inbase);
    if (outbase == 3)
    {
        printf("%ld\n", num);
    }
    else
    {
        inttobase(num, outbase, string);
        printf("%s\n", string);
    }

    return 0;
}
