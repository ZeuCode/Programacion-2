#pragma once
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace System;
using namespace std;

class File {
private:
	ofstream fileWrite;
	ifstream fileRead;
	string text;

	int vidas, fantasmas, pacdots;

public:
	File(){
		readData();
	}
	~File(){}

	void readData() {
		fileRead.open("input.txt", ios::in);

		if (!fileRead.good()) {
			fileRead.close();

			fileWrite.open("input.txt", ios::out); //crea el archivo
			fileWrite << "5" << endl;
			fileWrite << "20" << endl;
			fileWrite << "20" << endl;
			fileWrite.close();

			fileRead.open("input.txt", ios::in);
		}

		getline(fileRead, text);
		vidas = stoi(text);
		getline(fileRead, text);
		fantasmas = stoi(text);
		getline(fileRead, text);
		pacdots = stoi(text);

		fileRead.close();
	}

	void writeData(int pacdotsComidos) {
		fileWrite.open("output.txt", ios::out); //crea el archivo
		fileWrite << "Pacdots comidos: " << pacdotsComidos << endl;
		fileWrite.close();
	}
	int getVidas() { return vidas; }
	int getCFantasmas() { return fantasmas; }
	int getCPacdots() { return pacdots; }

};