// this one makes hangman.
// longer words get less guesses
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

/*
	    __________
        | /      | 
        |/       | 
        |        | 
        |       \O/
        |        | 
        |       / \
        |          
        |          
       /|\         
______/_|_\________
*/

void getPic(int state, char *hangmanGuy)
{
char dudeArray[1998];
	
// 0
if (state==0)
{
	strncpy(dudeArray, "\nHANGMAN!!!\n\n", 1998);
}

// 1							start the bottom line
if (state==1)
{
strncpy(dudeArray,
" \n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"___________________\n", 1998);
}

// 2							add pole
if (state==2)
{
strncpy(dudeArray,
"         \n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"________|__________\n", 1998);
}

// 3							first support

if (state==3)
{
strncpy(dudeArray,
"         \n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\\ \n"
"________|_\\________\n", 1998);
}

// 4							second support
if (state==4)
{
strncpy(dudeArray,
"         \n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"        |\n"
"       /|\\ \n"
"______/_|_\\________\n", 1998);
}


// 5							top bar
if (state==5)
{
strncpy(dudeArray,
"        __________  \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"       /|\\         \n"
"______/_|_\\________\n", 1998);
}


// 6							top bar support
if (state==6)
{
strncpy(dudeArray,
"        __________  \n"
"        | /         \n"
"        |/          \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"       /|\\         \n"
"______/_|_\\________\n", 1998);
}


// 7							rope
if (state==7)
{
strncpy(dudeArray,
"        __________  \n"
"        | /      |  \n"
"        |/       |  \n"
"        |        |  \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"       /|\\         \n"
"______/_|_\\________\n", 1998);
}


// 8							head
if (state==8)
{
strncpy(dudeArray,
"        __________  \n"
"        | /      |  \n"
"        |/       |  \n"
"        |        |  \n"
"        |        O  \n"
"        |           \n"
"        |           \n"
"        |           \n"
"        |           \n"
"       /|\\         \n"
"______/_|_\\________\n", 1998);
}


// 9							body
if (state==9)
{
strncpy(dudeArray,
"        __________  \n"
"        | /      |  \n"
"        |/       |  \n"
"        |        |  \n"
"        |        O  \n"
"        |        |  \n"
"        |           \n"
"        |           \n"
"        |           \n"
"       /|\\         \n"
"______/_|_\\________\n", 1998);
}


// 10							arm 1
if (state==10)
{
strncpy(dudeArray,
"        __________  \n"
"        | /      |  \n"
"        |/       |  \n"
"        |        |  \n"
"        |       \\O \n"
"        |        |  \n"
"        |           \n"
"        |           \n"
"        |           \n"
"       /|\\         \n"
"______/_|_\\________\n", 1998);
}

// 11							arm 2
if (state==11)
{
strncpy(dudeArray,
"        __________  \n"
"        | /      |  \n"
"        |/       |  \n"
"        |        |  \n"
"        |       \\O/\n"
"        |        |  \n"
"        |           \n"
"        |           \n"
"        |           \n"
"       /|\\         \n"
"______/_|_\\________\n", 1998);
}

// 12							leg 1
if (state==12)
{
strncpy(dudeArray,
"        __________  \n"
"        | /      |  \n"
"        |/       |  \n"
"        |        |  \n"
"        |       \\O/\n"
"        |        |  \n"
"        |       /   \n"
"        |           \n"
"        |           \n"
"       /|\\         \n"
"______/_|_\\________\n", 1998);
}

// 13							leg 2
if (state==13)
{
strncpy(dudeArray,
"        __________  \n"
"        | /      |  \n"
"        |/       |  \n"
"        |        |  \n"
"        |        O  \n"
"        |       /|\\\n"
"        |       / \\\n"
"        |           \n"
"        |           \n"
"       /|\\         \n"
"______/_|_\\________\n", 1998);
}

	int i;
	for (i=0; i<1998; i++)
	{
		hangmanGuy[i]=dudeArray[i];
	}
}

void displayThings(int numFails, char *failArray, char *displayArray, int length)
{
	// we have to work out which state to get
	
	// 4,5,6 is all guesses
	// 7,8 is -1 guesses
	// 9 is -2 guesses
	// any more is -3 guesses
	
	
	
	
	// figure out which one to display
	int state;
	state = numFails;
	
	// surely just case by case
	if ((length>6) && (length<9))
	{
		if (state>4)
		{		
			state++;
		}
		
	}
	if (length==9)
	{
		if (state>1)
		{		
			state=state+2;
		}
		
	}
	if (length>9)
	{
		if (state>1)
		{		
			state=state+2;
		}
		if (state>4)
		{		
			state++;
		}
	}
	
	// intialise our image, and get the image
	char hangmanGuy[1998];
	getPic(state, hangmanGuy);
	
	// actually print the things
	printf("%s\n", hangmanGuy);
	printf("fail letters: %s\n", failArray);
	printf("your word: ");
	
	// add spaces between the characters, a heavily requested feature
	int i;
	for (i=0; i<length; i++)
	{
		printf("%c ", displayArray[i]);
	}
	
	printf("\n\n");
}

// this one gets a word that the player must guess
int getWord(char *word)
{
	// asks for a word from the user, and then returns the number of letters in the word
	
	int i=0;
	char read[1998];
	
	// ask for a word and read it in
	printf("What's your word? ");
	scanf("%s", &read);
	strncpy(word, read, 1998);
	
	// so now we have the loop; find the length
	i=0;
	while (word[i]!= '\0')
	{
		i++;
	}
	
	// and just spam newlines so that the other player can't see the word
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	// we now have the length of the word
	//printf("word is %s", word);
	return i; // abcde returns 5
}

int main(void)
{
	// initialise a few things to get our word
	srand(time(NULL));
	char word[1998];
	int length;
	length = getWord(word);
	// now how many guesses
	int numGuesses;
	if (length <=6)
	{
		numGuesses=13;
	} else if (length <=8)
	{
		numGuesses=12;
	} else if (length <=10)
	{
		numGuesses=11;
	} else
	{
		numGuesses=10;
	}
	
	// initialise a few other things
	int numRuns = 0;
	char guess[1998];
	char displayArray[1998];
	char failArray[1998];
	int i;
	int inWord = 0;
	int numFails=0;
	int numRight=0;
	int validq=0;
	
	// build up the display array
	for (i=0; i<length; i++)
	{
		displayArray[i]='_';
	}
	displayArray[length]='\0';
	failArray[0]='\0';
	
	
	// so now we have our word, and how long the word is.
	// go through a few times and get a guess, and check

	while (numFails < numGuesses)
	{
		displayThings(numFails, failArray, displayArray, length);
		inWord=0;
		validq=0;
		
		// read in the guess
		
		// check the letters to see if they are in the word
			// I think we do this by havng a reference array and a display array
		
		// add the letters that failed to the final cringe array, which we will also be displaying
		
		
		// get a word, and check it's unique
		while (validq == 0)
		{
			// ask for a word and read it in
			printf("Guess %d:\n", numRuns+1);
			scanf("%s", &guess);
		
			// check we haven't already guessed it
			validq=1;
			for (i=0; i<length; i++)
			{
				if (displayArray[i]==guess[0])
				{
					validq=0;
				}
			}
		}
		
		// process our guess
		for (i=0; i<length; i++)
		{
			//make it lower case
			if ('A' <= guess[i] && guess[i] <='Z')
			{
				guess[i]=guess[i]+'a'-'A';
			}
			
			// check if it is in the word
			for (i=0; i<length; i++)
			{
				if (word[i]==guess[0])
				{
					// this letter is in the word
					inWord=1;
					numRight++;
				}
			}
			
			if (inWord==1)
			{
				// the letter is in the word
				// put the letters in the word into the display array
				
				// go through the reference array
				// if the current letter is the guessed letter:
					// write it to the output display
				// else:
					// it isn't in the guessed letter. Put the letter in the fail cringe array, and don't change the output display
				
				for (i=0; i<length; i++)
				{
					if (word[i]==guess[0])
					{
						displayArray[i]=guess[0];
					}
				}
			} else {
				// it was not in the word
				// put it in the fail cringe array
				failArray[numFails]=guess[0];
				
				// make sure to end it well
				failArray[numFails+1]='\0';
				
				numFails++;
			}
			
			if (numRight==length)
			{
				numFails=100;
			}
		}
		
		numRuns++;
	}
	
	displayThings(numFails, failArray, displayArray, length);
	
	printf("\n\n");
	
	// display the win/lose message
	if (numFails == 100)
	{
		printf("you won good work");
	} else {
		printf("ha you lose. noob. The word was %s", word);
	}
	
	printf("\n\n");
}