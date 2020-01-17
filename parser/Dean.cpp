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

void Dean::set_marks(std::string group_name, int id, const std::vector<int>& marks){
    for (auto & group : groups) {
        if (group.get_name() == group_name){
            Student * ptr = group.find_student(id);
            for (auto mark: marks) ptr->set_mark(mark);
        }
    }
}

Group * Dean::find_group(std::string name) {
    for (auto & group : groups){
        if (group.get_name() == name)
            return &group;
    }
    return nullptr;
}

std::vector<Group> Dean::get_groups() const {return groups;}