#include "otterVector.h"
#include "otterMatrix.h"


using namespace otterEngine;
int main() {
	/*
	otterMatrix matrix1(
		7, 6, 3,
		4, 2, 5,
		10, 6, 4);
	otterMatrix matrix2(
		3, 2, 1,
		5, 3, 3,
		4, 2, 1);
	matrix1 *= matrix2;
	*/

	otterVector v1(2, 3, 4);
	otterVector v2(7, 9, 5);

	float dot = otterVector::dot(v1, v2);
	return 0;
}