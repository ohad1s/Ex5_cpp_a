//
// Created by shira on 13/05/2022.
//
#include "OrgChart.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

namespace ariel {
    OrgChart::OrgChart() {
    }

    OrgChart::~OrgChart() {}


    OrgChart &OrgChart::add_root(string s) {
        if (s=="" || s== " " || s== "\n" || s=="\t"){
            throw invalid_argument("invalid string for root");
        }
        this->root.value = s;
        return *this;
    }

    OrgChart &OrgChart::add_sub(string s1, string s2) {
        bool b = add_sub_check(s1, s2, &root);
        if (b) {
            return *this;
        }
        throw std::invalid_argument("There is no such Node 'root' in the OrgChart");
    }

    bool OrgChart::add_sub_check(string s1, string s2, node *root) {
        bool x = false;
        if (root->value == s1) {
            node *new_node = new node();
            new_node->value = s2;
            root->sons.push_back(new_node);
            return true;
        }
//        vector <node> sons_of_root = root->sons;
        for (node* s: root->sons){
            x= add_sub_check(s1,s2,s);
            if (x){
                return true;
            }
        }
        return x;
    }

    std::ostream &operator<<(std::ostream &output, const OrgChart &o) {
//        for (auto it = o.begin_level_order(); it != o.end_level_order(); ++it) {
//            output << (*it) << " ";
//        }
        return output;
    }

}
