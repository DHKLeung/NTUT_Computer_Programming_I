#include <stdio.h>
#include <stdbool.h>
/*Computer Programming 2016 week 16 hw 1, Coded by Leung Ho Kwan 104360098*/
typedef enum _action action;
enum _action {  //enumerate the action
    plug,
    showallprob,
    showcomprob
};
action inputxy(int *x, int *y) {    //process the input, return the action which need to be performed
    char xx;
    scanf("%c", &xx);
    getchar();
    if (xx == 'w') {    //return the action which means to show computer's winning probability
        return showcomprob;
    }else if (xx == 'd') {  //return the action which means to show both computer's and player's winning probability
        return showallprob;
    }else { //return the action which means to insert element
        *x = xx - 48;
        scanf("%d", y);
        getchar();
        return plug;
    }
}
bool errorExist(int (*board)[3], int x, int y) {    //check whether there is input error
    if (board[x][y] == 0) {
        return false;
    }else {
        printf("input error\n");
        return true;
    }
}
void plugboard(int (*board)[3], int x, int y, int turn) {   //insert to the board
    board[x][y] = ((turn == 1) ? -1 : 1);
}
int checkboard_row(int row[]) { //check row
    int comcounter = 0, playercounter = 0, i;
    for (i = 0; i < 3; i++) {   //calculate who wins
        if (row[i] == 1) {
            playercounter++;
        }else if (row[i] == -1) {
            comcounter++;
        }
    }
    if (playercounter == 3) {   //return 1 if player wins
        return 1;
    }else if (comcounter == 3) {    //return -1 if com wins
        return -1;
    }else { //return 0 if no one wins
        return 0;
    }
}
int checkboard_col (int e1, int e2, int e3) {   //check column
    int col[3];
    col[0] = e1;    //pretend to be a row
    col[1] = e2;
    col[2] = e3;
    return checkboard_row(col); //check as row
}
int checkboard_slash(int (*board)[3]) { //check slash
    int i, slash[3];
    for (i = 0; i < 3; i++) {   //pretend to be a row
        slash[i] = board[i][i];
    }
    return checkboard_row(slash);   //check as row
}
int checkboard_backslash(int (*board)[3]) { //check backslash
    int i, backslash[3];
    for (i = 2; i >= 0; i--) {  //pretend to be row
        backslash[2 - i] = board[2 - i][i];
    }
    return checkboard_row(backslash);   //check as row
}
bool checkboard(int (*board)[3]) {  //check whether player or com wins, print who wins, return true, else return false
    int i, whoWins = 0;
    for (i = 0; i < 3; i++) {   //check row
        whoWins = checkboard_row(board[i]);
        if (whoWins != 0) {
            break;
        }
    }
    if (whoWins == 0) { //check column
        for (i = 0; i < 3; i++) {
            whoWins = checkboard_col(board[0][i], board[1][i], board[2][i]);
            if (whoWins != 0) {
                break;
            }
        }
    }
    if (whoWins == 0) { //check slash
        whoWins = checkboard_slash(board);
    }
    if (whoWins == 0) { //check backslash
        whoWins = checkboard_backslash(board);
    }
    if (whoWins == 1) { //if 1 then player wins, return true for finished
        printf("Player win\n");
        return true;
    }else if (whoWins == -1) {  //if -1 then com wins,  return true for finished
        printf("Computer win\n");
        return true;
    }else { //no one wins, return false for finished
        return false;
    }
}
bool calprob_checkboard(int (*board)[3]) {  //check board for calculate the prob to win
    int i, whoWins = 0;
    for (i = 0; i < 3; i++) {   //check row
        whoWins = checkboard_row(board[i]);
        if (whoWins != 0) {
            break;
        }
    }
    if (whoWins == 0) { //check column
        for (i = 0; i < 3; i++) {
            whoWins = checkboard_col(board[0][i], board[1][i], board[2][i]);
            if (whoWins != 0) {
                break;
            }
        }
    }
    if (whoWins == 0) { //check slash
        whoWins = checkboard_slash(board);
    }
    if (whoWins == 0) { //check backslash
        whoWins = checkboard_backslash(board);
    }
    if (whoWins != 0) { //if the assigned element can lead to be win, return true, else return false
        return true;
    }else {
        return false;
    }
}
void calprob(int (*board)[3], int assign) { //calculate the probable way to win
    int i, j;
    for (i = 0; i < 3; i++) {   //run each row
        for (j = 0; j < 3; j++) {   //run each col
            if (board[i][j] == 0) { //if the place is empty
                board[i][j] = assign;   //assign the element
                if (calprob_checkboard(board)) {    //check if the board with assigned element can win or not
                    if (assign == 1) {  //print the result
                        printf("Player will win with (%d, %d)\n", i, j);
                    }else if (assign == -1) {
                        printf("Computer will win with (%d, %d)\n", i, j);
                    }
                }
                board[i][j] = 0;    //reset
            }
        }
    }
}
void gamestart(int (*board)[3], int turn) { //in game
    int x, y;
    action todo;
    bool finished = false, error = false;
    while (1) {
        todo = inputxy(&x, &y); //know what action need to be performed
        switch (todo) {
            case plug : //perform insertion
                error = errorExist(board, x, y);    //check input error, if error exists, return true, else return false
                if (!error) {   //if no error
                    plugboard(board, x, y, turn);   //insert element
                    finished = checkboard(board);   //check the board to see who wins and print who wins in function, return true if finished, else return false;
                }
                break;
            case showcomprob :
                calprob(board, -1); //find out the probable way for com to win
                break;
            case showallprob :
                calprob(board, -1); //find out the probable way for com to win
                calprob(board, 1);  //find out the probable way for player to win
                break;
        }
        if (finished) { //if the game is finished, break
            break;
        }else if (!finished && !error && todo != showcomprob && todo != showallprob) {    //if the game isn't finished and error did'nt exist
            turn = !turn;   //the next turn
        }
    }
}
int main(int argc, char **argv) {
    int board[3][3] = { 0 }, firsthand;
    scanf("%d", &firsthand);    //input who's the first hand
    getchar();
    gamestart(board, firsthand);    //gamestart
    return 0;
}
