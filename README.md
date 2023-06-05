# ***Word Search Game***
The Word Search Game is a console-based game implemented in C++. It allows players to find words in a grid of letters. The game provides different levels of difficulty, including easy, medium, and hard.

## **Table of Contents**

* Introduction
* Gameplay
* Functions
* How to Use
* Examples
* Introduction

The Word Search Game is a classic puzzle game where players search for words hidden in a grid of letters. Words can be found horizontally, vertically, diagonally, and even backwards. The game provides a grid of letters and a list of words to find. Players need to locate the words by highlighting them in the grid.

### **Gameplay**
The game starts by displaying the Word Search grid and the player's score and number of tries.
The player can choose to start a new game or resume a paused game.
The player selects a word from the provided list and enters it.
The game checks if the word is present in the grid and updates the score and tries accordingly.
The game continues until the player finds all the words or runs out of tries.
At the end of the game, the player can choose to play again or exit the game.
The game also keeps track of high scores, which can be viewed by the player.

### **Functions**

 The game consists of several functions to perform different tasks. Here are some of the key functions used in the game:

`read`: Reads the Word Search grid from a file.

`display`: Displays the Word Search grid and game information.

`pause_s`: Pauses the game and saves the current state to a file.

`resume`: Resumes a paused game by loading the saved state from a file.

`check_r`: Checks for word matches in rows.

`check_c`: Checks for word matches in columns.

`diagnol_r`: Checks for word matches in right diagonal direction.

`diagnol_l`: Checks for word matches in left diagonal direction.


`diagnol_rh`: Checks for word matches in right half diagonal direction.

`diagnol_lh`: Checks for word matches in left half diagonal direction.

`reverse`: Reverses a word.

`easy`: Starts a new game with the easy difficulty level.

`medium`: Starts a new game with the medium difficulty level.

`hard`: Starts a new game with the hard difficulty level.

`s_high`: Saves the player's score in the high score list.

`high_check`: Displays the high score list.

### ***How to Use***

Clone the repository to your local machine.
Compile the C++ source code using a C++ compiler.
Run the compiled executable file to start the game.
Follow the on-screen instructions to play the game.
Use the keyboard to enter words and navigate through the game options.
Enjoy finding words in the Word Search grid!

> **Note :** This documentation assumes that you have a basic understanding of C++ programming and how to compile and run C++ code.

> *For better understanding and visulaization you can see documentation*

> The words to be search are written in the board.txt file and to add further words add the word in the dictionary file change the board.txt file accordingly.

> Must add all files in th project in order to compile it sucessfuly.

> `Enjoy playing the Word Search Game!`
