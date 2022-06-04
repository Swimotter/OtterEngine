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

	//dual subtraction
	void otterDual::operator-=(const otterDual& d) {
		real -= d.real;
		dual -= d.dual;
	}
	otterDual otterDual::operator-(const otterDual& d) {
		return otterDual(real - d.real, dual - d.dual);
	}

	//scalar multiplication
	void otterDual::operator*=(float s) {
		real *= s;
		dual *= s;
	}
	otterDual otterDual::operator*(float s) {
		return otterDual(real * s, dual * s);
	}

	//dual multiplication
	void otterDual::operator*=(const otterDual& d) {
		real *= d.real;
		dual = real * d.dual + d.real * dual;
	}
	otterDual otterDual::operator*(const otterDual& d) {
		return otterDual(real * d.real, real * d.dual + d.real * dual);
	}

	//scalar division
	void otterDual::operator/=(float s) {
		real /= s;
		dual /= s;
	}
	otterDual otterDual::operator/(float s) {
		return otterDual(real / s, dual / s);
	}

	//dual division
	void otterDual::operator/=(const otterDual& d) {
		if (d.real == 0) {
			return;
		}
		real /= d.real;
		dual = (d.real * dual - real * d.dual) / (d.real * d.real);
	}
	otterDual otterDual::operator/(const otterDual& d) {
		if (d.real == 0) {
			return;
		}
		return otterDual(real / d.real, (d.real * dual - real * d.dual) / (d.real * d.real));
	}
}