public class Main {
  public static void main(String[] args) {
    Student student = new StudentImpl("John Doe", "456 Elm St.", "987654321", 3.75);

    System.out.println("name: " + student.getName());
    System.out.println("address: " + student.getAddress());
    System.out.println("id: " + student.getId());
    System.out.println("gpa: " + student.getGpa());

    Person person = student;

    System.out.println("name: " + person.getName());
    System.out.println("address: " + person.getAddress());
  }
}
