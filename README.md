# John Conwell

## Grid Battle

### Description
This project is a simple game comprised of two teams of characters arranged in a 2x4 grid. Each character is one of several jobs (often referred to as classes), with various stats and actions. Each action can damage other character(s), heal other character(s), swap places with another character, or a combination of the three. Each action is only usable from certain positions on the grid, and has specified target positions from each valid position.

### To Compile
Open a terminal in the same directory as the source code and use the command
```bash
$ make
```
to compile this program. This program compiles on Unix with gcc 7.4.0. Note that for future releases, SDL must be installed on the compiling machine. To install SDL, see https://wiki.libsdl.org/Installation

### To Execture
Run the program from the terminal with the following command:
```bash
$ ./game
```
