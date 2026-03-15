#include "dog.h"
#include <stdio.h>

/**
 * free_dog - frees a dog
 * @d: dog to free
 */

void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->name);
		free(d->owner);
		free(d);
	}
}
