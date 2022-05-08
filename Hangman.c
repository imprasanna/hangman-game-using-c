#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<time.h>		//for using time() function in srand function
void title(void);		//for calling and displaying game title i.e. hangman at the top
void game(void);		//for calling and displaying game type i.e. 5 letter game and so on
void category(void);	//for calling and displaying game category i.e. country name and so on
void gameFunction(void);		//for calling main functioning of the game
void gameLoading(void);			//game display at the beginning while opening 
void instructions(void);		//for calling and displaying instructions for the game
void credits(void);				//for calling and displaying credits for the game 
void gameReset(void);			//for calling and resetting the game once it is continued again
int gameType, categoryType;      
int line, randomNum;
char dash;
int i;
int wordLength;
int correct=0;
int playLeftCount=0;
int gamePoint;
char letter[10];
char guessedLetter;
char randomWord[300][20];
int continueGame;
int main()
{
	FILE *fileptr;
	fileptr = fopen("hangman words.txt", "r");       //reading words for the game on different lines of the file
	char wordFromFile[20];
	int menuChoice;
	char mainMenu1, mainMenu2;
	if(fileptr==NULL)
	{
		printf("File not found!");
		exit(0);
	}
	line = 0;
	while(fgets(wordFromFile, 20, fileptr))
	{
		sscanf(wordFromFile, "%s", randomWord[line]);      //sscanf scans the string from the variable wordsFromFile and stores it in randomWord
		line++;                   //reads all the lines that contains different words for the game
	}
	fclose(fileptr);
	srand(time(NULL));         //seeding number through time() function for getting random and changing number every time
	gameLoading();			//calling function for game loading display
	label1:
	title();             //calling function for generating title hangman
	printf("\n\n\n\n\n\t\t\t\t\t\t1.PLAY\n");
	printf("\t\t\t\t\t\t2.INSTRUCTIONS\n");
	printf("\t\t\t\t\t\t3.CREDITS\n");
	printf("\t\t\t\t\t\t4.QUIT\n\n\n");
	printf("\t\t\t\t\t    Enter your choice: ");
	scanf("%d", &menuChoice);
	while(menuChoice!=1 && menuChoice!=2 && menuChoice!=3 && menuChoice!=4)			//loop  for rejecting other numbers than 1,2,3 and 4
	{
		system("cls");          //system function for clearing the screen
		title();
		printf("\n\n\n\n\n\t\t\t\t\t\t1.PLAY\n");
		printf("\t\t\t\t\t\t2.INSTRUCTIONS\n");
		printf("\t\t\t\t\t\t3.CREDITS\n");
		printf("\t\t\t\t\t\t4.QUIT\n\n\n");
		printf("\t\t\t\t\t    Enter your choice: ");
		scanf("%d", &menuChoice);
	}
	if(menuChoice==4)
	{
		exit(0);         //progam terminates on quitting the game through number 4
	}
	system("cls");
	switch(menuChoice)
	{
		case 1:
			title();
			game();
			while(gameType!=1 && gameType!=2 && gameType!=3 && gameType!=4)      //loop for rejecting other numbers
			{
				system("cls");
				title();
				game();
			}
			if(gameType==4)
			{
				gameType = (rand() % 3) + 1;		//generates random number lesser than 3 i.e. 0 or 1 or 2 and adds it with 1 for entering any gametype
			}
			system("cls");
			switch(gameType)
			{
				case 1:
					title();
					category();
					while(categoryType!=1 && categoryType!=2 && categoryType!=3 && categoryType!=4 && categoryType!=5)
					{
						system("cls");
						title();
						category();
					}
					if(categoryType==5)
					{
						categoryType = (rand() % 3) + 1;
					}
					system("cls");
					switch(categoryType)
					{
						case 1:
							label2:
							randomNum = rand() % 10;
							line = (10*0) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label2;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
						case 2:
							label3:
							randomNum = rand() % 10;
							line = (10*1) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label3;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
						case 3:
							label4:
							randomNum = rand() % 10;
							line = (10*2) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label4;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
						case 4:
							label5:
							randomNum = rand() % 10;
							line = (10*3) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label5;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;			
					}		//end of swich stattement for category types of game type1
				break;
				case 2:
					title();
					category();
					while(categoryType!=1 && categoryType!=2 && categoryType!=3 && categoryType!=4 && categoryType!=5)
					{
						system("cls");
						title();
						category();
					}
					if(categoryType==5)
					{
						categoryType = (rand() % 3) + 1;
					}
					system("cls");
					switch(categoryType)
					{
						case 1:
							label6:
							randomNum = rand() % 10;
							line = (10*4) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label6;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
						case 2:
							label7:
							randomNum = rand() % 10;
							line = (10*5) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label7;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
						case 3:
							label8:
							randomNum = rand() % 10;
							line = (10*6) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label8;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
						case 4:
							label9:
							randomNum = rand() % 10;
							line = (10*7) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label9;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
					}			//end of switch statement for category types of game type 2
				break;
				case 3:
					title();
					category();
					while(categoryType!=1 && categoryType!=2 && categoryType!=3 && categoryType!=4 && categoryType!=5)
					{
						system("cls");
						title();
						category();
					}
					if(categoryType==5)
					{
						categoryType = (rand() % 3) + 1;
					}
					system("cls");
					switch(categoryType)
					{
						case 1:
							label10:
							randomNum = rand() % 10;
							line = (10*8) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label10;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
						case 2:
							label11:
							randomNum = rand() % 10;
							line = (10*9) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label11;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
						case 3:
							label12:
							randomNum = rand() % 10;
							line = (10*10) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label12;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
						case 4:
							label13:
							randomNum = rand() % 10;
							line = (10*11) + randomNum;
							gameFunction();
							printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
							scanf("%d", &continueGame);
							while(continueGame!=1 && continueGame!=2)
							{
								system("cls");
								printf("\n\nDo you want to continue?\n1.Yes\n2.No\nEnter your choice: ")	;
								scanf("%d", &continueGame);
							}
							system("cls");
							if(continueGame==1)
							{
								gameReset();
								goto label13;
							}
							else
							{
								gameReset();
								goto label1;
							}
							break;
					}		//end of switch statement for category types of game type 3
				break;
			}			//end of switch statements for gametypes in 
		break;
		case 2:       //for instructions
			label14:
			instructions();
			goto label1;
			break;
		case 3:			//for credits
			label15:
			credits();
			goto label1;
			break;
	}			//end of switch statement for credits
	
}
void gameLoading()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t");
	printf("O");
	Sleep(200);
	printf("p");
	Sleep(200);
	printf("e");
	Sleep(200);
	printf("n");
	Sleep(200);
	printf("i");
	Sleep(200);
	printf("n");
	Sleep(200);
	printf("g");
	Sleep(200);
	printf(" ");
	Sleep(200);
	printf("g");
	Sleep(300);
	printf("a");
	Sleep(200);
	printf("m");
	Sleep(300);
	printf("e");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(400);
	printf(".");
	Sleep(500);
	system("cls");
}
void title()
{
	  printf(" 				-------------------------------------------\n");
      printf("				| #  #   #   #   #  #### #   #   #   #   # |\n");
      printf("				| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
      printf("				| #### ##### # # # #  ## # # # ##### # # # |\n");
      printf("				| #  # #   # #  ## #   # #   # #   # #  ## |\n");
      printf("				| #  # #   # #   #  ###  #   # #   # #   # |\n");
      printf("				--------------------------------------------\n\n");	
}
void game()
{
	printf("\n\n\n\t\t\t\t\t    Welcome to Hangman!\n\n\n");
	printf("\t\t\t\t\tGame types:\n");
	printf("\t\t\t\t\t1.Five letters game\n");
	printf("\t\t\t\t\t2.Six letters game\n");
	printf("\t\t\t\t\t3.Seven letters game\n");
	printf("\t\t\t\t\t4.Random game\n\n\n");
	printf("\t\t\t\t\tEnter your choice: ");
	scanf("%d", &gameType);
}
void category()
{
	printf("\n\n\n\n\n\n\t\t\t\t\tCategories:");
	printf("\n\n\t\t\t\t\t1.Country names");
	printf("\n\t\t\t\t\t2.Animal names");
	printf("\n\t\t\t\t\t3.Birds names");
	printf("\n\t\t\t\t\t4.Fruits and vegetables names");
	printf("\n\t\t\t\t\t5.Random category");
	printf("\n\n\n\t\t\t\t\tEnter your choice: ");
	scanf("%d", &categoryType);
}
void gameFunction()				//main game functioning
{
	dash = '_';
	wordLength = strlen(randomWord[line]);
	for(i=0; i<wordLength; i++)
	{
    	letter[i] = dash;              //assigning the character dash for the letters
	}
	do			//use of do while loop
	{
		gamePoint = 0;              //a game point
		printf("\n\nGuess a letter for %d lettered word: ", wordLength);
		guessedLetter = getche();
		Sleep(200);
		printf("\nYou entered: %c\n", guessedLetter);
		for(i=0; i<wordLength; i++)
		{
			if(guessedLetter == randomWord[line][i])
			{
				letter[i] = randomWord[line][i];       //assigning the letters of the random word to the letter that previously stored dash character if guess is correct
				gamePoint=1;			//another game point
				correct++;			//incrementing of the correct letters for the word
			}		
		}
		Sleep(500);        //Sleep function delays the time for executing the next function, here the argument inside Sleep is in milliseconds
		for(i=0; i<wordLength; i++)
		{
			printf("%c ", letter[i]);     //printing the letter that may contain the correct letter after successful guess or dash, stored previously
		}
		printf("\n");
		Sleep(200);
    	if(gamePoint==0)
		{
			playLeftCount++;
			printf("Oops! ");
			Sleep(500);
			printf("You ");
			Sleep(400);
			printf("guessed ");
			Sleep(300);
			printf("wrong");
			Sleep(200);
			printf(".");
			printf("\nYou have %d guesses left.", 6-playLeftCount);		//decrease in number of guesses if guessed wrong
			sleep(1);			//this function is similar to sleep but the argument is in seconds
		}
		else if(gamePoint==1)
		{
			printf("Wow! ");
			Sleep(500);
			printf("Correct ");
			Sleep(300);
			printf("guess");
			Sleep(200);
			printf(".");
			printf("\nYou have %d more letters to guess.", wordLength-correct);		//decrease in the number of plays counts after successful guess
			sleep(1);
		}
		if(correct == wordLength)
		{
			break;	
		}
		printf("\n\n\n");
	}while(playLeftCount < 6);               //end of do while loop
	system("cls");
	if(correct == wordLength)
	{
		printf("\n\t\t\t=====You won!=====");
	}
	else
	{
		printf("\n\t\t\t=====You lost!=====\n");
		printf("The correct word was: %s", randomWord[line]);			//printing the secret word if the game is lost without knowing the word
	}
}
void gameReset()
{
	playLeftCount = 0;
	correct = 0;
	wordLength = 0;
}
void instructions()
{
	printf("\n\n\n\t\t HOW TO PlAY? \n\t\t ============");
	printf("\n\n\n        Welcome to Hangman game!\n");
	printf("    Who else has not played this game in school on childhood?\n");
	printf("    Will you be able to guess maximum number of words?");
	sleep(5);
	system("cls");
	printf("\n\n\n\t\t INSTRUCTIONS \n\t\t ============");
    printf("\n\n   1.Hangman is a word game where you have to guess the word.");
    printf("\n   2.You can try to guess maximum number of words.");
    printf("\n   3.If you guess the correct letter for the given word, the letter is filled in the correct place.");
    printf("\n   4.If you guess the letter wrong, you will lose the number of guesses.");
    printf("\n   5.Be sure to guess the letters in the word right before you are out of guesses.");
    sleep(6);
    system("cls");
}
void credits()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tProject on C");
	sleep(2);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tCreated By Prasanna Acharya");
	sleep(3);
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tSubmitted to Sushant Poudel");
	sleep(2);
	system("cls");
}
