#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <istream>
#include "Dean.h"
#include "Group.h"
#include "Student.h"

using namespace std;

std::vector<std::string> split (const std::string & s, char delimiter){
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    Group pmi(string("18ПМИ-2"),string("Computer science"));
    Dean dean;

    ifstream file(R"(C:\Users\Anton Musatov\CLionProjects\parser\students.txt)");
    system("chcp 65001");
    while (!file.eof()){
        string buf;
        getline(file, buf, '\n');
        vector<string> data = split(buf,':');

        Group * group = dean.find_group(data[1]);
        if (group == nullptr){
            Group tmp(string(data[1]),string(" "));
            dean.add_group(tmp);
            dean.find_group(data[1])->add_student(data[0]);
        } else {
            group->add_student(data[0]);
        }

    }

    vector<int> marks = {5,6,7,10,9};
    dean.set_marks(string("17Ю-2"),0,marks);
    cout << dean.find_group("17Ю-2")->find_student(0)->get_marks()[2] << endl;
}