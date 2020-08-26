#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<conio.h>

using namespace std;

class itemEntry {
public:
       float unit_price;
       int quantity ;
       char name[30];
       char company[30];
};

class Store {
public:
       int numItem;
       itemEntry database[100];

       Store() {
              numItem = 0;
       }
       void insertItem(char itemName[], char company[], int c, float p);
       void deleteItem(char itemName[]);
       itemEntry *search(char itemName[]);
       void updateItem(char itemName[], int total, float price);
};

void Store::insertItem(char itemName[], char company[], int c, float p) {
       strcpy(database[numItem].name, itemName);
       strcpy(database[numItem].company, company);
       database[numItem].quantity  = c;
       database[numItem].unit_price = p;
       cout << "Item Inserted Successfully.\n";
       ++numItem;
}

void Store::deleteItem(char itemName[]) {
       int i;
       for (i = 0; i < numItem; i++) {
              if (strcmp(itemName, database[i].name) == 0) {
                     database[i].quantity --;
                     cout << "Item Deleted Successfully.\n";
                     return;
              }
       }
       cout << "Item not found.\n";
}

itemEntry *Store::search(char itemName[]) {
       int i;
       for (i = 0; i < numItem; i++) {
              if (strcmp(itemName, database[i].name) == 0)
                     return &database[i];
       }
       return NULL;
}

void Store::updateItem(char itemName[], int total, float price)
{
       itemEntry *item = search(itemName);
       if (item == NULL)
       {
              cout << "Item not found.\n";
              return;
       }
       item->quantity  += total;
       item->unit_price = price;
}

int main() {
       Store sto;
       system("cls");
       char cond='f',option='f', name[30], company[30], quantity [10], unit_price[30];
       cout<<"Press 1 for Buyer\nPress 2 for Seller\n";
       cin>>cond;
       if (cond == '2'){
       while (option != 'e') {
              cout << "\n----------->Enter your choice:<------------\n";
              cout << "I for insert\n";
              cout << "D for delete\n";
              cout << "S for search\n";
              cout << "U for update\n";
              cout << "E for exit\n";

              cin>>name;
              option = name[0];

              switch (option) {

              case 'i':
                     cout << "Enter Name of Item\n"; 
                     cin>>name;
                      cout << "Enter Name of Company\n";
                     cin>>company;
                      cout << "Enter Quantity\n";
                     cin>>quantity;
                      cout << "Enter Unit Price\n";
                     cin>>unit_price;
                     sto.insertItem(name, company, atoi(quantity ), atof(unit_price));
                     break;
              case 'd':
                     cout << "Enter Name of Item:\n";
                     cin>>name;
                     sto.deleteItem(name);
                     break;
              case 's':
                     cout << "Enter Name of Item:\n";
                     cin>>name;
                     itemEntry *test;
                     test = sto.search(name);
                     if (test != NULL) {
                           cout << "---------------->Searching Result<---------------------" << endl;
                           cout << "Item found\n" << "Name of the Item:" << test->name << endl << "Company name:" << test->company << endl << "Number of quantity  available:" << test->quantity  << endl << "Unit price:" << test->unit_price << endl;
                     }
                     else
                           cout << "Item not found\n";
                     break;
              case 'u':
                     cout << "Enter details for update...\n";
                     cout << "Enter name: "; cin>>name;
                     cout << "Enter total new entry: "; cin>>quantity;
                     cout << "Enter new price: "; cin>>unit_price;
                     sto.updateItem(name, atoi(quantity ), atof(unit_price));
                     break;
                     /*        case 'e':
                     exit(0);
                     break;*/
              }
       }}
       return 0;

}
