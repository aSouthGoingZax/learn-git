/*
 * This program takes colours from the 24-bit true colour depth and produces the closest match from the 8-bit colour palette.
 * Use it for making colours schemes for programs that support only 256 colour.
 */

#include <stdio.h>
#include <stdlib.h>

/* function declarations */
int calcrgbdiff(int rgb[]);
void comparetobase(int rgb[], int base[], int bmatch[]);    // the first 16 of the 256, i.e. the base colours
void comparetocols(int rgb[], int cmatch[]);                // the colours in between the base and greys
void comparetogrey(int rgb[], int gmatch[]);                // the last 14 of the 256, i.e. the greys
void converthexin(char input[], int rgb[]);
void convertrgbin(char input[], int rgb[]);
void fixcase(char input[]);
int getcolour(char input[], int len);
void loopbasecols(int rgb[], int bmatch[]);
void rgbtohex(int xmatch[], char hexout[]);

/* function implementations */
/*
 * Attempt matching greys only if the rgb components are close to each other.
 * The worst case is 47,0,0. This should match to 0,0,0 because 95,0,0 is further away.
 * 48,0,0 will go up to 95,0,0. Hence, if the max difference between rgb components...
 * is more than 47, don't bother matching greys.
 */
int calcrgbdiff(int rgb[])
{
    int diff;

    if (rgb[0] > rgb[1] && rgb[0] > rgb[2])
    {
        diff = (rgb[1] > rgb[2]) ? rgb[0] - rgb[2] : rgb[0] - rgb[1];
    }
    else if (rgb[1] > rgb[0] && rgb[1] > rgb[2])
    {
        diff = (rgb[0] > rgb[2]) ? rgb[1] - rgb[2] : rgb[1] - rgb[0];
    }
    else
    {
        diff = (rgb[0] > rgb[1]) ? rgb[2] - rgb[1] : rgb[2] - rgb[0];
    }

    return diff;
}

void comparetobase(int rgb[], int base[], int bmatch[])
{
    /*
     * Since the  <=  operator is used in the condition, the brighter colour--which is...
     * produced later in the loop because that is how it is written--overwrites the...
     * darker colour even though they have the same difference in components.
     */
    if (abs(rgb[0] - base[0]) + abs(rgb[1] - base[1]) + abs(rgb[2] - base[2]) <= bmatch[6])
    {
        bmatch[0] = base[0];
        bmatch[1] = base[1];
        bmatch[2] = base[2];
        bmatch[3] = abs(rgb[0] - base[0]);
        bmatch[4] = abs(rgb[1] - base[1]);
        bmatch[5] = abs(rgb[2] - base[2]);
        bmatch[6] = bmatch[3] + bmatch[4] + bmatch[5];
    }
}

void comparetocols(int rgb[], int cmatch[])
{
    int colours[] = {0, 95, 135, 175, 215, 255};
    int i, j;

    for (i = 0; i < 3; ++i)    // 3 is how many colour components there are
    {
        for (j = 0; rgb[i] > colours[j]; ++j);

        /* Go up or down if  rgb[i]  is on the midpoint, e.g. 155 between 135 and 175? Offer both? */
        if (rgb[i] - colours[j - 1] < colours[j] - rgb[i])    // if on a midpoint, this chooses the higher value
        {
            cmatch[i] = colours[j - 1];
            cmatch[i + 3] = rgb[i] - colours[j - 1];
        }
        else
        {
            cmatch[i] = colours[j];
            cmatch[i + 3] = colours[j] - rgb[i];
        }
    }
}

/* TODO:
 * Once above 95, the jump in rgb component value is 40. So if the max difference...
 * between the rgb components is more than half of 40, don't bother finding the...
 * closest grey match because there will necessarily be a colour match that is closer. */
void comparetogrey(int rgb[], int gmatch[])
{   // the last element of  greys[]  is there only to account for  average  being greater than 238
    int greys[] = {0, 8, 18, 28, 38, 48, 58, 68, 78, 88, 98, 108, 118, 128, 138, 148, 158, 168, 178, 188, 192, 198, 208, 218, 228, 238, 255};
    int i, j, average;

    average = (rgb[0] + rgb[1] + rgb[2]) / 3;
    for (j = 0; average >= greys[j]; ++j);

    if (average - greys[j - 1] < greys[j] - average)
    {
        for (i = 0; i < 3; ++i)
        {
            gmatch[i] = greys[j - 1];
            gmatch[i + 3] = abs(rgb[i] - greys[j - 1]);
        }
    }
    else
    {
        for (i = 0; i < 3; ++i)
        {
            gmatch[i] = greys[j];
            gmatch[i + 3] = abs(rgb[i] - greys[j]);
        }
    }
}

/* turn {'#', '2', 'F', 'D', '9', 'A', '7', '\n', '\0'} into {47, 217, 167} */
void converthexin(char input[], int rgb[])
{
    char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int i, j, k, l;
    k = l = 0;

    for (i = 1; input[i] != '\n'; ++i)    // start on 1 because  input[0]  is a #
    {
        for (j = 0; input[i] != hex[j]; ++j);

        if (i % 2 == 1)
        {
            l = 16 * j;
        }
        else
        {
            rgb[k] = l + j;
            ++k;
        }
    }
}

/* turn {'2', '5', '1', ',', '9', ',', '7', '3', '\n', '\0'} into {251, 9, 73} */
void convertrgbin(char input[], int rgb[])
{
    int i, j;

    for (i = j = 0; j < 3; ++j)
    {
        for (rgb[j] = 0; input[i] != ',' && input[i] != '\n'; ++i)
        {
            rgb[j] = (10 * rgb[j]) + (input[i] - '0');
        }
        ++i;    // move past the comma that the inner loop stopped on
    }
}

void fixcase(char input[])
{
    char letters[2][6] =
    {
        {'a', 'b', 'c', 'd', 'e', 'f'},
        {'A', 'B', 'C', 'D', 'E', 'F'},
    };
    int i, j;

    for (i = 1; input[i] != '\n'; ++i)    // start on 1 because  input[0]  is a #
    {
        for (j = 0; j < 6; ++j)
        {
            if (input[i] == letters[0][j])
            {
                input[i] = letters[1][j];
                break;
            }
        }
    }
}

int getcolour(char input[], int len)    // nothing here accounts for incorrect input format or invalid values
{
    int c, i;

    for (i = 0; i < (len - 1) && (c = getchar()) && c != '\n' && c != EOF; ++i)
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

/*
 * Comparing to these base colours is almost pointless because terminal colour schemes change the base 16.
 * Who actually uses the default xterm colours which this function produces?
 */
void loopbasecols(int rgb[], int bmatch[])
{
    int colours[] = {0, 128};    // 192,192,192 is part of base but  comparetogrey()  captures it
    int base[3];
    int r, g, b, i;
    i = 0;

    for (b = 0; b < 2 && i < 2; ++b)    // second condition is just to avoid an infinite loop
    {
        for (g = 0; g < 2; ++g)
        {
            for (r = 0; r < 2; ++r)
            {
                base[0] = colours[r];
                base[1] = colours[g];
                base[2] = colours[b];
                comparetobase(rgb, base, bmatch);
            }
        }

        if (b == 1)    // once the loop has run through as if the second condition were not there,...
        {              // run through it again but using 255 instead of 128
            colours[1] = 255;
            b = -1;
            ++i;
        }
    }
}

void rgbtohex(int xmatch[], char hexout[])
{
    int i, j, k;
    char hex[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    hexout[0] = '#';
    k = 1;

    for (j = 0; j < 3; ++j)
    {
        for (i = 0; i < xmatch[j] / 16; ++i);
        hexout[k] = hex[i];
        ++k;
        for (i = 0; i < xmatch[j] % 16; ++i);
        hexout[k] = hex[i];
        ++k;
    }
    hexout[k] = '\0';
}

int main()
{
    int len = 13;
    int rgb[3], cmatch[6], bmatch[7], gmatch[6];
    char input[len], hexout[8];

    bmatch[6] = 999;    // set to a number bigger than 3*255 because that is the max diff possible

    printf("Enter colour in either of the following formats.\n1)\t#f4c809\n2)\t231,7,49\n");

    while (getcolour(input, len) > 0)
    {
        if (input[0] == '#')
        {
            fixcase(input);
            converthexin(input, rgb);
        }
        else
        {
            convertrgbin(input, rgb);
        }

        printf(">>%s", input);
        printf(">>%i,%i,%i\n", rgb[0], rgb[1], rgb[2]);

        comparetocols(rgb, cmatch);
        rgbtohex(cmatch, hexout);
        printf("col\t%i,%i,%i\t%s\tdiff: %i\n", cmatch[0], cmatch[1], cmatch[2], hexout, cmatch[3] + cmatch[4] + cmatch[5]);

        loopbasecols(rgb, bmatch);
        rgbtohex(bmatch, hexout);
        printf("base\t%i,%i,%i\t%s\tdiff: %i\n", bmatch[0], bmatch[1], bmatch[2], hexout, bmatch[6]);
        bmatch[6] = 999;

        if (calcrgbdiff(rgb) < 48)    // explanation given above  calcrgbdiff()
        {
            comparetogrey(rgb, gmatch);
            rgbtohex(gmatch, hexout);
            printf("grey\t%i,%i,%i\t%s\tdiff: %i\n", gmatch[0], gmatch[1], gmatch[2], hexout, gmatch[3] + gmatch[4] + gmatch[5]);
        }
    }

    return 0;
}
