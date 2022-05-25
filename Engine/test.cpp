#include "otterVector.h"
#include "otterMatrix.h"


using namespace otterEngine;
int main() {
	
	otterMatrix matrix1(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	otterMatrix matrix2(
		1, 2, 3,
		4, 5, 6,
		7, 8, 9);
	matrix1.transpose();
	

	otterVector v1(2, 3, 4);
	otterVector v2(7, 9, 5);

	//float dot = otterVector::dot(v1, v2);
	return 0;
}