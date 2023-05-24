class Storage {
protected:
	double capacity;
public:
	Storage() {
		capacity = 0;
	}
	Storage(double c) {
		capacity = c;
	}
	virtual void read() {}
};