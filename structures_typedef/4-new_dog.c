#include "dog.h"
#include <stdio.h>


/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to the new dog, or NULL if it fails
 */

dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(dog_t));

	if (d == NULL)

		return (NULL);

	d->name = malloc(strlen(name) + 1);

	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc(strlen(owner) + 1);

	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	strcpy(d->name, name);
	d->age = age;
	strcpy(d->owner, owner);
	return (d);
}
