//
// Created by Maksim Karnaukh on 10/03/2021.
//

#ifndef PROJECT_SOFTWARE_ENGENEERING_DESIGNBYCONTRACT_H // niet nodig?
#define PROJECT_SOFTWARE_ENGENEERING_DESIGNBYCONTRACT_H // niet nodig?


#include <assert.h>

#define REQUIRE(assertion, what) \
	if (!(assertion)) __assert (what, __FILE__, __LINE__)

#define ENSURE(assertion, what) \
	if (!(assertion)) __assert (what, __FILE__, __LINE__)


#endif //PROJECT_SOFTWARE_ENGENEERING_DESIGNBYCONTRACT_H // niet nodig?
