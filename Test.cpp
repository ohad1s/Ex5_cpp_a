/**
 * AUTHOR: Ohad Shirazi
 * Date: 14-5-2022
 */
#include "doctest.h"
#include "OrgChart.hpp"
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
            cout << (*it) << " " ;
        }
        CHECK("MAGAD MP1 MP2 MP3 MP4 MM11 MM12 MM21 MM22 MM31 MM32 MM41 MM41 Sergent11"
              " Sergent12 Sergent21 Sergent22 Sergent31 Sergent32 Sergent41 Sergent42 " == idf);
    }
}

TEST_CASE ("bad Organization") {
    OrgChart fail_organiztaion;
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
