/*
 * C programming video on youtube
 */

#include <stdio.h>
#include <stdlib.h>

/*
int main()
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
*/
//----------------------------------------------
/*
int main()
{
    sayHi("John", 21);                      // John and 21 and called arguments. These arguments get passed to the function being called.
    sayHi("Mike", 34);                      // if nothing were in the () of the function being called, the () of sayHi would be empty here too
    return 0;
}

void sayHi(char name[], int age)            // anything in the () is called a parameter. It is essentially function's input value(s)
{
    printf("Hello, %s. You're %i.", name, age);
}
 */
//----------------------------------------------
/*
float cubeaNum(float num);                  //prototyping this function above the main function allows it to be put below the main function

int main()
{
    printf("%f\n", cubeaNum(2.0));
    printf("%f\n", cubeaNum(2.5));
    printf("%f\n", cubeaNum(2.5555555));
}

float cubeaNum(float num)                   //this function is called by another function but is below it because...
{                                           //this function is prototyped above the function that calls it
    float answer = num * num * num;
    return answer;                          //this line could be: return num * num * num;
}
*/
//----------------------------------------------
/*
int main()
{
    int num1, num2, num3;
    printf("Enter numbers:\n");
    scanf("%i\n%i\n%i", &num1, &num2, &num3);
    if (num1>num2 && num1>num3)             //(num1>num2 || num1>num3)    || is or condition
    {                                       //(!(num1>num2))    ! around a condition negates that condition, inverts it output
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
    return 0;
}
*/
//----------------------------------------------
/*
int main()
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
    return 0;
}
*/
//----------------------------------------------
/*
struct GraphicsCard
{
    char brand[10];
    char name[15];
    int vram, year;
};

int main()
{
    struct GraphicsCard gpu1;
    strcpy(gpu1.brand, "AMD");
    strcpy(gpu1.name, "R6900XT");
    gpu1.vram = 16;
    gpu1.year = 2020;
    printf("%s %s. Released in %i with %i GB of VRAM.", gpu1.brand, gpu1.name, gpu1.year, gpu1.vram);
    return 0;
}
*/
//----------------------------------------------
/*
int main()
{
    int i = 1;
    while (i<10)
    {
        printf("%i", i);
        i++;                                //same as i = i + 1;
    }                                       //i-- is i = i - 1;
    return 0;
}

int main()
{
    int i = 1;
    do                                      //a do while loop runs the code in the loop before checking the condition
    {                                       //a while loop checks the condition before executing the code in the loop
        printf("%i", i);
        i++;
    }
    while (i<10);
    return 0;
}

int main()
{
    int i;
    int primeNumbers[] = {2, 3, 5, 7, 11, 13, 17, 19};
    for (i = 0; i < 8; i++)                 //less than 8 because there are 7 elements in the array
    {
        printf("%i\n", primeNumbers[i]);
    }
    return 0;
}
*/
//----------------------------------------------
/*
int main()
{
    int nums[3][4] =                        //2D array has 3 rows and 4 columns
    {
        {2, 4,  6,  8},
        {3, 6,  9, 12},
        {4, 8, 12, 16},
    };
    //nums[2][1] = 8;                       //this is how you would specify individual elements of 2D array
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%i, ", nums[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/
//----------------------------------------------
/*
{
    int myAge = 27;
    char starType = 'B';
    printf("I am %i. Our sun is a %c class star.\n", myAge, starType);
    printf("The physical address in memory of the age variable is %p\n", &myAge);
    printf("The physical address in memory of the name variable is %p\n", &starType);
    int * pMyAge = &myAge;                  //a pointer is simply the memory address of a variable
    char * pStarType = &starType;           //so the variable pmyAge is storing the memory address of the myAge variable
    printf("%p\n", pMyAge);                 //the variable type for pointer must match the type of the variable that it is the memory address of
    printf("%i\n", *pMyAge);                //the asterisk dereferences the pointer, so it goes to that memory address and grabs the value stored in there

    int i;
    int *p;    // this is a pointer to an int
    p = &i;    // use & operator to get a pointer to  i, assign that to  p
    *p = 3;    // use * operator to "dereference"  p, meaning that 3 is assigned to  i

    return 0;    //sometimes you want to know the memory address, so it's convenient to store the address in a variable
}
*/
//----------------------------------------------
/*
int main()
{
    FILE * pFile = fopen("fruits.txt", "w");        //w means write. r means read. a means append.    if the file doesn't exist, write will create it
                                                    //if no path (absolute or relative) is specified, it will create it where the source code file is
    fprintf(pFile, "Raspberry, yum\nApple, okay\nDurian, smelly");
    fopen("fruits.txt", "a");                       //append adds on to the end of a file
    fprintf(pFile, "\nStrawberry, also yum");
    fclose(pFile);                                  //if you open a file, always close it
    return 0;
}

int main()
{
    char line[200];
    FILE * pFile = fopen("fruits.txt", "r");
    fgets(line, 200, pFile);                //this reads the first 200 characters on the first line of the file and stores them in the line variable
    printf("%s", line);
    fgets(line, 200, pFile);                //using fgets again will read the second line because it increments after each use
    printf("%s", line);
    fclose(pFile);
    return 0;
}
*/
//----------------------------------------------
/*
int main()
{
    int i, j = 4;                           // setting like this is not allowed.  i  will be 0 and j will be 4
    int i = 0, j = 4;                       // setting like this is allowed

    printf("var i is %i\n", i);
    printf("var j is %i\n", j);
    i = i + 1;
    j = j - 1;
    printf("var i is now %i\n", i);
    printf("var j is now %i\n", j);
    return 0;
}
*/
