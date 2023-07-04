// this one reads in setlist2.txt and places all the words with four or more letters into setlist.txt.
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

/* Reads all of the words from the dictionary file, and writes the ones with four or more letters to the list*/

// this one gets a word at a time
void getWord(char word[])
{
	// initialise a few things
	int i=0;
	FILE *fpr;
	FILE *fpw;
	
	// initialise the file we read from
	fpr=fopen("wordlist2.txt", "r");
	// If it fails, fpr==NULL is true.
	if (fpr==NULL)
	{
		printf("something went wrong here fpr didn't open");
	}
	
	// initialise the file we write to`
	fpw=fopen("wordlist.txt", "w");
	// If it fails, fpr==NULL is true.
	if (fpw==NULL)
	{
		printf("something went wrong here fpw didn't open");
	}
	
	// go through the rest of the words
	while (fgets(word, 100, fpr) != NULL)
	{
		//we have our line
		// extract the word
		i=0;
		while (word[i+1]!= '\0')
		{
			i++;
		}
		
		// write to the file if the word is long enough
		if (i>3)
		{
			fprintf(fpw,"%s", word);
		}
	}
} 


int main(void)
{
	// it works
	char word[1998];
	getWord(word);
}