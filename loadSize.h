int loadSize (char fileName[]){
	
	int size;
	FILE *Load;
    Load = fopen(fileName,"r");
    if(Load==NULL)
    {
        printf("Unable to create file.\n");
    }
	
	fscanf(Load,"%i\n", &size);
	return size;
}
