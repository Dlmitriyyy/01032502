#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

void sortByAlphabet()
{
	ifstream read_file("text.txt");
	string text;

	while (getline(read_file, text))
	{
		sort(text.begin(), text.end());
		cout << "Букви відсортовані у алфавітному порядку: " << text << endl;
	}
	read_file.close();
}
void sortByQuantity()
{
	ifstream read_file("text.txt");
	string text;
	unordered_map<char, int> count;

	while (getline(read_file, text))
	{
		for (char letter : text)
		{
			count[letter]++;
		}
	}
	vector<pair<char, int>> countVector(count.begin(), count.end());

	sort(countVector.begin(), countVector.end(), [](const auto& a, const auto& b)
		{
			return a.second > b.second;
		});

	cout << "Відсортовані букви у кількості спадання: ";

	for (const auto& pair : countVector)
	{
		for (int a = 0; a < pair.second; a++)
		{
			cout << pair.first;
		}
	}
	read_file.close();
}
void displayLetterAndQuanity()
{
	ifstream read_file("text.txt");
	string text;
	unordered_map<char, int> count;

	while (getline(read_file, text))
	{
		for (char letter : text)
		{
			count[letter]++;
		}
		for (auto& pair : count)
		{
			cout << "Буква: " << pair.first << " кількість: " << pair.second << endl;
		}
	}
}
int main()
{
	system("chcp 1251>nul");
	int input;
	
	do
	{
		cout << "Для виводу відсортованих букв у алфавітному порядку введіть  - '1', для виводу відсортованих букв за спаданням кількості введіть - '2', для виводу кожної букви з відображенням кількості - '3'" << endl;
		cin >> input;
		
		if (input == 1)
		{
			sortByAlphabet();
			break;
		}
		if (input == 2)
		{
			sortByQuantity();
			break;
		}
		if (input == 3)
		{
			displayLetterAndQuanity();
			break;
		}
		else
		{
			cout << "Помилка. Некорректний ввід." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}	
	} while (input != 1 && input != 2);
		

	return 0;
}