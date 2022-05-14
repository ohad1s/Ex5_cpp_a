//
// Created by shira on 13/05/2022.
//
#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#ifndef EX5_CPP_A_ORGCHART_H
#define EX5_CPP_A_ORGCHART_H

#endif //EX5_CPP_A_ORGCHART_H
using namespace std;
namespace ariel {
    class OrgChart {
    public:
        typedef struct node
        {
            string value;
            node *son;
            node *brother;
        }node;
        typedef struct root
        {
            string value;
            node *son;
        }root;


        OrgChart();
        ~OrgChart();
        OrgChart& add_root(string s);
        OrgChart&  add_sub(string s1,string s2);
        friend std::ostream &operator<<(std::ostream &output, const OrgChart &o);
        string* begin_level_order();
        string* end_level_order();
        string* begin_reverse_order();
        string* end_reverse_order();
        string* begin_preorder();
        string* end_preorder();
        string* reverse_order();
        string* begin(){
            return begin_level_order();
        }
        string* end(){
            return end_level_order();
        }


    };
}