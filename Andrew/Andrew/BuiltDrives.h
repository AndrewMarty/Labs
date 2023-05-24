class  BuiltDrives : public Storage {
private:
	double speed;
public:
	double getSpeed() {
		return speed;
	}
	void setSpeed(double w) {
		speed = w;
	}
	BuiltDrives() {
		Storage(256);
		speed = 100;
	}
	BuiltDrives(double w, double d) : Storage(d), speed(w) {}
	void write() {
		std::cout << "BuiltDrive start a write information" << std::endl;
	}
	void read() {
		std::cout << "BuiltDrive read information..." << std::endl;
	}
};