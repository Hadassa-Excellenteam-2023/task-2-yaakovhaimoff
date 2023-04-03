#pragma once

#include <string>
#include <map>
#include <memory>

#include "IncPieces/Piece.h"

using std::unique_ptr;

template<typename T>
class Factory {

    static auto &getMap() {
        static std::map<std::string, pFnc> m_map;
        return m_map;
    }

public:
    using pFnc = std::unique_ptr<T>(*)();

    static unique_ptr<T> create(const std::string &name,
                                     const int &x,
                                     const int &y,
                                     Piece *piece);

    static bool registerIt(const std::string &name, pFnc f);

    static bool checkIfNameInMap(const std::string &name) { return Factory<T>::getMap().count(name) > 0; }
};

template<typename T>
unique_ptr<T> Factory<T>::create(const std::string &name,
                                      const int &x,
                                      const int &y,
                                      Piece *piece) {
    auto it = Factory<T>::getMap().find(name);
    if (it == Factory<T>::getMap().end())
        return nullptr;
    return it->second(x, y, piece);
}

template<typename T>
bool Factory<T>::registerIt(const std::string &name, pFnc f) {
    Factory<T>::getMap().emplace(name, f);
    return true;
}
