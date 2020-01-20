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

    dean.set_random_marks("17Ю-2", 7);
    dean.set_random_marks("18ПМИ-2",8);
    dean.set_random_marks("19ПИ-1",7);

    dean.choose_head("17Ю-2");
    dean.choose_head("18ПМИ-2");
    dean.choose_head("19ПИ-1");

    dean.find_group("17Ю-2")->set_spec("Юрисприденция");
    dean.find_group("18ПМИ-2")->set_spec("Прикладная математика и информатика");
    dean.find_group("19ПИ-1")->set_spec("Программирование");

    dean.write("output1.txt");

    dean.find_group("17Ю-2")->expel_student("Херман Моисей Ульянович");
    dean.student_transfer("Нечаев Лавр Тимурович","17Ю-2","19ПИ-1");
    dean.check_progress(4.5);
    dean.choose_head("17Ю-2");
    dean.choose_head("18ПМИ-2");
    dean.choose_head("19ПИ-1");
    dean.write("output2.txt");
}