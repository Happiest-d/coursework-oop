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

    Vacancy() : Employee() {
        company = "";
        offer_min_age = 0;
        offer_max_age = 0;
    }

    Vacancy(string _company, int _offer_min_age, int _offer_max_age,
        string _sex, string _education, int _last_experience, int _sum_experience, string _desired_position,
        int _desired_salary) : Employee(_sex, _education, _last_experience, _sum_experience, _desired_position, _desired_salary) {
        company = _company;
        offer_min_age = _offer_min_age;
        offer_max_age = _offer_max_age;
    }

    void update(string _company, int _offer_min_age, int _offer_max_age,
        string _sex, string _education, int _last_experience, int _sum_experience, string _desired_position, int _desired_salary) {
        company = _company;
        offer_min_age = _offer_min_age;
        offer_max_age = _offer_max_age;
        sex = _sex;
        education = _education;
        last_experience = _last_experience;
        sum_experience = _sum_experience;
        desired_position = _desired_position;
        desired_salary = _desired_salary;
    }

};

int main()
{
    setlocale(LC_ALL, "ru");

    string unemployed_path = "unemployed.txt";
    string vacancy_path = "vacancy.txt";
    string output_path = "out.txt";

    Unemployed person;
    queue<Unemployed> people_queue;

    Vacancy job;
    queue<Vacancy> offer_queue;

    //fstream get_people;
    //get_people.open(unemployed_path, fstream::in | fstream::out | fstream::app);
    //if (!get_people.is_open()) 
    //{
    //    cout << "Ошибка при открытии файла unemployed" << endl;
    //}
    //else 
    //{
    //    while (!get_people.eof()) 
    //    {
    //        string _surname, _age, _profession, _last_position, _date,
    //            _sex, _education, _last_experience, _sum_experience, _desired_position, _desired_salary, skip;
    //        get_people >> _surname >> _age >> _profession >> _last_position >> _date >>
    //            _sex >> _education >> _last_experience >> _sum_experience >> _desired_position >> _desired_salary >> skip;

    //        person.update(_surname, stoi(_age), _profession, _last_position, stoi(_date),
    //            _sex, _education, stoi(_last_experience), stoi(_sum_experience), _desired_position, stoi(_desired_salary));

    //        //cout << person.age << " " << person.surname << " " << person.desired_salary << " " << person.sex << endl;

    //        people_queue.push(person);

    //        //cout << people_queue.size() << endl;
    //    }
    //}
    //get_people.close();

    //cout << "\n\n\n" << endl;

    //fstream get_offer;
    //get_offer.open(vacancy_path, fstream::in | fstream::out | fstream::app);
    //if (!get_offer.is_open()) 
    //{
    //    cout << "Ошибка при открытии файла vacancy" << endl;
    //}
    //else 
    //{
    //    while (!get_offer.eof()) 
    //    {
    //        string _company, _offer_min_age, _offer_max_age,
    //            _sex, _education, _last_experience, _sum_experience, _desired_position, _desired_salary, skip;
    //        get_offer >> _company >> _offer_min_age >> _offer_max_age >>
    //            _sex >> _education >> _last_experience >> _sum_experience >> _desired_position >> _desired_salary >> skip;

    //        job.update(_company, stoi(_offer_min_age), stoi(_offer_max_age),
    //            _sex, _education, stoi(_last_experience), stoi(_sum_experience), _desired_position, stoi(_desired_salary));

    //        //cout << job.company << " " << job.education << " " << job.offer_min_age << " " << job.offer_max_age << endl;

    //        offer_queue.push(job);

    //        //cout << offer_queue.size() << endl;
    //    }
    //}
    //get_offer.close();

    //Модель работы биржи труда в течение 30 дней
    for (int i = 1; i <= 30; i++) 
    {
        cout << "День " << i << endl;
        int people_per_day = rand() % 4; //в день от 0 до 3 человек
        cout << "Человек в день: " << people_per_day << endl;
        for (int n = 1; n <= people_per_day; n++) 
        {
            cout << n << endl;
            //Даём человку 3 вакансии, он выбирает первую подхящую
            for (int m = 1; m <= 3; m++)
            {
                if (people_queue.empty()) //Если в очереди нет людей, то заполняем её из файла
                {
                    fstream get_people;
                    get_people.open(unemployed_path, fstream::in | fstream::out | fstream::app);
                    if (!get_people.is_open())
                    {
                        cout << "Ошибка при открытии файла unemployed" << endl;
                    }
                    else
                    {
                        while (!get_people.eof())
                        {
                            string _surname, _age, _profession, _last_position, _date,
                                _sex, _education, _last_experience, _sum_experience, _desired_position, _desired_salary, skip;
                            get_people >> _surname >> _age >> _profession >> _last_position >> _date >>
                                _sex >> _education >> _last_experience >> _sum_experience >> _desired_position >> _desired_salary >> skip;

                            person.update(_surname, stoi(_age), _profession, _last_position, stoi(_date),
                                _sex, _education, stoi(_last_experience), stoi(_sum_experience), _desired_position, stoi(_desired_salary));

                            //cout << person.age << " " << person.surname << " " << person.desired_salary << " " << person.sex << endl;

                            people_queue.push(person);

                            //cout << people_queue.size() << endl;
                        }
                    }
                    get_people.close();
                }

                if (offer_queue.empty()) //Если в очереди нет вакансий, то заполняем её из файла
                {
                    fstream get_offer;
                    get_offer.open(vacancy_path, fstream::in | fstream::out | fstream::app);
                    if (!get_offer.is_open())
                    {
                        cout << "Ошибка при открытии файла vacancy" << endl;
                    }
                    else
                    {
                        while (!get_offer.eof())
                        {
                            string _company, _offer_min_age, _offer_max_age,
                                _sex, _education, _last_experience, _sum_experience, _desired_position, _desired_salary, skip;
                            get_offer >> _company >> _offer_min_age >> _offer_max_age >>
                                _sex >> _education >> _last_experience >> _sum_experience >> _desired_position >> _desired_salary >> skip;

                            job.update(_company, stoi(_offer_min_age), stoi(_offer_max_age),
                                _sex, _education, stoi(_last_experience), stoi(_sum_experience), _desired_position, stoi(_desired_salary));

                            //cout << job.company << " " << job.education << " " << job.offer_min_age << " " << job.offer_max_age << endl;

                            offer_queue.push(job);

                            //cout << offer_queue.size() << endl;
                        }
                    }
                    get_offer.close();
                }

                //Проверяем, подходит ли человеку вакансия
                if ((people_queue.front().age >= offer_queue.front().offer_min_age) &&
                    (people_queue.front().age <= offer_queue.front().offer_max_age) &&
                    (offer_queue.front().sex == "-" || people_queue.front().sex == offer_queue.front().sex) &&
                    (offer_queue.front().education == "-" || people_queue.front().education == offer_queue.front().education) &&
                    (offer_queue.front().last_experience == 0 || people_queue.front().last_experience >= offer_queue.front().last_experience) &&
                    (offer_queue.front().sum_experience == 0 || people_queue.front().sum_experience >= offer_queue.front().sum_experience) &&
                    (people_queue.front().desired_position == "-" || people_queue.front().desired_position == offer_queue.front().desired_position) &&
                    (people_queue.front().desired_salary <= offer_queue.front().desired_salary))
                {
                    cout << "Подходит" << endl;
                    offer_queue.pop();
                    m = 4;
                }
                else
                {
                    cout << "Не подходит" << endl;
                    offer_queue.pop();
                }
            }
            people_queue.pop();
        }
        cout << "\n\n" << endl;
    }

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



    return 0;
}