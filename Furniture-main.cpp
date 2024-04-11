// лаба1 Антипин Р 23-ПМ-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>

#include "Furniture.h"
#include "funcs.h"

using namespace std;
using namespace funcs;

int main() {
    int flt=0;
    int flt1, flt2, flt3;
    int n{};
    cout << "n=";
    cin >> n;
    if (n < 1)
        return 0;

    Furniture* arr = new Furniture[n];
    for (int i = 0; i < n; i++) {
        string name;
        string material;
        int per;
        cout << "name[" << i << "]=";
        cin >> name;
        cout << "material[" << i << "]=";
        cin >> material;
        cout << "per[" << i << "]=";
        cin >> per;
        arr[i].setName(name);
        arr[i].setMaterial(material);
        arr[i].setPer(per);
    }

    cout << "\ncreated arr (hooray):" << endl;
    for (int i = 0; i < n; i++) {
        cout << "name[" << i << "]=" << arr[i].name() << endl;
        cout << "material[" << i << "]=" << arr[i].material() << endl;
        cout << "per[" << i << "]=" << arr[i].per() << endl;
    }
    save(arr, n);

    while (1) {
        cout << "1-create,2-load,3-get outta here" << endl;
        cin >> flt1;
        if (flt1 < 0 || flt1>3) return 0;
        switch (flt1) {
        case 1: {
            cout << "1-create new arr(Furniture),2-change arr(Furniture),3-add new elements for arr(Furniture),4-delete elements from arr(Furniture)" << endl;
            cin >> flt2;
            switch (flt2)
            {
            case 1: {
                cout << "n=";
                cin >> n;
                if (n < 1) return 0;
                Furniture* arr = new Furniture[n];
                for (int i = 0; i < n; i++) {
                    string name;
                    string material;
                    int per;
                    cout << "name[" << i << "]=";
                    cin >> name;
                    cout << "material[" << i << "]=";
                    cin >> material;
                    cout << "per[" << i << "]=";
                    cin >> per;
                    arr[i].setName(name);
                    arr[i].setMaterial(material);
                    arr[i].setPer(per);
                    save(arr, n);
                }
            }
            case 2: {
                cout << "Which element?" << endl;
                cin >> flt3;
                arr = load(n);
                for (int i = 0; i <= flt3; i++) {
                    if (i == flt3) {
                        string name;
                        string material;
                        int per;
                        cout << "name[" << i << "]=";
                        cin >> name;
                        cout << "material[" << i << "]=";
                        cin >> material;
                        cout << "per[" << i << "]=";
                        cin >> per;
                        arr[i].setName(name);
                        arr[i].setMaterial(material);
                        arr[i].setPer(per);
                        save(arr, n);
                    }

                }
            }
            case 3: {
                string name;
                string material;
                int per;
                Furniture* arrflt = new Furniture[n + 1];
                for (int i = 0; i < n; i++) {
                    arrflt[i] = arr[i];
                }
                delete[] arr;
                Furniture* arr = new Furniture[n + 1];
                for (int i = 0; i < n + 1; i++) {
                    arr[i] = arrflt[i];
                }
                delete[] arrflt;
                cout << "name[" << n << "]=";
                cin >> name;
                cout << "material[" << n << "]=";
                cin >> material;
                cout << "per[" << n << "]=";
                cin >> per;
                arr[n].setName(name);
                arr[n].setMaterial(material);
                arr[n].setPer(per);
                save(arr, n + 1);
            }
            case 4: {
                cout << "Which element?" << endl;
                cin >> flt3;
                for (int i = 0; i < n; i++) {
                    if (i == flt3) {
                        Furniture* arrflt = new Furniture[n - 1];
                        for (int i = 0; i < flt3; i++) {
                            arrflt[i] = arr[i];
                        }
                        for (int i = flt3 + 1; i < n - 1; i++) {
                            arrflt[i] = arr[i];;
                        }
                        delete[] arr;
                        Furniture* arr = new Furniture[n - 1];
                        for (int i = 0; i < n - 1; i++) {
                            arr[i] = arrflt[i];
                        }
                        delete[] arrflt;
                        save(arr, n - 1);
                    }
                }
            }
            }
        }
        case 2: {
            cout << "1-load full arr(Furniture),2-find element from arr(Furniture)" << endl;
            cin >> flt3;
            if (flt3 < 0 || flt3>2) return 0;
            switch (flt3) {
            case 1: {
                cout << "loading from (Furniture.txt): " << endl;
                arr = load(n);
                cout << "loaded n=" << n << endl;
                if (!arr) {
                    cout << "arr is null (hehehehaw)" << endl;
                    return 0;
                }
                for (int i = 0; i < n; i++) {
                    cout << "name[" << i << "]=" << arr[i].name() << endl;
                    cout << "material[" << i << "]=" << arr[i].material() << endl;
                    cout << "per[" << i << "]=" << arr[i].per() << endl;
                }
            }
            case 2: {
                cout << "1-name,2-material,3-period" << endl;
                cin >> flt3;
                if (flt3 < 0 || flt3>3) return 0;
                switch (flt3) {
                case 1: {
                    string nameflt;
                    cout << "name=" << endl;
                    cin >> nameflt;
                    for (int i = 0; i < n; i++) {
                        if (arr[i].name() == nameflt) {
                            cout << "found->" << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
                            flt = 1;
                        }
                    }
                    if (flt == 0) cout << "not found (hehehehaw)" << endl;
                    flt = 0;
                }
                case 2: {
                    string matflt;
                    cout << "material=" << endl;
                    cin >> matflt;
                    for (int i = 0; i < n; i++) {
                        if (arr[i].material() == matflt) {
                            cout << "found->" << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
                            flt = 1;
                        }
                    }
                    if (flt == 0) cout << "not found (hehehehaw)" << endl;
                    flt = 0;
                }
                case 3: {
                    int perflt;
                    cout << "period=" << endl;
                    cin >> perflt;
                    for (int i = 0; i < n; i++) {
                        if (arr[i].per() == perflt) {
                            cout << "found->" << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
                            flt = 1;
                        }
                    }
                    if (flt == 0) cout << "not found (hehehehaw)" << endl;
                    flt = 0;
                }
                }
            }
            }
        }
        case 3: {
            break;
        }
        }
        delete[] arr;
        return 0;
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
