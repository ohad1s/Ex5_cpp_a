//
// Created by shira on 13/05/2022.
//
#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>

#ifndef EX5_CPP_A_ORGCHART_H
#define EX5_CPP_A_ORGCHART_H

#endif //EX5_CPP_A_ORGCHART_H
using namespace std;
namespace ariel {
    class OrgChart {
    public:
        typedef struct node {
            string value;
            vector<node *> sons;
        } node;

        node root;

        OrgChart();

        ~OrgChart();

        OrgChart &add_root(string s);

        OrgChart &add_sub(string s1, string s2);

        bool add_sub_check(string s1, string s2, node *root);

        friend std::ostream &operator<<(std::ostream &output, const OrgChart &o);

        class level_order_Iterator {
        public:
            queue<node *> sons;
            node *_ptr;


            level_order_Iterator(node *ptr) : _ptr(ptr) {
                this->sons.push(ptr);
            }

            string &operator*() {
                return _ptr->value;
            }

            node *operator&() {
                return _ptr;
            }

            string &operator*() const {
                return _ptr->value;
            }

            string *operator->() const {
                return &(_ptr->value);
            }

            level_order_Iterator &operator++() {
                node *curr = this->sons.front();
                for (size_t i = 0; i < curr->sons.size(); ++i) {
                    this->sons.push(curr->sons.at(i));
                }
                if (this->sons.size() == 1 && sons.front()->sons.empty()) {
                    this->_ptr = nullptr;
                } else {
                    this->sons.pop();
                    this->_ptr = sons.front();
                }
                return *this;
            }


            const level_order_Iterator operator++(int) {
                level_order_Iterator tmp = *this;
                node *curr = this->sons.front();
                for (size_t i = 0; i < curr->sons.size(); ++i) {
                    this->sons.push(curr->sons.at(i));
                }
                if (this->sons.size() == 1 && sons.front()->sons.empty()) {
                    this->_ptr = nullptr;
                } else {
                    this->sons.pop();
                    this->_ptr = sons.front();
                }
                return tmp;
            }

            bool operator==(const level_order_Iterator &it) const {
                return _ptr == it._ptr;
            }

            bool operator!=(const level_order_Iterator &it) const {
                return _ptr != it._ptr;
            }
        };

        level_order_Iterator begin_level_order() {
//            cout << "begin" << endl;
            return level_order_Iterator{&root};
        }

        level_order_Iterator end_level_order() {
            return nullptr;
        }

        class preorder_Iterator {
        public:
            stack<node *> sons;
            node *_ptr;


            preorder_Iterator(node *ptr) : _ptr(ptr) {
                this->sons.push(ptr);
            }

            string &operator*() {
                return _ptr->value;
            }

            node *operator&() {
                return _ptr;
            }

            string &operator*() const {
                return _ptr->value;
            }

            string *operator->() const {
                return &(_ptr->value);
            }

            preorder_Iterator &operator++() {
                node *curr = this->sons.top();
                this->sons.pop();
                for (int i = (int) curr->sons.size() - 1; i >= 0; --i) {
                    this->sons.push(curr->sons.at((unsigned int) i));
                }
                if (this->sons.empty()) {
                    this->_ptr = nullptr;
                } else {
                    this->_ptr = sons.top();
                }
                return *this;
            }


            const preorder_Iterator operator++(int) {
                preorder_Iterator tmp = *this;
                node *curr = this->sons.top();
                this->sons.pop();
                for (int i = (int) curr->sons.size() - 1; i >= 0; --i) {
                    this->sons.push(curr->sons.at((unsigned int) i));
                }
                if (this->sons.empty()) {
                    this->_ptr = nullptr;
                } else {
                    this->_ptr = sons.top();
                }
                return tmp;
            }

            bool operator==(const preorder_Iterator &it) const {
                return _ptr == it._ptr;
            }

            bool operator!=(const preorder_Iterator &it) const {
                return _ptr != it._ptr;
            }
        };

        preorder_Iterator begin_preorder() {
            return preorder_Iterator{&root};
        }

        preorder_Iterator end_preorder() {
            return nullptr;
        }

        class reverse_order_Iterator {
        public:
            vector<node *> sons;
            queue<node *> my_queue;
            node *_ptr;
            int index;


            reverse_order_Iterator(node *ptr) : _ptr(ptr) {
                if (ptr == nullptr) {
                    return;
                }
                node *curr = ptr;
                my_queue.push(curr);
                while (!my_queue.empty()) {
                    for (int i = (int) my_queue.front()->sons.size() - 1; i >= 0; --i) {
                        this->my_queue.push(my_queue.front()->sons.at((unsigned int) i));
                    }
                    node *f = my_queue.front();
                    my_queue.pop();
                    sons.push_back(f);
                }
                index = sons.size() - 1;
                _ptr = this->sons.at((unsigned int) index);
            }

            string &operator*() {
                return _ptr->value;
            }

            node *operator&() {
                return _ptr;
            }

            string &operator*() const {
                return _ptr->value;
            }

            string *operator->() const {
                return &(_ptr->value);
            }

            reverse_order_Iterator &operator++() {
                index--;
                try {
                    _ptr = this->sons.at((unsigned int) index);
                }
                catch (const std::exception &e) {
                    _ptr = nullptr;
                }
                return *this;
            }


            const reverse_order_Iterator operator++(int) {
                reverse_order_Iterator tmp = *this;
                index--;
                try {
                    _ptr = this->sons.at((unsigned int) index);
                }
                catch (const std::exception &e) {
                    _ptr = nullptr;
                }
                return tmp;
            }

            bool operator==(const reverse_order_Iterator &it) const {
                return _ptr == it._ptr;
            }

            bool operator!=(const reverse_order_Iterator &it) const {
                return _ptr != it._ptr;
            }
        };

        reverse_order_Iterator begin_reverse_order() {
            return reverse_order_Iterator{&root};
        }

        reverse_order_Iterator reverse_order() {
            return reverse_order_Iterator{nullptr};
        }

        level_order_Iterator begin() {
            return level_order_Iterator{&root};
        }

        level_order_Iterator end() {
            return nullptr;
        }
    };
}