package shared.communication;

/**
 * Parameters for validateUser requests.
 */
public class ValidateUser_Params {

  String userName;
  String password;

  public ValidateUser_Params() {
    userName = null;
    password = null;
  }

  public ValidateUser_Params(String userName, String password) {
    this.userName = userName;
    this.password = password;
  }

  public String getUserName() {
    return userName;
  }

  public void setUserName(String userName) {
    this.userName = userName;
  }

  public String getPassword() {
    return password;
  }

  public void setPassword(String password) {

    this.password = password;
  }

}
