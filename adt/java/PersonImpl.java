public class PersonImpl implements Person {
  private final String name;
  private final String address;

  public PersonImpl(String name, String address) {
    this.name = name;
    this.address = address;
  }

  @Override
  public String getName() {
    return name;
  }

  @Override
  public String getAddress() {
    return address;
  }
}
