package spell;

import java.io.IOException;

/**
 * Created by spencer on 5/15/15.
 */
public class TestTrie {
  public static void main(String[] args) throws IOException {
    String file = args[0];
    SpellCorrector spell = new SpellCorrector();
    spell.useDictionary(file);
    System.out.println(spell.dictionary.toString());
  }
}
