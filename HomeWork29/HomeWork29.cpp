//������ �������
#include <iostream>
#include <string>
#include <fstream>

std::ofstream out;
std::ifstream in;
bool overwrite(std::string path, std::string str);
int main() {
	setlocale(LC_ALL, "Russian");
	std::cout << "������ 1.\n";
	std::string end = "end",path ="Text.txt",str;
	out.open(path, std::ios::app);
	if (out.is_open()) {
		do {
			std::cout << "������� ������ ->";
			getline(std::cin, str);
			if (str == end)
				break;
			out << str + '\n';
		} while (str != end);
	}
	else
		std::cout << "������ �������� �����!\n";
	out.close();
	in.open(path);
	if (in.is_open()) {
		while (getline(in, str))
			std::cout << str << '\n';	
	}
	else
		std::cout << "������ �������� �����!\n";
	in.close();
	if (!remove(path.c_str()))
		std::cout << "���� ������\n\n";
	else
		std::cout << "Error denaed file!\n\n";
	std::cout << "������ 2.\n������� ������ -> ";
	getline(std::cin, str);
	out.open(path);// ��� �������� �� ������������� ����� ��������������� 
	out.close();// ��� �������� �� ������������� ����� ��������������� 
	if (overwrite(path, str)){
		std::cout << "���� �����������!";
	}
	else
		std::cout<<"����� �� ����������!";
	
	
}
bool overwrite(std::string path, std::string str) {
	in.open(path);
	if (in.is_open()!=true)
		return false;
	in.close();
	out.open(path);
	out << str;
	out.close();
	return true;
}