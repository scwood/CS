package spell;

import java.io.IOException;

public class TestTrie {
  
  public static void main(String[] args) throws IOException {
    SpellCorrector spell = new SpellCorrector();
    SpellCorrector spell2 = new SpellCorrector();
    spell.useDictionary(args[0]);
    spell2.useDictionary(args[1]);
    if (spell2.dictionary.equals(spell.dictionary)) {
      System.out.println("equal");
    } else {
      System.out.println("NOT equal");
    }
  }

}
  