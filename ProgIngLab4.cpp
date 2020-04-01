// ProgIngLab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	const int len = 100, strings = 100, stlb = 4; //размеры массива , k = 100, l = 100
	const char ch = '\n', bl = '|'; //перенос строки в файле
	char mass[len][strings];
	int k, l;
	string perem, mass1[len][stlb], mass2[len];


	ifstream fs("\\example.txt", ios::in | ios::binary); // окрываем файл для чтения

	if (!fs) return 1; //Если ошибка открытия файла, то завершаем программу

	for (int r = 0; r < strings; r++) //считывание данных из файла и занесение их в массив
	{
		fs.getline(mass[r], len - 1, ch); //Считываем строки в массив
		//cout << "String " << r + 1 << " = " << mass[r] << endl; //Выводи строку из массива
	}
	for (int r = 0; r < 2; r++) //вывод строк из массива
	{
		cout << "String " << r + 1 << " = " << mass[r] << endl;
	}
	fs.close(); //Закрываем файл
	k = 0; 
	for (int i = 0; i < 2; i++) //перевод из символьнового массива в строковый
	{
		l = 0;
		for (int j = 0; j < strings; j++)
		{
			if (mass[i][j] == '\r') break;
			if (mass[i][j] == '\0') break;
			mass2[k] += mass[i][j];
		}
		k++;
	}
	for (int i = 0; i < 2; i++) {
			regex telsp("\\s"); 
			mass2[i] = regex_replace(mass2[i], telsp, ""); //Убирает все пробелы
			regex fio("\\B[A-Z]\\B");
			mass2[i] = regex_replace(mass2[i], fio, " $&"); //разделяет имя и фамилию
			regex tel("[\|]8");
			mass2[i] = regex_replace(mass2[i], tel, "|+7 ("); //заменяет все первую 8 на +7
			regex tel1("[\(]9[0-9]{2}");
			mass2[i] = regex_replace(mass2[i], tel1, "$&) "); //Добавляет "()" к коду
			regex mail("\\@+");
			mass2[i] = regex_replace(mass2[i], mail, "@"); //убирает все лишние @ в адресе
			regex dot("\\.+");
			mass2[i] = regex_replace(mass2[i], dot, "."); //убирает все лишние точки в адресе
	}
	/**for (int i = 0; i < len; i++) //перевод из символьнового массива в строковый
	{
		l = 0;
		for (int j = 0; j < strings; j++)
		{
			if (mass[i][j] == '|') l++;
			if (mass[i][j] == '\r') break;
			if (mass[i][j] == '\0') break;
			mass1[k][l] += mass[i][j];
		}
		k++;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= 3; j++) {
			regex fio("\\B[A-Z]\\B");
			mass1[i][j] = regex_replace(mass1[i][j], fio, " $&"); //разделение имени и фамилии \\BИ\\B
			if (j > 1) {
				regex tel("[\|]8");
				mass1[i][j] = regex_replace(mass1[i][j], tel, "|+7"); // |8\d*
				regex telsp("\\s"); //, regex::ECMAScript
				mass1[i][j] = regex_replace(mass1[i][j], telsp, ""); //|.*\s.*|
				regex mail("\\@+");
				mass1[i][j] = regex_replace(mass1[i][j], mail, "@");//@+
				regex dot("\\.+");
				mass1[i][j] = regex_replace(mass1[i][j], dot, "."); //\S*\.+
			}
		}
	}**/

	std::ofstream out("\\rightdoc.txt", std::ios::app); // открываем файл для записи и добавляем новые строки
	if (out.is_open())
	{
		/**for (int i = 0; i < 2; i++) //вывод строк из массива
		{
			for (int j = 0; j <= 3; j++) {
				out << mass1[i][j];
			}
			out << endl;
		}**/
		for (int r = 0; r < 2; r++) //вывод строк из массива
		{
				out << mass2[r];
				out << endl;
		}
	}
	out.close(); //Закрываем файл
	std::cout << "End of program" << std::endl;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
