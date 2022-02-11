/*
 * The C programming language - K&R
 * Chapter 4
 */

#include <stdio.h>
#include <ctype.h>

/*
 * > All functions should be declared before they are defined. This allows for type coercions and some error detection.
 *   - return type, name, parameters:  int strtoint(char input[], short base);
 *   - The language server will complain when function calls and definition don't match the declaration.
 * > Function names must be unique.
 * > Functions that are small and simple are easier to alter and less prone to bugs.
 *   - They should do one thing, and do it well. This increases their utility to other functions.
 */
/*
 * Exercise 4-1
 * find the last occurrence of a pattern in a string
 */
int lastoccurinstr()
{
    int i, j, k, pos = -1;
    char str[] = "You can think about the woman or the girl you knew the night before\n";
    char pttrn[] = "the";

    for (i = 0; str[i] != '\0'; ++i)
    {
        for (j = i, k = 0; pttrn[k] != '\0' && str[j] == pttrn[k]; ++j, ++k);
        if (k > 0 && pttrn[k] == '\0')
        {
            pos = i;
        }
    }

    return pos;
}
/*
 * > If a function declaration lists no parameters, nothing is assumed--parameter checking is turned off.
 *   - int foo();      the arguments could be anything
 *   - int foo(void);  the function takes no arguments
 * > A function's argument can be a function call.
 *   - push(strtoint(str));
 *   - funcz(funcx(a) + funcy(b));
 * > If return values are used in expressions, beware of commutative operators.
 *   - funcz(funcx() - funcx());
 *   - This might fail because you don't know which of the two calls to  funcx()  gets evaluated first.
 *   - Store the return value of one call in a temporary variable to ensure proper calculation.
 */
/*
 * Exercise 4-2
 * add the ability to parse numbers in the form 123.45e-6
 */
#define BETWEEN(X, A, B) ((A) <= (X) && (X) <= (B))

double strtofloat(char str[])
{
    double val, decdig;
    short i, sign, exp, expsign;

    for (i = 0; str[i] == ' ' || str[i] == '\t'; ++i);
    sign = (str[i] == '-') ? -1 : 1;
    if (str[i] == '-' || str[i] == '+')
    {
        ++i;
    }
    for (val = 0.0; BETWEEN(str[i], '0', '9'); ++i)
    {
        val = (10.0 * val) + (str[i] - '0');
    }
    if (str[i] == '.')
    {
        ++i;
    }
    for (decdig = 1.0; BETWEEN(str[i], '0', '9'); ++i)    // this loop is outside the if above it because the loop's...
    {                                                     // test serves to check if the relevant characters have ended
        val = (10.0 * val) + (str[i] - '0');
        decdig *= 10.0;
    }
    val = sign * val / decdig;
    if (str[i] == 'e' || str[i] == 'E')
    {
        ++i;
        expsign = (str[i] == '-') ? -1 : 1;
        if (str[i] == '-' || str[i] == '+')
        {
            ++i;
        }
        for (exp = 0; BETWEEN(str[i], '0', '9'); ++i)
        {
            exp = (10 * exp) + (str[i] - '0');
        }
        if (expsign == -1)
        {
            for (i = 0; i < exp; ++i)
            {
                val /= 10;    // e-5  divide by 10 five times
            }
        }
        else
        {
            for (i = 0; i < exp; ++i)
            {
                val *= 10;    // e5  multiply by 10 five times
            }
        }
    }

    return val;
}
/*
 * > A program consists of external functions and variables. External variables are defined outside of any functions.
 *   All functions are external. The external property means that they are potentially available to other functions.
 * > External variables offer an alternative to function arguments and return values.
 *   - They MIGHT be better than long argument lists.
 *   - They are useful because of their greater scope and lifetime--they are always there, so they retain their value.
 * > The scope of a name is the part of a program that can access that name.
 *   - Automatic variables are limited to the function in which they are declared. Same for the functions parameters.
 *   - Functions and external variables last from the declaration point to the end of the file being compiled.
 *   - An external variable defined between  funcx()  and  funcy()  is visible only to the latter one UNLESS...
 * > For external variables, the  extern  declaration is mandatory if:
 *   a) it is referred to before it is defined, or if
 *   b) it is defined in a different source file from the one which uses it.
 * > A declaration merely announces the variable's properties.
 * > A definition does that and also sets storage aside.
 *   - see bottom of page 80 and top of 81
 *   - Since storage is set aside, array sizes must be given for definitions.
 * > The functions that constitute a program can be split across multiple files. It may be convenient to put...
 *   functions that are closely related in one file, and unrelated functions in another file.
 * > Function declarations typically go in header files which are included as needed. All functions could be...
 *   declared in one header file, but then all functions would have access to each other which is probably unnecessary.
 *   - There is a tradeoff between having each file access only what it needs, and maintaining many header files.
 */
int main()
{
    // printf("%d\n", lastoccurinstr());
    printf("%f\n", strtofloat("835.71e-3"));

    return 0;
}
