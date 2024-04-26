#pragma once
#include <iostream>
#include <ctime>
#include <cstring>
#include <cstdio>
using namespace std;

struct Card {
	char name[100] = "";
	unsigned long number = 0;
	double money = 0;

	void fillCard() {
		srand(time(0));
		cout << "Name: ";
		cin.getline(name, 100);
		number = rand() * pow(10, 5) + rand();
		money = 50;
	}

	void printCard() {
		cout << "Client: " << name << endl;
		cout << "Card: " << number << endl;
		cout << "Cash: " << money << " UAH\n" << endl;
	}

	void saveToTextFile(FILE* file) {
		fprintf(file, "%s\n%lu %lf\n", name, number, money);
	}

	void loadFromTextFile(FILE* file) {
		fgets(name, 100, file);
		int size = strlen(name);
		name[size - 1] = '\0';
		fscanf_s(file, "%lu %lf", &number, &money);
	}

	void saveToBinFile(FILE* file) {
		int size = strlen(name) + 1;
		fwrite(&size, sizeof(int), 1, file);
		fwrite(name, sizeof(char), size, file);
		fwrite(&number, sizeof(unsigned long), 1, file);
		fwrite(&money, sizeof(double), 1, file);
	}
	void LoadFromBinFile(FILE* file) {
		int size = 0;
		fread(&size, sizeof(int), 1, file);
		fread(name, sizeof(char), size, file);

		fread(&number, sizeof(unsigned long), 1, file);
		fread(&money, sizeof(double), 1, file);
	}
};