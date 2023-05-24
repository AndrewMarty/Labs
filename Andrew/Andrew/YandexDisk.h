class  YandexDisk : public Storage {
private:
	bool _active;
public:
	bool getActive() {
		return _active;
	}
	void setActive(bool w) {
		_active = w;
	}
	YandexDisk() {
		Storage(10);
		_active = false;
	}
	YandexDisk(bool w) : Storage(w ? 150 : 15), _active(w) {}
	void write() {
		std::cout << "YandexDisk start a write information" << std::endl;
	}
	void read() {
		std::cout << "YandexDisk read information..." << std::endl;
	}
};