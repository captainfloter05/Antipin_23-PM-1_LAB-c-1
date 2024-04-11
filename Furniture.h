#pragma once

#include <string>
using namespace std;

class Furniture {
private:
    string _name;
    string _material;
    int _per = 0;
public:
    string name() const;
    void setName(const string& name);

    string material() const;
    void setMaterial(const string& material);

    int per() const;
    void setPer(const int& per);
};