#include "Card.h"
#include "Func.h"


int main()
{
    FILE* file = nullptr;
    int n = 0;
    Card* card = new Card[n];
    int index = 0;

    loadCardsFromBinaryFile(card, n);

    int menu = -1;
    do
    {
        showMenu();
        cin >> menu;
        cin.ignore();
        switch (menu)
        {
        case 1:
            n++;
            card->fillCard();
            cout << "\nCard was added\n";
            break;
        case 2:
            cout << "Input index: "; cin >> index;
            deleteCard(card, n, index);
        case 3:
            for (int i = 0; i < n; i++) {
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
            saveCardsToBinaryFile(card, n);
            cout << "\nCards were saved\n";
            break;
        case 0:
            break;
        default:
            cout << "Invalid input\n";
            break;
        }
    } while (menu != 0);
    delete[] card;
}