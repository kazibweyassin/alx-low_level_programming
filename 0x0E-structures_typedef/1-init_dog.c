#include <stdio.h>
#include "dog.h"

/**
 *init_dog - inialize a variable of type
 *@d: pointer to the structure
 *@name: dog's name
 *@age: dog's age
 *@owner: dog's owner
 *
 * Return: Always 0 (success)
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d)
	{
		d->name = name;
		d->age = age;
		d->owner = owner;
	}
}
