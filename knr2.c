/*
 * The C programming language - K&R
 * Chapter 2
 */

#include <stdio.h>
#include <string.h>

/*
 * DATA TYPES
 * > char a
 *   - 1 byte (8 bits) that holds one character
 * > int b
 *   - an integer
 * > float c
 *   - single precision floating point
 * > double d
 *   - double precision floating point
 *
 * DATA TYPE QUALIFIERS
 * > short int a
 *   - 16 bit integer
 * > long int b
 *   - 32 bit integer
 * > signed char c
 *   - a value between -128 and 127
 * > unsigned char d
 *   - a value between 0 and 255
 * > unsigned int e
 *   - a non-negative integer
 *
 * CONSTANTS
 * > constants have a letter after them, the letters can be combined
 *   - 123456789L   long constant
 *   - 240U         unsigned constant
 *   - 123.4F       float constant
 * > integers can be given in decimal, hexadecimal, or octal
 *   - 31           decimal
 *   - 0x1F         hexadecimal
 *   - 037          octal
 * > an arbitrary byte-sized bit pattern
 *   - '\013'       octal
 *   - '\x9F'       hexadecimal
 * > character constants are surrounded by single quotes
 * > string constants are surrounded by double quotes
 * > string constants can be concatenated
 *   - "hello," " world\n"  is equivalent to  "hello, world\n"
 * > an enumeration constant is a list of constant integer values
 *   - enum boolean { NO, YES }
 *   - the first element has value 0, the next element 1, and so on unless explicit values are specified, see page 39
 *   - enumerations are a convenient way of assigning constants to names, an alternative to  #define ALPHA 0xd8U
 *
 * DECLARATIONS
 * > declarations specify the type and name(s) of the variable(s)
 * > the initialisation may be done in the declaration
 * > automatic (local to a function) variables are initialised upon each entry to the function
 * > non-automatic variables are initialised only once before the program starts executing
 * > external and static variables are initialised to zero if not specified
 * > adding the  const  keyword to any declaration means that the value will not be changed
 *   - int findthefirstq(cont char input[]);  the function does not change the array
 *
 * ARITHMETIC OPERATORS
 * > +   -   *   /   %
 *   - the  %  operator cannot be applied to floats or doubles
 *
 * RELATIONAL & LOGICAL OPERATORS
 * > ==   !=   >   >=   <   <=
 * > &&   ||
 * > conditions are evaluated left to right and evaluation stops as soon as truth or falsehood is known
 *   - for (i = 0; i < MAXLEN - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *   - if the first condition is false, the remaining conditions are not even checked
 *   - c  must also get its value from  getchar()  before being compared to  EOF
 * > if a relational or logical expression is true, it has value 1; 0 if false
 * > the negation operator  !  converts non-zero operands to 0, and a zero operand into a 1
 *   - if (!valid)  is equivalent to  if (valid == 0)
 */

int testa()
{
    return 5;
}

int main()
{
    /* char message[] = "What's up, dickhead"; */
    /* int len = strlen(message); */
    /* printf("%i\n", len); */
    if (!testa())
        printf("success\n");
    else
        printf("fuck\n");

    return 0;
}
