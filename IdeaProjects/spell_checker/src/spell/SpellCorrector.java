package spell;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SpellCorrector implements ISpellCorrector {

  public Trie dictionary = new Trie();
  private List<String> editedWords = new ArrayList<String>();
  private List<String> correctedWords = new ArrayList<String>();

  @Override
  public void useDictionary(String dictionaryFileName) throws IOException {
    File dict = new File(dictionaryFileName);
    Scanner scanner = new Scanner(dict);
    while (scanner.hasNext()) {
      dictionary.add(scanner.next());
    }
    scanner.close();
  }

  private void clearLists() {
    editedWords.clear();
    correctedWords.clear();
  }

  @Override
  public String suggestSimilarWord(String inputWord) throws NoSimilarWordFoundException {
    clearLists();
    generateSimilarWords();
    throw new NoSimilarWordFoundException();
  }

  private void generateSimilarWords() {

  }

  private void
}
