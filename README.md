# Queens Program

This program solves the the eight queens puzzle, published by chess composer Max Bezzel in 1848. The puzzle presents the question of how to place eight queens on a 8x8 chessboard such that no queen can capture any other queens. 
This program finds a way to place queens on the chessboard such that there is only one queen on each row, column and diagonal. This is the output when running this program from Terminal:

![](board.png)

## Checking row, column and diagonal

In the program, the methods isRowClear and isColClear loop through columns and rows, respectively, and return true if there is no queen in a row or column. The method isDiagonalClear first checks if a move is out of bounds of the chessboard. If true, it stops checking since it already reaches the border. If false, it proceeds to loop through and check the diagonal lines in four directions.

## Placing queens recursively

After all checks are cleared, method placeQueens puts a queen at a position. It then calls itself recursively, passing the next row. If the recursive call returns false, it means that at some point, no more queens can be placed given the positions of the already placed queens. This is an incorrect solution. In this case, the function erases the current arrangment, backtracks to the first queen, places it at the next legal column and tries the recursion again.

If the recursive call returns true, a queen has been successfully placed in the current row. Because of the recursion, queens have also been placed in all subsequent rows of the board. The correct solution is found. 

## File description

This program has both C and Java versions: [Queens.c](https://github.com/vantrinh7/QueensProgram/blob/master/queens.c) and [Queens.java](https://github.com/vantrinh7/QueensProgram/blob/master/src/Queens.java).
