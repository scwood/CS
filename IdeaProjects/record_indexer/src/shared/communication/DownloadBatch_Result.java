package shared.communication;

import shared.model.Batch;

/**
 * Results for downloadBatch requests.
 */
public class DownloadBatch_Result {

  private Batch batch;

  public DownloadBatch_Result() {
    batch = null;
  }

  public DownloadBatch_Result(Batch batch) {
    this.batch = batch;
  }

  public Batch getBatch() {
    return batch;
  }

  public void setBatch(Batch batch) {
    this.batch = batch;
  }

}
