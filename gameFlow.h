
int minimum(int num1, int num2)
{
	if(num1 > num2)
	{
		return num2;
	}
	else
	{
		return num1;
	}
}

void reverseTurns(int *playerTurn)
{
	if(*playerTurn == 1)
	{
		*playerTurn = 2;
	}
	else
	{
		*playerTurn = 1;
	}
}

int pointToLines(point a,point p,int sizeOfBoard, Player players[], Box board[][sizeOfBoard],int *playerTurn, int *totalRemainingLines)
{
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
		box1Index.x = box2Index.x = min(p.y,a.y);
        if(a.x==sizeOfBoard)
        {
            box1Index.y=a.x-1;
        }
		if(a.x == sizeOfBoard)
		{
			box1Index.y=a.x-1;
		}
        else if(a.x == 0)
        {
            box1Index.y=a.x;
        }
        else
        {
			box1Index.y=a.x-1;
            box2Index.y=a.x;
        }
    }
    ///when y is constant then the box are around it
    ///the column of the two boxes is constant equal to min x
    ///the row is not constant as it take values: y , y-1
    else if(a.y==p.y)
    {
		box1Index.y = box2Index.y = min(a.x, p.x);
        if(a.y==sizeOfBoard)
        {
            box1Index.x=a.y-1;
        }
        else if(a.y == 0)
        {
            box1Index.x=a.y;
        }
        else
        {
			box1Index.x=a.y-1;
            box2Index.x=a.y;
        }
    }
	int anotherTurn = 0;
    if(a.y==box1Index.x && p.y==box1Index.x && ((a.x==box1Index.y && p.x==box1Index.y+1) || (p.x==box1Index.y && a.x==box1Index.y+1)))
    {
        if(board[box1Index.x][box1Index.y].upperSide==0)
        {
            board[box1Index.x][box1Index.y].upperSide=*playerTurn;
			board[box1Index.x][box1Index.y].remainingLines--;
			*totalRemainingLines = *totalRemainingLines - 1;
            players[*playerTurn-1].noOfMoves++;
			reverseTurns(playerTurn);
            if(board[box1Index.x][box1Index.y].remainingLines==0)
            {
				reverseTurns(playerTurn);
                board[box1Index.x][box1Index.y].boxColor=*playerTurn;
                players[*playerTurn-1].score++;
            }
        }
        else
        {
            return -3;
        }
    }
    else if(a.x==box1Index.y && p.x==box1Index.y && ((a.y==box1Index.x && p.y==box1Index.x+1) || (p.y==box1Index.x && a.y==box1Index.x+1)))
    {
        if(board[box1Index.x][box1Index.y].leftSide == 0)
        {
            board[box1Index.x][box1Index.y].leftSide = *playerTurn;
			board[box1Index.x][box1Index.y].remainingLines--;
			*totalRemainingLines = *totalRemainingLines - 1;
            players[*playerTurn-1].noOfMoves++;
			reverseTurns(playerTurn);
            if(board[box1Index.x][box1Index.y].remainingLines==0)
            {
				reverseTurns(playerTurn);
                board[box1Index.x][box1Index.y].boxColor= *playerTurn;
                players[*playerTurn-1].score++;
            }
        }
        else
        {
            return -3;
        }
    }
    else if(a.x==box1Index.y+1 && p.x==box1Index.y+1 && ((a.y==box1Index.x+1 && p.y==box1Index.x) || (p.y==box1Index.x+1 && a.y==box1Index.x)))
    {
		anotherTurn = 0;
        if(board[box1Index.x][box1Index.y].rightSide == 0)
        {
            board[box1Index.x][box1Index.y].rightSide=*playerTurn;
            board[box1Index.x][box1Index.y].remainingLines--;
			*totalRemainingLines = *totalRemainingLines - 1;
			if(box2Index.x  > -1 && box2Index.y  > -1)
			{
				board[box2Index.x][box2Index.y].leftSide=*playerTurn;
				board[box2Index.x][box2Index.y].remainingLines--;
				if(board[box2Index.x][box2Index.y].remainingLines==0)
				{
					board[box2Index.x][box2Index.y].boxColor=*playerTurn;
					players[*playerTurn-1].score++;
					anotherTurn = 1;
				}
			}
			players[*playerTurn-1].noOfMoves++;
            if(board[box1Index.x][box1Index.y].remainingLines==0)
            {
                board[box1Index.x][box1Index.y].boxColor=*playerTurn;
                players[*playerTurn-1].score++;
				anotherTurn = 1;
            }
			if(anotherTurn == 0)
			{
				reverseTurns(playerTurn);
			}
        }
        else
        {
            return -3;
        }
    }
    else if(a.y==box1Index.x+1 && p.y==box1Index.x+1 && ((a.x==box1Index.y+1 && p.x==box1Index.y) || (p.x==box1Index.y+1 && a.x==box1Index.y)))
    {
		anotherTurn = 0;
        if(board[box1Index.x][box1Index.y].lowerSide == 0)
        {
            board[box1Index.x][box1Index.y].lowerSide=*playerTurn;
            board[box1Index.x][box1Index.y].remainingLines--;
			*totalRemainingLines = *totalRemainingLines - 1;
			if(box2Index.x  > -1 && box2Index.y  > -1)
			{
				board[box2Index.x][box2Index.y].upperSide=*playerTurn;
				board[box2Index.x][box2Index.y].remainingLines--;
				if(board[box2Index.x][box2Index.y].remainingLines==0)
				{
					board[box2Index.x][box2Index.y].boxColor=*playerTurn;
					players[*playerTurn-1].score++;
					anotherTurn = 1;
				}
			}
			players[*playerTurn-1].noOfMoves++;
            if(board[box1Index.x][box1Index.y].remainingLines==0)
            {
                board[box1Index.x][box1Index.y].boxColor=*playerTurn;
                players[*playerTurn-1].score++;
				anotherTurn = 1;
            }
			if(anotherTurn == 0)
			{
				reverseTurns(playerTurn);
			}
        }
        else
        {
            return -3;
        }
    }
	return 0;
}
int undo(point a,point p,int sizeOfBoard, Player players[], Box board[][sizeOfBoard],int *playerTurn, int *totalRemainingLines)
{
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
		box1Index.x = box2Index.x = min(p.y,a.y);
        if(a.x==sizeOfBoard)
        {
            box1Index.y=a.x-1;
        }
		if(a.x == sizeOfBoard)
		{
			box1Index.y=a.x-1;
		}
        else if(a.x == 0)
        {
            box1Index.y=a.x;
        }
        else
        {
			box1Index.y=a.x-1;
            box2Index.y=a.x;
        }
    }
    ///when y is constant then the box are around it
    ///the column of the two boxes is constant equal to min x
    ///the row is not constant as it take values: y , y-1
    else if(a.y==p.y)
    {
		box1Index.y = box2Index.y = min(a.x, p.x);
        if(a.y==sizeOfBoard)
        {
            box1Index.x=a.y-1;
        }
        else if(a.y == 0)
        {
            box1Index.x=a.y;
        }
        else
        {
			box1Index.x=a.y-1;
            box2Index.x=a.y;
        }
    }
	int player = 0;
    if(a.y==box1Index.x && p.y==box1Index.x && ((a.x==box1Index.y && p.x==box1Index.y+1) || (p.x==box1Index.y && a.x==box1Index.y+1)))
    {
        if(board[box1Index.x][box1Index.y].upperSide!=0)
        {
			player = board[box1Index.x][box1Index.y].upperSide;
			*playerTurn = player;
            if(board[box1Index.x][box1Index.y].remainingLines == 0)
			{
				board[box1Index.x][box1Index.y].boxColor=0;
				players[player-1].score--;
			}
			board[box1Index.x][box1Index.y].upperSide=0;
			board[box1Index.x][box1Index.y].remainingLines++;
			*totalRemainingLines = *totalRemainingLines + 1;
			players[player-1].noOfMoves--;
        }
        else
        {
            return -3;
        }
    }
    else if(a.x==box1Index.y && p.x==box1Index.y && ((a.y==box1Index.x && p.y==box1Index.x+1) || (p.y==box1Index.x && a.y==box1Index.x+1)))
    {
		if(board[box1Index.x][box1Index.y].leftSide != 0)
		{
			player = board[box1Index.x][box1Index.y].leftSide;
			*playerTurn = player;
			if(board[box1Index.x][box1Index.y].remainingLines == 0)
			{
				board[box1Index.x][box1Index.y].boxColor=0;
				players[player-1].score--;
			}
			board[box1Index.x][box1Index.y].leftSide=0;
			board[box1Index.x][box1Index.y].remainingLines++;
			*totalRemainingLines = *totalRemainingLines + 1;
			players[player-1].noOfMoves--;
        }
        else
        {
            return -3;
        }
    }
    else if(a.x==box1Index.y+1 && p.x==box1Index.y+1 && ((a.y==box1Index.x+1 && p.y==box1Index.x) || (p.y==box1Index.x+1 && a.y==box1Index.x)))
    {
		if(board[box1Index.x][box1Index.y].rightSide != 0)
		{
			player = board[box1Index.x][box1Index.y].rightSide;
			*playerTurn = player;
			if(board[box1Index.x][box1Index.y].remainingLines == 0)
			{
				board[box1Index.x][box1Index.y].boxColor=0;
				players[player-1].score--;
			}
			board[box1Index.x][box1Index.y].rightSide=0;
			board[box1Index.x][box1Index.y].remainingLines++;
			if(box2Index.x  > -1 && box2Index.y  > -1)
			{
				if(board[box2Index.x][box2Index.y].remainingLines == 0)
				{
					board[box2Index.x][box2Index.y].boxColor=0;
					players[player-1].score--;
				}
				board[box2Index.x][box2Index.y].leftSide=0;
				board[box2Index.x][box2Index.y].remainingLines++;
			}
			*totalRemainingLines = *totalRemainingLines + 1;
			players[player-1].noOfMoves--;
        }
        else
        {
            return -3;
        }
    }
    else if(a.y==box1Index.x+1 && p.y==box1Index.x+1 && ((a.x==box1Index.y+1 && p.x==box1Index.y) || (p.x==box1Index.y+1 && a.x==box1Index.y)))
    {
        if(board[box1Index.x][box1Index.y].lowerSide != 0)
		{
			player = board[box1Index.x][box1Index.y].lowerSide;
			*playerTurn = player;
			if(board[box1Index.x][box1Index.y].remainingLines == 0)
			{
				board[box1Index.x][box1Index.y].boxColor=0;
				players[player-1].score--;
			}
			board[box1Index.x][box1Index.y].lowerSide=0;
			board[box1Index.x][box1Index.y].remainingLines++;
			if(box2Index.x  > -1 && box2Index.y  > -1)
			{
				if(board[box2Index.x][box2Index.y].remainingLines == 0)
				{
					board[box2Index.x][box2Index.y].boxColor=0;
					players[player-1].score--;
				}
				board[box2Index.x][box2Index.y].upperSide=0;
				board[box2Index.x][box2Index.y].remainingLines++;
			}
			*totalRemainingLines = *totalRemainingLines + 1;
			players[player-1].noOfMoves--;
        }
        else
        {
            return -3;
        }
    }
	return 0;
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
            return -4;
    }
    else if(a.y==p.y)
    {
        if(abs(a.x-p.x)==1)
        {
            return 1;
        }
        else
            return -4;
    }
    else if(a.x!=p.x&&a.y!=p.y)
    {
        return -4;
    }
	return -10;
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

int getRand(int lower, int upper)
{
	int num = (rand() % (upper - lower + 1)) + lower; 
	return num;
}

void start2PlayersGame(int sizeOfBoard, Box board[sizeOfBoard][sizeOfBoard], Player players[], int playerTurn, int totalRemainingLines, int gameTime)
{
	time_t startTime = time(NULL);
	point undoSequence[totalRemainingLines][2];
	int undoCounter = -1;
	int errorFlag = 1;
	int undoFlag = -1;
	int redoFlag = -1;
	int noOfMovesPlayed = 0;
	while(totalRemainingLines > 0)
	{
		system("cls");
		printBoard(sizeOfBoard,board, players, playerTurn, totalRemainingLines, time(NULL) - startTime + gameTime);
		point point1, point2;
		switch(errorFlag)
		{
			case -1:
				printf("\t\t\t\t\t\tIt's the same point!!\n");
				break;
			case -2:
				printf("\t\t\t\t\t\tOne of the points is out of range!!\n");
				break;
			case -3:
				printf("\t\t\t\t\t\tThis line is already taken!!\n");
				break;
			case -4:
				printf("\t\t\t\t\t\tNot valid points!!\n");
				break;
		}
		errorFlag = 1;
		printGameMenu(undoFlag, redoFlag, undoCounter, noOfMovesPlayed);
		printf("\t\t\t\t\t\tEnter the first point: (x, y)\n\t\t\t\t\t\t");
		if(scanf("%d %d", &point1.x, &point1.y) != 2)
		{
			char keychar;
			scanf("%c", &keychar);
			if(keychar == 's' || keychar == 'S')
			{
				//Save Function
				save(sizeOfBoard, board, players, playerTurn, totalRemainingLines, time(NULL) - startTime + gameTime, 2);
				break;
			}
			else if((keychar == 'u' || keychar == 'U') && undoFlag == 1 && undoCounter > -1)
			{
				//Undo
				undo(undoSequence[undoCounter][0], undoSequence[undoCounter][1], sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
				undoCounter--;
				redoFlag = 1;
				continue;
			}
			else if((keychar == 'r' || keychar == 'R') && redoFlag == 1 && undoCounter < noOfMovesPlayed)
			{
				//Redo
				pointToLines(undoSequence[undoCounter+1][0], undoSequence[undoCounter+1][1], sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
				undoCounter++;
				continue;
			}
			else if(keychar == 'e' || keychar == 'E')
			{
				//Exit
				break;
			}
			continue;
		}
		printf("\t\t\t\t\t\tEnter the second point: (x, y)\n\t\t\t\t\t\t");
		if(scanf("%d %d", &point2.x, &point2.y) != 2)
		{
			char keychar;
			scanf("%c", &keychar);
			if(keychar == 's' || keychar == 'S')
			{
				//Save Function
				save(sizeOfBoard, board, players, playerTurn, totalRemainingLines, time(NULL) - startTime +gameTime, 2);
				break;
			}
			else if((keychar == 'u' || keychar == 'U') && undoFlag == 1 && undoCounter > -1)
			{
				//Undo
				undo(undoSequence[undoCounter][0], undoSequence[undoCounter][1], sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
				undoCounter--;
				redoFlag = 1;
				continue;
			}
			else if((keychar == 'r' || keychar == 'R') && redoFlag == 1 && undoCounter < noOfMovesPlayed)
			{
				//Redo
				pointToLines(undoSequence[undoCounter+1][0], undoSequence[undoCounter+1][1], sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
				undoCounter++;
				continue;
			}
			else if(keychar == 'e' || keychar == 'E')
			{
				//Exit
				break;
			}
		}
		errorFlag = checkValidityOfPoints(point1, point2, sizeOfBoard);
		if(errorFlag == 1)
		{
			errorFlag = pointToLines(point1, point2, sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
			if(errorFlag == 0)
			{
				noOfMovesPlayed++;
				undoCounter++;
				undoSequence[undoCounter][0] = point1;
				undoSequence[undoCounter][1] = point2;
				undoFlag = 1;
			}
		}
	}
	if(totalRemainingLines == 0)
	{
		system("cls");
		printBoard(sizeOfBoard,board, players, playerTurn, totalRemainingLines, time(NULL) - startTime + gameTime);
		int winner;
		if(players[0].score == players[1].score)
		{
			printf("\t\t\t\t\t\tDraw\n");
			loadLeaderboard();
			printf("\t\t\t\t\t\tPress Enter To Exit\n\t\t\t\t\t\t");
			getchar();
			getchar();
		}
		else 
		{
			if(players[0].score > players[1].score)
			{
				winner = 0;
			}
			else
			{
				winner = 1;
			}
			printf("\t\t\t\t\t\t%s IS THE WINNER :)\n\t\t\t\t\t\tScore: %d\n", players[winner].name, players[winner].score);
			checkLeaderBoard(players[winner]);
			loadLeaderboard();
			printf("\t\t\t\t\t\tPress Enter To Exit\n\t\t\t\t\t\t");
			getchar();
			getchar();
		}
	}
}


void start1PlayerGame(int sizeOfBoard, Box board[sizeOfBoard][sizeOfBoard], Player players[], int playerTurn, int totalRemainingLines, int gameTime)
{
	time_t startTime = time(NULL);
	point undoSequence[totalRemainingLines][2];
	int errorFlag = 1;
	int undoFlag = -1;
	int redoFlag = -1;
	int compValidFlag;
	int undoCounter = -1;
	int noOfMovesPlayed = 0;
	point point1, point2;
	while(totalRemainingLines > 0)
	{
		system("cls");
		printBoard(sizeOfBoard,board, players, playerTurn, totalRemainingLines, time(NULL) - startTime + gameTime);
		if(playerTurn == 2)
		{
			Sleep(2000);
			compValidFlag = -5;
			point points[2];
			if(find3SidedBox(sizeOfBoard, board, points) == 1)
			{
				point1 = points[0];
				point2 = points[1];
				pointToLines(point1, point2, sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
				noOfMovesPlayed++;
				undoCounter++;
				undoSequence[undoCounter][0] = point1;
				undoSequence[undoCounter][1] = point2;
				continue;
			}
			if(findNot2SidedBox(sizeOfBoard, board, points) == 1)
			{
				point1 = points[0];
				point2 = points[1];
				pointToLines(point1, point2, sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
				noOfMovesPlayed++;
				undoCounter++;
				undoSequence[undoCounter][0] = point1;
				undoSequence[undoCounter][1] = point2;
				continue;
			}
			while(compValidFlag != 0)
			{
				point1.x = getRand(0, sizeOfBoard);
				point1.y = getRand(0, sizeOfBoard);
				point2.x = getRand(0, sizeOfBoard);
				point2.y = getRand(0, sizeOfBoard);
				compValidFlag = checkValidityOfPoints(point1, point2, sizeOfBoard);
				if(compValidFlag == 1)
				{
					compValidFlag = pointToLines(point1, point2, sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
					noOfMovesPlayed++;
					undoCounter++;
					undoSequence[undoCounter][0] = point1;
					undoSequence[undoCounter][1] = point2;
				}
			}
			continue;
		}
		switch(errorFlag)
		{
			case -1:
				printf("\t\t\t\t\t\tIt's the same point!!\n");
				break;
			case -2:
				printf("\t\t\t\t\t\tOne of the points is out of range!!\n");
				break;
			case -3:
				printf("\t\t\t\t\t\tThis line is already taken!!\n");
				break;
			case -4:
				printf("\t\t\t\t\t\tNot valid points!!\n");
				break;
		}
		errorFlag = 1;
		printGameMenu(undoFlag, redoFlag, undoCounter, noOfMovesPlayed);
		printf("\t\t\t\t\t\tEnter the first point: (x, y)\n\t\t\t\t\t\t");
		if(scanf("%d %d", &point1.x, &point1.y) != 2)
		{
			char keychar;
			scanf("%c", &keychar);
			if(keychar == 's' || keychar == 'S')
			{
				//Save Function
				save(sizeOfBoard, board, players, playerTurn, totalRemainingLines, time(NULL) - startTime + gameTime, 1);
				break;
			}
			else if((keychar == 'u' || keychar == 'U') && undoFlag == 1 && undoCounter > -1)
			{
				//Undo
				do
				{
					undo(undoSequence[undoCounter][0], undoSequence[undoCounter][1], sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
					undoCounter--;
				}
				while(playerTurn != 1);
				redoFlag = 1;
				continue;
			}
			else if((keychar == 'r' || keychar == 'R') && redoFlag == 1 && undoCounter < noOfMovesPlayed)
			{
				//Redo
				do
				{
					pointToLines(undoSequence[undoCounter+1][0], undoSequence[undoCounter+1][1], sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
					undoCounter++;
				}
				while(playerTurn != 1);
				continue;
			}
			else if(keychar == 'e' || keychar == 'E')
			{
				//Exit
				break;
			}
			continue;
		}
		printf("\t\t\t\t\t\tEnter the second point: (x, y)\n\t\t\t\t\t\t");
		if(scanf("%d %d", &point2.x, &point2.y) != 2)
		{
			char keychar;
			scanf("%c", &keychar);
			if(keychar == 's' || keychar == 'S')
			{
				//Save Function
				save(sizeOfBoard, board, players, playerTurn, totalRemainingLines, time(NULL) - startTime +gameTime, 1);
				break;
			}
			else if((keychar == 'u' || keychar == 'U') && undoFlag == 1 && undoCounter > -1)
			{
				//Undo
				do
				{
					undo(undoSequence[undoCounter][0], undoSequence[undoCounter][1], sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
					undoCounter--;
				}
				while(playerTurn != 1);
				redoFlag = 1;
				continue;
			}
			else if((keychar == 'r' || keychar == 'R') && redoFlag == 1 && undoCounter < noOfMovesPlayed)
			{
				//Redo
				do
				{
					pointToLines(undoSequence[undoCounter+1][0], undoSequence[undoCounter+1][1], sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
					undoCounter++;
				}
				while(playerTurn != 1);
				continue;
			}
			else if(keychar == 'e' || keychar == 'E')
			{
				//Exit
				break;
			}
		}
		errorFlag = checkValidityOfPoints(point1, point2, sizeOfBoard);
		if(errorFlag == 1)
		{
			errorFlag = pointToLines(point1, point2, sizeOfBoard, players, board, &playerTurn, &totalRemainingLines);
			if(errorFlag == 0)
			{
				noOfMovesPlayed++;
				undoCounter++;
				undoSequence[undoCounter][0] = point1;
				undoSequence[undoCounter][1] = point2;
				undoFlag = 1;
			}
		}
	}
	if(totalRemainingLines == 0)
	{
		system("cls");
		printBoard(sizeOfBoard,board, players, playerTurn, totalRemainingLines, time(NULL) - startTime + gameTime);
		int winner;
		if(players[0].score == players[1].score)
		{
			printf("\t\t\t\t\t\tDraw\n");
			loadLeaderboard();
			printf("\t\t\t\t\t\tPress Enter To Exit\n\t\t\t\t\t\t");
			getchar();
			getchar();
		}
		else 
		{
			if(players[0].score > players[1].score)
			{
				winner = 0;
			}
			else
			{
				winner = 1;
			}
			printf("\t\t\t\t\t\t%s IS THE WINNER :)\n\t\t\t\t\t\tScore: %d\n", players[winner].name, players[winner].score);
			if(winner == 0)
			{
				checkLeaderBoard(players[winner]);
			}
			loadLeaderboard();
			printf("\t\t\t\t\t\tPress Enter To Exit\n\t\t\t\t\t\t");
			getchar();
			getchar();
		}
	}
}
