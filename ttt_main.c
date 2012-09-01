/*
 * This is a *better* version of that shitty code u provided us.
 */

#include <stdio.h>
#include <string.h>
#include "ttt_lib.h"

int main() {

	int player = 1;                        /* Player number - 1 or 2               */
	int stdin_input = 0;                   /* Square selection number for turn     */
	int row = 0;                           /* Row index for a square               */
	int column = 0;                        /* Column index for a square            */
	int winner = -1;                       /* The winning player                   */
	char * token = NULL;
	char stdin_buffer[MAX_BUFFER_LEN] = {0};

	printf("Tic Tac Toe - really hammered version\nPress 'exit' to quit the app.\n");

	/* The main game loop. The game continues for up to 9 turns */
	/* As long as there is no winner                            */
	while (winner == -1) {
		printCurrentBoard();

		printf("\nPlayer %d, please enter the number of the square where you want to place your %c : ", player, (player==1) ? 'X' : 'O');

		if(fgets(stdin_buffer, MAX_BUFFER_LEN, stdin) == NULL) {
			printf("Error reading the stream.");
			continue;
		}

		stdin_buffer[strlen(stdin_buffer)-1] = '\0';
		token = strtok (stdin_buffer, " " "\t");
		
		if(token == NULL)
			continue;
		else if(!strcmp(token, "exit"))
			return 0;
		else if(!sscanf(stdin_buffer, " %d", &stdin_input)) {
			printf("Let's try again. This time with the numbers on board u fool.\n");
			stdin_input = 0;
			continue;
		}

		row = --stdin_input / 3;                       /* Get row index of square      */
		column = stdin_input % 3;                      /* Get column index of square   */

		if (!play(row, column, player))
			continue;

		winner = checkWinner();
		player = (player++) % 2;               /* Select player */

	}

	printCurrentBoard();	/* Game is over so display the final board */

	/* Time to display the results message */
	if(winner == 2)
		printf("\nHow boring, nothing more than a bad draw.\n");
	else if(winner == player)
		printf("\nCongratulations, player %d, YOU ARE THE WINNER!\n", winner);
	else
		printf("\nToo bad, player %d, WINS! Better luck next time...\n", winner);

}

