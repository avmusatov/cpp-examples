//
// Created by Anton Musatov on 16.01.2020.
//

#include "Dean.h"

Dean::Dean(Group group) {
    add_group(group);
}

void Dean::add_group(const Group & group) {
    groups.push_back(group);
}

void Dean::set_marks(const std::string group_name, int id, const std::vector<int>& marks){
    for (auto & group : groups) {
        if (group.get_name() == group_name){
            Student * ptr = group.find_student(id);
            if (ptr != nullptr)
                for (auto mark: marks) ptr->set_mark(mark);
        }
    }
}

void Dean::set_random_marks(const std::string group_name, int num) {
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

Group * Dean::find_group(std::string group_name) {
    for (auto & group : groups){
        if (group.get_name() == group_name)
            return &group;
    }
    return nullptr;
}

std::vector<Group> Dean::get_groups() const {return groups;}