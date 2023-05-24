class  PortableDrives : public Storage {
private:
	double speed;
public:
	double getSpeed() {
		return speed;
	}
	void setSpeed(double w) {
		speed = w;
	}
	PortableDrives() {
		Storage(256);
		speed = 100;
	}
	PortableDrives(double w, double d) : Storage(d), speed(w) {}
	void write() {
		std::cout << "PortableDrive start a write information" << std::endl;
	}
	void read() {
		std::cout << "PortableDrive read information..." << std::endl;
	}
};