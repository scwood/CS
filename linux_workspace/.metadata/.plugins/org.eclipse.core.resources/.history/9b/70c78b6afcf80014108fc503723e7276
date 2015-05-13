package spell;

import java.io.IOException;
import spell.ISpellCorrector.NoSimilarWordFoundException;

public class CorrectWord {
  
  public static void main(String[] args) {
    if (args.length < 2) {
      System.out.println("Usage: java spell.CorrectWord dictionary word");
      return;
    }
    String dictionaryFileName = args[0];
    String inputWord = args[0].toLowerCase();
    SpellCorrector corrector = new SpellCorrector();
    try {
      corrector.useDictionary(dictionaryFileName);
    } catch (IOException e) {
      System.err.println("Error: bad dictionary file");
      return;
    }
    String suggestion = null;
    try {
      suggestion = corrector.suggestSimilarWord(inputWord);
    } catch (NoSimilarWordFoundException e) {
      System.err.println("Error: no similar word found in dictionary");
      return;
    }
    System.out.println("Suggestions is: " + suggestion);
  }

}
