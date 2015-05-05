package spell;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import spell.ISpellCorrector.NoSimilarWordFoundException;

public class SpellCorrector implements ISpellCorrector {

  private ArrayList<String> editedWords = new ArrayList<String>();
  private ArrayList<String> correctedWords =  new ArrayList<String>();
  private Trie trie = new Trie();

  public void useDictionary(String dictionaryFileName) throws IOException {
    File dictionaryFile = new File(dictionaryFileName);
    Scanner scanner = new Scanner(dictionaryFile);
    while (scanner.hasNext()) {
      trie.add(scanner.next());
    }
    scanner.close();
  }

  public void checkDictEquality(SpellCorrector other) {
    if (trie.equals(other.trie)) {
      System.out.println("dicts equal");
      return; 
    }
    System.out.println("dicts unequal");
  }

  public String suggestSimilarWord(String inputWord) throws NoSimilarWordFoundException {
    if (trie.find(inputWord) != null) {
      return inputWord;
    }
    calculatePossibleSuggestions(inputWord);
    if (correctedWords.size() == 1) {
      return correctedWords.get(0);
    } else if (correctedWords.size() > 1 ) {
      return getMostSimilarWord();
    }
    Object[] editTwoDistanceOriginals = editedWords.toArray();
    for (Object obj : editTwoDistanceOriginals) {
      calculatePossibleSuggestions((String)obj);
    }
    if (correctedWords.size() != 0) {
      return getMostSimilarWord();
    } 
    throw new NoSimilarWordFoundException();
  }

  private void calculatePossibleSuggestions(String word) {
    checkDeletionDistance(word);
    checkTranspositionDistance(word);
    checkAlterationDistance(word);
    checkInsertionDistance(word);
  }

  private void checkDeletionDistance(String word) {
    for (int i = 0; i < word.length(); i++) {
      StringBuilder edited = new StringBuilder(word);
      edited.deleteCharAt(i);
      unionWordWithLists(edited.toString());
    }
  }

  private void checkTranspositionDistance(String word) {
    for (int i = 0; i < word.length() - 1; i++) {
      StringBuilder edited = new StringBuilder(word);
      char temp = edited.charAt(i);
      edited.setCharAt(i, edited.charAt(i + 1));
      edited.setCharAt(i + 1, temp);
      unionWordWithLists(edited.toString());
    }
  }

  private void checkAlterationDistance(String word) {
    final char A = 'a';
    for (int i = 0; i < word.length(); i++) {
      for (int j = 0; j < 26; j++) {
        StringBuilder edited = new StringBuilder(word);
        char replacementCharacter = (char)(A + j);
        edited.setCharAt(i, replacementCharacter);
        unionWordWithLists(edited.toString());
      }
    }
  }

  private void checkInsertionDistance(String word) {
    final char A = 'a';
    for (int i = 0; i < word.length() + 1; i++) {
      for (int j = 0; j < 26; j++) {
        StringBuilder edited = new StringBuilder(word);
        char newCharacter = (char)(A + j);
        edited.insert(i, newCharacter);
        unionWordWithLists(edited.toString());
      }
    }
  }

  private void unionWordWithLists(String word) {
    if (trie.find(word) == null) {
      editedWords.add(word);
    } else { 
      correctedWords.add(word);
    }
  }

  private String getMostSimilarWord() {
    ArrayList<String> finalWords = new ArrayList<String>();
    int highestValue = 0;
    for (String str : correctedWords) {
      if (trie.find(str).getValue() > highestValue) {
        highestValue = trie.find(str).getValue();
        finalWords.clear();
        finalWords.add(str);
      } else if (trie.find(str).getValue() == highestValue) {
        finalWords.add(str);
      }
    }
    Collections.sort(finalWords);
    String result = (finalWords.size() > 0) ? finalWords.get(0) : "";
    return result;
  }

  @Override
  public String toString() {
    return trie.toString();
  }

}
