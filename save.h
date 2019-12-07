void save (int size, Box Boxes[size][size], Player players[], int playerTurn, int totalRemainingLines, int fileNumber){
    FILE *Save;
    Save = fopen("saveFile.txt","w");
    if(Save==NULL)
    {
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }
   
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
    fprintf(Save, "%s %i %i\n", players[0].name, players[0].score, players[0].numMoves);
    fprintf(Save, "%s %i %i\n", players[1].name, players[1].score, players[1].numMoves);
    fprintf(Save, "%i\n", playerTurn);
    fprintf(Save, "%i\n", totalRemainingLines);
   
    fclose(Save);
}
