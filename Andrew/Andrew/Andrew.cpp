#include <iostream>
#include <string>
#include "Storage.h"
#include "SSD.h"
#include "FlashCart.h"
#include "GoogleDrive.h"
#include "YandexDisk.h"
#include "PortableDrives.h"
#include "BuiltDrives.h"
#include "DVD.h"
#include "HDD.h"
int main()
{
	SSD* ssd = new SSD(500,700);
	ssd->connect();
	ssd->read();
	HDD* hdd = new HDD(1000,500);
	hdd->connect();
	hdd->read();
	DVD* dvd = new DVD();
	dvd->read();
	dvd->write();
	FlashCart* flash = new FlashCart(100,60);
	flash->write();
	flash->read();
	GoogleDrive* google = new GoogleDrive();
	google->read();
	google->write();
	YandexDisk* yandex = new YandexDisk();
	yandex->read();
	yandex->write();
	PortableDrives* p = new PortableDrives();
	p->write();
	p->read();
	BuiltDrives* b = new BuiltDrives();
	b->read();
	b->write();
}