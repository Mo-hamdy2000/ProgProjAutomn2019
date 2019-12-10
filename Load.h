void load (int size, Box Boxes[size][size], Player players[], int* playerTurn, int* totalRemainingLines, char fileName[]){
	FILE *Load;
    Load = fopen(fileName,"r");
    if(Load==NULL)
    {
        printf("Unable to create file.\n");
    }
    fscanf(Load,"%i \n");
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
    fscanf(Load, "%s %i %i\n", players[0].name, &players[0].score, &players[0].numMoves);
    fscanf(Load, "%s %i %i\n", players[1].name, &players[1].score, &players[1].numMoves);
    fscanf(Load, "%i\n", playerTurn);
    fscanf(Load, "%i\n", totalRemainingLines);
   
    fclose(Load);
}
