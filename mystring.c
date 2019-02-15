/** mystring.c
 * This is the my string c file. It will be used to implement the c functions.
 * Theses implementations are meant to use special rules, no array brackets and
 * no dereference increments.
 *  Created on: February 12, 2019
 *      Author: Tom Graham
 */
#include <stdlib.h>
#include "mystring.h"

/**
 * Calculate the length of the string,
 * excluding the terminating null byte ('\0')
 * @param  *s A const char to count the length of.
 * @return The number of characters in the string pointed to by s.
 */
size_t mystrlen1(const char* s)
{
	size_t n = 0;

	// Step through the array, counting up until we find the null terminator
	while (s[n] != '\0') {
		n++;
	}

	return n;
}

/**
 * This is a function used to calculate the length of the string excluding the
 * terminating null byte ('\0').
 * @param *s A const char to count the length of.
 * @return The number of characters in the string pointed to by s.
 */
size_t mystrlen2(const char* s)
{
	size_t n = 0;

	// Keep incrementing the pointer until we find it is pointing to the null terminator
	while (*s != '\0') {
		n++;
		s++;
	}

	/* Note: This could have been written as:
	 while (*(s++)) n++;
	 */

	return n;
}

/**
 * Duplicates a character string into a freshly-allocated block of memory.
 * @param s The string to duplicate.
 * @return Pointer to the new string.
 *         NULL if unable to allocate memory, errno holds the error code.
 */
char* mystrdup(char* s) {
	size_t length = strlen(s); // Length of the original string

	// Allocate a block of memory big enough to hold all the characters of the original string,
	// plus the null terminator.
	char* newstr = (char*) malloc(length + 1);
	if (newstr) { // If allocation succeeded, copy into it
		strcpy(newstr, s);
	}
	return newstr;
}

/**
 * A function used to copy the source string to the destinations string.
 * This includes the \0 terminator.
 * @param destination The pointer to destination.
 * @param source The pointer to the source.
 * @return temp_ptr This is the saved destination string to safely return to.
 */
char* mystrcpy(char* dest, char* src) {
	char *temp_ptr = dest;
	while(*dest++ = *src++);// @suppress("Assignment in condition")
	return temp_ptr;
}

/**
 * A function used to copy a string with a given size.
 * The difference here is that strncpy will copy n chars from source
 * to the destination.
 * @param dest A pointer to destination string.
 * @param src A pointer to the source, the data to copy.
 * @param n The size of the data to copy.
 * @return temp_ptr This is the saved destination string to safely return to.
 */
char* mystrncpy(char* dest, char* src, size_t n) {
	char *temp_ptr = dest;
	n += mystrlen1(dest);
	while (n-- && *src){
		*dest++ = *src++;
	}
	return temp_ptr;
}

/**
 * A function used to concatenate two parts of strings together. Copy up to n bytes.
 * @param dest The pointer to destination char.
 * @param src The pointer to the source char.
 * @param n Amount of data to copy
 * @return A char pointer to the destination of the string.
 */
char* mystrncat(char* dest, char* src, size_t n){
	char *temp = dest;
	dest += mystrlen1(dest);
	while (*src && n--){
		*dest++ = *src++;
	}
	*dest = '\0';
	return temp;
}
