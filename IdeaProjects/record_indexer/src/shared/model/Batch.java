package shared.model;

/**
 * An image of records.
 */
public class Batch {

  private int id;
  private int parent_id;
  private String path;
  private boolean available;

  public Batch() {
    id = -1;
    parent_id = -1;
    path = null;
    available = true;
  }

  public Batch(int id, int parent_id, String path) {
    this.id = id;
    this.parent_id = parent_id;
    this.path = path;
  }

  public int getId() {
    return id;
  }

  public void setId(int id) {
    this.id = id;
  }

  public int getParent_id() {
    return parent_id;
  }

  public void setParent_id(int parent_id) {
    this.parent_id = parent_id;
  }

  public String getPath() {
    return path;
  }

  public void setPath(String path) {
    this.path = path;
  }

  public boolean isAvailable() {
    return available;
  }

  public void setAvailable(boolean available) {
    this.available = available;
  }
}
