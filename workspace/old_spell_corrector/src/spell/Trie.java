package spell;

import java.util.ArrayList;

public class Trie implements ITrie {

  private Node root = new Node();
  private int nodeCount = 1; // root counts as a node
  private int wordCount = 0;
  private ArrayList<Node> nodeList = new ArrayList<Node>();

  /**
   * Adds the specified word to the trie (if necessary) and increments the
   * word's value 
   * @param word The word being added to the trie
   */
  public void add(String word) {
    word = word.toLowerCase();
    Node currentNode = root;
    for (char c : word.toCharArray()) {
      int index = c - 'a';
      if (currentNode.nodes[index] == null) {
        currentNode.nodes[index] = new Node();
        nodeList.add(currentNode);
        nodeCount++;
        currentNode.nodes[index].parent = currentNode;
      }
      currentNode = currentNode.nodes[index];
    }
    if (currentNode.value == 0) {
      wordCount++;
    }
    currentNode.incramentValue();
  }

  /**
   * Searches the trie for the specified word
   * @param word The word being seared for
   * @return A reference to the trie node that represents the word or null if
   * the word is not in the trie
   */
  public ITrie.INode find(String word) { 
    word = word.toLowerCase();
    Node currentNode = root;
    for (char c : word.toCharArray()) {
      int index = c - 'a';
      if (currentNode.nodes[index] == null) {
        return null;
      }
      currentNode = currentNode.nodes[index];
    }
    if (currentNode.value == 0) {
      return null;
    }
    return currentNode;
  }

  /**
   * Builds a StringBuilder object of the trie
   * @return A string of format <word>\n (the last \n is omitted)
   */
	@Override
	public String toString() {
    StringBuilder currentWord = new StringBuilder();
    StringBuilder result = new StringBuilder();
    preOrderTraversal(root, currentWord, result); 
    if (result.length() > 0) {
      result.setLength(result.length() - 1); // removes extra new line character
    }
    return result.toString();
  }
	
  /**
   * Performs a pre-order traversal of the trie and builds a StringBuilder
   * object passed in by reference
   * @param node The current node being traversed
   * @param currentWord The current word built by the position in the trie
   * @param result The StringBuilder object being modified
   */
  private void preOrderTraversal(Node node, StringBuilder currentWord,
        StringBuilder result) {
    if (node.value != 0) {
      result.append(currentWord);
      result.append(" ");
      result.append(node.value);
      result.append('\n');
    }
    for (int i = 0; i < node.nodes.length; i++) {
      if (node.nodes[i] != null) {
        StringBuilder nextCurrentWord = new StringBuilder(currentWord);
        char c = (char)('a' + i);
        nextCurrentWord.append(c);
        preOrderTraversal(node.nodes[i], nextCurrentWord, result);
      }
    }
  }

// ------------------------------------------------------------

  /**
   * Builds a StringBuilder object of the trie
   * @return A string of format <word>\n (the last \n is omitted)
   */
	public String toStringValues() {
    StringBuilder currentWord = new StringBuilder();
    StringBuilder result = new StringBuilder();
    preOrderTraversalValues(root, currentWord, result); 
    if (result.length() > 0) {
      result.setLength(result.length() - 1); // removes extra new line character
    }
    return result.toString();
  }
	
  /**
   * Performs a pre-order traversal of the trie and builds a StringBuilder
   * object passed in by reference
   * @param node The current node being traversed
   * @param currentWord The current word built by the position in the trie
   * @param result The StringBuilder object being modified
   */
  private void preOrderTraversalValues(Node node, StringBuilder currentWord,
        StringBuilder result) {
    if (node.value != 0) {
      result.append(node.value);
      result.append('\n');
    }
    for (int i = 0; i < node.nodes.length; i++) {
      if (node.nodes[i] != null) {
        StringBuilder nextCurrentWord = new StringBuilder(currentWord);
        char c = (char)('a' + i);
        nextCurrentWord.append(c);
        preOrderTraversalValues(node.nodes[i], nextCurrentWord, result);
      }
    }
  }


// ------------------------------------------------------------

  /** Checks for equality through wordCount and nodeCount, and if equal,
    * iterates through the trie to check node equality.
    */
	@Override
	public boolean equals(Object other) {
    if (other == null) {
      return false;
    }
    if (other.getClass() != this.getClass()) {
      return false;
    }
    if (other == this) {
      return true;
    }
    Trie otherTrie = (Trie)other;
    if (otherTrie.nodeCount != this.nodeCount) {
      return false;
    }
    if (otherTrie.wordCount != this.wordCount) {
      return false;
    }
    String one = this.toStringValues();
    String two = otherTrie.toStringValues();
    if (one.equals(two)) {
      return true;
    }
    return false;
  }

  private boolean trieCompare(Node original, Node other) {
    for (int i = 0; i < original.nodes.length; i++) {
      // are nodes equal?
      if (!original.equals(other)) {
        return false;
      }
      // are either null when the other isn't?
      if ((original.nodes[i] == null && other.nodes[i] != null) || 
          (original.nodes[i] != null && other.nodes[i] == null)) {
        return false;
      }
      // if they're both not null, do the recursive call
      if (original.nodes[i] != null && other.nodes[i] != null) {
        return trieCompare(original.nodes[i], other.nodes[i]);
      }
    }
    return true;
  }

	@Override
	public int hashCode() {
    final int PRIME_NUMBER = 31;
    return (nodeCount + wordCount) * PRIME_NUMBER;
  }
	
	public int getWordCount() {
    return wordCount;
  }

	public int getNodeCount() {
    return nodeCount;
  }

  public class Node implements ITrie.INode {

    private Node parent = null;
    private Node[] nodes = new Node[26];
    private int value = 0;

		public int getValue() {
      return value;
    }

    public void incramentValue() {
      value++;
    }

    public Node getParent() { 
      return parent;
    }

    public void setParent(Node parent) { 
      this.parent = parent;
    }

    @Override
    public boolean equals(Object other) {
      if (other == null) {
        return false;
      }
      if (other.getClass() != this.getClass()) {
        return false;
      }
      if (other == this) {
        return true;
      }
      Node otherNode = (Node)other;
      if (otherNode.value != this.value) {
        return false;
      }
      return true;
    }

    @Override 
    public int hashCode() {
      final int PRIME_NUMBER = 31;
      return value * PRIME_NUMBER;
    }

  }

}