#include <iostream>
#include <string>

struct myDate {
	int day = 13;
	int month = 9;
	int year = 2004;
};
struct myPerson {
	std::string name = "noname";
	myDate birthday;
	std::string job = "programer";
	int salary = 420000;
};
void print_myPerson(const myPerson& MP) {
	std::cout << "Name: " << MP.name << std::endl;
	std::cout << "Birthday: " <<
		MP.birthday.day << '.' <<
		MP.birthday.month << '.' <<
		MP.birthday.year << std::endl;
	std::cout << "Job: " << MP.job << std::endl;
	std::cout << "Salary: " << MP.salary << std::endl;
}
myPerson input_myPerson() {
	myPerson tmp;
	
	std::cout << "Enter name -> ";
	std::getline(std::cin, tmp.name);
	
	std::cout << "Enter birtday day -> ";
	std::cin >> tmp.birthday.day;
	
	std::cout << "Enter birtday month -> ";
	std::cin >> tmp.birthday.month;
	
	std::cout << "Enter birtday year -> ";
	std::cin >> tmp.birthday.year;
	std::cin.ignore();
	
	std::cout << "Enter Job -> ";
	std::getline(std::cin, tmp.job);
	
	std::cout << "Enter Salary -> ";
	std::cin >> tmp.salary;
	
	return tmp;
}

struct coinsKeeper {
	std::string name = "noname";
	int age = 0;
	int coins_number = 0;
	int* coins = nullptr;
};

void print_coinsKeeper(const coinsKeeper& CK);
inline int year_of_birth(const coinsKeeper& CK, int year);
int cash(const coinsKeeper& CK);

int main(){
	setlocale(LC_ALL, "Russian");
	int n;

	// Структурf person.
	/*
	struct person { // Структура person, описывающая содержимое объектов.
		std::string name; // Поле структуры типа string с именем персоны
		int age; // Поле структыры типа int с возрастом персоны.
		std::string gender;
		std::string job;
		int salary;
	} p1, p2 { // Создание объектов структуры, один из которых мнгновенно инициализируется.
		"Lox lohovich",
		12, 
		"male", 
		"actres",
		100 
	};

	// Обращение к полям объектов, как и обычным переменным.
	p1.name = "Denis Smith";
	p1.age = 28;
	p1.gender = "male";
	p1.job = "programer";
	p1.salary = 800000;

	std::cout << "Name: " << p1.name << std::endl;
	std::cout << "Age: " << p1.age << std::endl;
	std::cout << "Gender: " << p1.gender << std::endl;
	std::cout << "Job: " << p1.job << std::endl;
	std::cout << "Salary: " << p1.salary << std::endl;
	
	std::cout << "======================================================\n";
	
	std::cout << "Name: " << p2.name << std::endl;
	std::cout << "Age: " << p2.age << std::endl;
	std::cout << "Gender: " << p2.gender << std::endl;
	std::cout << "Job: " << p2.job << std::endl;
	std::cout << "Salary: " << p2.salary << std::endl;
	
	std::cout << "======================================================\n";
	
	person p3{ // Альтернативный способ создание объекта.
		"Arnold Shawscneger",
		50,
		"male",
		"director",
		470000
	};

	person p4;
	p4 = p3; // Копирование значений полей объекта p3 в поля объекта p4 

	std::cout << "Name: " << p4.name << std::endl;
	std::cout << "Age: " << p4.age << std::endl;
	std::cout << "Gender: " << p4.gender << std::endl;
	std::cout << "Job: " << p4.job << std::endl;
	std::cout << "Salary: " << p4.salary << std::endl;
	*/
	
	
	// Структура day.
	/*
	struct day {
		int day = 1;
		int month = 1;
		int years = 1980;
		std::string note = "empty";
	} x, y , z ;

	day d1 { 20, 01, 1980 };
	std::cout << d1.day << ".";
	std::cout << d1.month << ".";
	std::cout << d1.years << " ";
	std::cout << d1.note << std::endl; // empty.
	*/

	// Структура myDate и myPerson.
	/*
	myPerson mp{
		"Denis Pobedynsky",
		{ 13, 9, 2004 },
		"designer",
		900000
	};

	print_myPerson(mp);

	myPerson* pointer = &mp;
	std::cout << pointer->name << "\n\n";
 
	myPerson mp2 = input_myPerson();
	std::cout << "==============================\n";
	print_myPerson(mp2);
	*/

	// Задача 1. Хранитель монет.
	
	std::cout << "Задача 1.\n==== Объект ====\n";
	coinsKeeper ck{
		"Peter",
		12,
		7,
		new  int[7]{ 5, 1, 1, 2, 5, 2, 1 }
	};
	
	print_coinsKeeper(ck);
	std::cout << "Год рождения: " << year_of_birth(ck, 2023) << std::endl;
	std::cout << "Общие сбережения: " << cash(ck) << std::endl;

	delete[] ck.coins;

	return 0;
}

void print_coinsKeeper(const coinsKeeper& CK) {
	std::cout << "Имя: " << CK.name << std::endl;
	std::cout << "Возраст: " << CK.age << std::endl;
	std::cout << "Монеты: ";
	for (int i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ' ';
	std::cout << std::endl;
};

inline int year_of_birth(const coinsKeeper& CK, int year) {
	return (year - CK.age);
}

int cash(const coinsKeeper& CK) {
	int sum = 0;
	for (int i = 0; i < CK.coins_number; i++)
		sum += CK.coins[i];
	return sum;
}