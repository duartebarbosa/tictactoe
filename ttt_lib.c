#include "ttt_lib.h"
#include <stdio.h>

/* The board */
static char board[3][3] = {
	{'1','2','3'},    		/* Initial values are reference numbers */
	{'4','5','6'},    		/* used to select a vacant square for   */
	{'7','8','9'}     		/* a turn.                              */
};
static int numPlays; 	/* Number of plays so far */

/* ********** */

int printCurrentBoard() {

	/* Print the board to stdout */
	printf("\n\n %c | %c | %c\n---+---+---\n %c | %c | %c\n---+---+---\n %c | %c | %c\n ",
	       board[0][0], board[0][1], board[0][2],
	       board[1][0], board[1][1], board[1][2],
	       board[2][0], board[2][1], board[2][2]);

	return 0;
}

/* Returns 0 if incorrect request, 1 otherwise */
int play(int row, int column, int player) {
	if (!(row >=0 && row <3 && column >= 0 && column < 3)) {
		printf("Off the board move. Try again...\n");
		return 0;
	}
	if (board[row][column] > '9') {
		printf("Invalid move; already occupied. Try again...\n");
		return 0;
	}

	board[row][column] = (player == 1) ? 'X' : 'O';  /* Insert player symbol   */
	numPlays++;
	return 1;
}

/* Returns 0 or 1 if there is a winner, 2 if there is a draw, -1 otherwise */
int checkWinner() {
	int line;
	/* Check for a winning line - diagonals first */
	if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
	   (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
		return ((board[1][1]=='X') ? 1 : 0);
	else
		/* Check rows and columns for a winning line */
		for(line = 0; line <= 2; line++) {
			if((board[line][0] == board[line][1] && board[line][0] == board[line][2]))
				return ((board[line][0]=='X') ? 1 : 0);

			if ((board[0][line] == board[1][line] && board[0][line] == board[2][line]))
				return ((board[0][line]=='X') ? 1 : 0);
		}
	if (numPlays == 9)
		return 2;  /* A draw! */
	else
		return -1;  /* Game is not over yet */
}

