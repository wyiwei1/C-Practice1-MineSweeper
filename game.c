#include "game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	printf("-------MineSweeper-------\n");

	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}

	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	
}

//randomly set mines
//x:1~9
//y:1~9
void SetMine(char mine[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	int x = 0;
	int y = 0;
	while (count) {
		x = rand() % row + 1;
		y = rand() % col + 1;
		
		if (mine[x][y] != '1') {
			mine[x][y] = '1';
			count--;
		}
	}
}

/*
1. enter a coordinate
2. Determine if this coordinate is out of bounds
3. if the coordinate is a mine, game over
   if not, game on
*/
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int count = row*col-EASY_COUNT;
	int x = 0;
	int y = 0;
	while (count) {
		DisplayBoard(show, ROW, COL);
		printf("please enter the row coordinate: ");
		scanf("%d %d", &x, &y);
		printf("\n ");

		// determine if the coordinate is out of bounds
		if (x > row || x<1 || y>col || y < 1) {
			printf("the coordinate you entered is out of bounds, please enter again!\n");
			continue;
		}
		// stepped a mine
		if (mine[x][y] == '1') {
			break;
		}
		//did not step a mine
		else {
			int num = 0;
			for (int i = x - 1; i <= x + 1; i++) {
				for (int j = y - 1; j <= y + 1; j++) {
					if (mine[i][j] == '1') {
						num++;
					}
				}
			}
			show[x][y] = (char)(num+48);
			count--;
		}
	}

	if (count != 0) {
		printf("\n");
		printf("You stepped on a mine, you are dead\n");
		printf("All the coordinates of mines are shown below: \n");
		DisplayBoard(mine, ROW, COL);
	}
	else {
		printf("You found all of the mines, you win!\n");
	}
}