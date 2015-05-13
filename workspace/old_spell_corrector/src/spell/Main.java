package spell;

import java.io.IOException;
import spell.ISpellCorrector.NoSimilarWordFoundException;

public class Main {

  public static void main(String[] args) throws NoSimilarWordFoundException,
         IOException {
    if (args.length < 2) {
      System.out.println("error: missing arguments");
      return;
    }
    String dictionaryFileName = args[0];
    String inputWord = args[1];
    inputWord = inputWord.toLowerCase();
    SpellCorrector corrector = new SpellCorrector();
    corrector.useDictionary(dictionaryFileName);
    String suggestion = corrector.suggestSimilarWord(inputWord);
    System.out.println("Suggestion is: " + suggestion);
  }

}
