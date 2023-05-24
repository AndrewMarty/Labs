class  GoogleDrive : public Storage {
private:
	bool _active;
public:
	bool getActive() {
		return _active;
	}
	void setActive(bool w) {
		_active = w;
	}
	GoogleDrive() {
		Storage(15);
		_active = false;
	}
	GoogleDrive(bool w) : Storage(w ? 100 : 15), _active(w) {}
	void write() {
		std::cout << "GoogleDrive start a write information" << std::endl;
	}
	void read() {
		std::cout << "GoogleDrive read information..." << std::endl;
	}
};