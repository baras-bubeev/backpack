#include<iostream>
#include<fstream>
#include<windows.h>
#include<string>
#include<iomanip>

using namespace std;
ofstream fout("Object.txt", ios_base::app);
ifstream fin("Object.txt");

class backpack {
public:
	backpack();
	float		MaxWeight;
	int			i;
	struct		Object {
		string	name;
		float	weight;
		int		value;
		float	spec_val;
	};
	struct		Object obj[100];
	struct		Object sp;
	void		sort();
	void		fill();
	void		add_object();
	void		obj_change();
	void		save();
};

backpack::backpack() {
	MaxWeight = 20;
	i = 0;
	while (!fin.eof()) {
	fin >> obj[i].name >> obj[i].weight >> obj[i].value >> obj[i].spec_val;
	i++;
	}
	//fin.close();
}

void	backpack::sort() {
	for (int m = 0; m < i-1; m++) {
		for (int n = 0; n < i-m; n++) {
			if (obj[n].spec_val < obj[n + 1].spec_val) {
				sp = obj[n + 1];
				obj[n + 1] = obj[n];
				obj[n] = sp;
			}
		}
	}
}

void	backpack::fill() {
	backpack::sort();
	int n = 0;
	float s = obj[n].weight;
	while (s <= MaxWeight && n!=i) {
		cout << obj[n].name << endl;
		s += obj[n+1].weight;
		n++;
	}
}

void	backpack::add_object() {
	cout << "Введите наименование: ";
	cin.ignore();
	getline(cin, obj[i].name);
	cout << "Введите вес: ";
	cin >> obj[i].weight;
	cout << "Введите ценность: ";
	cin >> obj[i].value;
	obj[i].spec_val = obj[i].value / obj[i].weight;
	fout.open("Object.txt", ios_base::app);
	fout << obj[i].name << " " << obj[i].weight << " " << obj[i].value << " " << obj[i].spec_val << endl;
	fout.close();
	i++;
}

void backpack::obj_change() { int a;
	cout << left << setw(3) << '№' << setw(20) << "Наименование" << setw(10) << "Вес" << setw(4) << "Ценность" << endl;
	for (int n = 0; n < i-1; n++) {
		cout << left << setw(3) << n << setw(20) << obj[n].name << setw(10) << obj[n].weight << setw(4) << obj[n].value << endl;
	}
	cout << endl << "Выберите номер объекта: ";
	cin >> a;
	cout << endl << obj[a].name << endl << endl;
	cout << "Введите вес: ";
	cin >> obj[a].weight;
	cout << "Введите ценность: ";
	cin >> obj[a].value;
	obj[a].spec_val = obj[a].value / obj[a].weight;
	backpack::save();
	cout << "Данные обновлены!" << endl;
}

void backpack::save() {
	fout.open("Object.txt", ios_base::out | ios_base::trunc);
	for (int n = 0; n < i; n++) {
		fout << obj[n].name << " " << obj[n].weight << " " << obj[n].value << " " << obj[n].spec_val << endl;
	}
	fout.close();
}

backpack bp;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu;
	do {
		cout << endl;
		cout << "1. Сформировать рюкзак" << endl;
		cout << "2. Изменить вместимость рюкзака" << endl;
		cout << "3. Добавить объекты" << endl;
		cout << "4. Изменить параметры объектов" << endl;
		cout << "0. Выход" << endl;
		cout << "Выберите действие: ";
		cin >> menu;
		switch (menu) {
		case 0:
			exit(0);
			break;
		case 1:
			cout << endl;
			bp.fill();
			break;
		case 2:
			cout << endl;
			cout << "Введите вместимость рюкзака: ";
			cin>>bp.MaxWeight;
			break;
		case 3:
			cout << endl;
			bp.add_object();
			break;
		case 4:
			cout << endl;
			bp.obj_change();
			break;
		default:
			cout << endl << "Введены некорректные данные!!!" << endl;
		}
	} while (menu != 0);
	return 0;
}