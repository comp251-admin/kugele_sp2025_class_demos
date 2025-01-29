#include <stdio.h>
#include <string.h>

struct studentT {
    char name[65];
    int age;
    float gpa;
    int grad_yr;
};

// WARNING: passing structs by value is inefficient! (pass by value = full copy of memory)
void display_student(struct studentT s) {
	/* Note: printf doesn't have a format placeholder for printing a
	 * struct studentT (a type we defined).  Instead, we'll need to
	 * individually pass each field to printf. */
	printf("name: %s age: %d gpa: %g, year: %d\n", s.name, s.age, s.gpa, s.grad_yr);
}

// question: will this work?
void hack_gpa(struct studentT student) {
	student.gpa = 4.0;
}

int main(void) {
  struct studentT student1, student2;

	strcpy(student1.name, "Kwame Salter");  // name field is a char array
	student1.age = 18 + 2;                  // age field is an int
	student1.gpa = 3.5;                     // gpa field is a float
	student1.grad_yr = 2020;                // grad_yr field is an int

  display_student(student1);

	/* Copy all the field values of student1 into student2. */
	student2 = student1;


	/* Make a few changes to the student2 variable. */
	strcpy(student2.name, "Frances Allen");
	student2.grad_yr = student1.grad_yr + 1;

	/* Print the fields of student2. */
	printf("sizeof(name): %lu sizeof(age): %lu sizeof(gpa): %lu, sizeof(year): %lu\n",
				 sizeof(student1.name), sizeof(student1.age), sizeof(student1.gpa), 
				 sizeof(student1.grad_yr));

	printf("sizeof(struct studentT): %lu\n", sizeof(struct studentT));

  // question: what will happen here?
  puts("before gpa hack:");
  display_student(student2);

  hack_gpa(student2);

  puts("after gpa hack:");
  display_student(student2);

	return 0;
}
