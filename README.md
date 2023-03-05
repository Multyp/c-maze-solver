# c-maze-solver

C Maze Solver is a program that solves mazes of any size by brute-forcing them. It stores the
maze in a graph and determines the shortest path from the entry to the exit.

## Usage
To use C Maze Solver, you first need to compile it trough Makefile by running make. Then, run
the program with the path to your maze file as the argument. The maze file should have a
valid format, composed of '.' for the path one can take and 'X' for walls. The entry should be in
the top left corner and the exit in the bottom right corner. If there is an empty line after the
last line of the maze, it will be considered invalid.

Example usage:
```bash
make
./solver maze.txt
```
The program will output the maze with a solution marked by 'o'.

## Performance
C Maze Solver can solve mazes of any size. It solved a 10,000 x 10,000 character mazes in
under 20 seconds without redirecting to a file.

## Future updates
In the future, C Maze Solver will be updated with the A* algorithm for faster solving.

## License
C Maze Solver is released under the MIT License.
