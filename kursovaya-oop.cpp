#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include<queue>


#include "Popular_sort.h"
using namespace std;


class Employee {
public:
    string sex;
    string education;
    int last_experience;
    int sum_experience;
    string desired_position;
    int desired_salary;

    Employee() {
        sex = "";
        education = "";
        last_experience = 0;
        sum_experience = 0;
        desired_position = "";
        desired_salary = 0;
    }

    Employee(string _sex, string _education, int _last_experience, int _sum_experience, string _desired_position, int _desired_salary) {
        sex = _sex;
        education = _education;
        last_experience = _last_experience;
        sum_experience = _sum_experience;
        desired_position = _desired_position;
        desired_salary = _desired_salary;
    }
};

class Unemployed : public Employee {
public:
    string surname;
    int age;
    string profession;
    string last_position;
    int date;

    //сразу два метода записи стоит привести к одному
    Unemployed() : Employee() {
        surname = "";
        age = 0;
        profession = "";
        last_position = "";
        date = 0;
    }

    Unemployed(string _surname, int _age, string _profession, string _last_position, int _date,
        string _sex, string _education, int _last_experience, int _sum_experience, string _desired_position,
        int _desired_salary) : Employee(_sex, _education, _last_experience, _sum_experience, _desired_position, _desired_salary) {
        surname = _surname;
        age = _age;
        profession = _profession;
        last_position = _last_position;
        date = _date;
    }
    
    void update(string _surname, int _age, string _profession, string _last_position, int _date,
        string _sex, string _education, int _last_experience, int _sum_experience, string _desired_position, int _desired_salary){
        surname = _surname;
        age = _age;
        profession = _profession;
        last_position = _last_position;
        date = _date;
        sex = _sex;
        education = _education;
        last_experience = _last_experience;
        sum_experience = _sum_experience;
        desired_position = _desired_position;
        desired_salary = _desired_salary;
    }
};

class Vacancy : public Employee {
public:
    string company;
    int offer_min_age;
    int offer_max_age;
};

int main()
{
    setlocale(LC_ALL, "ru");

    string path = "unemployed.txt";

    Unemployed person;
    queue<Unemployed> people_queue;
    //cout << person.age;

    //job_sort();

    /*ofstream freader;
    string path = "unemployed.txt";

    freader.open(path, ofstream::app);
    if (freader.is_open()) {
        cout << "File open" << endl;
        freader << "\nДополнительная строка";
    }
    else {
        cout << "Error" << endl;
    }
    freader.close();*/

    /*ifstream finput;
    finput.open("unemployed.txt");
    if (finput.is_open()) {
        cout << "File open" << endl;
        string ch[15];
        int i = 0;
        while (!finput.eof()) {
            finput >> ch[i];
            cout << ch[i] << endl;
            i++;
        }
    }
    else {
        cout << "Error" << endl;
    }
    finput.close();*/


    //read and write to file
    /*fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
    }
    else {
        cout << "Файл успешно открыт" << endl;
        string msg;
        int value = 0;
        cout << "1 для запись в файл" << endl;
        cout << "2 для чтение из файла" << endl;
        cin >> value;

        switch (value)
        {
            case 1: {
                cout << "запись" << endl;
                SetConsoleCP(1251);
                cin >> msg;
                fs << msg << "\n";
                SetConsoleCP(866);
                break;
            }
            case 2: {
                cout << "чтение" << endl;
                while (!fs.eof()) {
                    msg = "";
                    fs >> msg;
                    cout << msg << endl;

                }
                break;
            }
            default: {
                cout << "ошибка ввода" << endl;
                break;
            }
        }

    }
    fs.close();*/

    //string to int
    /*string input;
    std::cout << "Введите число: ";
    std::cin >> input;

    int value = stoi(input);
    std::cout << "Введенное число - " << value << ", удвоим его = " << (value * 2);*/

    fstream fs;
    fs.open(path, fstream::in | fstream::out | fstream::app);
    if (!fs.is_open())
    {
        cout << "Ошибка при открытии файла" << endl;
    }
    else {
        while (!fs.eof()) {
            string _surname,  _age, _profession, _last_position, _date, _sex, _education, _last_experience,
                _sum_experience, _desired_position, _desired_salary, skip;
            fs >> _surname >> _age >> _profession >> _last_position >> _date >> _sex >> _education >> _last_experience >>
                _sum_experience >> _desired_position >> _desired_salary >> skip;

            person.update(_surname, stoi(_age), _profession, _last_position, stoi(_date),
                _sex, _education, stoi(_last_experience), stoi(_sum_experience), _desired_position, stoi(_desired_salary));

            cout << person.age << " " << person.surname << " " << person.desired_salary << " " << person.sex << endl;

            people_queue.push(person);
            
            cout << people_queue.size() << endl;
        }
    }

    return 0;
}