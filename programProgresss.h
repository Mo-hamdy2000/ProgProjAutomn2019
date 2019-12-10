#include <stdio.h>
#include <stdlib.h>
#include <math.h>
///////////////////////////////////////////////////////////////////////////////////////////////
#include <windows.h>

typedef struct {

	int upperSide;

	int lowerSide;

	int rightSide;

	int leftSide;

	int remainingLines;

	int boxColor;

} Box;




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
//////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct
{
    int x;
    int y;
}point;

typedef struct {

	char name[256];

	int score;

	int noOfMoves;

} Player;

int readPointsAndPrintBoard(int sizeOfBoard,Box board[][sizeOfBoard],int player);


void printPoint(point p)
{
    printf("%d",p.x);
    printf("%d",p.y);
    printf("\n");
}

void printPlayer(Player player1)
{
    printf("player name : %s",player1.name);
    printf("score %d\n",player1.score);
    printf("number of moves %d\n\n",player1.noOfMoves);
}

Player player1,player2;

int pointToLines(point a,point p,point box,int sizeOfBoard,Box board[][sizeOfBoard],int player)
{
    int z=0;
    if(a.x==box.y&&a.y==box.x&&p.x==box.y+1&&p.y==box.x)
    {
        if(board[box.x][box.y].upperSide!=1&&board[box.x][box.y].upperSide!=2)
        {
            board[box.x][box.y].upperSide=player;
            if(player==1)
                {
                    player1.noOfMoves++;
                }
                else if(player==2)
                {
                    player2.noOfMoves++;
                }
            board[box.x][box.y].remainingLines--;
            if(board[box.x][box.y].remainingLines==0)
            {
                board[box.x][box.y].boxColor=player;
                z=-1;///keep the same player
                if(player==1)
                {
                    player1.score++;
                }
                else if(player==2)
                {
                    player2.score++;
                }
            }
        }
        else
        {
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("***\nthat line is taken\n***\n");
            readPointsAndPrintBoard(sizeOfBoard,board,player);
        }
    }
    else if(p.x==box.y&&p.y==box.x&&a.x==box.y+1&&a.y==box.x)
    {
        if(board[box.x][box.y].upperSide!=1&&board[box.x][box.y].upperSide!=2)
        {
            board[box.x][box.y].upperSide=player;
            if(player==1)
                {
                    player1.noOfMoves++;
                }
                else if(player==2)
                {
                    player2.noOfMoves++;
                }
            board[box.x][box.y].remainingLines--;
            if(board[box.x][box.y].remainingLines==0)
            {
                board[box.x][box.y].boxColor=player;
                z=-1;///keep the same player
                if(player==1)
                {
                    player1.score++;
                }
                else if(player==2)
                {
                    player2.score++;
                }
            }
        }
        else
        {
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("***\nthat line is taken\n***\n");
            readPointsAndPrintBoard(sizeOfBoard,board,player);
        }
    }
    else if(a.x==box.y&&a.y==box.x&&p.x==box.y&&p.y==box.x+1)
    {
        if(board[box.x][box.y].leftSide!=1&&board[box.x][box.y].leftSide!=2)
        {
            board[box.x][box.y].leftSide=player;
            if(player==1)
                {
                    player1.noOfMoves++;
                }
                else if(player==2)
                {
                    player2.noOfMoves++;
                }
            board[box.x][box.y].remainingLines--;
            if(board[box.x][box.y].remainingLines==0)
            {
                board[box.x][box.y].boxColor=player;
                z=-1;///keep the same player
                if(player==1)
                {
                    player1.score++;
                }
                else if(player==2)
                {
                    player2.score++;
                }
            }
        }
        else
        {
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("***\nthat line is taken\n***\n");
            readPointsAndPrintBoard(sizeOfBoard,board,player);
        }
    }
    else if(p.x==box.y&&p.y==box.x&&a.x==box.y&&a.y==box.x+1)
    {
        if(board[box.x][box.y].leftSide!=1&&board[box.x][box.y].leftSide!=2)
        {
            board[box.x][box.y].leftSide=player;
            if(player==1)
                {
                    player1.noOfMoves++;
                }
                else if(player==2)
                {
                    player2.noOfMoves++;
                }
            board[box.x][box.y].remainingLines--;
            if(board[box.x][box.y].remainingLines==0)
            {
                board[box.x][box.y].boxColor=player;
                z=-1;///keep the same player
                if(player==1)
                {
                    player1.score++;
                }
                else if(player==2)
                {
                    player2.score++;
                }
            }
        }
        else
        {
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("***\nthat line is taken\n***\n");
            readPointsAndPrintBoard(sizeOfBoard,board,player);
        }
    }
    else if(a.x==box.y+1&&a.y==box.x+1&&p.x==box.y+1&&p.y==box.x)
    {
        if(board[box.x][box.y].rightSide!=1&&board[box.x][box.y].rightSide!=2)
        {
            board[box.x][box.y].rightSide=player;
            if(player==1)
                {
                    player1.noOfMoves++;
                    printf("%d",player1.noOfMoves);
                }
                else if(player==2)
                {
                    player2.noOfMoves++;
                }
            board[box.x][box.y].remainingLines--;
            if(board[box.x][box.y].remainingLines==0)
            {
                board[box.x][box.y].boxColor=player;
                z=-1;///keep the same player
                if(player==1)
                {
                    player1.score++;
                }
                else if(player==2)
                {
                    player2.score++;
                }
            }
        }
        else
        {
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("***\nthat line is taken\n***\n");
            readPointsAndPrintBoard(sizeOfBoard,board,player);
        }
    }
    else if(p.x==box.y+1&&p.y==box.x+1&&a.x==box.y+1&&a.y==box.x)
    {
        if(board[box.x][box.y].rightSide!=1&&board[box.x][box.y].rightSide!=2)
        {
            board[box.x][box.y].rightSide=player;
            if(player==1)
                {
                    player1.noOfMoves++;
                }
                else if(player==2)
                {
                    player2.noOfMoves++;
                }
            board[box.x][box.y].remainingLines--;
            if(board[box.x][box.y].remainingLines==0)
            {
                board[box.x][box.y].boxColor=player;
                z=-1;///keep the same player
                if(player==1)
                {
                    player1.score++;
                }
                else if(player==2)
                {
                    player2.score++;
                }
            }
        }
        else
        {
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("***\nthat line is taken\n***\n");
            readPointsAndPrintBoard(sizeOfBoard,board,player);
        }
    }
    else if(a.x==box.y+1&&a.y==box.x+1&&p.x==box.y&&p.y==box.x+1)
    {
        if(board[box.x][box.y].lowerSide!=1&&board[box.x][box.y].lowerSide!=2)
        {
            board[box.x][box.y].lowerSide=player;
            if(player==1)
                {
                    player1.noOfMoves++;
                }
                else if(player==2)
                {
                    player2.noOfMoves++;
                }
            board[box.x][box.y].remainingLines--;
            if(board[box.x][box.y].remainingLines==0)
            {
                board[box.x][box.y].boxColor=player;
                z=-1;///keep the same player
                if(player==1)
                {
                    player1.score++;
                }
                else if(player==2)
                {
                    player2.score++;
                }
            }
        }
        else
        {
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("***\nthat line is taken\n***\n");
            readPointsAndPrintBoard(sizeOfBoard,board,player);
        }
    }
    else if(p.x==box.y+1&&p.y==box.x+1&&a.x==box.y&&a.y==box.x+1)
    {
        if(board[box.x][box.y].lowerSide!=1&&board[box.x][box.y].lowerSide!=2)
        {
            board[box.x][box.y].lowerSide=player;
            if(player==1)
                {
                    player1.noOfMoves++;
                }
                else if(player==2)
                {
                    player2.noOfMoves++;
                }
            board[box.x][box.y].remainingLines--;
            if(board[box.x][box.y].remainingLines==0)
            {
                board[box.x][box.y].boxColor=player;
                z=-1;///keep the same player
                if(player==1)
                {
                    player1.score++;
                }
                else if(player==2)
                {
                    player2.score++;
                }
            }
        }
        else
        {

            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("***\nthat line is taken\n***\n");
            readPointsAndPrintBoard(sizeOfBoard,board,player);
        }
    }
    return z;
}

point readpoint()
{
    point p;
    if (scanf("%d %d",&p.x,&p.y) != 2)
    {
        scanf("%c");
    }
    return p;
}

///this function check the Validity Of Points
///it returns 0 if the points are not valid
///it return -1 if the points are the same point
///it return -2 if one of the points is out of range
int checkValidityOfPoints(point a,point p,int sizeOfBoard)
{
    if(a.x<0||a.x>sizeOfBoard||a.y<0||a.y>sizeOfBoard||p.x<0||p.x>sizeOfBoard||p.y<0||p.y>sizeOfBoard)
    {
        return -2;
    }
    else if(a.x==p.x&&a.y==p.y)
    {
        return -1;
    }
    else if(a.x==p.x)
    {
        if(abs(a.y-p.y)==1)
        {
            return 1;
        }
        else
            return 0;
    }
    else if(a.y==p.y)
    {
        if(abs(a.x-p.x)==1)
        {
            return 1;
        }
        else
            return 0;
    }
    else if(a.x!=p.x&&a.y!=p.y)
    {
        return 0;
    }
}
///this function print the index of the boxes contain of the line
///as that line consists of that two points
int boxOffThatPoints(point a,point p,int sizeOfBoard,Box board[][sizeOfBoard],int player)
{
    int z=0;
    system("cls");
    printPlayer(player1);
    printPlayer(player2);
    ///correct the wrong points by taking other from the user
    while(checkValidityOfPoints(a,p,sizeOfBoard)!=1)
    {
        if(checkValidityOfPoints(a,p,sizeOfBoard)==0)
        {
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("\a***\nnot valid points\n***\n");
            printf("please enter the points again\n");
            printf("enter the first point\n");
            a=readpoint();
            printf("enter the second point\n");
            p=readpoint();
        }
        else if(checkValidityOfPoints(a,p,sizeOfBoard)==-1)
        {
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("\a***\nit is the same point\n***\n");
            printf("please enter the points again\n");
            printf("enter the first point\n");
            a=readpoint();
            printf("enter the second point\n");
            p=readpoint();
        }
        else if(checkValidityOfPoints(a,p,sizeOfBoard)==-2)
        {
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
            printf("\a***\none of the points is out of range\n***\n");
            //printBoard(sizeOfBoard,board);
            printf("->please enter the points again\n");
            printf("enter the first point\n");
            a=readpoint();
            printf("enter the second point\n");
            p=readpoint();
            system("cls");
            printPlayer(player1);
            printPlayer(player2);
            printBoard(sizeOfBoard,board);
        }
    }
    ///find the boxes indexes :
    ///it deal with box1Index and box2Index as points
    ///x of the index is the row of the array of boxes where the box exist
    ///y of the index is the column of the array of boxes where the box exist
    point box1Index,box2Index;
    ///initialize the box index equal to -1
    ///to know if it has changed or no
    ///to be easier to print
    box1Index.x=-1;
    box2Index.x=-1;
    box1Index.y=-1;
    box2Index.y=-1;
    ///when x is constant then the box are around it
    ///the row of the two boxes is constant equal to min y
    ///the column is not constant as it take values: x , x-1
    if(a.x==p.x)
    {
        if(a.y<p.y)
        {
            box1Index.x=a.y;
            box2Index.x=a.y;
        }
        else if(p.y<a.y)
        {
            box1Index.x=p.y;
            box2Index.x=p.y;
        }
        if(a.x==sizeOfBoard)
        {
            box1Index.y=a.x-1;
        }
        else if(a.x!=0)
        {
            box1Index.y=a.x-1;
            box2Index.y=a.x;
        }
        else
        {
            box1Index.y=a.x;
        }
    }
    ///when y is constant then the box are around it
    ///the column of the two boxes is constant equal to min x
    ///the row is not constant as it take values: y , y-1
    else if(a.y==p.y)
    {
        if(a.x<p.x)
        {
            box1Index.y=a.x;
            box2Index.y=a.x;
        }
        else if(p.x<a.x)
        {
            box1Index.y=p.x;
            box2Index.y=p.x;
        }
        if(a.y==sizeOfBoard)
        {
            box1Index.x=a.y-1;
        }
        else if(a.y!=0)
        {
            box1Index.x=a.y-1;
            box2Index.x=a.y;
        }
        else
        {
            box1Index.x=a.y;
        }
    }
    ///print first box if it exist
    if(box1Index.x!=-1&&box1Index.y!=-1)
    {
        //printPoint(box1Index);
        if(pointToLines(a,p,box1Index,sizeOfBoard,board,player)==-1)
        {
            z=-1;
        }
    }
    ///print second box if it exist
    if(box2Index.x!=-1&&box2Index.y!=-1)
    {
        //printPoint(box2Index);
        if(player==1)
        {
            player1.noOfMoves--;
        }
        else if(player==2)
        {
            player2.noOfMoves--;
        }
        if(pointToLines(a,p,box2Index,sizeOfBoard,board,player)==-1)
        {
            z=-1;
        }
    }
    return z;
}

int readPointsAndPrintBoard(int sizeOfBoard,Box board[][sizeOfBoard],int player)
{
    point a,p;
    printf("enter the first point\n");
    a=readpoint();
    printf("enter the second point\n");
    p=readpoint();
    int remainPlayer=0;
    remainPlayer=boxOffThatPoints(a,p,sizeOfBoard,board,player);
    system("cls");
    printPlayer(player1);
    printPlayer(player2);
    printBoard(sizeOfBoard,board);
    return remainPlayer;
}

void initializeBoard(int sizeOfBoard,Box board[sizeOfBoard][sizeOfBoard])
    {
        int i,j;
        for(i=0;i<sizeOfBoard;i++)
        {
            for(j=0;j<sizeOfBoard;j++)
            {
                board[i][j].boxColor=0;
                board[i][j].leftSide=0;
                board[i][j].lowerSide=0;
                board[i][j].remainingLines=4;
                board[i][j].rightSide=0;
                board[i][j].rightSide=0;
                board[i][j].upperSide=0;
            }
        }
    }

Player   initializePlayer(Player player0)
{
    Player player1;
    player1=player0;
    player1.noOfMoves=0;
    player1.score=0;
    return player1;
}

int main()
{
    int sizeOfBoard=4;///number of boxes in each rows or columns
    Box board[sizeOfBoard][sizeOfBoard];
    initializeBoard(sizeOfBoard,board);
    player1=initializePlayer(player1);
    player2=initializePlayer(player2);
    printf("1'st player Name :\n");
    fgets(player1.name,256,stdin);
    printf("2'nd player Name :\n");
    fgets(player2.name,256,stdin);
    system("cls");
    printPlayer(player1);
    printPlayer(player2);
    printBoard(sizeOfBoard,board);
    int i,player=1;
    while(1){
    i=readPointsAndPrintBoard(sizeOfBoard,board,player);
    if(i==-1)
    {
        printf("the player %d have earned rum :)\n",player);
    }
    else if(i!=-1)
    {
        if(player==1)
        {
            player=2;
        }
        else if(player==2)
        {
            player=1;
        }
    }
    }
    return 0;
}
