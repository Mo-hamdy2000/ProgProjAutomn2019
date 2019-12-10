Point find2NotSidedBox (int size , Box Boxes [size][size]){
	Point point;
	for(int i=0 ; i<size ; i++){
		for (int j=0 ; j<size ; j++){
			if(Boxes[i][j].remainingLines!=2){
				point.x = i;
				point.y = j;
				return point;
			}
		}
	}
	point.x=-1;
	point.y=-1;
return point;
}
