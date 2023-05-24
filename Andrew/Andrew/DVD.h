class  DVD : public Storage {
private:
	double speed;
public:
	double getSpeed() {
		return speed;
	}
	void setSpeed(double w) {
		speed = w;
	}
	DVD() {
		Storage(15);
		speed = 2;
	}
	DVD(double w, double d) : Storage(d), speed(w) {}
	void write() {
		std::cout << "DVD start a write information" << std::endl;
	}
	void read() {
		std::cout << "DVD read information..." << std::endl;
	}
};