package hangman;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class EvilHangmanGame implements IEvilHangmanGame {
  
  private int wordLength = 0;
  private int numberOfGuesses = 0;
  private String currentPattern = null;
  private Set<Character> guessSet = new HashSet<Character>();
  private Set<String> wordSet = new HashSet<String>();

  // init

  @Override
  public void startGame(File dictionary, int wordLength) {
    clear();
    this.wordLength = wordLength;
    generateWordList(dictionary);
    StringBuilder pattern = new StringBuilder();
    for (int i = 0; i < wordLength; i++) {
      pattern.append('-');
    }
    currentPattern = pattern.toString();
  }
  
  private void generateWordList(File file) {
    Scanner scanner = null;
    try {
      scanner = new Scanner(file);
    } catch (FileNotFoundException e) {
      e.printStackTrace();
    }
    while (scanner.hasNext()) {
      String word = scanner.next();
      if (word.length() == this.wordLength) {
        wordSet.add(word);
      }
    }
  }
  
  private void clear() {
    wordLength = 0;
    numberOfGuesses = 0;
    wordSet.clear();
    currentPattern = null;
    guessSet.clear();
  }
  
  // playing the game
  
  public void playGame(int numberOfGuesses) {
    if (wordSet.isEmpty()) {
      System.err.printf(
          "Error: no words of length %d in dictionary\n", wordLength);
    }
    this.numberOfGuesses = numberOfGuesses;
    printGameStatus();
    Scanner input = new Scanner(System.in);
    while (this.numberOfGuesses > 0 && currentPattern.contains("-")) {
      try {
        wordSet = makeGuess(getGuess(input));
        if (this.numberOfGuesses > 0 && currentPattern.contains("-")) {
          System.out.println();
          printGameStatus();
        }
      } catch (GuessAlreadyMadeException e) {
        System.err.println("Error: you have already guessed that character");
      }
    }
    printGameResult();
  }
  
  private char getGuess(Scanner input) {
    System.out.print("Enter guess: ");
    String guessString = input.nextLine();
    if (guessString.isEmpty()) {
      guessString = "0"; // garbage input if enter is hit
    }
    char guessChar = guessString.charAt(0);
    while (guessString.length() > 1 || !Character.isLetter(guessChar)) {
      System.err.println("Error: guess must be a single letter");
      System.out.print("Enter guess: ");
      guessString = input.nextLine().toLowerCase();
      if (guessString.isEmpty()) {
        guessString = "0"; // garbage input if enter is hit
      }
      guessChar = guessString.charAt(0);
    }
    return guessChar;
  }
  
  private void printGameStatus() {
    System.out.printf("You have %d guesses left\n", numberOfGuesses);
    System.out.print("Used letters: ");
    for (Character c : guessSet) {
      System.out.print(c + " ");
    }
    System.out.println("\nWord: " + currentPattern);
  }

  private void printGameResult() {
    if (currentPattern.contains("-")) {
      System.out.println("You lose!");
      Object[] endWords = wordSet.toArray();
      Collections.shuffle(Arrays.asList(endWords));
      System.out.print("The word was: " + endWords[0]);
    } else {
      System.out.println("You win!");
      System.out.println("The word was " + currentPattern);
    }
  }

  // making guesses

  @Override
  public Set<String> makeGuess(char guess) throws GuessAlreadyMadeException {
    if (guessSet.contains(guess)) {
      throw new GuessAlreadyMadeException();
    }
    guessSet.add(guess);
    String patternBackup = currentPattern;
    makeNewWordList(guess);
    printTurnResult(patternBackup, guess);
    return wordSet;
  }
  
  private void makeNewWordList(char guess) {
    Map<String, HashSet<String>> wordPartitions = 
        new HashMap<String, HashSet<String>>();
    for (String word : wordSet) {
      String pattern = makePattern(word, guess);
      if (wordPartitions.containsKey(pattern)) {
        HashSet<String> wordPartition = wordPartitions.get(pattern);
        wordPartition.add(word);
        wordPartitions.put(pattern, wordPartition);
      } else {
        HashSet<String> wordPartition = new HashSet<String>();
        wordPartition.add(word);
        wordPartitions.put(pattern, wordPartition);
      }
    }
    pickMostEvilWordSet(wordPartitions);
  }
  
  private void pickMostEvilWordSet(Map<String, HashSet<String>> wordPartitions) {
//    System.out.println("Options: " + wordPartitions.toString());
    wordPartitions = pickLargestPartition(wordPartitions);
    wordPartitions = pickLeastFrequentPartition(wordPartitions);
    wordPartitions = pickRightMostPartition(wordPartitions);
    updatePattern(wordPartitions.entrySet().iterator().next().getKey());
    wordSet = wordPartitions.entrySet().iterator().next().getValue();
//    System.out.println("Choice: " + wordPartitions.toString());
  }
  
  private Map<String, HashSet<String>> pickLargestPartition(
      Map<String, HashSet<String>> wordPartitions) {
    if (wordPartitions.size() == 1) {
      return wordPartitions;
    }
    int currentMax = 0;
    Map<String, HashSet<String>> temp = new HashMap<String, HashSet<String>>();
    for (Map.Entry<String, HashSet<String>> partition : wordPartitions.entrySet()) {
      if (partition.getValue().size() > currentMax) {
        currentMax = partition.getValue().size();
        temp.clear();
        temp.put(partition.getKey(), partition.getValue());
      } else if (partition.getValue().size() == currentMax) {
        temp.put(partition.getKey(), partition.getValue());
      }
    }
    return temp;
  }
  
  private Map<String, HashSet<String>> pickLeastFrequentPartition(
      Map<String, HashSet<String>> wordPartitions) {
    if (wordPartitions.size() == 1) {
      return wordPartitions;
    }
    Map<String, HashSet<String>> temp = new HashMap<String, HashSet<String>>();
    int lowestCount = 0;
    for (Map.Entry<String, HashSet<String>> partition : wordPartitions.entrySet()) {
      int currentCount = 0;
      for (char c : partition.getKey().toCharArray()) {
        if (c != '-') {
          currentCount++;
        }
      }
      if (temp.isEmpty()) {
        lowestCount = currentCount;
        temp.put(partition.getKey(), partition.getValue());
      } else if (currentCount < lowestCount) {
        lowestCount = currentCount;
        temp.clear();
        temp.put(partition.getKey(), partition.getValue());
      } else if (currentCount == lowestCount) {
        temp.put(partition.getKey(), partition.getValue());
      }
    }
    return temp;
  }
  
  private Map<String, HashSet<String>> pickRightMostPartition(
      Map<String, HashSet<String>> wordPartitions) {
    Map<String, HashSet<String>> temp = new HashMap<String, HashSet<String>>();
    Map.Entry<String, HashSet<String>> highestPriority = null;
    for (Map.Entry<String, HashSet<String>> partition : wordPartitions.entrySet()) {
      if (highestPriority == null) {
        highestPriority = partition;
      } else {
        String currentReversed =  
            new StringBuilder(partition.getKey()).reverse().toString();
        String highestReversed = 
            new StringBuilder(highestPriority.getKey()).reverse().toString();
        if (currentReversed.compareTo(highestReversed) > 0) {
          highestPriority = partition;
        }
      }
    }
    temp.put(highestPriority.getKey(), highestPriority.getValue());
    return temp;
  }

  private void updatePattern(String pattern) {
    StringBuilder oldPattern = new StringBuilder(currentPattern);
    StringBuilder newPattern = new StringBuilder(pattern);
    StringBuilder result = new StringBuilder();
    for (int i = 0; i < pattern.length(); i++) {
      if (oldPattern.charAt(i) == newPattern.charAt(i)) {
        result.append(oldPattern.charAt(i));
      } else if (oldPattern.charAt(i) != '-') {
        result.append(oldPattern.charAt(i));
      } else if (newPattern.charAt(i) != '-') {
        result.append(newPattern.charAt(i));
      } else {
        result.append('-');
      }
    }
    currentPattern = result.toString();
  }
  
  private String makePattern(String word, char guess) {
    StringBuilder pattern = new StringBuilder();
    for (char c : word.toCharArray()) {
      if (c == guess) {
        pattern.append(c);
      } else {
        pattern.append('-');
      }
    }
    return pattern.toString();
  }

  private void printTurnResult(String oldPattern, char guess) {
    int newChars = 0;
    for (int i = 0; i < currentPattern.length(); i++) {
      if (currentPattern.charAt(i) == guess) {
        newChars++;
      }
    }
    if (newChars == 0) {
      System.out.printf("Sorry, there are no %c's\n", guess);
      numberOfGuesses--;
    } else if (newChars == 1) {
      System.out.printf("Yes, there is 1 %c\n", guess);
    } else if (newChars > 1) {
      System.out.printf("Yes, there are %d %c's\n", newChars, guess);
    }
  }
}