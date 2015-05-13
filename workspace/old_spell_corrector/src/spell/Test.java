package spell;
import java.io.IOException;

public class Test {
  public static void main(String[] args) throws IOException {
    SpellCorrector one = new SpellCorrector();
    SpellCorrector two = new SpellCorrector();
    one.useDictionary(args[0]);
    two.useDictionary(args[1]);
    System.out.println("\nONE\n\n" + one.toString());
    System.out.println("\nTWO\n\n" + two.toString());
    System.out.println();
    one.checkDictEquality(two);
    System.out.println();
  }
}
