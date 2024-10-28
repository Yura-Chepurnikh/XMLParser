#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <string>
#include <vector>

//struct JSONKeyValue {
//    std::string json_value;
//    std::string json_key;
//
//    JSONKeyValue(std::string json_value, std::string json_key) :
//        json_value(json_value), json_key(json_key) { }
//};

struct Node {
    std::string value;
    std::string key;

    //JSONKeyValue json_kv;

    Node* parent;
    std::vector<Node*> children;
    Node(const std::string& str) : key(str), value(value), parent(nullptr) { }
};