package client.communication;

import shared.communication.*;

/**
 * Object that contains methods client needs to communicate with the server.
 */
public class ClientCommunicator {

  /**
   * Checks for valid user credentials.
   * @param params User information.
   * @return Whether or not the user was validated, as well as the first and
   * last name, and how many records the user has indexed.
   */
  public ValidateUser_Result validateUser(ValidateUser_Params params) {
    ValidateUser_Result result = new ValidateUser_Result();
    return result;
  }

  /**
   * Returns information about all of the available projects.
   * @param params User information.
   * @return Information about all available projects.
   */
  public GetProjects_Result getProjects(GetProjects_Params params) {
    GetProjects_Result result = new GetProjects_Result();
    return result;
  }

  /**
   * Gets a sample image from a specified project.
   * @param params User information and project id.
   * @return A URL to a sample image.
   */
  public GetSampleImage_Result getSampleImage(GetSampleImage_Params params) {
    GetSampleImage_Result result = new GetSampleImage_Result();
    return result;
  }

  /**
   * Downloads a batch from a specified project.
   * @param params User information and project id.
   * @return A batch object.
   */
  public DownloadBatch_Result downloadBatch(DownloadBatch_Params params) {
    DownloadBatch_Result result = new DownloadBatch_Result();
    return result;
  }

  /**
   * Submits the indexed record field values for a batch to the server.
   * @param params User information, batch id, and field values.
   * @return
   */
  public boolean submitBatch(SubmitBatch_Params params) {
    return false;
  }

  /**
   * Returns information about all of the fields for the specified
   * project or all projects if not specified.
   * @param params User information and project id.
   * @return Information about the fields.
   */
  public GetFields_Result getFields(GetFields_Params params) {
    GetFields_Result result = new GetFields_Result();
    return result;
  }

  /**
   * Searches the indexed records for the specified strings.
   * @param params A list of fields to search and a list of search values to
   *               search for.
   * @return A list of search results.
   */
  public Search_Result search(Search_Params params) {
    Search_Result result = new Search_Result();
    return result;
  }

  /**
   * Downloads a file from the server.
   * @param url URL of file to be downloaded.
   * @return The bytes of the file.
   */
  public String downloadFile(String url) {
    return null;
  }

}
