package shared.communication;

/**
 * Parameters for getSampleImage requests.
 */
public class GetSampleImage_Params extends ValidateUser_Params {

  private int projectId;

  public GetSampleImage_Params() {
    super();
    projectId = -1;
  }

  public GetSampleImage_Params(String userName, String password,
                               int projectId) {
    super(userName, password);
    this.projectId = projectId;
  }

  public int getProjectId() {
    return projectId;
  }

  public void setProjectId(int projectId) {
    this.projectId = projectId;
  }
}
