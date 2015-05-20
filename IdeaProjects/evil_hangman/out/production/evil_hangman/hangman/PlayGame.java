package hangman;

import javax.sound.midi.Soundbank;
import java.io.File;

public class PlayGame {

  public static void main(String[] args) {
    if (args.length < 3) {
      System.out.println("Usage: java hangman.PlayGame dictionary wordLength " +
          "numberOfGuesses");
      return;
    }
    File dict = new File(args[0]);
    if (!dict.canRead()) {
      System.err.println("Error: dictionary unreadable");
      return;
    }
    if (dict.isDirectory()) {
      System.err.println("Error: dictionary is unreadable");
      return;
    }
    int wordLength = 0;
    int numberOfGuesses = 0;
    try {
      wordLength = Integer.parseInt(args[1]);
      numberOfGuesses = Integer.parseInt(args[2]);
    } catch (NumberFormatException e) {
      System.err.println("Error: wordLength and numberOfGuesses must be " +
          "integers");
      return;
    }
    EvilHangmanGame game = new EvilHangmanGame();
    game.startGame(dict, wordLength);
    game.playGame(numberOfGuesses);
  }

}
