/*
 * C programming video on youtube
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inthebeginning()
{
    printf("hello, world\n");
    char starType;
    double itemPrice;
    printf("How much is that pussy?\n");
    scanf("%lf", &itemPrice);             // you need the & before the variable for everything other than a string
    printf("estas seguro?\n");
    scanf(" %c", &starType);              // equivalent line but for a single characater
    printf("%c, a %f pussy?!?", starType, itemPrice);
    char fullName[24];                    // this string can be 24 characters max
    printf("Enter your name...\n");
    scanf("%s", fullName);                // scanf will stop reading characters after a space. John Smith -> John
    fgets(fullName, 24, stdin);
    printf("hello, %s", fullName);
}

void sayHi(char name[], int age);
float cubeaNum(float num);           // prototyping a function above the function that calls it below the calling function

void functioncalldemo()
{
    sayHi("John", 21);    // John and 21 and called arguments. These arguments get passed to the function being called.
    sayHi("Mike", 34);    // If nothing were in the () of the function being called, the () of sayHi would be empty here too.

    printf("%f\n", cubeaNum(2.0));
    printf("%f\n", cubeaNum(2.5));
    printf("%f\n", cubeaNum(2.5555555));
}

void sayHi(char name[], int age)    // anything in the () is called a parameter. It is essentially the function's input value(s)
{
    printf("Hello, %s. You're %i.", name, age);
}

float cubeaNum(float num)    // this function returns a float, hence its type is float
{
    float answer = num * num * num;
    return answer;    // this line could be:  return num * num * num;
}

void ifdemo()
{
    int num1, num2, num3;
    printf("Enter numbers:\n");
    scanf("%i\n%i\n%i", &num1, &num2, &num3);
    if (num1>num2 && num1>num3)             // (num1>num2 || num1>num3)    || is or condition
    {                                       // (!(num1>num2))    ! around a condition negates that condition, inverts it output
        printf("%i is biggest.", num1);
    }
    else if (num2>num1 && num2>num3)
    {
        printf("%i is biggest.", num2);
    }
    else
    {
        printf("%i is biggest.", num3);
    }
}

void switchdemo()
{
    char starType;

    scanf(" %c", &starType);

    switch (starType)
    {
    case 'O':
        printf("star is type %c", starType);
        break;
    case 'B':
        printf("star is type %c", starType);
        break;
    case 'A':
        printf("star is type %c", starType);
        break;
    default:
        printf("star is not first three on main sequence");
        break;
    }
}

struct GraphicsCard    // this struct declaration is just an empty framework or scaffolding
{                      // multiple structs can be used in your program
    char brand[10];
    char name[15];
    int vram, year;
};

void structdemo()
{
    struct GraphicsCard gpu1;        // this  gpu1  struct uses the structure of the  GraphicsCard  struct

    strcpy(gpu1.brand, "AMD");       // the next struct could be  gpu2
    strcpy(gpu1.name, "R6900XT");    // gpu1  and  gpu2  are to each other what two ints are to each other
    gpu1.vram = 16;                  // just another instance of the same data type
    gpu1.year = 2020;

    printf("%s %s. Released in %i with %i GB of VRAM.", gpu1.brand, gpu1.name, gpu1.year, gpu1.vram);
}

void whileloopdemo()    // a while loop checks the condition before executing the code in the loop
{
    int i = 1;

    while (i < 10)
    {
        printf("%i", i);
        i++;    // same as i = i + 1;
    }           // i-- is i = i - 1;
}

void dowhileloopdemo()    // a do while loop runs the code in the loop before checking the condition
{
    int i = 1;

    do
    {
        printf("%i", i);
        i++;
    }
    while (i < 10);
}

void forloopdemo()
{
    int i;
    int primeNumbers[] = {2, 3, 5, 7, 11, 13, 17, 19};

    for (i = 0; i < 8; i++)    // less than 8 because there are 7 elements in the array
    {
        printf("%i\n", primeNumbers[i]);
    }
}

void twodimarray()
{
    int i, j;
    int nums[3][4] =         // 2D array has 3 rows and 4 columns
    {
        {2, 4,  6,  8},
        {3, 6,  9, 12},
        {4, 8, 12, 16},
    };

    nums[2][1] = 69;         // how to assign a value to a specific element of a 2D array

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%i, ", nums[i][j]);
        }
        printf("\n");
    }
}

void pointerdemo1()
{
    int myage = 27;
    char startype = 'B';

    printf("I am %i. Our sun is a %c class star.\n", myage, startype);
    printf("The physical address in memory of the age variable is %p\n", &myage);
    printf("The physical address in memory of the name variable is %p\n", &startype);

    int *pmyage = &myage;           // a pointer is simply the memory address of a variable
    char *pstartype = &startype;    // so the variable  pmyage  stores the memory address of the  myage  variable

    printf("%p\n", pmyage);         // the variable type for pointer must match the type of the variable that it is the memory address of
    printf("%i\n", *pmyage);        // the asterisk dereferences the pointer, so it goes to that memory address and does some operation
                                    // it could be to assign a value, get a value, or some other operation
    int i;
    int *p;      // this is a pointer to an int
    p = &i;      // use & operator to get a pointer to  i, assign that to  p
    *p = 3;      // use * operator to "dereference"  p, meaning that 3 is assigned to  i
    // sometimes you want to know the memory address, so it's convenient to store the address in a variable
}

void filehandling()
{
    FILE * pFile = fopen("fruits.txt", "w");    // w means write. r means read. a means append. if the file doesn't exist, write will create it
                                                // if no path (absolute or relative) is specified, it will create it where the source code file is
    fprintf(pFile, "Raspberry, yum\nApple, okay\nDurian, smelly");
    fopen("fruits.txt", "a");                   // a means append on to the end of a file
    fprintf(pFile, "\nStrawberry, also yum");
    fclose(pFile);                              // if you open a file, always close it
}

void pointerdemo2()
{
    char line[200];
    FILE * pFile = fopen("fruits.txt", "r");

    fgets(line, 200, pFile);    //this reads the first 200 characters on the first line of the file and stores them in the  line  variable
    printf("%s", line);
    fgets(line, 200, pFile);    //using fgets again will read the second line because it increments after each use
    printf("%s", line);
    fclose(pFile);
}

void assignmenttest()
{
    /* int i, j = 4; */  // don't set like this,  i  will be garbage and  j  will be 4
    int i = 0, j = 4;    // setting like this is allowed

    printf("var i is %i\n", i);
    printf("var j is %i\n", j);

    i = i + 1;
    j = j - 1;

    printf("var i is now %i\n", i);
    printf("var j is now %i\n", j);
}

int main()
{
    inthebeginning();
    functioncalldemo();
    ifdemo();
    switchdemo();
    structdemo();
    whileloopdemo();
    dowhileloopdemo();
    forloopdemo();
    twodimarray();
    pointerdemo1();
    filehandling();
    pointerdemo2();
    assignmenttest();

    return 0;
}
