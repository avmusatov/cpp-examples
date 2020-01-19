//
// Created by Anton Musatov on 16.01.2020.
//

#include "Dean.h"

Dean::Dean(Group group) {
    add_group(group);
}

Dean::Dean(const std::string & filename) {
    fill(filename);
}

void Dean::add_group(const Group & group) {
    groups.push_back(group);
}

void Dean::set_marks(const std::string & group_name, int id, const std::vector<int>& marks){
    for (auto & group : groups) {
        if (group.get_name() == group_name){
            Student * ptr = group.find_student(id);
            if (ptr != nullptr)
                for (auto mark: marks) ptr->set_mark(mark);
        }
    }
}

void Dean::set_random_marks(const std::string & group_name, int num) {
    Group * group = find_group(group_name);
    if (group != nullptr){
        int size = group->get_size();

        for (int i = 0; i < size ; i++){
            for (int j = 0; j < num; j++)
                group->find_student(i)->set_mark(rand() % 10);
        }
    } else {
        std::cout << "Нет такой группы!"<< std::endl;
    }
}

void Dean::choose_head(const std::string & group_name) {
    Group * ptr = find_group(group_name);
    if (ptr != nullptr){
        ptr->set_head(rand() % ptr->get_size());
    } else {
        std::cout << "Нет такой группы!"<< std::endl;
    }
}

void Dean::student_transfer(const std::string & name, const std::string & group_name_from, const std::string & group_name_to) {
    Group * group_ptr_from = find_group(group_name_from);
    Group * group_ptr_to = find_group(group_name_to);
    Student * student_ptr = group_ptr_from->find_student(name);
    if (student_ptr != nullptr && group_ptr_from != nullptr && group_ptr_to != nullptr ){
        Student student_copy = * student_ptr;
        group_ptr_from->expel_student(name);
        group_ptr_to->add_student(name);
        std::vector<int> marks = student_ptr->get_marks();
        set_marks(group_name_to,group_ptr_to->get_size() - 1,marks);
    } else {
        std::cout << "Некорректные данные!" << std::endl;
    }


}

Group * Dean::find_group(const std::string & group_name) {
    for (auto & group : groups){
        if (group.get_name() == group_name)
            return &group;
    }
    return nullptr;
}

std::vector<Group> Dean::get_groups() const {return groups;}

std::vector<std::string> Dean::split (const std::string & s, char delimiter){
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (getline(tokenStream, token, delimiter)){
        tokens.push_back(token);
    }
    return tokens;
}

void Dean::fill(const std::string & filename) {
    std::ifstream file(std::string("C:\\Users\\Anton Musatov\\cpp-examples\\parser\\") + filename);
    system("chcp 65001");
    while (!file.eof()){
        std::string buf;
        getline(file, buf, '\n');
        std::vector<std::string> data = split(buf,':');


        Group * group = find_group(data[1]);
        if (group == nullptr){
            Group tmp(std::string(data[1]),std::string(" "));
            add_group(tmp);
            find_group(data[1])->add_student(data[0]);
        } else {
            group->add_student(data[0]);
        }
    }
}