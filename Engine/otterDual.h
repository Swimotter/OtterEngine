#pragma once

namespace otterMath {
	class otterDual {
	private:

	public:
		//real component
		float real;

		//dual component
		float dual;

		//constructors
		otterDual();
		otterDual(float _real, float _dual);

		//destructor
		~otterDual();

		//copy constructors
		otterDual(const otterDual& d);
		otterDual& operator=(const otterDual& d);

		//dual addition
		void operator+=(const otterDual& d);
		otterDual operator+(const otterDual& d);
	};
}