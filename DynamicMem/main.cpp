#include <stdio.h>
#include <stdlib.h>

struct Person {
	char* nimi = NULL;
};

void SortByName(Person* list, Person* lista) {

	return;
}

void AllocateName(char* buffer, Person* list, int* personCount) {

	int letter = 0;

	(list + *personCount)->nimi = (char*)malloc(sizeof(char) * 100);

	while (buffer[letter] != '\0') {
		(list + *personCount)->nimi[letter] = buffer[letter];
		letter++;
	}
	(list + *personCount)->nimi[letter] = '\0';

	return;

}

int main() {

	Person* list;
	int personCount = 0;
	char buffer[100];

	list = (Person*)malloc(sizeof(Person) * 1);

	while (1) {

		printf("Insert name: ");
		fgets(buffer, 99, stdin);

		if (buffer[0] == '\n')
			break;

		if (personCount > 0) {
			list = (Person*)realloc(list, sizeof(Person) * (personCount + 1));

		}
		AllocateName(buffer, list, &personCount);
		personCount++;

	}

	printf("TALLENNETUT HENKILOT\n");
	for (int i = 0; i < personCount; i++) {
		printf("Name: %s", (list + i)->nimi);
	}

	Person* sortList;
	sortList = (Person*)malloc(sizeof(Person) * personCount);

	SortByName(list, sortList);

	return 0;

}