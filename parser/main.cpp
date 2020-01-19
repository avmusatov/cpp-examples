#include <iostream>
#include <vector>
#include <string>
#include <istream>
#include "Dean.h"
#include "Group.h"
#include "Student.h"

using namespace std;

int main() {
    string filename = "students.txt";
    Dean dean(filename);

    dean.set_random_marks("17Ю-2", 5);
    cout << dean.find_group("17Ю-2")->find_student(0)->average_mark() << endl;
    dean.find_group("17Ю-2")->print_group();
    dean.find_group("17Ю-2")->expel_student("Херман Моисей Ульянович");
    cout << dean.find_group("17Ю-2")->find_student(0)->get_name()<< endl;
    dean.student_transfer("Нечаев Лавр Тимурович","17Ю-2","19ПИ-1");
    dean.choose_head("19ПИ-1");
    dean.find_group("17Ю-2")->print_group();
    dean.find_group("19ПИ-1")->print_group();
}