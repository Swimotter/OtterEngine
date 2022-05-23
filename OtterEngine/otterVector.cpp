namespace otterEngine {
	//constructors
	otterVector::otterVector() :
		x(0.0),
		y(0.0),
		z(0.0) {};
	otterVector::otterVector(float _x, float _y, float _z) :
		x(_x),
		y(_y),
		z(_z) {};

	//destructor
	otterVector::~otterVector() {};

	//copy constructors
	otterVector::otterVector(const otterVector& v) :
		x(v.x),
		y(v.y),
		z(v.z) {};
	otterVector& otterVector::operator=(const otterVector& v) {
		x = v.x;
		y = v.y;
		z = v.z;
		return *this;
	}

	//vector addition
	void otterVector::operator+=(const otterVector& v) {
		x += v.x;
		y += v.y;
		z += v.z;
	}
	otterVector otterVector::operator+(const otterVector& v) const {
		return otterVector(x + v.x, y + v.y, z + v.z);
	}

	//vector subtraction
	void otterVector::operator-=(const otterVector& v) {
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}
	otterVector otterVector::operator-(const otterVector& v) {
		return otterVector(x - v.x, y - v.y, z - v.z);
	}
}