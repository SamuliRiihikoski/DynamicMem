#include <stdio.h>
#include <stdlib.h>

struct Person {
	char* name;
};

void freeHeap(Person* list, int* countPersons) {

	for (int i = 0; i < *countPersons; i++) {
		free((list + i)->name);
		(list + i)->name = NULL;
	}

	free(list);
	list = NULL;
}

void SortByName(Person* list, int* countPersons) {

	Person** lista = (Person**)malloc(sizeof(Person*) * (*countPersons));
	int index = 0;
	Person* temp = NULL;

	for (int i = 0; i < *countPersons; i++)
	{	
		index = i;
		lista[i] = (list + i);

		while (index && lista[index]->name[0] < lista[index-1]->name[0]) 
		{
			temp = lista[index];
			lista[index] = lista[index - 1];
			lista[index - 1] = temp;
			index--;
		}
	}

	printf("\nSORTED LIST\n");
	for (int i = 0; i < *countPersons; i++)
		printf("%s", lista[i]->name);

	return;
}

void AllocateName(char* buffer, Person* list, int* countPersons) {

	int letter = 0;

	(list + *countPersons)->name = (char*)malloc(sizeof(char) * 100);

	while (buffer[letter] != '\0') {
		(list + *countPersons)->name[letter] = buffer[letter];
		letter++;
	}
	(list + *countPersons)->name[letter] = '\0';

	return;

}

int main() {

	Person* list;
	int countPersons = 0;
	char buffer[100];

	list = (Person*)malloc(sizeof(Person) * 1);
	printf("Empty line ends program. \n");
	while (1) {

		printf("Insert name: ");
		fgets(buffer, 99, stdin);

		if (buffer[0] == '\n')
			break;

		if (countPersons > 0) {
			list = (Person*)realloc(list, sizeof(Person) * (countPersons + 1));

		}
		AllocateName(buffer, list, &countPersons);
		countPersons++;

	}

	printf("\nSAVED PROFILES\n");
	for (int i = 0; i < countPersons; i++) {
		printf("Name: %s", (list + i)->name);
	}

	SortByName(list, &countPersons);

	freeHeap(list, &countPersons);

	return 0;

}
