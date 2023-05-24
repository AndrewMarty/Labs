class  HDD : public Storage {
private:
	double speed;
public:
	double getSpeed() {
		return speed;
	}
	void setSpeed(double w) {
		speed = w;
	}
	HDD() {
		Storage(1000);
		speed = 500;
	}
	HDD(double w, double d) : Storage(d), speed(w) {}
	void connect() {
		std::cout << "HDD was connected" << std::endl;
	}
	void read() {
		std::cout << "HDD read information..." << std::endl;
	}
};