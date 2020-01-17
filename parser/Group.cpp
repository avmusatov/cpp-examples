//
// Created by Anton Musatov on 16.01.2020.
//

#include "Group.h"

Group::Group(std::string name, std::string spec)
: name(name), spec(spec), head(Student()), size(0) {}

void Group::add_student(const std::string name) {
    Student student(students.size(), name, this->name);
    students.push_back(student);
    size++;
}

Student * Group::find_student(int id) {
    if (id >= 0 && id < students.size())
        return &students[id];
    else
        return nullptr;
}

void Group::expel_student(const std::string name){
    int id = find_student(name) ->get_id();
    for (int i = id + 1; i < students.size(); i++){
        students[i].set_id(i - 1);
    }
    students.erase(students.begin() + id);
    size--;
}

Student * Group::find_student(std::string name) {
    for (auto & student: students){
        if (name == student.get_name()){
            return &student;
        }
    }
    return nullptr;
}

void Group::set_head(int id){
    head = students[id];
}

Student Group::get_head() const {return head;}

std::string Group::get_name() const {return name;}

std::string Group::get_spec() const {return spec;}

size_t Group::get_size() const {return size;}

double Group::average_group() const {
    double sum = 0;
    for (auto & student: students){
        sum += student.average_mark();
    }
    return sum/students.size();
}

void Group::print_group() const {
    std::cout << "Группа: " << name << std::endl;
    for (auto & student : students){
        std::cout << student.get_id() << ". " << student.get_name() << ':' << student.get_group() << std::endl;
        std::cout << '{';
        for (auto & mark : student.get_marks())
            std::cout << " " << mark << " ";
        std::cout << '}' << std::endl;
    }
}
