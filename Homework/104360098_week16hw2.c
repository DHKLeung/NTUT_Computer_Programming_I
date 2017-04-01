#include <stdio.h>
#include <stdbool.h>
/*Computer Programming 2016 week 16 hw 2, Coded by Leung Ho Kwan 104360098*/
void boardinput(int (*board)[10]) {	//user input the content of the board
	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			scanf("%d", &board[i][j]);	
		}
	}
}
bool checkboard_row(int (*board)[10], int x, int row_front) {	//check the row
	int i;
	for (i = row_front; i <= row_front + 4; i++) {
		if (board[x][i] != 1) {
			return false;
		}
	}
	return true;
}
bool checkboard_col(int (*board)[10], int y, int col_front) {	//check the column
	int i;
	for (i = col_front; i <= col_front + 4; i++) {
		if (board[i][y] != 1) {
			return false;
		}
	}
	return true;
}
bool checkboard_slash(int (*board)[10], int x, int y, int slash_frontx, int slash_fronty) {	//check the slash
	int i, j;
	for (i = slash_frontx, j = slash_fronty; i <= slash_frontx + 4 && j <= slash_fronty + 4; i++, j++) {
		if (board[i][j] != 1) {
			return false;
		}
	}
	return true;
}
bool checkboard_backslash(int (*board)[10], int x, int y, int backslash_frontx, int backslash_fronty) {	//check the backslash
	int i, j;
	for (i = backslash_frontx, j = backslash_fronty; i <= backslash_frontx + 4 && j >= backslash_fronty - 4; i++, j--) {
		if (board[i][j] != 1) {
			return false;
		}
	}
	return true;
}
void checkboard(int (*board)[10], int x, int y) {	//check the board after inserting the 1 for testing
	int row_front, col_front, slash_frontx, slash_fronty, backslash_frontx, backslash_fronty;
	bool finished = false;
	for (row_front = y - 4; row_front <= y && row_front <= 5; row_front++) {	//check the row whether it wins, the row front increment!
		if (row_front < 0) {	//if the front element is over the board, just immediately set it to 0 and continue the following checking
			row_front = 0;
		}
		finished = checkboard_row(board, x, row_front);	//front element is in the board range, check row, return true if wins, else false
		if (finished) {	//if finished, print the coordinate and return
			printf("%d %d\n", x, y);
			return;
		}
	}
	for (col_front = x - 4; col_front <= x && col_front <= 5; col_front++) {	//check the column whether it wins, the col front increment!
		if (col_front < 0) {	//if the front element is over the board, just immediately set it to 0 and continue the following checking
			col_front = 0;
		}
		finished = checkboard_col(board, y, col_front);	//front element is in the board range, check column, return true if wins, else false
		if (finished) {	//if finished, print the coordinate and return
			printf("%d %d\n", x, y);
			return;
		}
	}
	for (slash_frontx = x - 4, slash_fronty = y - 4; slash_frontx <= x && slash_fronty <= y && (slash_frontx <= 5 || slash_fronty <= 5); slash_frontx++, slash_fronty++) {	//check the slash whether it wins, the slash front increment
		if (slash_frontx < 0 || slash_fronty < 0) {	//if the front element is over the board, skip the loop once
			continue;
		}
		finished = checkboard_slash(board, x, y, slash_frontx, slash_fronty);	//front element is in the board range, check slash, return true if wins, else false
		if (finished) {	//if finished, print the coordinate and return
			printf("%d %d\n", x, y);
			return;
		}
	}
	for (backslash_frontx = x - 4, backslash_fronty = y + 4; backslash_frontx <= x && backslash_fronty >= y && (backslash_frontx <= 5 || backslash_fronty >= 4); backslash_frontx++, backslash_fronty--) {	//check the backslash whether it wins, the backslash front increment
		if (backslash_fronty > 9 || backslash_frontx < 0) {	//if the front element is over the board, skip the loop once
			continue;
		}
		finished = checkboard_backslash(board, x, y, backslash_frontx, backslash_fronty);	//front element is in the board range, check backslash, return true if wins, else false
		if (finished) {	//if finished, print the coordinate and return
			printf("%d %d\n", x, y);
			return;
		}
	}
}
void crackboard_inserttesting(int (*board)[10], int x, int y) {	//process if the coordinate will be win or not, insert 1 for testing
	if (board[x][y] == 1) {	//element exist, no need to process, return
		return;
	}else {	//insert 1 for testing
		board[x][y] = 1;	//insert 1
		checkboard(board, x, y);	//check the board if it wins after inserting the 1
		board[x][y] = 0;	//reset to 0
	}
}
void crackboard(int (*board)[10]) {	//figure out the place for winning
	int i, j;
	for (i = 0; i < 10; i++) {	//loop the row
		for (j = 0; j < 10; j++) {	//loop the column
			crackboard_inserttesting(board, i, j);	//process the coordinate, insert the 1 for testing
		}
	}
}
int main(int argc, char **argv) {
	int board[10][10];
	boardinput(board);	//user input the board content
	crackboard(board);	//call function to figure out the place for winning
	return 0;
}
