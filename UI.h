#include <windows.h>
#define LESS_INTENSITY 0x0080 // background color is intensified.

void printGameMenu(int undoFlag, int redoFlag, int undoCounter, int noOfMovesPlayed)
{
	printf("\t\t\t\t\t\tEnter: s:Save\te:Exit");
	if(undoFlag == 1 && undoCounter > -1)
	{
		printf("\tu:Undo");
	}
	if(redoFlag == 1 && undoCounter < noOfMovesPlayed)
	{
		printf("\tr:Redo");
	}
	printf("\n\n");
}


void printIntro()
{
	for(int i = 0; i < 3; i++)
	{
		printf("88888888888                                                                 8888888888                                 \n");
		printf("    888                                                                     888                                        \n");
		printf("    888                                                                     888                                        \n");
		printf("    888   .d88b.  888d888 88888b.   8888b.  888d888 888  888                8888888    888d888 888d888 .d88b.  888d888 \n");
		printf("    888  d8P  Y8b 888P^   888 ^88b     ^88b 888P^   888  888                888        888P^   888P^  d88^^88b 888P^   \n");
		printf("    888  88888888 888     888  888 .d888888 888     888  888                888        888     888    888  888 888     \n");
		printf("    888  Y8b.     888     888  888 888  888 888     Y88b 888                888        888     888    Y88..88P 888     \n");
		printf("    888   ^Y8888  888     888  888 ^Y888888 888      ^Y88888                8888888888 888     888     ^Y88P^  888     \n");
		printf("                                                         888                                                           \n");
		printf("                                                    Y8b d88P                                                           \n");
		printf("                                                     ^Y88P^                                                            \n");
		Sleep(800);
		system("cls");
		Sleep(200);
	}
}


void printBanner()
{
	printf("\n\n\n");
	printf("\t\t\t\t88888888ba,                                          ,adba,        88888888ba                                                  \n");
	printf("\t\t\t\t88      `'8b                 ,d                      8I  I8        88      '8b                                                 \n");
	printf("\t\t\t\t88        `8b                88                      '8bdP'        88      ,8P                                                 \n");
	printf("\t\t\t\t88         88   ,adPPYba,  MM88MMM  ,adPPYba,       ,d8^8b  88     88aaaaaa8P'   ,adPPYba,  8b,     ,d8  ,adPPYba,  ,adPPYba,  \n");
	printf("\t\t\t\t88         88  a8^     ^8a   88     I8[    ^^     .dP'   Yb,8I     88^^^^^^8b,  a8^     ^8a  `Y8, ,8P'  a8P_____88  I8[    ^^  \n");
	printf("\t\t\t\t88         8P  8b       d8   88      `^Y8ba,      8P      888'     88      `8b  8b       d8    )888(    8PP^^^^^^^   `^Y8ba,   \n");
	printf("\t\t\t\t88      .a8P   ^8a,   ,a8^   88,    aa    ]8I     8b,   ,dP8b      88      a8P  ^8a,   ,a8^  ,d8^ ^8b,  ^8b,   ,aa  aa    ]8I  \n");
	printf("\t\t\t\t88888888Y^'     `^YbbdP^'    ^Y888  `^YbbdP^'     `Y8888P^  Yb     88888888P^    `^YbbdP^'  8P'     `Y8  `^Ybbd8^'  `^YbbdP^'  \n\n\n\n");
}

void printPlayerSelection(int playerTurn)
{
	if(playerTurn == 1)
	{
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t  1111111   \n");
		printf("\t\t\t\t 1::::::1   \n");
		printf("\t\t\t\t1:::::::1   \n");
		printf("\t\t\t\t111:::::1   \n");
		printf("\t\t\t\t   1::::1   \n");
		printf("\t\t\t\t   1::::1   \n");
		printf("\t\t\t\t   1::::1   \n");
		printf("\t\t\t\t   1::::1   \n");
		printf("\t\t\t\t   1::::1   \n");
		printf("\t\t\t\t   1::::1   \n");
		printf("\t\t\t\t   1::::1   \n");
		printf("\t\t\t\t   1::::1   \n");
		printf("\t\t\t\t111::::::111\n");
		printf("\t\t\t\t1::::::::::1\n");
		printf("\t\t\t\t1::::::::::1\n");
		printf("\t\t\t\t111111111111\n");
	}
	else
	{
		printf("\n\n\n\n\n\n\n");
		printf("\t\t\t\t 222222222222222    \n");
		printf("\t\t\t\t2:::::::::::::::22  \n");
		printf("\t\t\t\t2::::::222222:::::2 \n");
		printf("\t\t\t\t2222222     2:::::2 \n");
		printf("\t\t\t\t            2:::::2 \n");
		printf("\t\t\t\t            2:::::2 \n");
		printf("\t\t\t\t         2222::::2  \n");
		printf("\t\t\t\t    22222::::::22   \n");
		printf("\t\t\t\t  22::::::::222     \n");
		printf("\t\t\t\t 2:::::22222        \n");
		printf("\t\t\t\t2:::::2             \n");
		printf("\t\t\t\t2:::::2             \n");
		printf("\t\t\t\t2:::::2       222222\n");
		printf("\t\t\t\t2::::::2222222:::::2\n");
		printf("\t\t\t\t2::::::::::::::::::2\n");
		printf("\t\t\t\t22222222222222222222\n");
	}
}

void playerSelection(int playerTurn)
{
	for(int i = 0; i < 10+playerTurn; i++)
	{
		system("cls");
		printPlayerSelection(i%2+1);
		Sleep(100);
	}
	Sleep(500);
}

// This function takes a row of boxes and its size (no. of boxes in it) and print the upper line  of each box respectively.
// The row is an array of boxes.
// The line color depend on Box.upperSide value where 0 indicates no line & 1 indicates blue line (1st player) & 2 indicates red line (2nd player).
void printUpperSides(int size ,Box boxes[]){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	for(int i = 0; i < size; i++)
	{
		printf("%c%c", 219, 219);
		if(boxes[i].upperSide == 1)
		{
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
		}
		else if(boxes[i].upperSide == 2)
		{
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
		}
		printf("            ");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
		if(i == size-1)
		{
			printf("%c%c", 219, 219);
		}
	}
}

// This function takes a row of boxes and its size (no. of boxes in it) and print the body of each box respectively where it first print the left side,
// then prints the body of the box - black if the box isn't closed & light blue if it was closed by the first player & light red if it was closed by the second player -,
// then it prints the right side.
// The row is an array of boxes.
// The left side color depend on Box.leftSide value and box body color depends on Box.boxColor value and the right side color depend on Box.rightSide value.
void printBoxBody(int size ,Box boxes[]){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi );
	for(int i = 0; i < size; i++)
	{
		switch(boxes[i].leftSide){
			case 1:
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
				break;
			case 2:
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
				break;
		}
		printf("  ");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
		switch(boxes[i].boxColor){
			case 1:
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), LESS_INTENSITY | BACKGROUND_BLUE);
				break;
			case 2:
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), LESS_INTENSITY | BACKGROUND_RED);
				break;
		}
		printf("            ");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
		switch(boxes[i].rightSide){
			case 1:
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
				break;
			case 2:
				SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
				break;
		}
		if(i == size-1)
		{
			printf("  ");
		}
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
	}
}

// This function takes a row of boxes and its size (no. of boxes in it) and print the lower line  of each box respectively.
// The row is an array of boxes.
// The line color depend on Box.lowerSide value where 0 indicates no line & 1 indicates blue line (1st player) & 2 indicates red line (2nd player).
void printLowerSides(int size ,Box boxes[]){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi );
	for(int i = 0; i < size; i++)
	{
		printf("%c%c", 219, 219);
		if(boxes[i].lowerSide == 1)
		{
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
		}
		else if(boxes[i].lowerSide == 2)
		{
			SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
		}
		printf("            ");
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
		if(i ==  size-1){
			printf("%c%c", 219, 219);
		}
	}
}

void printTime(int time)
{
	int hours = time / 3600;
	time = time % 3600;
	int minutes = time / 60;
	int seconds = time % 60;
	printf("Game time: %d:%d:%d\n", hours, minutes, seconds);
}

// This function takes a 2D array of boxes and its size the it prints each row in the array using the functions above respectively.
// Also It takes players array and prints their info.
void printBoard(int size, Box board[size][size], Player players[], int playerTurn, int totalRemainingLines, int elapsedTime){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	printBanner();
	printf("\t\t\t\t\t     x  ");
	for(int i = 0; i < size; i++)
	{
		printf("%d             ", i);
	}
	printf("%d    y\n\n", size);
	for(int i = 0; i < size; i++)
	{
		printf("\t\t\t\t\t\t");
		printUpperSides(size, board[i]);
		printf("\t%d\n", i);
		for (int k = 0; k < 4; k++)
		{
			printf("\t\t\t\t\t\t");
			printBoxBody(size ,board[i]);
			printf("\n");
		}
		if(i == size-1)
		{
			printf("\t\t\t\t\t\t");
			printLowerSides(size, board[i]);
			printf("\t%d\n", size);
		}
	}
	printf("\n\n\t\t\t\t\t\t");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
	printf("                  ");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_RED);
	printf("                  ");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
	printf("\n\n\t\t\t\t\t\tName: %s \t\tName: %s \n", players[0].name, players[1].name);
	printf("\t\t\t\t\t\tScore: %d \t\tScore: %d \n", players[0].score, players[1].score);
	printf("\t\t\t\t\t\t# of moves: %d \t\t# of moves: %d \n\n", players[0].noOfMoves, players[1].noOfMoves);
	printf("\t\t\t\t\t\t\tPlayer Turn: %s\n", players[playerTurn-1].name);
	printf("\t\t\t\t\t\t\tTotal Remaining Lines: %d\n\t\t\t\t\t\t\t", totalRemainingLines);
	printTime(elapsedTime);
}

// Prints the main menu for the user and return his choice
int printMainMenu()
{
	int choice;
	char skipper;
	printf("\t\t\t\t\t\t1. Start Game\n");
	printf("\t\t\t\t\t\t2. Load Game\n");
	printf("\t\t\t\t\t\t3. Top 10 players\n");
	printf("\t\t\t\t\t\t4. How to play\n");
	printf("\t\t\t\t\t\t5. Credits\n");
	printf("\t\t\t\t\t\t6. Exit\n\t\t\t\t\t\t");
	while((scanf("%d", &choice) != 1) || choice > 6 || choice < 1)
	{
		scanf("%c", &skipper);
	}
	return choice;
}

//Prints Sub-menu and return player game level (boardSize).
int printGameSubMenu1()
{
	int choice = 0;
	char skipper;
	printf("\t\t\t\t\t\t1. Beginner\n");
	printf("\t\t\t\t\t\t2. Expert\n\t\t\t\t\t\t");
	while((scanf("%d", &choice) != 1) || choice > 2 || choice < 1)
	{
		scanf("%c", &skipper);
	}
	if(choice == 1)
	{
		return 2;
	}
	else
	{
		return 5;
	}
}
//Prints Sub-menu and return game mode player vs player or player vs computer.
int printGameSubMenu2()
{
	int choice = 0;
	char skipper;
	printf("\t\t\t\t\t\t1. 1 player\n");
	printf("\t\t\t\t\t\t2. 2 players\n\t\t\t\t\t\t");
	while((scanf("%d", &choice) != 1) || choice > 2 || choice < 1)
	{
		scanf("%c", &skipper);
	}
	return choice;
}

//Prints Sub-menu and return load file name.
void printLoadSubMenu(char fileName[])
{
	printf("\t\t\t\t\t\tChoose Load file: 1.File1\t2.File2\t\t3.File3\n\t\t\t\t\t\t");
	int fileNo = 0;
	char skipper;
	while(scanf("%d", &fileNo) != 1 || fileNo > 3 || fileNo < 1)
	{
		if(fileNo <= 3 && fileNo >= 1)
		{
			scanf("%c",&skipper);
		}
	}
	switch(fileNo)
	{
		case 1:
			strcpy(fileName, "File1.txt");
			break;
		case 2:
			strcpy(fileName, "File2.txt");
			break;
		case 3:
			strcpy(fileName, "File3.txt");
			break;
	}
}

void printHowToPlay()
{
	printf("\t\t\t\t\t\tHow the game works:\n");
	printf("\t\t\t\t\t\tWhen the grid is loaded the program asks the user to enter the first point and the second point that represent the line that the user want to play \n");
	printf("\t\t\t\t\t\tHow to enter the points:\n");
	printf("\t\t\t\t\t\tThe x coordinate of the point starts from 0 and every single point toward right increase the x coordinate by 1.\n");
	printf("\t\t\t\t\t\tThe y coordinate of the point starts from 0 and every single point downwards increase the y coordinate by 1.\n");
	printf("\t\t\t\t\t\tGame rules:\n");
	printf("\t\t\t\t\t\tObject of the board game: Take more boxes than your opponent. You move by connecting two dots with a line.\n");
	printf("\t\t\t\t\t\tWhen you place the last wall of a single square (box), the box is yours.\n");
	printf("\t\t\t\t\t\tThe players move in turn, but whenever a player takes a box (s)he must move again. The player with the most boxes wins. \n");
	printf("\t\t\t\t\t\tConnecting dots: You connect two dots by entering the coordinate of the 2 points representing line as mentioned above.\n");
	printf("\t\t\t\t\t\tTaking boxes: When all four of the lines around a single box are in place, the player who made the last move owns the box.\n");
	printf("\t\t\t\t\t\tThe box is marked in that player color and (s)he must move again.\n");
	printf("\t\t\t\t\t\tEnd of the board game: The game is finished when all connections have been made and all boxes have been taken. The player who owns most boxes wins.\t\t\t\t\t\t\n");
}

void printCredits()
{
	printf("\t\t\t\t\t\tCredits\n");
	printf("\t\t\t\t\t\tThis program is designed by:\n");
	printf("\t\t\t\t\t\tTernary Error Team\n");
	printf("\t\t\t\t\t\tShehab Mohamed Saad\n\t\t\t\t\t\tMomen Ibrahim Fawzy \n\t\t\t\t\t\tMo\'men Mohamed Hamdy\n");
	printf("\t\t\t\t\t\tThis is CSED 2023.\n\t\t\t\t\t\t");
}
