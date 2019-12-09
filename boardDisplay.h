#include <windows.h>
#include <entities.h>

#define LESS_INTENSITY 0x0080 // background color is intensified.


// This function takes a row of boxes and its size (no. of boxes in it) and print the upper line  of each box respectively.
// The row is an array of boxes.
// The line color depend on Box.upperSide value where 0 indicates no line & 1 indicates blue line (1st player) & 2 indicates red line (2nd player).
void printUpperSides(int size ,Box boxes[]){
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi );
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
		if(i == size-1){
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

// This function takes a 2D array of boxes and its size the it prints each row in the array using the functions above respectively.
void printBoard(int size, Box board[size][size]){
	printf("\t\t\t\t\t\ta             b             c\n");
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
			printf("\n");
		}
	}
}
