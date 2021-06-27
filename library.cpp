
#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
using namespace std;


int counter = 0;
int counter_student = 0;
int increment(int c)
{
	c++;
	counter = c;
	return counter;
}

int decrement(int c)
{
	c--;
	counter = c;
	return counter;
}

int increment_student(int c)
{
	c++;
	counter_student = c;
	return counter_student;
}

int decrement_student(int c)
{
	c--;
	counter_student = c;
	return counter_student;
}






class entery{

private:

	string isbn, title, author, edition, publication;

public:

	string name, section, semester, password, enrollment;


	entery(){
		isbn = "0";
		title = "0";
		author = "0";
		edition = "0";
		publication = "0";

		name = "0";
		section = "0";
		semester = "0";
		password = "0";
		enrollment = "0";
	}



	void setIsbn(string isb){
		isbn = isb;
	}

	void setTitle(string ti){
		title = ti;
	}

	void setAuthor(string auth){
		author = auth;
	}

	void setEdition(string ed){
		edition = ed;
	}

	void setPublication(string pu){
		publication = pu;
	}


	string getIsbn()
	{
		return isbn;
	}

	string getTitle()
	{
		return title;
	}
	string getAuthor()
	{
		return author;
	}
	string getEdition()
	{
		return edition;
	}
	string getPublication()
	{
		return publication;
	}



	void setname(string na){
		name = na;
	}

	void setsection(string sec){
		section = sec;
	}

	void setsemester(string sem){
		semester = sem;
	}

	void setpassword(string pass){
		password = pass;
	}

	void setenrollment(string enroll){
		enrollment = enroll;
	}

	string getname(){
		return name;
	}

	string getsection(){
		return section;
	}

	string getsemester(){
		return semester;
	}

	string getpassword(){
		return password;
	}
	string getenrollment(){
		return enrollment;
	}
	~entery(){
		cout << "distructor run:" << endl;
	}
};

class  addbooks :virtual public entery{
public:
	void addbook(int counter){

		string isbn, title, author, edition, publication;

		cout << "\t\t\t ADD BOOKS " << endl;
		if (counter == 10)
		{
			cout << "YOU HAVE REACHED THE MAXIMUM LIMIT TO ADD THE BOOKS " << endl;
			cout << "Press any key to continue..." << endl;
			_getch();

		}

		else
		{
			cin.ignore();
			cout << "ENTER ISBN : " << endl;
			getline(cin, isbn);
			cout << "ENTER TITLE : " << endl;
			getline(cin, title);
			cout << "ENTER AUTHOR : " << endl;
			getline(cin, author);
			cout << "ENTER EDITION : " << endl;
			getline(cin, edition);
			cout << "ENTER PUBLICATION : " << endl;
			getline(cin, publication);
			setIsbn(isbn);
			setTitle(title);
			setAuthor(author);
			setEdition(edition);
			setPublication(publication);
			increment(counter);
			cout << "BOOK ADDED SUCCESFULLY! Press any key to continue..." << endl;
			_getch();

		}


	}

};

class addstudent :public virtual  entery{
public:
	void adddata(int counter_student){

		if (counter_student == 10){
			cout << "YOU HAVE REACHED THE MAXIMUM LIMIT TO ADD THE Students " << endl;
			cout << "Press any key to continue..." << endl;
			_getch();

		}
		else{
			cin.ignore();
			cout << "Enter student name              :";
			getline(cin, name);
			cout << "Enter student enrollment number :";
			getline(cin, enrollment);
			cout << "Enter student section           :";
			getline(cin, section);
			cout << "Enter student semester          :";
			getline(cin, semester);
			cout << "Enter student password          :";
			getline(cin, password);


			setname(name);
			setenrollment(enrollment);
			setsection(section);
			setsemester(semester);
			setpassword(password);

			increment_student(counter_student);
			cout << "Student ADDED SUCCESFULLY! Press any key to continue..." << endl;
			_getch();
		}
	}
};

class loginstudent :virtual public entery, virtual public addbooks, virtual public addstudent{
public:
	string name, pass;

	bool press = false;
	void login(int counter_student, loginstudent books[10]){
		if (counter_student == 10){
			cout << "YOU HAVE REACHED THE MAXIMUM LIMIT TO ADD THE Students " << endl;
			cout << "Press any key to continue..." << endl;
			_getch();
		}
		else{
		pass1:
			cout << "Please Enter Your name :";
			cin >> name;
			cout << "Plaese enter your password :";
			cin >> pass;
			for (int i = 0; i < counter_student; i++)
			{
				if (books[i].getpassword() == pass){
					cout << "You are successfully login your profile :\n\n";
					system("pause");
				}


				else if (books[i].getpassword() != pass)
				{
					cout << "You enter wrong password\nPlease enter correct password\n\n";
					system("pause");
					goto pass1;
				}

			}
		}

	}
	void borrowbooks(int counter_student, loginstudent books[10]){
		int select, borrow, returnbook;

		string isbn, title, author, edition, publication;
		system("cls");
	b:
		cout << setw(45) << setfill('*') << "*" << endl;
		cout << "What do you want next :\n";
		cout << setw(45) << setfill('*') << "*" << endl;
		cout << "[1] For Borrow_Books: \n";
		cout << "[2] For Return_Books: \n";
		cout << "[3] For checking all books in library :\n";
		cout << "[4] For Quit: \n\n";
		cin >> select;
		if (select == 1)
		{

		a:
			cout << "Plaese enter Book ISBN: ";
			cin >> isbn;
			for (int i = 0; i < counter_student; i++)
			{
				if (books[i].getIsbn() == isbn){
					cout << "Book Founded! \n\n";
					cout << "What do you want borrow [1] or exit:[2]";
					cin >> borrow;
					if (borrow == 1)
					{
						books[i].setIsbn("");
						books[i].setTitle("");
						books[i].setAuthor("");
						books[i].setEdition("");
						books[i].setPublication("");
						decrement(counter);
						cout << "BOOK Borrow SUCCESFULLY!\n Press any key to continue.." << endl;
						_getch();


						for (int a = i; a < counter; a++)
						{
							books[a] = books[a + 1];
						}

						books[9].setIsbn("");
						books[9].setTitle("");
						books[9].setAuthor("");
						books[9].setEdition("");
						books[9].setPublication("");
						goto b;
					}
					else {

					}


				}
				else{
					cout << "Book not founded! \nPlease enter Correct ISBN :\n\n";
					goto a;
				}

			}
		}


		else if (select == 2){
			cout << "DO yo want to return books: yes [1] or No [2]\n";
			cin >> returnbook;
			if (returnbook == 1){
				cout << "Please give me full information about return book:\n ";
				cin.ignore();
				cout << "Enter return book ISBN : " << endl;
				getline(cin, isbn);
				cout << "Enter return book TITLE : " << endl;
				getline(cin, title);
				cout << "Enter return book  AUTHOR : " << endl;
				getline(cin, author);
				cout << "Enter return book  EDITION : " << endl;
				getline(cin, edition);
				cout << "Enter return book  PUBLICATION : " << endl;
				getline(cin, publication);
				setIsbn(isbn);
				setTitle(title);
				setAuthor(author);
				setEdition(edition);
				setPublication(publication);
				increment(counter);
				cout << "BOOK RETURN SUCCESFULLY ! Press any key to continue..." << endl;
				_getch();

			}

		}
		else if (select == 3){
			system("cls");
			cout << setw(90) << setfill('*') << "*" << endl;
			cout << "\t\t\t    BOOK DETAILS " << endl;
			cout << setw(90) << setfill('*') << "*" << endl;
			cout << "ISBN          TiTLE           AUTHOR          EDITION        PUBLICATION " << endl;
			for (int i = 0; i < counter; i++)
			{


				cout << books[i].getIsbn() << "              "
					<< books[i].getTitle() << "              "
					<< books[i].getAuthor() << "              "
					<< books[i].getEdition() << "              "
					<< books[i].getPublication() << endl << endl;

			}
			goto b;


		}
	}
};
class deletebook :virtual public entery, virtual public addbooks, virtual public addstudent, virtual public loginstudent{
public:
	void deleteBooks(int counter, deletebook books[10])
	{
		string isbn;
		int choice;
		cout << "DELETE BOOK\n\n";
		if (counter == 0)
		{
			cout << "THERE IS NOT BOOKS TO BE DELETED " << endl;
			cout << "Press any key to continue..." << endl;
			_getch();

		}	cin.ignore();
		cout << "ENTER ISBN : " << endl;
		getline(cin, isbn);
		for (int i = 0; i < counter; i++)
		{
			if (books[i].getIsbn() == isbn)
			{
				cout << "BOOK FOUND!" << endl;
				cout << "Do You Want to delete this books yes[1], no[2]" << endl;
				cin >> choice;
				if (choice == 1)
				{
					books[i].setIsbn("");
					books[i].setTitle("");
					books[i].setAuthor("");
					books[i].setEdition("");
					books[i].setPublication("");
					decrement(counter);
					cout << "BOOK DELETED SUCCESFULLY!\n Press any key to continue.." << endl;
					_getch();


					for (int a = i; a < counter; a++)
					{
						books[a] = books[a + 1];
					}

					books[9].setIsbn("");
					books[9].setTitle("");
					books[9].setAuthor("");
					books[9].setEdition("");
					books[9].setPublication("");
				}

				else
				{

				}
			}
		}
		cout << "BOOK NOT FOUND " << endl;
		cout << "Press any key to continue.." << endl;
		_getch();

	}


};
class editbook :virtual public entery, virtual public addbooks, virtual public deletebook, virtual public addstudent, virtual public loginstudent{
public:
	void editBooks(int counter, editbook books[10])
	{
		string editisbn;
		string isbn, title, author, edition, publication;
		string choice;
		cout << "\t\t\tEDIT BOOKS " << endl;
		if (counter == 0)
		{
			cout << "THERE IS NO BOOKS TO BE EDITED FIRST ADD THE BOOKS!,Press any key to continue... " << endl;
			_getch();

		}
		cin.ignore();
		cout << "ENTER ISBN : " << endl;
		getline(cin, editisbn);

		for (int i = 0; i < counter; i++)
		{
			if (books[i].getIsbn() == editisbn)
			{
				cout << "BOOK FOUND!" << endl;
				cout << "DO YOU WANT TO EDIT THE BOOK 1 OR 2? " << endl;
				getline(cin, choice);
				if (choice == "1")
				{
					cout << "ENTER ISBN : " << endl;
					getline(cin, isbn);
					cout << "ENTER TITLE : " << endl;
					getline(cin, title);
					cout << "ENTER AUTHOR : " << endl;
					getline(cin, author);
					cout << "ENTER EDITION : " << endl;
					getline(cin, edition);
					cout << "ENTER PUBLICATION : " << endl;
					getline(cin, publication);
					books[i].setIsbn(isbn);
					books[i].setTitle(title);
					books[i].setAuthor(author);
					books[i].setEdition(edition);
					books[i].setPublication(publication);
					cout << "Press any key to proceed.." << endl;
					_getch();

				}
				else if (choice != "1")
				{
					cout << "BOOK NOT FOUND! PRESS ANY KEY TO CONTINUE.." << endl;
					_getch();
				}
			}

			else
			{


			}
		}
	}


};

class searchbook :virtual public entery, virtual public addbooks, virtual public deletebook, virtual public editbook, virtual public addstudent, virtual public loginstudent{
public:
	void searchBooks(int counter, searchbook books[10])
	{
		string isbn;

		bool print = false;
		cout << "SEARCH BOOKS " << endl;
		if (counter == 0)
		{
			cout << "THERE IS NO BOOK TO SEARCH " << endl;
			cout << "Press any key to continue..." << endl;
			_getch();

		}	cin.ignore();
		cout << "ENTER ISBN : " << endl;
		getline(cin, isbn);
		for (int i = 0; i < counter; i++)
		{
			if (books[i].getIsbn() == isbn)
			{
				cout << "BOOK FOUND " << endl;
				cout << "ISBN : " << books[i].getIsbn() << endl;
				cout << "TITLE : " << books[i].getTitle() << endl;
				cout << "AUTHOR : " << books[i].getAuthor() << endl;
				cout << "EDITION : " << books[i].getEdition() << endl;
				cout << "PUBLICATION : " << books[i].getPublication() << endl;
				print = true;
			}
			if (print)
			{
				cout << "PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();

			}
			else
			{
				cout << "BOOK NOT FOUND " << endl;
				cout << "PRESS ANY KEY TO CONTINUE..." << endl;
				_getch();

			}
		}
	}
};

class viewbooks :virtual public entery, virtual public addbooks, virtual public deletebook, virtual public editbook, virtual public searchbook, virtual public addstudent, virtual public loginstudent{
public:
	void viewAllBooks(int counter, viewbooks books[10])
	{
		cout << "VIEW ALL THE BOOKS " << endl;
		if (counter == 0)
		{
			cout << "THERE IS NO BOOK TO VIEW FIRST ADD THE BOOK! presss any key to continue..." << endl;
			_getch();

		}
		else
		{
			system("cls");
			cout << setw(90) << setfill('*') << "*" << endl;
			cout << "\t\t\t    BOOK DETAILS " << endl;
			cout << setw(90) << setfill('*') << "*" << endl;
			cout << "ISBN          TiTLE           AUTHOR          EDITION        PUBLICATION " << endl;
			for (int i = 0; i < counter; i++)
			{
				cout << books[i].getIsbn() << "              "
					<< books[i].getTitle() << "              "
					<< books[i].getAuthor() << "              "
					<< books[i].getEdition() << "              "
					<< books[i].getPublication() << endl << endl;

			}
			cout << "Press any key to continue . . .";
			_getch();

		}
	}

	void viewstudentprofile(int counter_student, viewbooks books[10]){
		system("cls");
		cout << setw(90) << setfill('*') << "*" << endl;
		cout << "\t\t\t    Students  DETAILS " << endl;
		cout << setw(90) << setfill('*') << "*" << endl;

		cout << "Name          Enrollment           Section          Semester        Password " << endl;
		for (int i = 0; i < counter_student; i++)
		{
			cout << books[i].getname() << "              "
				<< books[i].getenrollment() << "              "
				<< books[i].getsection() << "              "
				<< books[i].getsemester() << "              "
				<< books[i].getpassword() << endl << endl;
		}cout << "Press any key to continue . . .";
		_getch();
	}



};





void quit(void)
{
	system("cls");
	system("color a");
	cout << "      @@@@@@@@@@@@        ##         ##             $$$$$$$$$$$$$$$            \n";
	cout << "      @@        @@         ##       ##              $$                         \n";
	cout << "      @@        @@          ##     ##               $$                         \n";
	cout << "      @@@@@@@@@@@@           ##   ##                $$                         \n";
	cout << "      @@          @@          ## ##                 $$==========               \n";
	cout << "      @@          @@           ###                  $$                         \n";
	cout << "      @@          @@           ###                  $$                         \n";
	cout << "      @@@@@@@@@@@@             ###                  $$$$$$$$$$$$$$$            \n";
	cout << endl;
	cout << "\t\t" << setw(50) << setfill('*') << "*" << endl;
	cout << "\t\t        Thanks for using My Project \n";
	cout << "\t\t" << setw(50) << setfill('*') << "*" << endl;

	system("pause");
	exit(1);
}

int main(){
	system("color 02");

	string  c, choice;
	int q;
	viewbooks *books = new viewbooks[10];

	system("CLS");
	do
	{
		system("cls");

		cout << "\t\t\t WELCOME TO LIBRARY MANAGMENT SOFTWARE " << endl;
		cout << "\t\t\t THIS SOFTWARE IS MADE BY GROUP 13 " << endl;
		cout << "\t\t\t\t\t LBS " << endl;


		cout << "\n\n[1] For Librarian interface \n";
		cout << "[2] For Student interface \n";
		cout << "[3]      About  \n";
		cout << "[4]      Quit \n\n";
		cout << "\nEnter your choice here : ";
		cin >> q;

		if (q == 1)
		{
		a:
			system("cls");
			cout << "\n\n\n[1] ADD A BOOK " << endl;
			cout << "[2] DELETE A BOOK " << endl;
			cout << "[3] EDIT A BOOK " << endl;
			cout << "[4] SEARCH A BOOK " << endl;
			cout << "[5] VIEW ALL THE BOOKS " << endl;
			cout << "[6] VIEW ALL STUDENT PROFILE " << endl;
			cout << "[7] QUIT " << endl;
			cout << "[8] MAIN " << endl;
			cout << "\nEnter your choice here : ";
			cin >> c;

			if (c == "1")
			{
				books[counter].addbook(counter);
				goto a;
			}
			else if (c == "2")
			{
				books[counter].deleteBooks(counter, books);
			}

			else if (c == "3")
			{
				books[counter].editBooks(counter, books);
			}

			else if (c == "4")
			{
				books[counter].searchBooks(counter, books);
			}

			else if (c == "5")
			{

				books[counter].viewAllBooks(counter, books);


			}

			else if (c == "6")
			{
				books[counter_student].viewstudentprofile(counter_student, books);

			}
			else if (c == "7"){
				quit();
			}
			else
			{
				main();
			}


		}

		else if (q == 2){
		b:
			system("cls");
			cout << "\n[1] FOR ADD STUDENT " << endl;
			cout << "[2] FOR login STUDENT " << endl;
			cout << "[3] FOR Quit " << endl;
			cout << "[4] FOR MAIN " << endl;
			cout << "\nEnter your choice here : ";
			cin >> choice;

			if (choice == "1"){
				books[counter_student].adddata(counter_student);
				goto b;
			}

			else if (choice == "2"){
				books[counter_student].login(counter_student, books);
				books[counter_student].borrowbooks(counter_student, books);
			}
			else if (choice == "3"){
				quit();
			}
			else{
				main();
			}
		}

		else if (q == 3){
			system("cls");
			cout << setw(50) << setfill('*') << "*" << endl;
			cout << "  This program is created by Group 13 \n";
			cout << setw(50) << setfill('*') << "*" << endl;
			cout << "[1] IF YOU PRESS 1 A LIBRARIAN POP-UP MAIN MENU APPEAR IN WHICH YOU CAN ADD A BOOK \nDELETE A BOOK EDIT A BOOK SEARCH A BOOK AND YOU CAN VIEW ALL BOOKS IN LIBRARY  \nAND ALSO VIEW ALL STUDENTS PROFILE\n\n";

			cout << "[2] IF YOU PRESS 2 A STUDENT POP - UP MAIN MENU APPEAR IN WHICH YOU CAN CREATE YOUR STUDENT PROFILE\nOR USE THIS PROFILE TO LOGIN YOUR ACCOUNT  THEN YOU CAN BORROW A BOOK RETURN A BOOK\n\n";




			cout << "[4] IF YOU PRESS 4 THE PROGRAM WILL BE CLOSE\n\n";


			cout << "[5] IF YOU PRESS 5 OR ANY BUTTON ON KEYBOARD THE CONTROL OF THIS PROGRAM WILL RETURN TO THE MAIN MENU\n\n";
			system("pause");
		}
		else if (q == 4){
			quit();
		}
	} while (q != 8);
	_getch();




}