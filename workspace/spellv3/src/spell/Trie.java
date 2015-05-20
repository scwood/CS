package spell;

public class Trie implements ITrie {
  
  int nodeCount = 1;
  int wordCount = 0;
  Node root = new Node();
  
  // insertion/finding

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
    if (currentNode.getFrequency() == 0) {
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
    if (currentNode.getFrequency() == 0) {
      return null;
    }
    return currentNode;
  }
  
  // toString
  
  @Override
  public String toString() {
    StringBuilder result = new StringBuilder();
    StringBuilder currentWord = new StringBuilder();
    buildToString(root, currentWord, result);
    if (result.length() > 0) {
      result.setLength(result.length() - 1);;
    }
    return result.toString();
  }
  
  private void buildToString(Node node, StringBuilder currentWord, 
                             StringBuilder result) {
    if (node.getFrequency() > 0) {
      result.append(currentWord);
      result.append('\n');
    }
    for (int i = 0; i < node.alphabet.length; i++) {
      if (node.alphabet[i] != null) {
        char c = (char)('a' + i);
        StringBuilder newCurrentWord = new StringBuilder(currentWord);
        newCurrentWord.append(c);
        buildToString(node.alphabet[i], newCurrentWord, result);
      }
    }
  }
  
  // equals
  
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
    if (!this.frequenciesToString().equals(oTrie.frequenciesToString())) {
      return false;
    }
    return true;
  }
  
  private String frequenciesToString() {
    StringBuilder result = new StringBuilder();
    buildFrequenciesToString(root, result);
    return result.toString();
  }
  
  private void buildFrequenciesToString(Node node, StringBuilder result) {
    if (node.getFrequency() != 0) {
      result.append(node.getFrequency());
    }
    for (int i = 0; i < node.alphabet.length; i++) {
      if (node.alphabet[i] != null) {
        buildFrequenciesToString(node.alphabet[i], result);
      }
    }
  }
  
  // basics
  
  @Override
  public int hashCode() {
    final int PRIME_NUMBER = 31;
    return (nodeCount + wordCount) * PRIME_NUMBER;
  }

  @Override
  public int getWordCount() {
    return wordCount;
  }
  
  @Override
  public int getNodeCount() {
    return nodeCount;
  }

  public class Node implements ITrie.INode {
    
    private Node[] alphabet = new Node[26];
    private int frequency = 0;

    @Override
    public int getValue() {
      return frequency;
    }
    
    public int getFrequency() {
      return frequency;
    }
    
    public void incramentFrequency() {
      frequency++;
    }
    
  }
  
}
