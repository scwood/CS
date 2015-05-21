package shared.model;

/**
 * A column in a batch.
 */
public class Field {

  private int id;
  private int parent_id;
  private String title;
  private int width;
  private int column_number;
  private int first_x_coord;

  public Field() {
    id = -1;
    parent_id = -1;
    title = null;
    width = -1;
    column_number = -1;
    first_x_coord = -1;
  }

  public Field(int id, int parent_id, String title, int width,
               int column_number, int first_x_coord) {
    this.id = id;
    this.parent_id = parent_id;
    this.title = title;
    this.width = width;
    this.column_number = column_number;
    this.first_x_coord = first_x_coord;
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

  public String getTitle() {
    return title;
  }

  public void setTitle(String title) {
    this.title = title;
  }

  public int getWidth() {
    return width;
  }

  public void setWidth(int width) {
    this.width = width;
  }

  public int getColumn_number() {
    return column_number;
  }

  public void setColumn_number(int column_number) {
    this.column_number = column_number;
  }

  public int getFirst_x_coord() {
    return first_x_coord;
  }

  public void setFirst_x_coord(int first_x_coord) {
    this.first_x_coord = first_x_coord;
  }

}
