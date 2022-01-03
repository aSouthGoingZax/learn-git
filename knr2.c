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
 */
