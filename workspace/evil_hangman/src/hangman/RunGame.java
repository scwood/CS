package hangman;

import java.io.File;

public class RunGame {
  
  public static void main(String[] args) {
    if (args.length < 3) {
      System.err.println("Usage: java hangman.RunGame dictionary wordLength guesses");
      return;
    }
    File dictionary = new File(args[0]);
    if (!dictionary.canRead()) {
      System.err.println("Error: given dictionary can't be read");
      return;
    }
    if (dictionary.isDirectory()) {
      System.err.println("Error: given dictionary is a directory");
      return;
    }
    int wordLength = 0;
    int numberOfGuesses = 0;
    try {
      wordLength = Integer.parseInt(args[1]);
      numberOfGuesses = Integer.parseInt(args[2]);
    } catch (NumberFormatException e) {
      System.err.println("Error: wordSize and numberOfGuesses must be ints");
      return;
    }
    EvilHangmanGame game = new EvilHangmanGame();
    game.startGame(dictionary, wordLength);
    game.playGame(numberOfGuesses);
  }
  
}