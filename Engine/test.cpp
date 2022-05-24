#include "otterVector.h"
#include "otterMatrix.h"


using namespace otterEngine;
int main() {
	otterMatrix matrix1(
		7, 6, 3,
		4, 2, 5,
		10, 6, 4);
	otterMatrix matrix2(
		3, 2, 1,
		5, 3, 3,
		4, 2, 1);

	matrix1 *= matrix2;

	return 0;
}