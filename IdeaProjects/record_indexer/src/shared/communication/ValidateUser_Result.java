package shared.communication;

/**
 * Results of validateUser requests.
 */
public class ValidateUser_Result {

  boolean validated;
  String firstName;
  String lastName;
  int recordsIndexed;

  public ValidateUser_Result() {
    validated = false;
    firstName = null;
    lastName = null;
    recordsIndexed = -1;
  }

  public ValidateUser_Result(boolean validated, String firstName,
                             String lastName, int recordsIndexed) {
    this.validated = validated;
    this.firstName = firstName;
    this.lastName = lastName;
    this.recordsIndexed = recordsIndexed;
  }

  public boolean isValidated() {
    return validated;
  }

  public void setValidated(boolean validated) {
    this.validated = validated;
  }

  public String getFirstName() {
    return firstName;
  }

  public void setFirstName(String firstName) {
    this.firstName = firstName;
  }

  public String getLastName() {
    return lastName;
  }

  public void setLastName(String lastName) {
    this.lastName = lastName;
  }

  public int getRecordsIndexed() {
    return recordsIndexed;
  }

  public void setRecordsIndexed(int recordsIndexed) {
    this.recordsIndexed = recordsIndexed;
  }
}
