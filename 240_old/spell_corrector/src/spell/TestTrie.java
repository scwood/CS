package spell;

import java.io.IOException;

public class TestTrie {
  
  public static void main(String[] args) throws IOException {
    SpellCorrector one = new SpellCorrector();
    one.useDictionary(args[0]);
    SpellCorrector two = new SpellCorrector();
    two.useDictionary(args[1]);
    if (one.dictionary.equals(two.dictionary)) {
      System.out.println("equal");
    } else {
      System.out.println("NOT equal");
    }
  }

}
