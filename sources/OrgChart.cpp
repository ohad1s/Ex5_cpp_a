//
// Created by shira on 13/05/2022.
//
#include "OrgChart.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

namespace ariel {
    OrgChart::OrgChart() {}

    OrgChart::~OrgChart() {}


    OrgChart &OrgChart::add_root(string s) {
        return *this;
    }

    OrgChart &OrgChart::add_sub(string s1, string s2) {
        return *this;
    }

    std::ostream &operator<<(std::ostream &output, const OrgChart &o) {
        return output;
    }

    string *OrgChart::begin_level_order() {
        string x = "ohad";
        string *ohad = &x;
        return ohad;
    }

    string *OrgChart::end_level_order() {
        string x = "ohad";
        string *ohad = &x;
        return ohad;
    }

    string *OrgChart::begin_reverse_order() {
        string x = "ohad";
        string *ohad = &x;
        return ohad;
    }

    string *OrgChart::end_reverse_order() {
        string x = "ohad";
        string *ohad = &x;
        return ohad;
    }

    string *OrgChart::begin_preorder() {
        string x = "ohad";
        string *ohad = &x;
        return ohad;
    }

    string *OrgChart::end_preorder() {
        string x = "ohad";
        string *ohad = &x;
        return ohad;
    }

    string *OrgChart::reverse_order() {
        string x = "ohad";
        string *ohad = &x;
        return ohad;
    }
}