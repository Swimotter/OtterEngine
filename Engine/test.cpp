#include "otterVector.h"
#include "otterMatrix.h"


using namespace otterEngine;
int main() {

	otterMatrix matrix1(
		1, 0, 5,
		2, 1, 6,
		3, 4, 0);
	otterMatrix matrix2(
		1, 2, 3,
		0, 1, 4,
		5, 6, 0);
	otterMatrix matrix3(
		0, 0, 0,
		0, 0, 0,
		0, 0, 0);
	float det = otterMatrix::determinant(matrix2);
	matrix1 = otterMatrix::adjugate(matrix1);
	

	otterVector v1(2, 3, 4);
	otterVector v2(7, 9, 5);

	//float dot = otterVector::dot(v1, v2);
	return 0;
}