#include "otterVector.h"
#include "otterMatrix.h"


using namespace otterEngine;
int main() {
	
	otterMatrix matrix1(
		1, 2, 3,
		0, 1, 4,
		5, 6, 0);
	otterMatrix matrix2(
		3, 2, 1,
		5, 3, 3,
		4, 2, 1);
	matrix1.determinant();
	

	otterVector v1(2, 3, 4);
	otterVector v2(7, 9, 5);

	//float dot = otterVector::dot(v1, v2);
	return 0;
}