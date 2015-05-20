package hangman;

import hangman.IEvilHangmanGame;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;
import java.util.stream.Collector;

public class EvilHangmanGame implements IEvilHangmanGame {

  List<Character> guesses = new ArrayList<Character>();
  Set<String> words = new HashSet<String>();
  String currentPattern = null;
  int wordLength = 0;
  int numberOfGuesses = 0;

  // init

  @Override
  public void startGame(File dictionary, int wordLength) {
    clear();
    this.wordLength = wordLength;
    StringBuilder pattern = new StringBuilder();
    for (int i = 0; i < wordLength; i++) {
      pattern.append('-');
    }
    currentPattern = pattern.toString();
    generateWords(dictionary);
  }

  private void generateWords(File dictionary) {
    try {
      Scanner scanner = new Scanner(dictionary);
      while (scanner.hasNext()) {
        String word = scanner.next();
        if (word.length() == wordLength) {
          words.add(word);
        }
      }
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
  }

  private void clear() {
    guesses.clear();
    words.clear();
    currentPattern = null;
    wordLength = 0;
    numberOfGuesses = 0;
  }

  // playing

  public void playGame(int numberOfGuesses) {
    this.numberOfGuesses = numberOfGuesses;
    Scanner input = new Scanner(System.in);
    printGameStatus();
    while (this.numberOfGuesses > 0 && currentPattern.contains("-")) {
      try {
        makeGuess(getGuess(input));
        if (this.numberOfGuesses > 0 && currentPattern.contains("-")) {
          printGameStatus();
        }
      } catch (GuessAlreadyMadeException e) {
        System.err.println("Error: you have already guess that character");
      }
    }
    input.close();
  }

  private void printGameStatus() {
    System.out.printf("You have %d guesses left\n", numberOfGuesses);
    System.out.print("Used letters: ");
    for (char c : guesses) {
      System.out.print(c + " ");
    }
    System.out.println("\nWord: " + currentPattern);
  }

  // guesses

  @Override
  public Set<String> makeGuess(char guess) throws GuessAlreadyMadeException {
    if (guesses.contains(guess)) {
      throw new GuessAlreadyMadeException();
    }
    guesses.add(guess);
    partitionWords(guess);
    return words
  }

  private char getGuess(Scanner input) {
    System.out.print("Enter guess: ");
    String guessStr = input.nextLine();
    if (guessStr.isEmpty()) {
      guessStr = "0";
    }
    char guessChar = guessStr.charAt(0);
    while (guessStr.length() > 1 || !Character.isLetter(guessChar)) {
      System.err.println("Error: guess must be a single valid letter");
      System.out.print("Enter guess: ");
      guessStr = input.nextLine();
      if (guessStr.isEmpty()) {
        guessStr = "0";
      }
      guessChar = guessStr.charAt(0);
    }
    return guessChar;
  }

  private void partitionWords(char guess) {

  }

  private String makePattern(String word, char guess) {
    return "";
  }

}