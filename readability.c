#include <stdio.h>
#include <cs50.h> // "get float" location
#include <math.h> // "round" location
#include <ctype.h> // "isalpha" (letter), "isblank" (space), & "ispunct" (punctuation) location

int main(void)

{

    string text = get_string("Text: ");  // prompts user input stored as a string

    float let = 0;
    float word = 0;
    float sen = 0;

    for (int x = 0; text[x] != '\0'; x++)  //loop for passing over each value in a string/array
    {
        if (isalpha(text[x]) != 0) // checks to see if any char in the string "text" is a letter
        {
            let++;
        }
        if (isspace(text[x]) != 0) // checks to see if any char in the string "text" is a space
        {
            word++;
        }
        if (text[x] == '.' || text[x] == '?' || text[x] == '!') // finds the end of a sentence by checking to see if a char is ./?/!
        {
            sen++;
        }

    }

    float words = (word + 1); // finds the number of words in a string in relation to the number of spaces
    // (assumes no start or end space and no double spaces)

    float L = 100 / words * let; // formula finding average number of letters for 100 words of text
    float S = 100 / words * sen; // formula finding avaergae number of sentences for 100 words of text
    float index = 0.0588 * L - 0.296 * S - 15.8; // formula for the Coleman-Liau Index

    int result = round(index * 1); // rounds the index number to the nearest whole number

    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result < 16)
    {
        printf("Grade %i\n", result);
    }
    else
    {
        printf("Grade 16+\n");
    }

}
