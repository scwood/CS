package hangman;

import java.io.File;

public class RunGame {

  public static void main(String[] args) {
    if (args.length < 3) {
      System.out.println(
          "Usage: java hangman.RunGame dictionary wordLength numberOfGuesses");
      return;
    }
    String dictionaryFileName = args[0];
    File dictionary = new File(dictionaryFileName);
    if (!dictionary.canRead()) {
      System.err.println("Error: dictionary unreadable");
      return;
    }
    if (dictionary.isDirectory()) {
      System.err.println("Error: dictionary is a directory");
      return;
    }
    int wordLength = 0;
    int numberOfGuesses = 0;
    try {
      wordLength = Integer.parseInt(args[1]);
      numberOfGuesses = Integer.parseInt(args[2]);
    } catch (NumberFormatException e) {
      System.err.println("Error: wordLength and numberOfGuesses must be ints");
    }
    EvilHangmanGame game = new EvilHangmanGame();
    game.startGame(dictionary, wordLength);
    game.playGame(numberOfGuesses);
  }

}
