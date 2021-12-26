/*
 * The C programming language - K&R
 * Chapter 1
 */

#include <stdio.h>

/*
 * convert fahrenheit to celsius
 * /
#define LOWERLIMIT -40    // these are called symbolic constants
#define UPPERLIMIT 100    // any instances of the left word get replaced with the right word when compiled

int main()
{
    float tempF, tempC;

    //int lowerLimit = -40;    // these two variables are an alternative to the symbolic constants
    //int higherLimit = 100;
    int step = 10;
    tempF = LOWERLIMIT;

    printf("deg F\tdeg C\n");

    while (tempF <= UPPERLIMIT)
    {
        //tempF = ((tempC / 5) * 9) + 32;          // this requires  tempC  and  tempF  to be ints
        tempC = (tempF - 32.0) * (5.0 / 9.0);
        printf("%3.0f\t%6.2f\n", tempF, tempC);    // see page 13 of The C Programming Language
        tempF = tempF + step;
    }

    return 0;
}
*/

/*
 * print input
 * /
int main()
{
    int c;

    while ((c = getchar()) != EOF)    // ctrl+d is how you enter EOF
    {                                 // EOF is ctrl+z on windows
        putchar(c);
    }

    printf("%i\nsuccess\n", c);
    return 0;
}
*/

/*
 * count characters, lines, and words
 * /
#define IN  1    // inside a word
#define OUT 0    // outside a word

int main()
{
    int c, nl, nw, nc, state, i;

    state = OUT;
    nl = nc = nw = 0;

    printf("Enter text:\n");
    while ((c = getchar()) != EOF)
    {
        ++nc;

        if (c == '\n')
        {
            ++nl;
        }

        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            ++nw;
        }

        putchar(c);                   // exercise 1-12: print one word of input per line
        if (c == ' ' || c == '\t')    // using  if (state == OUT)  instead produces unnecessary new lines
        {
            printf("\n");
        }
    }

    printf("%i lines,\t%i words,\t%i characters\n", nl , nw, nc);
    return 0;
}
*/

/*
 * count numbers and spaces
 * /
int main()
{
    int i, j, c, spaces, max;
    int ndigit[10];                  // there are 10 single digit numbers, so an array of 10 will do

    spaces = 0;
    for (i = 0; i < 10; ++i)
    {
        ndigit[i] = 0;               // set all elements in array to 0
    }

    printf("\nEnter text now:\n");

    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')    // a character in single quotes means the character's numeric value in the character set
        {                            // so a character (a-z, 0-9, ~&?[^ etc) in ' ' is just a small integer
            ++ndigit[c - '0'];       // when a character is in ' ', it is called a character constant
        }                            // NB, '\n' is a character constant; "\n" is a string constant
        else if (c == ' ')
        {
            ++spaces;
        }
    }

    max = spaces;                    // find highest occurrence count
    for (i = 0; i < 10; ++i)
    {
        if (ndigit[i] > max)
        {
            max = ndigit[i];
        }
    }

    for (j = 0; j <= 10; ++j)        // histogram with horizontal bars
    {
        if (j != 10)
        {
            printf("%5i\t", j);
            for (i = 1; i <= ndigit[j]; ++i)
            {
                printf("|");
            }
            printf("\n");
        }
        else
        {
            printf("spaces\t");
            for (i = 1; i <= spaces; ++i)
            {
                printf("|");
            }
        }
    }

    printf("\n\n");

    for (j = max; j > 0; --j)        // histogram with vertical bars
    {
        for (i = 0; i <= 10; ++i)
        {
            if (i != 10)
            {
                if (ndigit[i] >= j)
                {
                    printf("-  ");
                }
                else
                {
                    printf("   ");
                }
            }
            else
            {
                if (spaces >= j)
                {
                    printf("-");
                }
            }
        }
        printf("\n");
    }
    printf("0  1  2  3  4  5  6  7  8  9  spaces\n");

    return 0;
}
*/

/*
 * function calling demo
 * /
int power(int m, int n);    // parameter names don't matter, so it could say  int power(int, int);
                            // as long as the prototype's parameters match the function's parameters
int main()
{
    int i;

    for (i = 0; i < 10; ++i)
    {
        printf("2^%i = %i\n", i, power(2,i));    // 2 and  i  get passed to the function  power()
    }                                            // they get passed as values rather than variables
                                                 // passing an array to a function does not pass the values
    return 0;
}

int power(int base, int exponent)                // so  base  is 2 and  exponent  inherits the value of  i
{                                                // base  and  exponent  are local to  power(), i.e. invisible to other functions
    int i, p;                                    // the variable  i  here is unrelated to the  i  in  main()

    p = 1;

    for (i = 1; i <= exponent; ++i)
    // int p;                                    // these two commented lines remove the variable  i  completely
    // for (p = 1; exponent > 0; --exponent)     // the parameter  exponent  is used as a temporary variable
    {
        p = p * base;
    }

    return p;
}
*/

/*
 * Exercise 1-15
 * rewrite the temp converter program using another function
 * /
#define LOWERLIMIT -40
#define UPPERLIMIT 100

float convert(float a, float b);

int main()
{
    float tempF, tempC;

    int step = 10;
    tempF = LOWERLIMIT;

    printf("deg F\tdeg C\n");

    while(tempF <= UPPERLIMIT)
    {
        printf("%3.0f\t%6.2f\n", tempF, convert(tempC, tempF));
        tempF = tempF + step;
    }

    return 0;
}

float convert(float tempC, float tempF)
{
    tempC = (tempF - 32.0) * (5.0 / 9.0);
    return tempC;    // the formula of  tempC  could go here instead of the variable name
}
*/

/*
 * grab lines of input and print the longest + some other functionality
 * /
#define MAXLEN 30 //1000

int fetchline(char line[], int length);
void copyline(char to[], char from[]);
void reverseline(char to[], char from[]);

int main()
{
    int currLen, longLen, overflow;
    char currLine[MAXLEN], longLine[MAXLEN], revLine[MAXLEN];

    currLen = longLen = overflow = 0;

    printf("Enter text now:\n");

    while ((currLen = fetchline(currLine, MAXLEN)) > 0)    // 0 is a valid condition because even a blank line has the new line character
    {
        if (currLen == (MAXLEN - 1))                       // if input overflowed array
        {                                                  // the condition could also be  currLine[MAXLEN - 1] == '\0'
            overflow = overflow + currLen;
        }
        else
        {
            currLen = currLen + overflow;
            overflow = 0;
        }

        if (currLen > longLen)
        {
            longLen = currLen;
            copyline(longLine, currLine);                  // when an array is used as an argument, the address of the beginning of the array is...
        }                                                  // passed to the the called function, there is no inheriting array elements

        //if (currLen > 15)                                // exercise 1-17, print only lines longer than 15
        //{
        //    printf(">> %s\n", currLine);
        //}

        reverseline(revLine, currLine);                    // exercise 1-19, print the line of input in reverse
        printf(">> %s\n", currLine);
        printf("<< %s\n", revLine);
    }

    if (longLine > 0)                                      // if there was a line of input
    {
        printf("-> %s", longLine);                         // this prints the last bit of the longest line because...
        printf("-> %i characters long\n", longLen);        // previous array fills of that line are lost
    }

    return 0;
}

int fetchline(char theLine[], int limit)
{
    int c, i;

    //   while (i < (limit - 1) && (c = getchar()) != EOF && c != '\n')         // this while loop equivalent requires lines to set and increment  i
    for (i = 0; i < (limit - 1) && (c = getchar()) != EOF && c != '\n'; ++i)    // run along the line of input, copying each character into the array until...
    {                                                                           // the array is filled, a new line character is encountered, or EOF is read
        theLine[i] = c;
        //if (c == ' ' || c == '\t')                                            // exercise 1-18, remove spaces and tabs from input
        //{
        //    --i;
        //}
    }
    if (c == '\n')
    {
        theLine[i] = c;    // add the new line character to the array...
        ++i;               // and move to the next element
    }
    theLine[i] = '\0';     // add the null character after the last used element to mark the end of the string
                           // partially filling an array and not appending the null character causes the unfilled elements to contain garbage
    return i;              // return the counter variable which, by definition, is the length of the input line
}                          // i  is the number of elements entered, if  i  is 23, the 24th element is \0, which is element[23]

void copyline(char to[], char from[])    // void type functions return no value; they are used only for their effect
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')    // copy the elements of  from[]  into  to[]
    {                                    // the null character is copied in as the last operation before returning
        ++i;
    }
}

void reverseline(char to[], char from[])   // the length of the string passed to  reverseline()  will always be less than or equal to  MAXLEN
{
    int i = 0;
    int truelen;

    while (from[i] != '\0')                // find where the null character is
    {                                      // alternatively,  for (i = 0; from[i] != '\0'; ++i)
        ++i;
    }
    truelen = i;
    i = 0;
    to[truelen] = '\0';
    if (from[truelen - 1] == '\n')         // if the character before the null character is a new line character, keep it...
    {                                      // at the end and reverse the rest of the string
        to[truelen - 1] = '\n';
        while (i < (truelen - 1))
        {
            to[truelen - (i + 2)] = from[i];
            ++i;
        }
    }
    else
    {
        while (i < (MAXLEN - 1))
        {
            to[(MAXLEN - 1) - (i + 1)] = from[i];
            ++i;
        }
    }
}
*/

// Always stop a loop before it fills whatever it is populating. If the loop continues past the end of an array, you get a stack smashing error.

/*
 * Exercise 1-20
 * replace tabs with spaces until wherever the next tab stop lands
 *
 * Notes:
 * 1. Testing if  output[]  contains all of the input is actually a proxy for testing if  input[]  contains all of the input
 *    because of the array sizes given in  main(). If the input does not fill the input array, one or more subsequent calls to
 *    fetchline()  will be needed to grab the rest. This matters because once tabs are expanded, there is a 1-in-TABSTOP
 *    chance that the output array finishes right before a tab stop. If it doesn't finish right before a tab stop, subsequent
 *    output lines need to be offset to match wherever the previous output line finished if the tabs are to be expanded correctly.
 * /
#define TABSTOP 8    // one tab equals this many spaces
#define MAXLEN 30    // input longer than this will be chopped, the next fill of input will grab it

int calcspaces(int a);
int fetchline(char input[]);
int processline(char output[], char input[], int o);

int calcspaces(int j)
{
    int s = 0;

    if (j % TABSTOP == 0)
    {
        s = TABSTOP;
    }
    else
    {
        while (j % TABSTOP != 0)
        {
            ++j;
            ++s;
        }
    }

    return s;
}

int fetchline(char input[])
{
    int c, i;

    for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
    {
        input[i] = c;
    }
    if (c == '\n')
    {
        input[i] = c;
        ++i;
    }
    input[i] = '\0';

    return i;
}

int processline(char output[], char input[], int o)
{
    int i, j, s;
    j = 0;

    for (i = 0; input[i] != '\0'; ++i)
    {
        if (input[i] == '\t')
        {
            s = calcspaces(j + o);    // number of spaces that tab expands to
            s = s + j;                // use  s  as the loop's end condition

            for (j = j; j < s; ++j)
            {
                output[j] = '_';
            }
        }
        else
        {
            output[j] = input[i];
            ++j;
        }
    }
    output[j] = '\0';

    if (output[j - 1] != '\n')      // test if  output[]  contains all of the input (see note 1.)
    {
        while (j % TABSTOP != 0)    // count down from  j  to the closest multiple of  TABSTOP
        {
            ++o;
            --j;
        }
    }
    else
    {
        o = 0;
    }

    return o;
}

int main()
{
    int o = 0;
    char input[MAXLEN], output[(MAXLEN * TABSTOP)];    // This size accounts for the worst case of every character being a tab.

    printf("Enter text now:\n");

    while (fetchline(input) > 0)
    {
        o = processline(output, input, o);    // o  is the offset for subsequent output lines (see note 1.)
        printf("%s", output);                 // the new line character from the input will be reproduced
    }

    return 0;
}
*/

/*
 * Exercise 1-21
 * replace consecutive spaces with tabs and spaces to achieve the same spacing
 *
 * There is still a bug, see tab expansion file, but I can't be bothered to fix it now.
 */
#define TABSTOP 8
#define MAXLEN ((3 * TABSTOP) + 1)

int fetchline(char input[]);
void processline(char input[], char output[]);

int fetchline(char input[])
{
    int c, i;

    for (i = 0; i < (MAXLEN - 1) && (c = getchar()) != '\n' && c != EOF; ++i)
    {
        input[i] = c;
    }
    if (c == '\n')
    {
        input[i] = c;
        ++i;
    }
    input[i] = '\0';

    return i;
}

void processline(char output[], char input[])
{
    int c, i, j, s;
    c = j = 0;

    for (i = 0; input[i] != '\0'; ++i)
    {
        if (input[i] == ' ')
        {
            for (s = 0; input[i] == ' '; ++s)
            {
                ++c;
                ++i;
                if (c % TABSTOP == 0)    // Stop once the output hits a tab stop. Deal with what has been recorded because...
                {                        // what happens before a tab stop has no effect on what happens after it.
                    break;
                }
            }

            if (c % TABSTOP == 0)
            {
                output[j] = '\t';
                ++j;
                c = 0;
            }
            else if (input[i] != '\t')     // Insert however many spaces have been recorded only if the next character...
            {                              // is not a tab. If the next character is a tab, the spaces can be ignored.
                for (s = s; s > 0; --s)    // this loop always returns  s  back to 0
                {
                    output[j] = '_';       // use an underscore to see where the spaces are
                    ++j;
                }
            }

            --i;    // move backwards because the surrounding for loop increments  i  as well as the loop that counts spaces
        }
        else
        {
            output[j] = input[i];
            ++j;
            ++c;
            if (output[j - 1] == '\t')
            {
                c = 0;
            }
        }
    }
    output[j] = '\0';
}

int main()
{
    char input[MAXLEN], output[MAXLEN];    // condensing spaces to tabs and spaces results in a shorter string

    printf("Enter text now:\n");

    while (fetchline(input) > 0)
    {
        processline(output, input);
        printf("%s", output);
    }

    return 0;
}
