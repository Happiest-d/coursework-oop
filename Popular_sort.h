#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

void job_sort()
{
	map <string, int> words;

	string arr[5] = { "one", "two", "three", "one", "one" };

	for (auto word : arr) {
		words[word]++;
	}

	ofstream out;
	out.open("out.txt");

	int count = 0;

	map <string, int>::iterator cur;

	out << "Job count:" << endl;

	for (cur = words.begin(); cur != words.end(); cur++)
	{
		out << (*cur).first << ": " << (*cur).second << endl; count += (*cur).second;
	}

	out << "Job percenc:" << endl;

	for (cur = words.begin(); cur != words.end(); cur++)
	{
		out << (*cur).first << ": " << (float)((float)(*cur).second / (float)count) * 100 << "%" << endl;
	}
}

//job_sort();

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
