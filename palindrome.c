#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define WORDSZ 30

int palindrome(char *_line)
{
    int line_len = strlen(_line);
    // compare the corresponding characters from the extremes
    for (int i = 0, j = line_len - 1; i < j; i++, j--)
    {
        //  if not equal return false(0)
        if (_line[i] != _line[j])
            return 0;
    }
    return 1;
}

typedef struct Palindrome
{
    char *word;
    struct Palindrome *link;

} Palindrome;

// to return a palindrome struct object
Palindrome *newPalindrome(char *pal)
{
    // allocate memory, copy the string and set the link to null
    struct Palindrome *nwp = (struct Palindrome *)malloc(sizeof(struct Palindrome));
    nwp->word = (char *)malloc(sizeof(char) * (strlen(pal) + 1)); // allocate the memory
    strcpy(nwp->word, pal);
    nwp->link = NULL;
    return nwp;
}

void delPalindrome(Palindrome *pal)
{
    // free the memory allocated to its word and itself
    free(pal->word);
    free(pal);
}

void delPalindromes(Palindrome *pal)
{
    Palindrome *curr = pal; // to traverse the list
    while (curr != NULL)
    {
        Palindrome *toDel = curr; // get the node to be deleted
        curr = curr->link;        // go to next node
        delPalindrome(toDel);     // delete the current node
    }
}

// method to append the node with 'word' to the list
void append(Palindrome **pal, char *word)
{
    Palindrome *nwp = newPalindrome(word); // create a new palindrome
    // if there is no node in the list
    if ((*pal) == 0)
    {
        *pal = nwp;
    }
    else
    {
        // add nwp to the end of the list
        Palindrome *curr = *pal;
        while (curr->link)
            curr = curr->link;
        curr->link = nwp;
    }
}

int main(int argc, char *argv[])
{
    int ct;
    int pct;
    char word[WORDSZ];

    FILE *in_file = fopen("data11.txt", "r"); // open the input file

    Palindrome *palList;
    ct = 0;
    pct = 0;
    palList = 0;

    while (0 <= fscanf(in_file, "%s", word))
    {
        // if current word is palindrome, append it to the list
        if (palindrome(word))
        {
            append(&palList, word);
            pct++; // increment the palindrome count
        }
        ct++; // increase total line count
    }

    printf("There are %d palindromes in the %d line input file\n", pct, ct);

    if (pct > 0)
    {
        Palindrome *curr = palList; // to traverse and print the list
        while (curr)
        {
            printf("%s\n", curr->word);
            curr = curr->link;
        }
    }

    delPalindromes(palList);
    fclose(in_file);
    return 0;
}
