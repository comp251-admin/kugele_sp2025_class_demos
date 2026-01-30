#include "person.h"

/* person implementation */
person_t *person(char *name, char *address) {
  person_t *_this = malloc(sizeof(person_t));

  _this->name = strdup(name);
  _this->address = strdup(address);

  _this->get_name = person_get_name;
  _this->get_address = person_get_address;
  _this->free = person_free;

  return _this;
}

char *person_get_name(person_t *_this) { return _this->name; }
char *person_get_address(person_t *_this) { return _this->address; }

void person_free(person_t *_this) {
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
