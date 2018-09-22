/**
 * This program draws a 8x8 chessboard and finds a way to place 8 queens on the board, so that no queens capture other queens
 * - there is exactly 1 queen in each row, column and diagonal.
 * @author vantrinh
 * @version Feb 1st 2018
 */

#include <stdio.h>
#include <stdbool.h>

#define NUM_COL 8
#define NUM_ROW 8
#define FIRST_ROW 0

char board[NUM_ROW][NUM_COL];
char empty = ' ';
char border = '|';
char queen = 'q';
bool placeQueens();
void fillSpace();
void drawBoard();
bool isRowClear(int row);
bool isColClear(int col);
bool isDiagonalClear(int row, int col);
bool isOutOfBounds(int attemptRow, int attemptCol);

/**
 * This main method calls methods to place the queens, fill the remaining space and draw a chess board
 * @param int argc argument count
 * @param **argv argument vector
 * @return int 0 if success
 */
int main (int argc, char **argv) {
  placeQueens(FIRST_ROW);
  fillSpace();
  drawBoard();
  return 0; 
}

/**
 * This method uses recursion to place the queens recursively into the chess board
 * @param int curRow the current row 
 * @return true if queen can be placed on row, false if not
 */
bool placeQueens(int curRow) {
  // Base case: if queen is placed in the last row, method is successful and is ended.
  if (curRow == NUM_ROW) {
    return true;
  }
  // If not last row, perform recursion
  else {
    
    // Check columns within current row
    for (int col = 0; col < NUM_COL; col++) {
      
      // Check if row, column and diagonal lines are clear of queens
      if ((isRowClear(curRow) == true) && (isColClear(col) == true) && (isDiagonalClear(curRow, col) == true)) {
	
	// If clear, place a queen at this column on this row
	board[curRow][col] = queen;

	// Then call the next row by a recursive call
	bool callNextRow = placeQueens(curRow + 1);

	// If recursive call is true, then return true here, which indicates that the queen in this row has been placed
	// Because of recursions, queens have also been placed in subsequent rows. The solution is found.
	if (callNextRow == true) {
	  return true;
	}
	// False result means from this position no more queen can be placed, we remove the queen from this position
	else {
	  board[curRow][col] = '\0';
	}
      }
    }
  }
  // If the function cannot place any queen in this row that passes the checks, return false.
  return false;
}

/**
 * This method checks if there is no queen in a row
 * @param int row the row to be checked
 * @return true if the row is clear of queens, false otherwise
 */
bool isRowClear(int row) {
  for (int i = 0; i < NUM_ROW; i++) {
    if (board[row][i] == queen) {
      return false;
    }
  }
  return true;
}

/**
 * This method checks if there is no queen in a column
 * @param int col the column to be checked
 * @return true if the column is clear of queens, false otherwise
 */
bool isColClear(int col) {
  for (int i = 0; i < NUM_COL; i++) {   
    if (board[i][col] == queen) {
      return false;
    }
  }
  return true;
}

/**
 * This method checks if there is no queen in diagonal lines. It first checks if next move is out of bounds of chessboard. 
 * If true, stop checking since it has reached the border. If false, check if there is queen on the diagonal lines.
 * @param int row the row to be checked
 * @param int col the column to be checked
 * @return true if the diagonals are clear of queens, false otherwise
 */
bool isDiagonalClear(int row, int col) {
  // Check diagonal forward, downward
  for (int i = row, j = col; i < NUM_ROW; i++, j++) {
    if (isOutOfBounds(i + 1, j + 1) == true) {
      break;
    } else {
      if (board[i + 1][j + 1] == queen) {
	return false;
      }
    }
  }

  // Check diagonal forward, upward
  for (int i = row, j = col; i < NUM_ROW; i--, j++) {
    if (isOutOfBounds(i - 1, j + 1) == true) {
      break;
    } else {
      if (board[i - 1][j + 1] == queen) {
	return false;
      }
    }
  }

  // Check diagonal backward, downward
  for (int i = row, j = col; i < NUM_ROW; i++, j--) {
    if (isOutOfBounds(i + 1, j - 1) == true) {
      break;
    } else {
      if (board[i + 1][j - 1] == queen) {
	return false;
      }
    }
  }

  // Check diagonal backward, upward
  for (int i = row, j = col; i < NUM_ROW; i--, j--) {
    if (isOutOfBounds(i - 1, j - 1) == true) {
      break;
    } else {
      if (board[i - 1][j - 1] == queen) {
	return false;
      }
    }
  }
  return true;
}

/**
 * This method checks if attempted row and columns are out of bounds of chessboard
 * Thus out of bounds for an array index
 *
 * @param int attemptRow the attempted row
 * @param int attemptCol the attempted column
 * @return true if out of bounds, false otherwise
 */
bool isOutOfBounds(int attemptRow, int attemptCol) {
  if ((attemptRow < 0) || (attemptRow > NUM_ROW - 1) || (attemptCol < 0) || (attemptCol > NUM_COL -1 )) {
    return true;
  }
  return false;
}

/**
 * This method checks if values on the board are null and fill in with space character.
 */
void fillSpace() {
  for (int row = 0; row < NUM_ROW; row++) {
    for (int col = 0; col < NUM_COL; col++) {
      if (board[row][col] == '\0') {
	board[row][col] = empty;
      }
    }
  }
}

/**
 * This method prints values and draws the chessboard.
 */
void drawBoard() {
  // Draw the top of board
  printf("-----------------\n");
  for (int row = 0; row < NUM_ROW; row++) {
    for (int col = 0; col < NUM_COL; col++) {
      printf("%c", border);
      printf("%c", board[row][col]);
      // At the end of the line, draw enclosing border
      if (col == 7) {
	printf("%c", border);
      }
    }
    // Draw the border under each row
    printf("\n");
    printf("-----------------\n");
  }
}
