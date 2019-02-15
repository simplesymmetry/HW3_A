/** tests.h
 * This is the main testing header file. It will list the prototypes of the functions to be used in this program.
 *  Created on: February 12, 2019
 *      Author: Tom Graham
 */
#ifndef TESTS_H_
#define TESTS_H_

#include <stdbool.h>
#include "production.h"

//These are the function prototypes to be used in the test.c.
bool tests(void);
bool testMystrlen1(void);
bool testMystrlen2(void);
bool testMystrdup();
bool testMystrcpy();
bool testMystrncpy();
bool testMystrcpy();
bool testMystrncat();

#endif /* TESTS_H_ */
