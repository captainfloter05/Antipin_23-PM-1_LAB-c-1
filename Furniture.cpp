#include "Furniture.h"

using namespace std;

string Furniture::name() const {
    return _name;
}

void Furniture::setName(const string& name) {
    if (_name != name)
        _name = name;
}

string Furniture::material() const {
    return _material;
}

void Furniture::setMaterial(const string& material) {
    if (_material != material)
        _material = material;
}

int Furniture::per() const {
    return _per;
}

void Furniture::setPer(const int& per) {
    if (per >= 0 && _per != per)
        _per = per;
}
