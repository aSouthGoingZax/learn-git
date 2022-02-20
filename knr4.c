/*
 * The C programming language - K&R
 * Chapter 4
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
 * BASICS OF FUNCTIONS
 * > All functions should be declared before they are defined. This allows for type coercions and some error detection.
 *   - return type, name, parameters:  int strtoint(char input[], short base);
 *   - The language server will complain when function calls and definition don't match the declaration.
 * > Function names must be unique.
 * > Functions should have a single, well defined task to perform, and the task should be done well.
 *   - This increases their utility to other functions.
 * > A function's interface (arguments and return value) to the rest of the program should be clean and narrow.
 *   - Not something that gets sent all manner of shit, and we don't care because it will deal with it.
 * > Functions that are small and simple are easier to alter and less prone to bugs.
 * > Functions should hide the details of operation from any parts of the program that don't need to know about them.
 *   - If you're not writing the function, you should have to think only about its input, not its implementation.
 *   - If you have to pass it too much input, it's probably not well defined.
 *   - You should not have to know why it's being called or under what circumstances its caller is calling it.
 *   - If difficulties cannot be buried inside functions and forgotten about, the program probably needs redesigning.
 *
 * COMPILATION
 * > Each source file is compiled, producing an object file which contains machine instructions.
 * > The various object files are linked together, along with any libraries, to produce an executable.
 * > To compile and link multiple files, run:
 *   $ gcc filex.c filey.c filez.c
 * > Source files can be compiled individually (useful if you edit one file):
 *   $ gcc -c filex.c
 *   $ gcc -c filey.c
 *   $ gcc -c filez.c
 * > Then the object files can be linked:
 *   $ gcc filex.o filey.o filez.o
 * > Standard C library functions are linked automatically. Other libraries must be requested manually.
 *   $ gcc file.c -lm    for the math library
 *   - The -l flag must come after the file names.
 * > If no name is given for the output file, a.out is used. Use the -o flag to specify a file name.
 *   $ gcc -o ayup ayup.c
 */
/*
 * Exercise 4-1
 * find the last occurrence of a pattern in a string
 */
int lastoccurinstr(char str[], char pttrn[])
{
    int i, j, k, pos = -1;

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
 * EXTERNAL VARIABLES
 * > A program consists of external functions and variables. External variables are defined outside of any functions.
 *   All functions are external. The external property means that they are potentially available to other functions.
 * > External variables offer an alternative to function arguments and return values.
 *   - They MIGHT be better than long argument lists.
 *   - They are useful because of their greater scope and lifetime--they are always there, so they retain their value.
 * > Externals are fine for configuration info which the whole program cares about.
 *   - This info is set just once at start up and does not change.
 *
 * SCOPE RULES
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
 *
 * HEADER FILES
 * > Function declarations typically go in header files which are included as needed. All functions could be...
 *   declared in one header file, but then all functions would have access to each other which is probably unnecessary.
 *   - There is a tradeoff between having each file access only what it needs, and maintaining many header files.
 *   - If  funcx()  in filea.c and  funcy()  in fileb.c  both need access to  funcz(),  funcz()  should be declared...
 *     in a header file which is included in both filea.c and fileb.c. The alternative is to declare  funcz()  in...
 *     both filea.c and fileb.c, which is obviously fucking stupid.
 *
 * STATIC VARIABLES
 * > One way of preventing unneeded access is to declare things as  static.
 *   - A static function or external variable limits its scope to the source that it is in.
 *   - A static automatic variable keeps its value after exit from the function (instead of disappearing on exit)...
 *     hence, it is ready for use on the next call to the function.
 *
 * REGISTER VAIABLES
 * > The  register  declaration tells the compiler that the variable will be heavily used. The compiler may not put...
 *   the variable in the machine register though, so yeah
 *   - Modern compilers do a good job of deciding where to put the variable even without the declaration.
 * > Only automatic variables and parameters can be declared as register.
 * > Taking the address of a register variable is impossible...relevant for pointers.
 */
void funca(register long n)
{
    register int i;
    // some code
}
/*
 * BLOCK STRUCTURE
 * > A function cannot be defined within a function.
 * > Variables can be defined within blocks. Variables declared within a brace exist until the matching closing...
 *   brace is reached. Such variables hide identically named variables in outer blocks.
 * > Automatic variables and parameters hide external variables and functions of the same name.
 * > Limiting the scope of a variable to a particular block may be useful.
 * > Using the same name is idiotic. Never do this, there are 26 letters to use, plus an infinity of unique names.
 */
void funcb(void)
{
    int i = 5, n = 100;

    if (n > 69)
    {
        int i = 420;          // declare a new  i
        printf("%d\n", i);    // this  i  exists only when this part of the if is entered
    }
    printf("%d\n", i);
}
/*
 * INITIALISATION
 * > If no value is given:
 *   - static and external variables are initialised to zero,
 *   - automatic and variables will be garbage.
 * > Static and external variables must be a constant expression because they are set at program start up.
 * > Automatic variables can be any expression, even a function call.
 * > An array must have its elements or its size specified.
 *   - With some elements initialised, missing elements are initialised to zero.
 *   - If there no elements initialised, the array will contain garbage.
 *
 * RECURSION
 * > A function can call itself.
 * > Recursive code is not less expensive in terms of memory and computation.
 *   - It is more compact and maybe easier to write and read.
 * > Recursion can be useful for recursively defined structures like trees.
 * > Each instance of a function that is called recursively has its own automatic variables and parameters.
 * > If a recursively called function accesses static or external data, watch the fuck out because the instances may...
 *   interfere with each other.
 * > Each instance passes a slightly reduced portion of the job onto its 'child'. This happens recursively until the...
 *   job is dealt with fully, at which point we return all the way back out.
 */
/*
 * Exercise 4-12
 * convert integer to string by calling a recursive function
 */
void recinttostr(int n, char str[], short i)
{
    if (n / 10 > 0)
    {
        recinttostr(n / 10, str, i - 1);
    }
    str[i] = n % 10 + '0';
}

void inttostr(int n)            // This function just prepares the number for recursion.
{
    char i = 'z';
    short l;
    int nn = n;                 // save  n  in  nn  because  n  gets altered in the for loop below

    if (n < 0)
    {
        i = -(n % 10) + '0';    // grab the lowest order digit because it is lost after the next line
        n /= 10;                // make it smaller so that it doesn't go out of range when the sign is flipped
        nn = n = -n;
    }

    for (l = 0; n % 10 > 0; ++l, n /= 10);    // determine how many digits  n  is so that we can set the array size
    l += (i != 'z') ? 3 : 1;                  // account for '\0', '-', and  i
    char str[l];

    str[l - 1] = '\0';          // this could be  str[l]  if  l  denoted the array subscript instead of the length
    if (i != 'z')
    {
        str[0] = '-';
        str[l - 2] = i;
        if (l > 3)              // l  is 3 only for single digit numbers, which get dealt with by  i
        {
            recinttostr(nn, str, l - 3);    // the recursion starts now
        }
    }
    else
    {
        recinttostr(nn, str, l - 2);    // the recursion starts now
    }

    printf("%s\n", str);
}
/*
 * Exercise 4-13
 * reverse a string using a recursive function
 */
void recrevstr(char str[], short i, short len)    // This function reverses the string in full. If the new line...
{                                                 // character is to be kept at the end, the caller must give the...
    char a;                                       // length of the string - 1.

    a = str[i];
    str[i] = str[len - 1];
    str[len - 1] = a;

    if (i + 1 < len - 1)
    {
        recrevstr(str, i + 1, len - 1);
    }
}
/*
 * THE PREPROCESSOR
 *
 * File inclusion
 * > #include  includes the contents a file during compilation. In effect, the include line is replaced with the...
 *   contents of the file that it specifies.
 *   - #include <filename>  is for headers that are provided for us
 *   - #include "filename"  is for headers that we write
 *   - #include "path/to/file"  if it's not in the same directory as the file that includes it
 * > A bunch of #defines that need to be program wide can be bundled into a header which is included in all files.
 * > When an included file is modified, all files that include that file need recompiling.
 *
 * Macro substitution
 * > #define AYY LMAO  replaces any instance of  AYY  with  LMAO  below the define
 *   - If a #define is broken onto more than one line, each line must end with a backslash.
 * > A #define may use previous defines
 * > A substitution doesn't occur if the macro name appears in quoted text.
 * > Each parameter of the macro must be in brackets so that the expansion works properly.
 *   - #define MAX(A, B) ((A) > (B) ? (A) : (B))
 * > The expressions of the macro are evaluated as many times as they appear. So make sure that no arguments change...
 *   within the expansion, through ++/-- operators for example.
 * > #undef MAX(A,B)  undefines the above #define
 * > see page 90 for more funky rules using # and ##
 *
 * Conditional inclusion
 * > Bits of code can be included or excluded depending on conditions evaluated during compilation.
 * > #if  evaluates a contstant integer expression (not including sizeof, casts, or enum constants), which if true...
 *   includes code until the next preprocessor if directive.
 * > #ifdef  and  #ifndef  test if a name is defined.

#if SYSTEM == SYSV
    #define HDR "sysv.h"
#elif SYSTEM == BSD
    #define HDR "bsd.h"
#elif SYSTEM == MSDOS
    #define HDR "msdos.h"
#else
    #define HDR "default.h"
#endif
#include HDR

#ifdef XINERAMA
#include <X11/extensions/Xinerama.h>
#endif // XINERAMA

 */
int main()
{
    char str[] = "You can think about the woman or the girl you knew the night before\n";
    char pttrn[] = "the";
    int n = -5;

    // printf("%d\n", lastoccurinstr(str, pttrn));
    // printf("%f\n", strtofloat("835.71e-3"));
    // funcb();
    // inttostr(n);
    // recrevstr(str, 0, strlen(str) - 1);
    // printf("%s\n", str);

    return 0;
}
