#include <iostream>
#include <string>
#include <fstream>
#include "Popular_sort.h"
using namespace std;

//название фирмы, вакантная должность, заработная плата, требования к кандидату: пол, возраст, образование, общий стаж, стаж работы в последней занимаемой должности.

class Unemployed {
private:
    string surname;
    string sex;
    int age;
    string education;
    string profession;
    string position;
    int last_experience;
    int sum_experience;
    string date;
    string desired_position;
    int desired_salary;
    
};

class Vacancy {
private:
    string company;
    string offer_position;
    int offer_salary;
    string offer_sex;
    int offer_min_age;
    int offer_max_age;
    string offer_education;
    int offer_last_experience;
    int offer_sum_experience;
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