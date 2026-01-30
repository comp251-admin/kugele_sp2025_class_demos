public class StudentImpl extends PersonImpl implements Student {
  private final String id;
  private final double gpa;

  public StudentImpl(String name, String address, String id, double gpa) {
    super(name, address);

    this.id = id;
    this.gpa = gpa;
  }

  @Override
  public String getId() {
    return id;
  }

  @Override
  public double getGpa() {
    return gpa;
  }
}
