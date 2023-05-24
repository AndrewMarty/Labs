class  SSD : public Storage {
private:
	double weight;
public:
	double getWeight() {
		return weight;
	}
	void setWeight(double w) {
		weight = w;
	}
	SSD() {
		Storage(500);
		weight = 400;
	}
	SSD(double w, double d) : Storage(d), weight(w) {}
	void connect() {
		std::cout << "SSD was connected" << std::endl;
	}
	void read() {
		std::cout << "SSD read information..." << std::endl;
	}
};