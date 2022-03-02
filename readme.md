# Minesweeper

My attempt at making a minesweeper. It is currently playable through the console and I plan to make some sort of automatic solver. 

## Playing on the console

The board is displayed on the console with x the column and y the rows (starting at value 1)
(Board dimension is changed through the source in main.cpp)
You can open or flag a cell with the commands :
* Open cell (x,y) ```o x y``` 
* Flag cell (x,y) ```f x y``` 

example : ```o 2 3``` opens the cell on the second column, third row.

Symbol | Meaning
---|---
_ | hidden cell
\# | mined cell
f | flagged cell
0,1,... | number of mined cell touching the cell

## Solver 

TODO