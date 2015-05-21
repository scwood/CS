package shared.communication;

import java.util.List;

/**
 * Results of search requests.
 */
public class Search_Result {
  private List<Result> results;

  public Search_Result() {
    results = null;
  }

  public Search_Result(List<Result> results) {
    this.results = results;
  }

  public List<Result> getResults() {
    return results;
  }

  public void setResults(List<Result> results) {
    this.results = results;
  }

  /**
   * Individual results returned by search requests.
   */
  private class Result {

    private int batchId;
    private String imageUrl;
    private int recordNumber;
    private int fieldId;

    public Result() {
      batchId = -1;
      imageUrl = null;
      recordNumber = -1;
      fieldId = -1;
    }

    public Result(int batchId, String imageUrl, int recordNumber, int fieldId) {
      this.batchId = batchId;
      this.imageUrl = imageUrl;
      this.recordNumber = recordNumber;
      this.fieldId = fieldId;
    }

    public int getBatchId() {
      return batchId;
    }

    public void setBatchId(int batchId) {
      this.batchId = batchId;
    }

    public String getImageUrl() {
      return imageUrl;
    }

    public void setImageUrl(String imageUrl) {
      this.imageUrl = imageUrl;
    }

    public int getRecordNumber() {
      return recordNumber;
    }

    public void setRecordNumber(int recordNumber) {
      this.recordNumber = recordNumber;
    }

    public int getFieldId() {
      return fieldId;
    }

    public void setFieldId(int fieldId) {
      this.fieldId = fieldId;
    }

  }

}
