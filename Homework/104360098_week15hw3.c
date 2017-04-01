#include <stdio.h>
#include <string.h>
#include <stdbool.h>
/*Computer Programming 2016 week 15 hw 3, Coded by Leung Ho Kwan 104360098*/
void inputmatrix(int matrix[9][9]) {	//input matrix
	int i = 0, j = 0;
	char input[11];
	while (i < 9) {
		fgets(input, sizeof(input), stdin);
		input[strlen(input) - 1] = '\0';
		for (j = 0; j < 9; j++) {
			matrix[i][j] = input[j] - 48;
		}
		i++;
	}
}
int maxallhorizero_amount(int matrix[9][9]) {	//the max amount of zero in matrix by row
	int i, j, counter = 0, firm = 0;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			if (matrix[i][j] == 0) {
				counter++;
			}
		}
		!(firm < counter) || (firm = counter);
		counter = 0;
	}
	return firm;
}
int maxallvertzero_amount(int matrix[9][9]) {	//the max amount of zero in matrix by column
	int i, j, counter = 0, firm = 0;
	for (j = 0; j < 9; j++) {
		for (i = 0; i < 9; i++) {
			if (matrix[i][j] == 0) {
				counter++;
			}
		}
		!(firm < counter) || (firm = counter);
		counter = 0;
	}
	return firm;
}
int searchtimes(int matrix[9][9]) {	//find the max times need to scan
	int scantimes = 0, temp;
	temp = maxallhorizero_amount(matrix);	//scan by row
	!(scantimes < temp) || (scantimes = temp);
	temp = maxallvertzero_amount(matrix);	//scan by column
	!(scantimes < temp) || (scantimes = temp);
	/*
	3x3 matrix search
	*/
	return scantimes;	//return the number of times that need to be scanned
}
void inistandard(bool standard[]) {	//initialize the bool array
	int i;
	for (i = 0; i < 10; i++) {
		standard[i] = false;
	}
}
bool plotstandardbyrow(int matrix[9][9], int row, bool standard[], int *y) {	//plot the bool array by the matrix's row
	int zerocounter = 0, i;
	for (i = 0; i < 9; i++) {	//ploting
		standard[matrix[row][i]] = true;
		if (matrix[row][i] == 0) {	//concurrently record the coordinate of the place that need to be filled
			*y = i;
			zerocounter++;
		}
	}
	if (zerocounter > 1 || zerocounter == 0) {	//return false if the row is complete or more than one space
		return false;
	}else {	//return true if only one space
		return true;
	}
}
bool plotstandardbycol(int matrix[9][9], int col, bool standard[], int *x) {	//plot the bool array by the matrix's row
	int zerocounter = 0, i;
	for (i = 0; i < 9; i++) {	//ploting
		standard[matrix[i][col]] = true;
		if (matrix[i][col] == 0) {	//concurrently record the coordinate of the place that need to be filled
			*x = i;
			zerocounter++;
		}
	}
	if (zerocounter > 1 || zerocounter == 0) {	//return false if the col is complete or more than one space
		return false;
	}else {	//return true if only one space
		return true;
	}
}
int needfill(bool standard[]) {	//find out the value that need to be filled
	int i;
	for (i = 1; i < 10; i++) {
		if (standard[i] == false) {	//find out which value do not exist
			return i;
		}
	}
}
void plotrec(int x, int y, int fillnum, int rec[81][3], int *reccounter) {	//record the coordinate and fillnum
	rec[*reccounter][0] = x;
	rec[*reccounter][1] = y;
	rec[*reccounter][2] = fillnum;
	*reccounter = *reccounter + 1;
}
void fillspace_row(int matrix[9][9], int row, bool standard[], int rec[81][3], int *reccounter) {	//fill the rowth row
	int y, fillnum;
	if (plotstandardbyrow(matrix, row, standard, &y)) {	//plot the bool array, return true if only one space, return false if more than one space or no space
		fillnum = needfill(standard);	//only one space, then get the value that need to be filled
		plotrec(row, y, fillnum, rec, reccounter);	//record the coordinate and fillnum
		matrix[row][y] = fillnum;	//insert value to matrix
	}
}
void fillspace_column(int matrix[9][9], int col, bool standard[], int rec[81][3], int *reccounter) {
	int x, fillnum;
	if (plotstandardbycol(matrix, col, standard, &x)) {	//plot the bool array, return true if only one space, return false if more than one space or no space
		fillnum = needfill(standard);	//only one space, then get the value that need to be filled
		plotrec(x, col, fillnum, rec, reccounter);	//record the coordinate and fillnum
		matrix[x][col] = fillnum;	//insert value to matrix
	}
}
void fillspace(int matrix[9][9], int rec[81][3], int *reccounter) {	//fill the space in matrix
	bool standard[10];	//bool array for recording the existed element
	int i;	//iterate for the row num and col num
	for (i = 0; i < 9; i++) {	//fill the 9 rows
		inistandard(standard);	//initialize the bool array
		fillspace_row(matrix, i, standard, rec, reccounter);	//fill the ith row, record it
	}
	for (i = 0; i < 9; i++) {	//fill the 9 cols
		inistandard(standard);	//initialize the bool array
		fillspace_column(matrix, i, standard, rec, reccounter);	//fill the ith col, record it
	}
	/*
	3x3 matrix fill
	*/
}
void processmatrix(int matrix[9][9], int scantimes, int rec[81][3], int *reccounter) {	//process
	while (scantimes > 0) {	//scan and fill the matrix for <scantimes> times
		fillspace(matrix, rec, reccounter);	//fill the space
		scantimes--;
	}
}
void printrec(int rec[81][3], int reccounter) {
	int i;
	for (i = 0; i < reccounter; i++) {
		printf("%d %d %d\n", rec[i][0], rec[i][1], rec[i][2]);
	}
}
void sortrec(int rec[81][3], int reccounter) {	//sort the rec
	int i, j, temp;
	for (i = 0; i < reccounter; i++) {
		for (j = 0; j < reccounter - 1 - i; j++) {
			if (rec[j][0] > rec[j + 1][0]) {
				temp = rec[j][0];	//swap the row coordinate
				rec[j][0] = rec[j + 1][0];	
				rec[j + 1][0] = temp;
				temp = rec[j][1];	//swap the col coordinate
				rec[j][1] = rec[j + 1][1];
				rec[j + 1][1] = temp;
				temp = rec[j][2];	//swap the value
				rec[j][2] = rec[j + 1][2];
				rec[j + 1][2] = temp;
			}else if (rec[j][0] == rec[j + 1][0]) {
				if (rec[j][1] > rec[j + 1][1]) {
				temp = rec[j][0];	//swap the row coordinate
				rec[j][0] = rec[j + 1][0];	
				rec[j + 1][0] = temp;
				temp = rec[j][1];	//swap the col coordinate
				rec[j][1] = rec[j + 1][1];
				rec[j + 1][1] = temp;
				temp = rec[j][2];	//swap the value
				rec[j][2] = rec[j + 1][2];
				rec[j + 1][2] = temp;					
				}
			}
		}
	}
}
int main(int argc, char **argv) {
	int matrix[9][9], scantimes, rec[81][3], reccounter = 0;
	inputmatrix(matrix);	//input matrix
	scantimes = searchtimes(matrix);	//return the number of times need to scan
	processmatrix(matrix, scantimes, rec, &reccounter);	//process
	sortrec(rec, reccounter);	//sort the rec for later display
	printrec(rec, reccounter);	//print recorder coordinate and element
	return 0;
}
