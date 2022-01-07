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
// int main()
// {
//     int i;
//     char c = 98;            // data type conversions work across the assignment
//     i = c;                  // so here, the value of  c  is converted to an int
//     printf("||%i\n", i);    // this works as expected, no information is lost when converting from char to int
//     c = i;
//     printf("<<%i\n", c);    // calling  c  as an int produces 98
//     printf(">>%c\n", c);    // calling  c  as a char produces  b
//     return 0;
// }
/*
 * TYPE CONVERSIONS
 * > operators that take two operands (binary operators) promote the lower type to the higher type
 *   - for an int that is multiplied by a float, the int is converted to a float
 *   - see section 6 of appendix A
 * > type conversions can be forced using a cast
 *   - n = sqrt((double) i);
 *   - sqrt()  expects a double so the int  i  has to be converted
 * > the parameters given in a function's prototype can serve to convert its arguments to the specified type
 *
 * INCREMENT & DECREMENT OPERATORS
 * > ++   --
 * > ++i  returns the value of  i  after incrementing
 * > i++  returns the value of  i  before incrementing
 * > the operators can be applied only to variables, not expressions
 *   - (i + j)++  is illegal
 */
// int main()
// {
//     int i, j;
//     int c = 97;
//     char s[] = "piwcfgpq aif gawi sfd";
//
//     for (i = j = 0; s[i] != '\0'; i++)
//     {
//         if (s[i] != c)    // this removes any instance of  a  from the string
//         {
//             s[j++] = s[i];    // this is equivalent to  s[j] = s[i]; ++j;
//         }
//     }
//     s[j] = '\0';
//
//     printf("%s\n", s);
//
//     return 0;
// }
/*
 * Exercise 2-4
 * delete any character from one string if that character is also in the other string
 */
// int main()
// {
//     int i, j, k, l;
//     char vowels[] = "aeiou";    // remove all vowels from the string
//     char string[] = "paieuhg qeiuhv pietvg hqei hsn vbqepy vqeiuv gdv bqefugiwcfgpq aif";
//     char output[100];
//     l = strlen(vowels);
//
//     for (i = k = 0; string[i] != '\0'; ++i)
//     {
//         for (j = 0; vowels[j] != '\0'; ++j)
//         {
//             if (string[i] == vowels[j])
//             {
//                 break;
//             }
//         }
//         if (j == l)
//         {
//             output[k++] = string[i];
//         }
//     }
//     output[k] = '\0';
//
//     printf("%s\n", output);
//
//     return 0;
// }
/*
 * Exercise 2-5
 * find the location of the first character in one string that that matches any character in another string
 */
// int main()
// {
//     int i, j, k;
//     char nums[] = "369";    // damn you fine
//     char string[] = "dgv nw4vgb9iu dhf7";
//
//     for (i = k = 0; string[i] != '\0'; ++i)
//     {
//         for (j = 0; nums[j] != '\0' && k == 0; ++j)
//         {
//             if (string[i] == nums[j])
//             {
//                 k = 1;
//             }
//         }
//
//         if (k == 1)
//         {
//             break;
//         }
//     }
//
//     if (string[i] == '\0')    // alternatively,  if (i == strlen(string))
//     {
//         i = -1;
//     }
//
//     printf("%i\n", i);
//
//     return 0;
// }
/*
 * BITWISE OPERATORS
 * > &   |   ^   <<   >>   ~
 * > AND, OR, XOR, left shift, right shift, one's complement
 * > these can be applied only to char and int
 *   - the right operand for shift operators should not be negative
 * > the operators compare equivalent bits and produce a result
 *   - AND  is 1 only if both bits are 1
 *   - OR   is 1 if either of the two bits is 1
 *   - XOR  is 1 only if the bits are different
 *   - <<   shifts the bits of the first operand to the left by the second operand's amount
 *   - >>   shifts the bits of the first operand to the right by the second operand's amount
 *   - ~    flips all of the bits
 * > when the shift operators are used, vacated bits are filled with 0s
 *   - a << b  is effectively  a * (2^b)   (here, 2^b is math notation, not XOR)
 *   - a >> b  is effectively  a / (2^b)
 */
// int main()
// {
//     unsigned char a = 5;
//     unsigned char b = 9;
//
//     printf("a is %i, 00000101\n", a);
//     printf("b is %i, 00001001\n\n", b);
//     printf("a & b = %i\n", a & b);
//     printf("a | b = %i\n", a | b);
//     printf("a ^ b = %i\n", a ^ b);
//     printf("~a = %i\n", ~a);
//     printf("a << 1 = %i\n", a << 1);
//     printf("a >> 1 = %i\n", a >> 1);
//
//     return 0;
// }
/*
 * Exercise 2-6
 * grab the  n  bits starting at  pos  from  a  and place them at the right of  b  leaving the rest of  b  untouched
 */
// int main()
// {                    //       -- ----
//     int a = 1690;    // 00000110 10011010
//     int b = 4443;    // 00010001 01011011
//     int n = 6;       // how many bits we want
//     int pos = 4;     // position of rightmost bit that we want, i.e. we want the bits that have a dash above them
//     int c, d, e, f, g;
//
//     // 00010001 01011011    b
//     // 00000000 00101001    the dashed bits of  a
//     // 00010001 01101001    what the end result should be
//
//     c = a >> pos;       // 00000000 01101001
//     d = ~0;             // 11111111 11111111
//     d = ~0 << n;        // 11111111 11000000
//     d = ~d;             // 00000000 00111111
//     e = c & d;          // 00000000 00101001    alas, we have isolated the bits under the dashes
//     f = (b >> n) << n;  // 00010001 01000000
//     g = f ^ e;          // 00010001 01101001    hooray! OR and XOR are equivalent in this case because of how the bits were masked
//
//     printf("%d\n", g);
//     printf("%d\n", ((b >> n) << n) ^ ((a >> pos) & ~(~0 << n)) );
//
//     return 0;
// }
/*
 * Exercise 2-7
 * invert the  n  bits starting at  pos  of  a  leaving the rest untouched
 */
// int main()
// {                     //      --- --
//     int a = 11575;    // 00101101 00110111
//     int n = 5;
//     int pos = 6;
//     int b, c, d, e, f, g, h, i, j, k;
//
//     // 00101101 00110111    a
//     // 00101000 00110111    a  with the dashed bits replaced with 0
//     // 00000010 11000000    the dashed bits of  a  inverted and in position
//     // we need to ^ or | the above two to get...
//     // 00101010 11110111    end result
//
//     b = a >> pos;    // 00000000 10110100
//     c = ~0 << n;     // 11111111 11100000
//     c = ~c;          // 00000000 00011111
//     d = b & c;       // 00000000 00010100    we have isolated the dashed bits
//     e = d << pos;    // 00000101 00000000
//     e = ~e;          // 11111010 11111111
//     f = c << pos;    // 00000111 11000000
//     g = e & f;       // 00000010 11000000    the dashed bits of  a  inverted and in position
//     h = ~0 << n;     // 11111111 11100000
//     h = ~h;          // 00000000 00011111
//     h = h << pos;    // 00000111 11000000
//     h = ~h;          // 11111000 00111111
//     j = a & h;       // 00101000 00110111    a  with the dashed bits replaced with 0
//     k = j ^ g;       // 00101010 11110111    hooray!
//
//     printf("%d\n", k);
//
//     k = (a & ~(~(~0 << n) << pos)) ^ (~(((a >> pos) & ~(~0 << n)) << pos) & ((~(~0 << n)) << pos));
//
//     printf("%d\n", k);
//
//     return 0;
// }
/*
 * Exercise 2-8
 * Rotate the bit pattern to the right
 * iteratively displace the lowest order bit and put it as the new highest order bit
 */
// int main()
// {
//     unsigned int a = 11573;    // 00101101 00110101
//     unsigned int rot = 5;
//     unsigned int lobm = 1;     // 00000001   this is the lowest order bit's mask
//     unsigned int hobm;
//     int b, c, i;
//     b = a;
//
//     /* determine how many active bits are required by  a
//      * then match  hobm's  mask to that number */
//     for (c = 0; a != 0; ++c)
//     {
//         a = a >> 1;    // a  must be unsigned so that vacated bits are filled with zeros, not sign bits
//     }
//     hobm = ~(~0 << 1) << (c - 1);
//
//     /* right shift by 1
//      * put the displaced lowest order bit at the top
//      * repeat until shifted by the right amount */
//     for (i = 0; i < rot; ++i)
//     {
//         if (b & lobm)    // if ((b & lobm) == 1)  or  if (b % 2 == 1)
//         {
//             b = (b >> 1) ^ hobm;
//         }
//         else
//         {
//             b = (b >> 1) ^ 0;
//         }
//
//         printf("%d\n", b);
//     }
//
//     return 0;
// }
/*
 * ASSIGNMENT OPERATORS
 * > +=   -=   *=   /=   %=   <<=   >>=   &=   ^=   |=
 * > an assignment in the form  i = i + x;  can be written as  i += x;
 * > these operators can be used in assignment statements that appear in expressions
 */
/* Exercise 2-9 */
// x &= (x - 1);    // sets the rightmost bit of  x  to 0
// x - 1  flips the lowest order bit, thereby changing an even number to an odd number, and an odd to an even
// b & c  produces a 1 only if both bits are 1
// since the  x - 1  changes the lowest bit, the  &  operation will never produce a 1
// int main()
// {
//     unsigned int x = 11573;
//     int b;
//
//     // 00101101 00110101   x
//     // 00101101 00110100   x - 1
//     // 00101101 00110100   the & of the above two lines
//     // 00101101 00110010   the line above - 1
//     // 00101101 00110000   the & of the above two lines
//     // 00101101 00101000   the line above - 1
//     // 00101101 00100000   the & of the above two lines
//     // 00101101 00010000   the line above - 1
//     // 00101101 00000000   the & of the above two lines
//     // 00101100 10000000   the line above - 1
//     // 00101100 00000000   the & of the above two lines
//     // 00101010 00000000   the line above - 1
//     // 00101000 00000000   the & of the above two lines
//     // 00100100 00000000   the line above - 1
//     // 00100000 00000000   the & of the above two lines
//     // 00010000 00000000   the line above - 1
//     // 00000000 00000000   the & of the above two lines
//
//     /* for (b = 0; x != 0; x >>= 1)
//     {
//         if (x & 01)
//         {
//             b++;
//         }
//     } */
//
//     for (b = 0; x != 0; x &= x - 1)
//     {
//         b++;
//     }
//
//     printf("%d\n", b);    // this is how many 1s are in  x's  bit representation
//
//     return 0;
// }
/*
 * CONDITIONAL EXPRESSIONS
 * > the two possibility if statement  if (a) b; else c;  can be written using a ternary operator
 * > a ? b : c;    if a is true, then b, otherwise c
 * > this expression can be used wherever any other expression can be
 *   - z = (a > b) ? a : b;
 * > type conversions via promotion a la binary operators apply to this ternary operator too
 */
/* Exercise 2-10 */
int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        c = (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;    // only for ASCII character set
        printf("%c", c);
    }

    return 0;
}
/*
 * OPERATOR PRECEDENCE
 * > see page 53
 * > watch out for the order in which expressions are evaluated
 *   - x = f(x) + g(y);    // the function call to  g()  may be evaluated before  f()
 *   - this can lead to unexpected behaviour if one modifies something that the other depends on
 * > do not write code that depends on order of evaluation
 * > delineate it explicitly so no funny stuff happens
 */
