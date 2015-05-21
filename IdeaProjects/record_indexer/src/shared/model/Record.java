package shared.model;

/**
 * A collection of related field values.
 */
public class Record {

  private int id;
  private int parent_id;
  private int row_number;

  public Record() {
    id = -1;
    parent_id = -1;
    row_number = -1;
  }

  public Record(int id, int parent_id, int row_number) {
    this.id = id;
    this.parent_id = parent_id;
    this.row_number = row_number;
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

  public int getRow_number() {
    return row_number;
  }

  public void setRow_number(int row_number) {
    this.row_number = row_number;
  }

}