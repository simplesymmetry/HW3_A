/*
 * mystring.c
 *
 * This is the mystring .c file.
 *  Created on: January 24, 2019
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
 * A function used to copy entire source to destination.
 * @param *destination The pointer to destination.
 * @param *source The pointer to the source.
 * @return temp_ptr to the newly copied string.
 */
char* mystrcpy(char* dest, char* src) {
	if (dest == NULL || src == NULL){
		return NULL;
	}

	char *temp_ptr = dest;
	while((*dest++ = *src++) != '\0'); // @suppress("Assignment in condition")

	return temp_ptr;
}

/**
 * A function used to copy a string with a given size.
 * @param *dest The pointer to destination.
 * @param *src The pointer to the source.
 * @param n The size of the string.
 */
char* mystrncpy(char* dest, char* src, size_t n) {
	if (dest == NULL){
		return NULL;
	}
	size_t temp = n;
	temp += 1;
	//First we save the pointer
	char *temp_ptr = dest;

	//Decrement n first then we set destination++ to src++, and loop.
	while(n-- && (*dest++ = *src++) && (*temp_ptr != '/0'));
	return temp_ptr;
}

/**
 * A function used to concat a string that has size passed with it..
 * @param *dest The pointer to destination.
 * @param *src The pointer to the source.
 * @param n Amount of bytes of
 * @return A char pointer to the dest of string.
 */
char* mystrncat(char* dest, char* src, size_t n) {
    size_t dest_len = strlen(dest);

    while (n-- && *src++ != '\0'){
    	dest[dest_len++] =*src++;
    	if (n==1){
    		*(dest + dest_len) = '\0';
    	}
    }
   return dest;
}


