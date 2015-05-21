package shared.communication;

import shared.model.Project;

import java.util.ArrayList;
import java.util.List;

/**
 * Results of a get projects request.
 */
public class GetProjects_Result {

  List<Project> projects;

  public GetProjects_Result() {
    projects = new ArrayList<Project>();
  }

  public GetProjects_Result(List<Project> projects) {
    this.projects = projects;
  }

  public List<Project> getProjects() {
    return projects;
  }

  public void setProjects(List<Project> projects) {
    this.projects = projects;
  }
}
