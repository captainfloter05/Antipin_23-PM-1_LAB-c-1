#include <iostream>
#include <fstream>
#include <string>

#include "funcs.h"

using namespace std;

void funcs::save(Furniture* arr, const int& n) {
    ofstream file("furniture.txt");
    if (!file.is_open()) {
        cout << "save error (hehehehaw)" << endl;
        return;
    }
    file << n << endl;
    for (int i = 0; i < n; i++)
        file << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
    file.close();
}

Furniture* funcs::load(int& n) {
    ifstream file("furniture.txt");
    if (!file.is_open()) {
        cout << "load error (hehehehaw)" << endl;
        return nullptr;
    }
    file >> n;
    if (n <= 0) {
        cout << "load: n error" << endl;
        return nullptr;
    }

    Furniture* arr = new Furniture[n];
    for (int i = 0; i < n; i++) {
        string name;
        string material;
        int per;
        file >> name >> material >> per;
        arr[i].setName(name);
        arr[i].setMaterial(material);
        arr[i].setPer(per);
    }
    file.close();
    return arr;
}

/*void funcs::search(Furniture* arr, const int& n) {
    int flt;
    cout << "1-name,2-material,3-period" << endl;
    cin >> flt;
    switch (flt) {
    case 1:
    {
        cout << "name:";
        string searchName;
        cin >> searchName;
        for (int i = 0; i < n; i++) {
            if (searchName == arr[i].name()) cout << "found->" << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
            else cout << "not found..." << endl;
        } break;
    }
    case 2:
    {
        cout << "material:";
        string searchMat;
        cin >> searchMat;
        for (int i = 0; i < n; i++) {
            if (searchMat == arr[i].material()) cout << "found->" << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
            else cout << "not found..." << endl;
        } break;
    }
    case 3:
        cout << "period:";
        int searchPer;
        cin >> searchPer;
        for (int i = 0; i < n; i++) {
            if (searchPer == arr[i].per()) cout << "found->" << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
            else cout << "not found..." << endl;
        } break;
    default:
        break;
    }
}*/