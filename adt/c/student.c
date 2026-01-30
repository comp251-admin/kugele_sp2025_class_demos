#include "student.h"

/* student implementation */
student_t *student(char *name, char *address, char *id, double gpa) {
  student_t *_this = malloc(sizeof(student_t));

  _this->name = strdup(name);
  _this->address = strdup(address);
  _this->id = id;
  _this->gpa = gpa;

  _this->get_name = student_get_name;
  _this->get_address = student_get_address;
  _this->get_id = student_get_id;
  _this->get_gpa = student_get_gpa;
  _this->free = student_free;

  return _this;
}

char *student_get_name(student_t *_this) { return _this->name; }
char *student_get_address(student_t *_this) { return _this->address; }
char *student_get_id(student_t *_this) { return _this->id; }
double student_get_gpa(student_t *_this) { return _this->gpa; }

void student_free(student_t *_this) {
  /* frees memory allocated in "constructor" using strdup */
  if (_this->name) {
    free(_this->name);
  }

  /* frees memory allocated in "constructor" using strdup */
  if (_this->address) {
    free(_this->address);
  }

  free(_this);
}
