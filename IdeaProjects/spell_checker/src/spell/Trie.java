package spell;

public class Trie implements ITrie {

  private Node root = new Node();
  private int nodeCount = 1;
  private int wordCount = 0;
  private final int ALPHABET_LENGTH = 26;

  // basics

  @Override
  public void add(String word) {
    Node currentNode = root;
    for (char c : word.toCharArray()) {
      int index = c - 'a';
      if (currentNode.alphabet[index] == null) {
        currentNode.alphabet[index] = new Node();
        nodeCount++;
      }
      currentNode = currentNode.alphabet[index];
    }
    if (currentNode.getValue() == 0) {
      wordCount++;
    }
    currentNode.incramentFrequency();
  }

  @Override
  public INode find(String word) {
    Node currentNode = root;
    for (char c : word.toCharArray()) {
      int index = c - 'a';
      if (currentNode.alphabet[index] == null) {
        return null;
      }
      currentNode = currentNode.alphabet[index];
    }
    if (currentNode.getValue() == 0) {
      return null;
    }
    return currentNode;
  }

  @Override
  public int getWordCount() {
    return wordCount;
  }

  @Override
  public int getNodeCount() {
    return nodeCount;
  }

  @Override
  public String toString() {
    StringBuilder result = new StringBuilder();
    StringBuilder currentWord = new StringBuilder();
    buildToString(root, currentWord, result);
    if (result.length() != 0) {
      result.setLength(result.length() - 1);
    }
    return result.toString();
  }

  private void buildToString(Node node, StringBuilder currentWord,
                             StringBuilder result) {
    if (node.getValue() != 0) {
      result.append(currentWord);
      result.append('\n');
    }
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
      if (node.alphabet[i] != null) {
        StringBuilder newCurrentWord = new StringBuilder(currentWord);
        newCurrentWord.append((char)('a' + i));
        buildToString(node.alphabet[i], newCurrentWord, result);
      }
    }
  }

  // equals/hash code

  @Override
  public boolean equals(Object o) {
    if (o == null) {
      return false;
    }
    if (o.getClass() != this.getClass()) {
      return false;
    }
    if (o == this) {
      return true;
    }
    Trie oTrie = (Trie)o;
    if (oTrie.nodeCount != this.nodeCount) {
      return false;
    }
    if (oTrie.wordCount != this.wordCount) {
      return false;
    }
    String thisFrequencies = this.frequenciesToString();
    String oFrequenices = oTrie.frequenciesToString();
    if (!thisFrequencies.equals(oFrequenices)) {
      return false;
    }
    return true;
  }

  private String frequenciesToString() {
    StringBuilder result = new StringBuilder();
    Node currentNode = root;
    buildFrequenciesToString(currentNode, result);
    return result.toString();
  }

  private void buildFrequenciesToString(Node node, StringBuilder result) {
    if (node.getValue() != 0) {
      result.append(node.getValue());
    }
    for (int i = 0; i < ALPHABET_LENGTH; i++) {
      if (node.alphabet[i] != null) {
        buildFrequenciesToString(node.alphabet[i], result);
      }
    }
  }

  @Override
  public int hashCode() {
    final int PRIME_NUMBER = 31;
    return (nodeCount + wordCount) * 31;
  }

  public class Node implements ITrie.INode {

    private int frequency = 0;
    private Node[] alphabet = new Node[26];

    @Override
    public int getValue() {
      return frequency;
    }

    public void incramentFrequency() {
      frequency++;
    }

  }

}
