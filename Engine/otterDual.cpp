#include "otterDual.h"

namespace otterMath {
	//constructors
	otterDual::otterDual() :
		real(0.0f),
		dual(0.0f) {};
	otterDual::otterDual(float _real, float _dual) :
		real(_real),
		dual(_dual) {};
	
	//destructor
	otterDual::~otterDual() {};

	//copy constructors
	otterDual::otterDual(const otterDual& d) :
		real(d.real),
		dual(d.dual) {};
	otterDual& otterDual::operator=(const otterDual& d) {
		real = d.real;
		dual = d.dual;
		return *this;
	}

	//dual addition
	void otterDual::operator+=(const otterDual& d) {
		real += d.real;
		dual += d.dual;
	}
	otterDual otterDual::operator+(const otterDual& d) {
		return otterDual(real + d.real, dual + d.dual);
	}
}