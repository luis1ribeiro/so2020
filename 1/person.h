
#define FILENAME "file_pessoas"

typedef struct Person{
  char name[200];
  int age;
} Person;

int new_person(char* name, int age);
int person_change_age(char* name, int age);
int person_change_agev2(char* name, int age);
