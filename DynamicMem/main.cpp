#include <stdio.h>
#include <stdlib.h>

struct Person {
	char* nimi;
};

void freeAll(Person* list, int* countPersons) {

	for (int i = 0; i < *countPersons; i++) {
		free((list + i)->nimi);
		(list + i)->nimi = NULL;
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

		while (index && lista[index]->nimi[0] < lista[index-1]->nimi[0]) 
		{
			temp = lista[index];
			lista[index] = lista[index - 1];
			lista[index - 1] = temp;
			index--;
		}
	}

	printf("\nSORTED LIST\n");
	for (int i = 0; i < *countPersons; i++)
		printf("%s", lista[i]->nimi);

	return;
}

void AllocateName(char* buffer, Person* list, int* countPersons) {

	int letter = 0;

	(list + *countPersons)->nimi = (char*)malloc(sizeof(char) * 100);

	while (buffer[letter] != '\0') {
		(list + *countPersons)->nimi[letter] = buffer[letter];
		letter++;
	}
	(list + *countPersons)->nimi[letter] = '\0';

	return;

}

int main() {

	Person* list;
	int countPersons = 0;
	char buffer[100];

	list = (Person*)malloc(sizeof(Person) * 1);

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
		printf("Name: %s", (list + i)->nimi);
	}

	SortByName(list, &countPersons);

	freeAll(list, &countPersons);

	return 0;

}