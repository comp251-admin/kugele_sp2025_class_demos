struct studentT {
  char name[65];
  int age;
  float gpa;
  int grad_yr;
}

int main(void) {
  studentT student1, student2;

  strcpy(student1.name, "Kwame Salter"); // name field is a char array
  student1.age = 18 + 2;                 // age field is an int
  student1.gpa = 3.5;                    // gpa field is a float
  student1.grad_yr = 2020;               // grad_yr field is an int
