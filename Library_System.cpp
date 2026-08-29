#include<iostream>
#include<string>
using namespace std;

//declreation of arrays global in heep

const int Max_Books = 100;
int Book_Id[Max_Books];
string Book_title[Max_Books];
string Book_author[Max_Books];
bool Book_available[Max_Books];
int No_of_books = 0;

//adding
void Adding_Books() {
	if (No_of_books == Max_Books) {
		cout << "Library is full!\n";
	}
	else {
		cout << "Enter id" << endl;
		cin >> Book_Id[No_of_books];
		cin.ignore();
		cout << "Enter Book Title\n";
		getline(cin, Book_title[No_of_books]);
		cout << "Enter Book Author" << endl;
		getline(cin, Book_author[No_of_books]);
		Book_available[No_of_books] = true;
		No_of_books++;
		cout << "Book is added Sucessfully\n";
		cout << "__=====================================__\n";
	}
}
//searching
int Search_Books(int id) {
	for (int i = 0; i < No_of_books; i++) {
		if (Book_Id[i] == id)
			return  i;
	}
	return -1;

}

//removing
void Removing_Books() {
	int id = {};
	cout << "Enter id : \n";
	cin >> id;
	int Book_index = Search_Books(id);
	if (Book_index == -1) {
		cout << "Book not found " << endl;
	}
	for (int i = Book_index; i < No_of_books - 1; i++) {
		Book_Id[i] = Book_Id[i + 1];
		Book_title[i] = Book_title[i + 1];
		Book_author[i] = Book_author[i + 1];
	}
	No_of_books--;
	cout << "Book is removed sucessfully\n";
}

//Borrow
void Borrow_Books() {
	int id;
	cout << "Enter id\n";
	cin >> id;
	int index = Search_Books(id);
	if (index == -1)
	{
		cout << "Book not found" << endl;
		return;
	}
	if (Book_available[index]) {
		Book_available[index] = false;
		cout << "is available, Book will borrow successfully" << endl;
	}
	else {
		cout << "not available,already borrowed" << endl;
	}
}

//Display
void display_Books() {
	cout << "__===========================__\n";
	if (No_of_books == 0) {
		cout << "No Books available" << endl;
	}
	for (int i = 0; i < No_of_books; i++) {
		cout << "id: " << Book_Id[i] << endl;
		cout << "title: " << Book_title[i] << endl;
		cout << "author: " << Book_author[i] << endl;
		cout << "status: " << (Book_available[i] ? "Available" : "Unavailable") << endl;
		cout << "__==================================__\n";
	}
}

//Display one book
void display_one_Book() {
	if (No_of_books == 0) {
		cout << "No Books available \n";
		return;
	}
	int id;
	cout << "Enter Book id \n";
	cin >> id;
	int index = Search_Books(id);
	if (index == -1) {
		cout << "No Books available" << endl;
		return;
	}
	cout << "id: " << Book_Id[index] << endl;
	cout << "title: " << Book_title[index] << endl;
	cout << "author: " << Book_author[index] << endl;
	cout << "status: " << (Book_available[index] ? "Available" : "Unavailable") << endl;
	cout << "__==================================__\n";
}

//returning
void Return_Books() {
	int id = {};
	cout << "Enter id\n";
	cin >> id;
	int index = Search_Books(id);
	if (index == -1)
	{
		cout << "Book not found" << endl;
	}
	if (!Book_available[index]) {
		Book_available[index] = true;
		cout << "Book will returned successfully" << endl;
	}
	else {
		cout << "Book not available" << endl;
	}
}

//updating
void Update_Books() {
	cout << "_______________________\n";

	if (No_of_books == 0) {
		cout << "No Books available\n";
		return;
	}

	int id;
	cout << "Enter Book ID to update: ";
	cin >> id;

	int index = Search_Books(id);

	if (index == -1) {
		cout << "Book not found!\n";
		return;
	}

	cin.ignore();

	cout << "Enter new Book Title: ";
	getline(cin, Book_title[index]);

	cout << "Enter new Book Author: ";
	getline(cin, Book_author[index]);

	cout << "Book updated successfully \n";
	cout << "__============================__\n";
}

//options
void options() {
	int choice = {};
	do {
		cout << "Library menu " << endl;
		cout << "1. Adding Book " << endl;
		cout << "2. remove Book " << endl;
		cout << "3. Borrow Book " << endl;
		cout << "4. Return Book " << endl;
		cout << "5. display Books " << endl;
		cout << "6. Update Book " << endl;
		cout << "7. Search Book " << endl;
		cout << "8. Exit " << endl;
		cout << "\nEnter your choice" << endl;
		cin >> choice;

		switch (choice) {
		case 1:system("cls");
			Adding_Books(); break;
		case 2:system("cls");
			Removing_Books(); break;
		case 3:system("cls");
			Borrow_Books(); break;
		case 4:system("cls");
			cout << "Returning book\n_________" << endl;
			Return_Books(); break;
		case 5:system("cls");
			display_Books(); break;
		case 6:system("cls");
			Update_Books(); break;
		case 7:system("cls");
			Search_Books(0);
			display_one_Book();
			break;
		case 8: cout << " Program ended\n"; break;
		}
	} while (choice >= 1 && choice < 8);

}

int main()
{
	options();

}
