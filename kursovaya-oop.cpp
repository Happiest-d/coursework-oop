#include <iostream>
#include <string>
#include <fstream>
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
};

class Unemployed : public Employee {
private:
    string surname;
    int age;
    string profession;
    string last_position;
    string date;
    
};

class Vacancy : public Employee {
private:
    string company;
    int offer_min_age;
    int offer_max_age;
};

int main()
{
    setlocale(LC_ALL, "ru");

    job_sort();
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

    return 0;
}