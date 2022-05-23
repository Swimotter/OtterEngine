namespace otterEngine {
	class otterVector {
	private:

	public:
		//position in cartesian coordinates
		float x;
		float y;
		float z;

		//constructors
		otterVector();
		otterVector(float _x, float_y, float _z);

		//destructor
		~otterVector();

		//copy constructors
		otterVector(const otterVector& v);
		otterVector& operator=(const otterVector& v);
	};
}