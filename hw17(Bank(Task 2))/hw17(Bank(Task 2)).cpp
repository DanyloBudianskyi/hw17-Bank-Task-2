#include "Card.h"
#include "Func.h"


int main()
{
    FILE* file = nullptr;
    int size = 0;
    Card* card = new Card[size];
    int index = 0;

    loadCardsFromBinaryFile(card, size);

    int menu = -1;
    do
    {
        cout << "Arr size:" << size << endl;
        showMenu();
        cin >> menu;
        cin.ignore();

        switch (menu)
        {
        case 1:
            ++size;
            card[size - 1].fillCard();
            cout << "\nCard was added\n";
            break;
        case 2:
            cout << "Input index: "; cin >> index;
            deleteCard(card, size, index);
            break;
        case 3:
            for (int i = 0; i < size; i++) {
                cout << "Card #" << i + 1 << "\n";
                card[i].printCard();
            }
            cout << endl;
            break;
        case 4:
            addMoney(card);
            cout << "Money was added on your card\n";
            break;
        case 5:
            withDrowMoney(card);
            cout << "Money has been debited from your card\n";
            break;
        case 6:
            saveCardsToBinaryFile(card, size);
            cout << "\nCards were saved\n";
            break;
        case 0:
            break;
        default:
            cout << "Invalid input\n";
            break;
        }
    } while (menu != 0);
}