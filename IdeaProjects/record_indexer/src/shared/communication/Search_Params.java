package shared.communication;

import java.util.List;

/**
 * Parameters used by search requests.
 */
public class Search_Params extends ValidateUser_Params {

  private List<Integer> fields;
  private List<String> searchValues;

  public Search_Params() {
    super();
    fields = null;
    searchValues = null;
  }

  public Search_Params(String userName, String password, List<Integer> fields,
                       List<String> searchValues) {
    super(userName, password);
    this.fields = fields;
    this.searchValues = searchValues;
  }

  public List<Integer> getFields() {
    return fields;
  }

  public void setFields(List<Integer> fields) {
    this.fields = fields;
  }

  public List<String> getSearchValues() {
    return searchValues;
  }

  public void setSearchValues(List<String> searchValues) {
    this.searchValues = searchValues;
  }

  public void addField(int id) {
    if (fields != null) {
      fields.add(id);
    }
  }

  public void addSearchValue(String value) {
    if (searchValues != null) {
      searchValues.add(value);
    }
  }

}
