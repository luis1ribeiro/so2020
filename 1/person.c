#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include <string.h>

Person new_person (char* name, int age){
  size_t n = strlen(name)+1;
  char* s = malloc (sizeof (char[n]));
  memcpy(s,name,n);
  return (Person){
    .nome=s,
    .idade=age,
  };
}

void person_change_age (Person *p, int age){
  p->idade=age;
}


