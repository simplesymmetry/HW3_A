/** mystring.h
 * This is the my string header file. It will be used to list the prototype of the functions
 * to be used in the actual file.
 *  Created on: February 12, 2019
 *      Author: Tom Graham
 */
#ifndef MYSTRING_H_
#define MYSTRING_H_
//has to be the same as strlen
#include <string.h>
//size_t strlen(const char* s);
size_t mystrlen1(const char* s);
size_t mystrlen2(const char* s);
char* mystrdup(char* s);
char* mystrcpy(char* dest, char* src);
char* mystrncpy(char* dest, char* src, size_t n);
char* mystrncat(char* dest, char* src, size_t n);

#endif /* MYSTRING_H_ */
