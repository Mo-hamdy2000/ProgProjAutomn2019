//#include "entities.h"
#include <strings.h>
#define LEADERBOARD_SIZE 10

void updateLeaderBoard(int line, Player player);

// Function for loading and printing players in the "leaderBoard" file.
void loadLeaderboard()
{
    FILE *boardFile = fopen("leaderBoard.txt", "r");
	int score;
	char name[20];
	Player players[LEADERBOARD_SIZE];
	if(boardFile==NULL)
    {
        printf("Unable to find file.\n");
    }
	// First it will read all players names and their scores.
	for(int i = 0; i < LEADERBOARD_SIZE; i++)
	{
		fscanf(boardFile, "%s %d\n", name, &score);
		strcpy(players[i].name, name);
		players[i].score = score;
	}
	fclose(boardFile);
	// Then it sorts them according to their scores. (Bubble Sort)
	Player temp;
	// loop n times - 1 per element
	for (int i = 0; i < LEADERBOARD_SIZE; i++) 
	{
        // last i elements are sorted already
		for (int j = 0; j < LEADERBOARD_SIZE - i - 1; j++)
		{
            // swap if order is broken
			if (players[j].score > players[j + 1].score) 
			{ 
                temp = players[j];
                players[j] = players[j + 1];
                players[j + 1] = temp;
            }
        }
    }
	//Finally it prints players name with their scores ordered descendingly.
	for (int i = LEADERBOARD_SIZE - 1; i >= 0 ; i--)
	{
		printf("\t\t\t\t\t\t%d. %s\t\t%d\n", LEADERBOARD_SIZE - i, players[i].name, players[i].score);
	}
}

// The main function manipulating player-leaderBoard oprerations.
void checkLeaderBoard(Player player)
{
	int score;
	char name[20];
	int lineOfLeastScore;
	int leastScore = player.score;
	int updatePlayerFlag = 1;
	FILE *boardFile;
    boardFile = fopen("leaderBoard.txt","r");
    if(boardFile==NULL)
    {
        printf("Unable to find file.\n");
    }
	/* It reads from the file searching for two cases.
	 * first if the player name is already recorded, then it will compare the previous score to the current one, and it updates the score if the current score is higher.
	 * second it checks if the least score in the leaderboard is less than the current score then it updates the leaderboard.
	 * */
    for (int i=0 ; i < LEADERBOARD_SIZE ; i++)
	{
		fscanf(boardFile,"%s %d\n", name, &score);
		if(strcasecmp(name, player.name) == 0 )
		{
			if(score < player.score)
			{
				//Update Player's score (line number = i)
				lineOfLeastScore = i;
				break;
			}
			else
			{
				updatePlayerFlag = 0;
				break;
			}
		}
		if(leastScore > score)
		{
			leastScore = score;
			lineOfLeastScore = i;
		}
	}
    fclose(boardFile);
	if(updatePlayerFlag == 1 && leastScore != player.score)
	{
		//update line of least score
		updateLeaderBoard(lineOfLeastScore, player);
	}
}

// The Function takes a certain line number and overwrite it with the current player name and score.
void updateLeaderBoard(int line, Player player)
{
	FILE *boardFile;
	FILE *temp;
	char name[20];
	int score;
    int count;
    // Open leaderBoard file and a temporary file.
    boardFile  = fopen("leaderBoard.txt", "r");
    temp = fopen("temp.txt", "w"); 

    if (boardFile == NULL || temp == NULL)
    {
        // Unable to open file hence exit
        printf("\nUnable to open file.\n");
    }

    // Read line from leaderBoard file and write to the temp file after replacing the given line.
    count = 0;
    while (fscanf(boardFile,"%s %d\n", name, &score) != 0 && count != LEADERBOARD_SIZE)
    {
        // If current line is line to replace.
        if (count == line)
		{	fprintf(temp, "%s %d\n", player.name, player.score); }
        else
		{	fprintf(temp, "%s %d\n", name, score); }
		count++;
    }
    fclose(boardFile);
    fclose(temp);
    // Delete original source file.
    remove("leaderBoard.txt");
    // Rename temporary file as original file.
    rename("temp.txt", "leaderBoard.txt");
}

void initializeLeaderBoardFile()
{
	FILE *boardFile;
	boardFile  = fopen("leaderBoard.txt", "w");
	for(int i = 0; i < 10; i ++)
	{
		fprintf(boardFile, "%s %d\n", "-----------", 0);
	}
	fclose(boardFile);
}
