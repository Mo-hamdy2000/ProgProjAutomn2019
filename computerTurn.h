int find3SidedBox (int size , Box Boxes [size][size], point points[])
{
	int row;
	int col;
	int isFound = 0;
	for(int i=0 ; i<size && !isFound ; i++){
		for (int j=0 ; j<size && !isFound ; j++){
			if(Boxes[i][j].remainingLines==1){
				isFound = 1;
				row = i;
				col = j;
			}
		}
	}
	if(isFound == 1)
	{
		if(Boxes[row][col].upperSide==0){
			points[0].x = col;
			points[0].y = row;
			points[1].x = col+1;
			points[1].y = row;
		}
		else if (Boxes[row][col].lowerSide==0){
			points[0].x = col;
			points[0].y = row+1;
			points[1].x = col+1;
			points[1].y = row+1;
		}
		else if (Boxes[row][col].rightSide==0){
			points[0].x = col+1;
			points[0].y = row;
			points[1].x = col+1;
			points[1].y = row+1;
		}
		else{
			points[0].x = col;
			points[0].y = row;
			points[1].x = col;
			points[1].y = row+1;
			}
		return 1;
	}
	return 0;
}
int findNot2SidedBox (int size , Box Boxes [size][size], point points[])
{
	int row = 0;
	int col = -1;
	int isFound = 0;
	int isValid = 0;
	int i = 0;
	int j = 0;
	while(isFound == 0 && !(i == size && j == size ))
	{
		for(i = row ;i<size && !isFound; i++)
		{
			for (j = 0 ;j<size && !isFound; j++)
			{
				if(j <= col && i == row)
				{
					continue;
				}
				else if(Boxes[i][j].remainingLines > 2){
					row = i;
					col = j;
					isFound = 1;
				}
			}
		}
		
		if(isFound == 1)
		{
			if(Boxes[row][col].upperSide==0)
			{
				points[0].x = col;
				points[0].y = row;
				points[1].x = col+1;
				points[1].y = row;
				if(row > 0 && Boxes[row-1][col].remainingLines == 2)
				{
					isFound = 0;
				}
				else
				{
					isValid = 1;
					isFound = 1;
				}
			}
			if (Boxes[row][col].lowerSide==0 && isValid == 0){
				points[0].x = col;
				points[0].y = row+1;
				points[1].x = col+1;
				points[1].y = row+1;
				if(row < size-1 && Boxes[row+1][col].remainingLines == 2)
				{
					isFound = 0;
				}
				else
				{
					isValid = 1;
					isFound = 1;
				}
			}
			if (Boxes[row][col].rightSide==0 && isValid == 0){
				points[0].x = col+1;
				points[0].y = row;
				points[1].x = col+1;
				points[1].y = row+1;
				if(col < size-1 && Boxes[row][col+1].remainingLines == 2)
				{
					isFound = 0;
				}
				else
				{
					isValid = 1;
					isFound = 1;
				}
			}
			if (Boxes[row][col].leftSide==0 && isValid == 0){
				points[0].x = col;
				points[0].y = row;
				points[1].x = col;
				points[1].y = row+1;
				if(col > 0 && Boxes[row][col-1].remainingLines == 2)
				{
					isFound = 0;
				}
				else
				{
					isValid = 1;
					isFound = 1;
				}
			}
		}
	}
	return isFound;
}
