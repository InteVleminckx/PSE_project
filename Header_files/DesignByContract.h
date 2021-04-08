/*
 * korte beschrijving:
 * @author: Vleminckx Inte en Karnaukh Maksim
 * @date:
 * @version: Specificatie 1.0
*/

#ifndef PROJECT_SOFTWARE_ENGENEERING_DESIGNBYCONTRACT_H
#define PROJECT_SOFTWARE_ENGENEERING_DESIGNBYCONTRACT_H


#include <assert.h>

#define REQUIRE(assertion, what) \
	if (!(assertion)) __assert (what, __FILE__, __LINE__)

#define ENSURE(assertion, what) \
	if (!(assertion)) __assert (what, __FILE__, __LINE__)


#endif //PROJECT_SOFTWARE_ENGENEERING_DESIGNBYCONTRACT_H // niet nodig?
