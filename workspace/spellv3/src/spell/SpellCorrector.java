package spell;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class SpellCorrector implements ISpellCorrector {

  public Trie dictionary = new Trie();
  private List<String> editedWords = new ArrayList<String>();
  private List<String> correctedWords = new ArrayList<String>();
  private final int ALPHABET_SIZE = 26;
  
  // initialize
  
  @Override
  public void useDictionary(String dictionaryFileName) throws IOException {
    File dictionaryFile = new File(dictionaryFileName);
    Scanner scanner = new Scanner(dictionaryFile);
    while (scanner.hasNext()) {
      dictionary.add(scanner.next().toLowerCase());
    }
    scanner.close();
  }
  
  private void clear() {
    editedWords.clear();
    correctedWords.clear();
  }

  // correct word

  @Override
  public String suggestSimilarWord(String inputWord)
      throws NoSimilarWordFoundException {
    clear();
    inputWord = inputWord.toLowerCase();
    if (dictionary.find(inputWord) != null) {
      return inputWord;
    }
    generateSimilarWords(inputWord);
    if (correctedWords.size() == 1) {
      return correctedWords.get(0);
    } else if (correctedWords.size() > 1) {
      return getMostSimilarWord();
    }
    Object[] editDistanceOneWords = editedWords.toArray();
    for (Object word : editDistanceOneWords) {
      generateSimilarWords((String)word);
    }
    if (correctedWords.size() > 0) {
      return getMostSimilarWord();
    }
    throw new NoSimilarWordFoundException();
  }
  
  private void generateSimilarWords(String word) {
    generateDeletionWords(word);
    generateTranspositionWords(word);
    generateAlterationWords(word);
    generateInsertionWords(word);
  }
  
  private void generateDeletionWords(String word) {
    for (int i = 0; i < word.length(); i++) {
      StringBuilder edited = new StringBuilder(word);
      edited.deleteCharAt(i);
      unionWordWithLists(edited.toString());
    }
  }
  
  private void generateTranspositionWords(String word) {
    for (int i = 0; i < word.length() - 1; i++) {
      StringBuilder edited = new StringBuilder(word);
      char temp = edited.charAt(i);
      edited.setCharAt(i, edited.charAt(i + 1));
      edited.setCharAt(i + 1, temp);
      unionWordWithLists(edited.toString());
    }
  }
  
  private void generateAlterationWords(String word) {
    for (int i = 0; i < word.length(); i++) {
      for (int j = 0; j < ALPHABET_SIZE; j++) {
        StringBuilder edited = new StringBuilder(word);
        edited.setCharAt(i, (char)('a' + j));
        unionWordWithLists(edited.toString());
      }
    }
  }
  
  private void generateInsertionWords(String word) {
    for (int i = 0; i < word.length() + 1; i++) {
      for (int j = 0; j < ALPHABET_SIZE; j++) {
        StringBuilder edited = new StringBuilder(word);
        edited.insert(i, (char)('a' + j));
        unionWordWithLists(edited.toString());
      }
    }
  }
  
  private void unionWordWithLists(String word) {
    if (dictionary.find(word.toString()) != null) {
      correctedWords.add(word.toString());
    } else {
      editedWords.add(word.toString());
    }
  }

  private String getMostSimilarWord()  {
    int highestFrequency = 0;
    List<String> finalWords = new ArrayList<String>();
    for (String word : correctedWords) {
      if (dictionary.find(word).getValue() > highestFrequency) {
        highestFrequency = dictionary.find(word).getValue();
        finalWords.clear();
        finalWords.add(word);
      } else if (dictionary.find(word).getValue() == highestFrequency) {
        finalWords.add(word);
      }
    }
    Collections.sort(finalWords);
    return finalWords.get(0);
  }
}
