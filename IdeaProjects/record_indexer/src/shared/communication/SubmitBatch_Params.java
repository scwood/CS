package shared.communication;

/**
 * Parameters used by submitBatch requests.
 */
public class SubmitBatch_Params extends ValidateUser_Params {

  private int batchId;
  private String fieldValues;

  public SubmitBatch_Params() {
    batchId = -1;
    fieldValues = null;
  }

  public SubmitBatch_Params(String userName, String password, int batchId,
                            String fieldValues) {
    super(userName, password);
    this.batchId = batchId;
    this.fieldValues = fieldValues;
  }

  public int getBatchId() {
    return batchId;
  }

  public void setBatchId(int batchId) {
    this.batchId = batchId;
  }

  public String getFieldValues() {
    return fieldValues;
  }

  public void setFieldValues(String fieldValues) {
    this.fieldValues = fieldValues;
  }

}
