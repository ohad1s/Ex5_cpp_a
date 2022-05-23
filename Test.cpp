/**
 * AUTHOR: Ohad Shirazi
 * Date: 14-5-2022
 */
#include "doctest.h"
#include "sources//OrgChart.hpp"
#include <string>
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace ariel;

TEST_CASE ("IDF case") {
    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("MP"));
    CHECK_NOTHROW(organization.add_root("MAGAD"));
    CHECK_NOTHROW(organization.add_sub("MAGAD", "MP1"));
    CHECK_NOTHROW(organization.add_sub("MAGAD", "MP2"));
    CHECK_NOTHROW(organization.add_sub("MAGAD", "MP3"));
    CHECK_NOTHROW(organization.add_sub("MAGAD", "MP4"));
    CHECK_NOTHROW(organization.add_sub("MP1", "MM11"));
    CHECK_NOTHROW(organization.add_sub("MP1", "MM12"));
    CHECK_NOTHROW(organization.add_sub("MP2", "MM21"));
    CHECK_NOTHROW(organization.add_sub("MP2", "MM22"));
    CHECK_NOTHROW(organization.add_sub("MP3", "MM31"));
    CHECK_NOTHROW(organization.add_sub("MP3", "MM32"));
    CHECK_NOTHROW(organization.add_sub("MP4", "MM41"));
    CHECK_NOTHROW(organization.add_sub("MP4", "MM42"));
    CHECK_NOTHROW(organization.add_sub("MM11","Sergent11"));
    CHECK_NOTHROW(organization.add_sub("MM12","Sergent12"));
    CHECK_NOTHROW(organization.add_sub("MM21","Sergent21"));
    CHECK_NOTHROW(organization.add_sub("MM22","Sergent22"));
    CHECK_NOTHROW(organization.add_sub("MM31","Sergent31"));
    CHECK_NOTHROW(organization.add_sub("MM32","Sergent32"));
    CHECK_NOTHROW(organization.add_sub("MM41","Sergent41"));
    CHECK_NOTHROW(organization.add_sub("MM42","Sergent42"));
    SUBCASE("level order iterator"){
        string idf;
        for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
        {
            idf+=*it;
            idf+=" ";
//            cout << (*it) << " " ;
        }
        CHECK("MAGAD MP1 MP2 MP3 MP4 MM11 MM12 MM21 MM22 MM31 MM32 MM41 MM42 Sergent11 Sergent12 Sergent21 Sergent22 Sergent31 Sergent32 Sergent41 Sergent42 " == idf);
    }
            SUBCASE("preorder iterator"){
        string idf;
        for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
        {
            idf+=*it;
            idf+=" ";
//            cout << (*it) << " " ;
        }
                CHECK("MAGAD MP1 MM11 Sergent11 MM12 Sergent12 MP2 MM21 Sergent21 MM22 Sergent22 MP3 MM31 Sergent31 MM32 Sergent32 MP4 MM41 Sergent41 MM42 Sergent42 " == idf);
    }

            SUBCASE("reverse iterator"){
        string idf;
        for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
        {
            idf+=*it;
            idf+=" ";
//            cout << (*it) << " " ;
        }
                CHECK("Sergent11 Sergent12 Sergent21 Sergent22 Sergent31 Sergent32 Sergent41 Sergent42 MM11 MM12 MM21 MM22 MM31 MM32 MM41 MM42 MP1 MP2 MP3 MP4 MAGAD " == idf);
    }
}

TEST_CASE ("bad Organization") {
    OrgChart fail_organiztaion;
    CHECK_THROWS(fail_organiztaion.add_root(""));
    CHECK_THROWS(fail_organiztaion.add_root(" "));
    CHECK_THROWS(fail_organiztaion.add_root("\n"));
    CHECK_THROWS(fail_organiztaion.add_root("\t"));
    CHECK_NOTHROW(fail_organiztaion.add_root("OHAD"));
    CHECK_NOTHROW(fail_organiztaion.add_root("TAMAR"));
    CHECK_NOTHROW(fail_organiztaion.add_sub("TAMAR", "yossi"));
    CHECK_NOTHROW(fail_organiztaion.add_sub("yossi", "daniel"));
    CHECK_NOTHROW(fail_organiztaion.add_sub("daniel", "tal"));
    CHECK_NOTHROW(fail_organiztaion.add_sub("tal", "roni"));
    CHECK_THROWS(fail_organiztaion.add_sub("OHAD", "Liron"));
    CHECK_THROWS(fail_organiztaion.add_sub("Liron", "Or"));
    CHECK_THROWS(fail_organiztaion.add_sub("KING", "KAKA"));
}

TEST_CASE("My family case")
{
    vector<string> names = {"Miriam", "Moshe", "Zion", "Revital", "Ohad", "Liron"};
    vector<string> exp_level_order = {names[0], names[1], names[2], names[3], names[4], names[5]};
    vector<string> exp_reverse_order = {names[4], names[5], names[1], names[2], names[3], names[0]};
    vector<string> exp_preorder = {names[0], names[1], names[4], names[2], names[3], names[5]};
    OrgChart organization;
    organization.add_root(names[0])
            .add_sub(names[0], names[1])
            .add_sub(names[0], names[2])
            .add_sub(names[0], names[3])
            .add_sub(names[1], names[4])
            .add_sub(names[3], names[5]);
    size_t i = 0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
                CHECK_EQ(exp_level_order[i++], (*it));
    } // Needs to be like exp_level_order
    i = 0;
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
                CHECK_EQ(exp_reverse_order[i++], (*it));
    } // Needs to be like exp_reverse_order
    i = 0;
    for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
    {
                CHECK_EQ(exp_preorder[i++], (*it));
    } // Needs to belike exp_preorder
    i = 0;
    for (auto element : organization)
    { // this should work like level order
                CHECK_EQ(exp_level_order[i++], element);
    } // Needs to be like exp_level_order
    i = 0;
    // demonstrate the arrow operator:
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
                CHECK_EQ(exp_level_order[i++].size(), it->size());
    } // Needs to be like exp_level_order
}
