#pragma once
#include "Card.h"

void showMenu() {
	cout << "--------------------------------\n";
	cout << "|            Welcome           |\n";
	cout << "--------------------------------\n";
	cout << "| 1.add new client.            |\n"; //Х	додаванн€ нового рахунку; 
	cout << "| 2.delete client.             |\n"; //Х	закритт€ рахунку.
	cout << "| 3.Show info                  |\n"; //Х	виведенн€ ≥нформац≥њ про на€вн≥сть загальноњ суми грошей у кожного з кл≥Їнт≥в;
	cout << "| 4.Put money on card          |\n"; //Х	додаванн€ кл≥Їнтом грошей на вказаний рахунок; 
	cout << "| 5.Withdraw money from card   |\n"; //Х	зн€тт€ кл≥Їнтом грошей;
	cout << "| 6.Save                       |\n"; //Х	зн€тт€ кл≥Їнтом грошей;
	cout << "--------------------------------\n";
	cout << "| 0.Exit                       |\n";
	cout << "--------------------------------\n";
	cout << ">>> ";
}

void loadCardsFromBinaryFile(Card*& cards, int& numberOfCards) {
	FILE* file = nullptr;
	fopen_s(&file, "bank.bin", "rb");
	if (file != nullptr) {
		fread(&numberOfCards, sizeof(int), 1, file);
		delete[] cards;
		cards = new Card[numberOfCards];
		for (int i = 0; i < numberOfCards; ++i) {
			cards[i].LoadFromBinFile(file);
		}
		fclose(file);
	}
}



void saveCardsToBinaryFile(Card* cards, int numberOfCards) {
	FILE* file = nullptr;
	fopen_s(&file, "bank.bin", "wb");
	if (file != nullptr) {
		fwrite(&numberOfCards, sizeof(int), 1, file);
		for (int i = 0; i < numberOfCards; ++i) {
			cards[i].saveToBinFile(file);
		}
		fclose(file);
		cout << "Cards were saved to binary file.\n";
	}
}

void addMoney(Card*& cards) {
	int index = 0;
	int value = 0;
	cout << "Input index: "; cin >> index;
	cout << "How much money you want put on your card?: "; cin >> value;
	cards[index - 1].money += value;
}

void withDrowMoney(Card*& cards) {
	int index = 0;
	int value = 0;
	cout << "Input index: "; cin >> index;
	cout << "How much money do you want to withdraw from your card?: "; cin >> value;
	cards[index - 1].money -= value;
}

void deleteCard(Card*& cards, int& numberOfCards, int& index) {
	index -= 1;
	if (index >= 0 && index < numberOfCards) {
		Card* temp = new Card[numberOfCards - 1];
		for (int i = 0; i < index; i++) {
			temp[i] = cards[i];
		}
		for (int i = index + 1; i < numberOfCards; i++) {
			temp[i] = cards[i];
		}
		delete cards;
		cards = temp;
		numberOfCards -= 1;
		cout << "Card with index " << index + 1 << " was deleted\n";
	}
	else {
		cout << "Wrong index\n";
	}
}