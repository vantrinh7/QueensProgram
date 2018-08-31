
public class Queens {
	public static final int NUM_COL = 8;
	public static final int NUM_ROW = 8;
	public static final int NUM_QUEENS = 8;
	public static final int FIRST_ROW = 0;
	private static String board[][];
	private static String empty = " ";
	private static String border = "|";
	private static String queen = "q";

	public static void main(String[] args) {
		// Board is an array of array. Each space in array String[NUM_ROW] holds an
		// array that represents columns
		board = new String[NUM_ROW][NUM_COL];
		placeQueens(FIRST_ROW);
		fillSpace();
		drawBoard();
	}

	/**
	 * This method determine positions of queens on board. It iterates through the
	 * 2D array. Inner loop iterates through columns (elements in a row), outer loop
	 * iterates through different rows.
	 */
	private static boolean placeQueens(int curRow) {
		// Base case: If place queen in last row, the method is successful, end it
		if (curRow == NUM_ROW) {
			return true;
		} else { // If not last row
			// Check columns of current row to see where queen could be placed
			for (int col = 0; col < board.length; col++) {
				if (isRowClear(curRow) && isColClear(col) && isDiagonalClear(curRow, col)) {
					// Place the queen that is not in the last row
					board[curRow][col] = queen;
					// Then call itself recursively, passing the next row
					boolean nextCall = placeQueens(curRow + 1);
					// If recursive call is true, then return true here - which indicates that the
					// queen in this row has been placed, and because of recursions, queens have
					// also been placed in all subsequent rows
					if (nextCall == true) {
						return true;
					} else {
						// If false, remove queen from this position
						board[curRow][col] = null;
					}
				}
			}
		}
		// If the function cannot place any queen in this row, return false
		return false;
	}

	private static boolean isRowClear(int row) {
		for (int i = 0; i < NUM_ROW; i++) {
			if (board[row][i] == queen) {
				// If a row already contains a queen, return false
				return false;
			}
		}
		return true;
	}

	public static boolean isColClear(int col) {
		for (int i = 0; i < NUM_COL; i++) {
			if (board[i][col] == queen) {
				// If a column already contains a queen, return false
				return false;
			}
		}
		return true;
	}

	private static boolean isDiagonalClear(int row, int col) {
		// Forward, downward
		for (int i = row, j = col; i < board.length; i++, j++) {
			if (isOutOfBounds(i + 1, j + 1)) {
				break; // If out of bounds, stop checking
			} else {
				if (board[i + 1][j + 1] == queen) { // If there's a queen, return false
					return false;
				}
			}
		}
		// Forward, upward
		for (int i = row, j = col; i < board.length; i--, j++) {
			if (isOutOfBounds(i - 1, j + 1)) {
				break;
			} else {
				if (board[i - 1][j + 1] == queen) {
					return false;
				}
			}
		}
		// Backward, downward
		for (int i = row, j = col; i < board.length; i++, j--) {
			if (isOutOfBounds(i + 1, j - 1)) {
				break;
			} else {
				if (board[i + 1][j - 1] == queen) {
					return false;
				}
			}
		}
		// Backward, upward
		for (int i = row, j = col; i < board.length; i--, j--) {
			if (isOutOfBounds(i - 1, j - 1)) {
				break;
			} else {
				if (board[i - 1][j - 1] == queen) {
					return false;
				}
			}
		}
		return true;
	}

	private static boolean isOutOfBounds(int attemptRow, int attemptCol) {
		if ((attemptRow < 0) || (attemptRow > NUM_ROW - 1) || (attemptCol < 0) || (attemptCol > NUM_COL - 1)) {
			return true;
		}
		return false;
	}

	private static void fillSpace() {
		for (int row = 0; row < board.length; row++) {
			for (int col = 0; col < board[row].length; col++) {
				if (board[row][col] == null) {
					board[row][col] = empty;
				}
			}
		}
	}

	private static void drawBoard() {
		// Draw top of board
		System.out.println("- - - - - - - - -");
		for (int row = 0; row < board.length; row++) {
			for (int col = 0; col < board[row].length; col++) {
				System.out.print(border);
				System.out.print(board[row][col]);
				// At the end of the line, draw another border
				if (col == 7) {
					System.out.print(border);
				}
			}
			// Draw the border under each row
			System.out.println();
			System.out.println("- - - - - - - - -");
		}
	}
}
