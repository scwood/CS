package shared.model;

/**
 * A collection batches.
 */
public class Project {

  private int id;
  private String title;
  private String records_per_image;
  private int first_y_coord;
  private int record_height;

  public Project() {
    id = -1;
    title = null;
    records_per_image = null;
    first_y_coord = -1;
    record_height = -1;
  }

  public Project(int id, String title, String records_per_image,
                 int first_y_coord, int record_height) {
    this.id = id;
    this.title = title;
    this.records_per_image = records_per_image;
    this.first_y_coord = first_y_coord;
    this.record_height = record_height;
  }

  public int getId() {
    return id;
  }

  public void setId(int id) {
    this.id = id;
  }

  public String getTitle() {
    return title;
  }

  public void setTitle(String title) {
    this.title = title;
  }

  public String getRecords_per_image() {
    return records_per_image;
  }

  public void setRecords_per_image(String records_per_image) {
    this.records_per_image = records_per_image;
  }

  public int getFirst_y_coord() {
    return first_y_coord;
  }

  public void setFirst_y_coord(int first_y_coord) {
    this.first_y_coord = first_y_coord;
  }

  public int getRecord_height() {
    return record_height;
  }

  public void setRecord_height(int record_height) {
    this.record_height = record_height;
  }

}
