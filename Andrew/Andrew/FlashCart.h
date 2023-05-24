class  FlashCart : public Storage {
private:
	double speed;
public:
	double getSpeed() {
		return speed;
	}
	void setSpeed(double w) {
		speed = w;
	}
	FlashCart() {
		Storage(128);
		speed = 60;
	}
	FlashCart(double w, double d) : Storage(d), speed(w) {}
	void write() {
		std::cout << "FlashCart start a write information" << std::endl;
	}
	void read() {
		std::cout << "FlashCart read information..." << std::endl;
	}
};