package shared.communication;

/**
 * Results of getFields requests.
 */
public class GetFields_Result {

  String fields;

  public GetFields_Result() {
    fields = null;
  }

  public GetFields_Result(String output) {
    this.fields = output;
  }

  public String getOutput() {
    return fields;
  }

  public void setOutput(String output) {
    this.fields = output;
  }

}
