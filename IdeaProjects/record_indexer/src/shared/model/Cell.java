package shared.model;

/**
 * An individual cell in a batch.
 */
public class Cell {

  private int parent_id;
  private int field_id;
  String value;

  public Cell() {
    parent_id = -1;
    field_id = -1;
    value = null;
  }

  public Cell(int parent_id, int field_id, String value) {
    this.parent_id = parent_id;
    this.field_id = field_id;
    this.value = value;
  }

  public int getParent_id() {
    return parent_id;
  }

  public void setParent_id(int parent_id) {
    this.parent_id = parent_id;
  }

  public int getField_id() {
    return field_id;
  }

  public void setField_id(int field_id) {
    this.field_id = field_id;
  }

  public String getValue() {
    return value;
  }

  public void setValue(String value) {
    this.value = value;
  }

}
