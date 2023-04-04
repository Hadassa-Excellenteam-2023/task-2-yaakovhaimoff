#pragma once

#include "macros.h"

class Piece;

template<typename T>
class Factory {

    static auto &getMap() {
        static std::map<char, pFnc> m_map;
        return m_map;
    }

public:
    using pFnc = std::unique_ptr<T>(*)();

    static unique_ptr<T> create(const char &name);

    static bool registerIt(const char &name, pFnc f);

};

template<typename T>
unique_ptr<T> Factory<T>::create(const char &name) {
    auto it = Factory<T>::getMap().find(name);
    if (it == Factory<T>::getMap().end())
        return nullptr;
    return it->second();
}

template<typename T>
bool Factory<T>::registerIt(const char &name, pFnc f) {
    Factory<T>::getMap().emplace(name, f);
    return true;
}
