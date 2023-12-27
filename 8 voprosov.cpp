#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <limits>
using namespace std;

void clear_answers() {
	fstream clear_file("answers.txt", ios::out);
	clear_file.close();
}
int err() {
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Вы ввели некорректное значение, ответ должен содержать число 1 или 0" << endl;
}
void check_answers() {

	fstream file("answers.txt");
	string answer;
	char a;

	getline(file, answer);
	a = answer[0];

	file.close();

	cout << "Вы:\n";
	if (a & (1 << 0)) {
		cout << "1) мужчина" << endl;
	}
	else {
		cout << "1) женщина" << endl;
	}
	if (a & (1 << 1)) {
		cout << "2) старше 30 лет "<< endl;
	}
	else {
		cout << "2) младше 30 лет" << endl;
	}
	if (a & (1 << 2)) {
		cout << "3) любите кошек" << endl;
	}
	else {
		cout << "3) люите собак" << endl;
	}
	if (a & (1 << 3)) {
		cout << "4) любите пить чай поутрам" << endl;
	}
	else {
		cout << "4) любите пить кофе по утрам" << endl;
	}
	if (a & (1 << 4)) {
		cout << "5) хороший человек" << endl;
	}
	else {
		cout << "5) не считаете себя хорошим человеком" << endl;
	}
	if (a & (1 << 5)) {
		cout << "6) живете в городе" << endl;
	}
	else {
		cout << "6) живете вне города (деревня, поселок)" << endl;
	}
	if (a & (1 << 6)) {
		cout << "7) ведете здоровый образ жизни" << endl;
	}
	else {
		cout << "7) ведете плохой образ жизни" << endl;
	}
	if (a & (1 << 7)) {
		cout << "8) Юрий Валентинович" << endl;
	}
	else {
		cout << "8) не Юрий Валентинович" << endl;
	}
	cout << "_____________________________" << endl;
}

void opros() {

	char answer = 0;
	fstream file("answers.txt");
	int v1, v2, v3, v4, v5, v6, v7, v8;
	int x;

	cout << "_____________________________________________________________________________________\n";
	do {
		cout << "1) Вы мужчина или женщина? (0 - женщина, 1 - мужчина) ";
		v1 = err();
	} while (v1 != 1 && v1 != 0);

	do {
		cout << "2) Вам больше 30 лет? (0 - да, 1 - нет) ";
		v2 = err();
	} while (v2 != 1 && v2 != 0);

	do{
	cout << "3) Вы любите кошек или собак? (0 - собак, 1 - кошек) ";
	v3 = err();
	} while (v3 != 1 && v3 != 0);

	do{
	cout << "4) Что любите пить по утрам? (0 - чай, 1 - кофе) ";
	v4 = err();
	} while (v4 != 1 && v4 != 0);

	do{
	cout << "5) Вы хороший человек? (0 - да, 1 -нет)";
	v5 = err();
	} while (v5 != 1 && v5 != 0);

	do{
	cout << "6) Вы живете в городе? (0 - да, 1 - нет) ";
	v6 = err();
	} while (v6 != 1 && v6 != 0);

	do{
	cout << "7) Вы ведете здоровый образ жизни? (0 - да, 1 - нет) ";
	v7 = err();
	} while (v7 != 1 && v7 != 0);

	do{
	cout << "8) Вас зовут Юрий Валентинович? (0 - да, 1 - нет)";
	v8 = err();
	} while (v8 != 1 && v8 != 0);
	cout << "---------------------------------"<< endl;

	if (file.is_open()) {
		file << answer;
	}
	file.close();

}

bool check_file() {

	fstream file("answers.txt");
	string line;

	getline(file, line);

	if (line == "") {
		return false;
	}
	else {
		return true;
	}
	file.close();
}

int main() {

	setlocale(LC_ALL, "Russian");

	int answer;

	cout << "Здравствуйте, вы запустили программу 8_voprosov\n";

	int flag{ 0 };

	do {
		if (check_file()) {
			cout << "В опросе уже есть ответы" << endl;
		}
		else {
			cout << "Ещё нет ответов на опрос" << endl;
		}
		cout << " Меню" << endl;
		cout << "------------------------------" << endl;
		cout << "1) Пройти опрос" << endl;
		cout << "2) Посмотреть ответы" << endl;
		cout << "3) Изменить ответы" << endl;
		cout << "4) Удалить ответы" << endl;
		cout << "Введите номер функции из меню ";
		cin >> answer;

		if (answer == 1) {
			opros();
		}
		else if (answer == 2 && check_file()) {
			check_answers();
		}
		else if (answer == 3 && check_file()) {
			changing_answers();//fdsvsdgsdfhgxdfg
		}
		else if (answer == 4) {
			clear_answers();//fxgxfnxfnfxfnxfnf
		}
		else if (answer > 4 || cin.fail()) {
			cin.clear();
			cin.ignore();
			flag = 1;
			cout << "Введен номер не существующей функции, попробуйте ввести заново" << endl;
		}
	} while (answer != 4 || flag == 1);

	return 0;
}