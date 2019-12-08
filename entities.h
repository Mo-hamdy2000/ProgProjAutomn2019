#define StringSize 20
typedef struct {
	int upperSide;
	int lowerSide;
	int rightSide;
	int leftSide;
	int remainingLines;
	int boxColor;
} Box;
typedef struct {
	char name[StringSize];
	int score;
	int noOfMoves;
} Player;
typedef struct
{
    int x;
    int y;
}point;
