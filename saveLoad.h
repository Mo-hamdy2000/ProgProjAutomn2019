void save (int size, Box Boxes[size][size], Player players[], int playerTurn, int totalRemainingLines, int gameTime, int gameMode){
    printf("\t\t\t\t\t\tChoose Save file: 1.File1\t2.File2\t\t3.File3\n\t\t\t\t\t\t");
	int fileNo = 0;
	char skipper;
	while(scanf("%d", &fileNo) != 1 || fileNo > 3 || fileNo < 1)
	{
		if(fileNo <= 3 && fileNo >= 1)
		{
			scanf("%c", &skipper);
		}
	}
	char fileName[15];
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
	FILE *Save;
    Save = fopen(fileName,"w");
    fprintf(Save,"%i\n", gameMode);
	fprintf(Save,"%i\n", size);
    for (int i=0 ; i<size ; i++)
        {
            for (int j=0 ; j<size ; j++)
                {
                fprintf(Save,"%i ", Boxes[i][j].upperSide);
                fprintf(Save,"%i ", Boxes[i][j].lowerSide);
                fprintf(Save,"%i ", Boxes[i][j].rightSide);
                fprintf(Save,"%i ", Boxes[i][j].leftSide);
                fprintf(Save,"%i ", Boxes[i][j].remainingLines);
                fprintf(Save,"%i ", Boxes[i][j].boxColor);
                fprintf(Save,"\n");
                }
        }
    fprintf(Save, "%s %i %i\n", players[0].name, players[0].score, players[0].noOfMoves);
    fprintf(Save, "%s %i %i\n", players[1].name, players[1].score, players[1].noOfMoves);
    fprintf(Save, "%i\n", playerTurn);
    fprintf(Save, "%i\n", totalRemainingLines);
    fprintf(Save, "%i\n", gameTime);
    fclose(Save);
}

int loadGameMode(int *gameMode, char fileName[])
{
	FILE *Load;
    Load = fopen(fileName,"r");
    if(Load==NULL)
    {
        printf("Unable to create file.\n");
    }
	if(fscanf(Load, "%i\n", gameMode) == 1)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

void loadSize(int *size, char fileName[])
{
	FILE *Load;
    Load = fopen(fileName,"r");
    if(Load==NULL)
    {
        printf("Unable to create file.\n");
    }
	int skipper;
	fscanf(Load, "%i\n", &skipper);
	fscanf(Load, "%i\n", size);
}

void load (int size, Box Boxes[size][size], Player players[], int* playerTurn, int* totalRemainingLines, char fileName[], int *gameTime){
	FILE *Load;
    Load = fopen(fileName,"r");
    if(Load==NULL)
    {
        printf("Unable to create file.\n");
    }
	int skipper;
    fscanf(Load,"%i\n", &skipper);
	fscanf(Load,"%i\n", &skipper);
    for (int i=0 ; i<size ; i++)
        {
            for (int j=0 ; j<size ; j++)
                {
                fscanf(Load,"%i ", &Boxes[i][j].upperSide);
                fscanf(Load,"%i ", &Boxes[i][j].lowerSide);
                fscanf(Load,"%i ", &Boxes[i][j].rightSide);
                fscanf(Load,"%i ", &Boxes[i][j].leftSide);
                fscanf(Load,"%i ", &Boxes[i][j].remainingLines);
                fscanf(Load,"%i ", &Boxes[i][j].boxColor);
                fscanf(Load,"\n");
                }
        }
    fscanf(Load, "%s %i %i\n", players[0].name, &players[0].score, &players[0].noOfMoves);
    fscanf(Load, "%s %i %i\n", players[1].name, &players[1].score, &players[1].noOfMoves);
    fscanf(Load, "%i\n", playerTurn);
    fscanf(Load, "%i\n", totalRemainingLines);
	fscanf(Load, "%i\n", gameTime);
    fclose(Load);
}