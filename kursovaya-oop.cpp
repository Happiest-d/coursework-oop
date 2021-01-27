#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <cstdlib>
#include<queue>
#include <map>

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

//Получение списка безработных из файла
void get_unemployee(queue<Unemployed>& q, string filename) {
    Unemployed person_for_queue;
    fstream get_people;
    get_people.open(filename, fstream::in | fstream::out | fstream::app);
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

            person_for_queue.update(_surname, stoi(_age), _profession, _last_position, stoi(_date),
                _sex, _education, stoi(_last_experience), stoi(_sum_experience), _desired_position, stoi(_desired_salary));

            q.push(person_for_queue);
        }
    }
    get_people.close();
}

//Получение списка вакансий из файла
void get_vacancy(queue<Vacancy>& q, string filename) {
    Vacancy offer_for_queue;
    fstream get_offer;
    get_offer.open(filename, fstream::in | fstream::out | fstream::app);
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

            offer_for_queue.update(_company, stoi(_offer_min_age), stoi(_offer_max_age),
                _sex, _education, stoi(_last_experience), stoi(_sum_experience), _desired_position, stoi(_desired_salary));

            q.push(offer_for_queue);
        }
    }
    get_offer.close();
}

int main()
{
    setlocale(LC_ALL, "ru");

    string unemployed_path = "unemployed.txt";
    string vacancy_path = "vacancy.txt";
    string output_path = "out.txt";

    queue<Unemployed> people_queue;
    queue<Vacancy> offer_queue;

    map <string, int> position;
    map <string, int> company;

    int get_job = 0;

    //Модель работы биржи труда в течение 30 дней
    fstream out;
    out.open(output_path, fstream::out | fstream::trunc);
    for (int i = 1; i <= 30; i++) 
    {
        out << "----------День " << i << "----------" "\n\n";
        //В день от 0 до 3 человек
        int people_per_day = rand() % 4; 
        out << "Человек в день: " << people_per_day << "\n\n";
        for (int n = 1; n <= people_per_day; n++) 
        {
            //Если в очереди нет людей, то заполняем её из файла
            if (people_queue.empty()) 
            {
                //Получение списка безработных из файла
                get_unemployee(people_queue, unemployed_path);
            }


            //Если в очереди нет вакансий, то заполняем её из файла
            if (offer_queue.empty())
            {
                //Получение списка вакансий из файла
                get_vacancy(offer_queue, vacancy_path);
            }



            //Выводим информацию о безработном
            out << "Информация о безработном номер  " << n << " :" << "\n";
            out << "Фамилия: " << people_queue.front().surname << "\n";
            out << "Возраст: " << people_queue.front().age << "\n";
            out << "Пол: " << people_queue.front().sex << "\n";
            out << "Образование: " << people_queue.front().education << "\n";
            out << "Стаж работы в последней занимаемой должности: " << people_queue.front().last_experience << "\n";
            out << "Общий стаж: " << people_queue.front().sum_experience << "\n";
            out << "Дата постановки на учёт: " << people_queue.front().date << "\n";
            out << "Желаемая должность: " << people_queue.front().desired_position << "\n";
            out << "Желаемая зарплата: " << people_queue.front().desired_salary << "\n\n\n";

            //Даём безработному до 10 вакансий, он выбирает первую подхящую
            for (int m = 1; m <= 10; m++)
            {

                //Если в очереди нет людей, то заполняем её из файла
                if (people_queue.empty())
                {
                    //Получение списка безработных из файла
                    get_unemployee(people_queue, unemployed_path);
                }

                //Если в очереди нет вакансий, то заполняем её из файла
                if (offer_queue.empty())
                {
                    //Получение списка вакансий из файла
                    get_vacancy(offer_queue, vacancy_path);
                }

                position[offer_queue.front().desired_position]++;
                company[offer_queue.front().company]++;

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
                    //cout << "Подходит" << endl;
                    out << "Найдена подходящая работа!" << "\n";
                    out << "Работодатель: " << offer_queue.front().company << "\n";
                    out << "Должность: " << offer_queue.front().desired_position << "\n";
                    out << "Зарплата: " << offer_queue.front().desired_salary << "\n\n\n";
                    get_job++;
                    offer_queue.pop();
                    m = 999;
                }
                else
                {
                    //cout << "Не подходит" << endl;
                    out << "Вакансия не подходит!" << "\n";
                    out << "Работодатель: " << offer_queue.front().company << "\n";
                    out << "Должность: " << offer_queue.front().desired_position << "\n";
                    out << "Зарплата: " << offer_queue.front().desired_salary << "\n\n\n";
                    offer_queue.pop();
                }

            }
            people_queue.pop();
        }
    }

    out << "----------Итоги----------" << "\n\n";

    map <string, int>::iterator cur;
    int num_pos = 0;
    string name_pos;
    int num_comp = 0;
    string name_comp;

    //Поиск самой востребованной профессии
    for (cur = position.begin(); cur != position.end(); cur++)
    {
        if ((*cur).second > num_pos)
        {
            num_pos = (*cur).second; name_pos = (*cur).first;
        }
    }

    //Поиск самой популярной компании
    for (cur = company.begin(); cur != company.end(); cur++)
    {
        if ((*cur).second > num_comp)
        {
            num_comp = (*cur).second; name_comp = (*cur).first;
        }
    }

    out << "За месяц " << get_job << " человек(а) получили работу" << "\n\n";

    out << "Самая востребованная профессия: " << name_pos << "\n";
    out << "Количество вакансий: " << num_pos << "\n\n";

    out << "Самая популярная компания: " << name_comp << "\n";
    out << "Количество вакансий: " << num_comp << "\n\n";

    out.close();

    return 0;
}