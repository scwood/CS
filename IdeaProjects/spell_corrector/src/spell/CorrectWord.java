package spell;

import java.io.IOException;

import spell.ISpellCorrector.NoSimilarWordFoundException;

public class CorrectWord {
  
  public static void main(String[] args) throws IOException, NoSimilarWordFoundException {
    String dict = args[0];
    String word = args[1];
    SpellCorrector spell = new SpellCorrector();
    spell.useDictionary(dict);
    System.out.println("Suggestion is " + spell.suggestSimilarWord(word));
  }

}
