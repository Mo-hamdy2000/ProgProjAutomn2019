int find3SidedBox (int size , Box Boxes [size][size], Point points[]){
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
	if(isFound)
	{
		if(Boxes[row][col].upperSide==1){
			points[0].x = col;
			points[0].y = row;
			points[1].x = col+1;
			points[1].y = row;
		}
		else if (Boxes[row][col].lowerSide==1){
			points[0].x = col;
			points[0].y = row+1;
			points[1].x = col+1;
			points[1].y = row+1;
		}
		else if (Boxes[row][col].rightSide==1){
			points[0].x = col+1;
			points[0].y = row;
			points[1].x = col+1;
			points[1].y = row;
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
