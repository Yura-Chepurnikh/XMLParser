#pragma once

#include <iostream>
#include <vector>
#include <string>

struct KeyValue {
    std::string m_value;
    std::string m_key;

    KeyValue(const std::string& value = "", const std::string& key = "") :
        m_value(value), m_key(key) { }
};

struct Node {
    std::string m_value;
    std::string m_key;

    KeyValue m_key_value;

    Node* m_parent;
    std::vector<Node*> m_children;
    Node(const std::string& str) : m_key(str), m_value(m_value), m_parent(nullptr) { }
};