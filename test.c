
#include "game.h"

void menu() {
	printf("*****************\n");
	printf("*****1.play******\n");
	printf("*****2.exit******\n");
	printf("*****************\n");
}


/*
1. User two 2-dimensional arrays to implement the minesweeper game
2. If the size of the gameboard is 9*9, the size of the array that were found
3. Arrays use character arrays
*/

void game() {
	
	
	char mine[ROWS][COLS];//store the information of mines
	char show[ROWS][COLS];//store the information on the mines that were found

	//Initialize two gameboards
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '-');

	//set mines
	SetMine(mine, ROW, COL);

	DisplayBoard(show, ROW, COL);

	//DisplayBoard(mine, ROW, COL);

	FindMine(mine, show, ROW, COL);

}

void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("Please select:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("Mine Sweeper\n");
			game();
			break;

		case 0:
			printf("Exit the game\n");
			break;

		default:
			printf("Select wrong, please select again\n");
		}
	} while (input);
}


int main() {
	test();
	return 0;
}