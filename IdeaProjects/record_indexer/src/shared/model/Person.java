package shared.model;

/**
 * Stores login information and personal details for users.
 */
public class Person {

  private int id;
  private String user_name;
  private String password;
  private String first_name;
  private String last_name;
  private String email;
  private int number_indexed;
  private int current_batch_id;

  public Person() {
    id = -1;
    user_name = null;
    password = null;
    first_name = null;
    last_name = null;
    email = null;
    number_indexed = 0;
    current_batch_id = -1;
  }

  public Person(int id, String user_name, String password, String first_name,
                String last_name, String email) {
    this.id = id;
    this.user_name = user_name;
    this.password = password;
    this.first_name = first_name;
    this.last_name = last_name;
    this.email = email;
    this.number_indexed = 0;
    this.current_batch_id = -1;
  }

  public int getId() {
    return id;
  }

  public void setId(int id) {
    this.id = id;
  }

  public String getUser_name() {
    return user_name;
  }

  public void setUser_name(String user_name) {
    this.user_name = user_name;
  }

  public String getPassword() {
    return password;
  }

  public void setPassword(String password) {
    this.password = password;
  }

  public String getFirst_name() {
    return first_name;
  }

  public void setFirst_name(String first_name) {
    this.first_name = first_name;
  }

  public String getLast_name() {
    return last_name;
  }

  public void setLast_name(String last_name) {
    this.last_name = last_name;
  }

  public String getEmail() {
    return email;
  }

  public void setEmail(String email) {
    this.email = email;
  }

  public int getNumber_indexed() {
    return number_indexed;
  }

  public void setNumber_indexed(int number_indexed) {
    this.number_indexed = number_indexed;
  }

  public int getCurrent_batch_id() {
    return current_batch_id;
  }

  public void setCurrent_batch_id(int current_batch_id) {
    this.current_batch_id = current_batch_id;
  }
}
