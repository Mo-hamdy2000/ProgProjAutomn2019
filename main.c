#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
///////////////////////////////////////////////////////////////////////////////////////////////
#include "entities.h"
#include "UI.h"
#include "saveLoad.h"
#include "computerTurn.h"
#include "ranking.h"
#include "gameFlow.h"

int main(void)
{
	printIntro();
	while(1)
	{
		system("cls");
		printBanner();
		int choice  = printMainMenu();
		if(choice == 1)
		{
			system("cls");
			printBanner();
			int sizeOfBoard = printGameSubMenu1();
			Box board[sizeOfBoard][sizeOfBoard];
			initializeBoard(sizeOfBoard,board);
			Player players[2];
			players[0]=initializePlayer(players[0]);
			players[1]=initializePlayer(players[1]);
			int playerTurn = 1;
			int totalRemainingLines = sizeOfBoard*(sizeOfBoard+1)*2;
			system("cls");
			printBanner();
			choice = printGameSubMenu2();
			if(choice == 1)
			{
				printf("\t\t\t\t\t\tEnter Player name: \n\t\t\t\t\t\t");
				scanf("%s", players[0].name);
				strcpy(players[1].name, "Computer");
				start1PlayerGame(sizeOfBoard, board, players, playerTurn, totalRemainingLines, 0);
			}
			else if(choice == 2)
			{
				printf("\t\t\t\t\t\tEnter Player 1 name: \n\t\t\t\t\t\t");
				scanf("%s", players[0].name);
				printf("\t\t\t\t\t\tEnter Player 2 name: \n\t\t\t\t\t\t");
				scanf("%s", players[1].name);
				playerTurn = getRand(1, 2);
				playerSelection(playerTurn);
				start2PlayersGame(sizeOfBoard, board, players, playerTurn, totalRemainingLines, 0);
			}
		}
		else if(choice == 2)
		{
			char fileName[15];
			system("cls");
			printBanner();
			printLoadSubMenu(fileName);
			int gameMode;
			int sizeOfBoard;
			if(loadGameMode(&gameMode, fileName) != 0)
			{
				printf("No Data at this file.");
				getchar();
				continue;
			}
			loadSize(&sizeOfBoard, fileName);
			Box board[sizeOfBoard][sizeOfBoard];
			Player players[2];
			int playerTurn;
			int totalRemainingLines;
			int gameTime;
			load(sizeOfBoard, board, players, &playerTurn, &totalRemainingLines, fileName, &gameTime);
			if(gameMode == 1)
			{
				start1PlayerGame(sizeOfBoard, board, players, playerTurn, totalRemainingLines, gameTime);
			}
			else
			{
				start2PlayersGame(sizeOfBoard, board, players, playerTurn, totalRemainingLines, gameTime);
			}
		}
		else if(choice == 3)
		{
			system("cls");
			printBanner();
			loadLeaderboard();
			getchar();
			getchar();
		}
		else if(choice == 4)
		{
			break;
		}
	}
    return 0;
}