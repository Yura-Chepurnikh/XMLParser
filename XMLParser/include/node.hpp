#pragma once

#include <iostream>
#include <vector>
#include <string>

struct JSONLikeKeyValue {
    std::string m_value;
    std::string m_key;

    JSONLikeKeyValue(const std::string& value = "", const std::string& key = "") :
        m_value(value), m_key(key) { }
};

struct Node {
    std::string m_value;
    std::string m_key;

    std::vector<JSONLikeKeyValue> m_key_values;

    Node* m_parent;
    std::vector<Node*> m_children;
    Node(const std::string& str) : m_key(str), m_value(""), m_key_values(), m_parent(nullptr) { }
};