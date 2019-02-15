/*
 ============================================================================
 Name        : HW3starter.c
 Author      : Tom Graham
 Version     : 0.0.1
 Copyright   : Your copyright notice
 Description : Homework 3: Pointer Fun.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"

int main(int argc, char* argv[]) {
	puts("!!!Hello classs, we are working HW3A!!!"); /* prints !!!Hello World!!! */
	if(tests())
	{
		puts("Tests succeeded.");
		if(production(argc, argv))
		{
			puts("Production successful.");
		}
		else
		{
			puts("Tests succeeded, but production didn't");
		}
	}
	else
	{
		puts("Tests did not succeed.");
	}

	return EXIT_SUCCESS;
}
