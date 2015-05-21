package shared.communication;

/**
 * Results of getSampleImage requests.
 */
public class GetSampleImage_Result {

  private String url;

  public GetSampleImage_Result() {
    url = null;
  }

  public GetSampleImage_Result(String url) {
    this.url = url;
  }

  public String getUrl() {
    return url;
  }

  public void setUrl(String url) {
    this.url = url;
  }

}
