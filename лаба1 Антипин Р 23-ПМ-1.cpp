// лаба1 Антипин Р 23-ПМ-1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>

#include "Furniture.h"
#include "funcs.h"

using namespace std;
using namespace funcs;

int main() {
    int flt, flt1, flt3;
    int strnumber;
    string fltname, fltmaterial; int fltper;
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
        cout << endl;
        arr[i].setName(name);
        arr[i].setMaterial(material);
        arr[i].setPer(per);
    }

    cout << "created arr (hooray):" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
    }
    save(arr, n);

    cout << "1 - create, 2 - load, 3 - search, 4 - get outta here" << endl;
    cin >> flt;
    switch (flt) {
        case 1: {
            cout << "1 - create new arr, 2 - change arr, 3 - add new elements for arr, 4 - delete elements from arr" << endl;
            cin >> flt1;
            switch (flt1) {
                case 1: {
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
                        cout << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
                    }
                    save(arr, n);
                    break;
                    }
                case 2: {
                    cout << "which string - ";
                    cin >> strnumber;
                    arr=load(n);
                    for (int i = 0; i < n; i++) {
                        if (i == strnumber) {
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
                    break;
                }
                case 3: {
                    string name;
                    string material;
                    int per;
                    Furniture* fltarr = new Furniture[n + 1];
                    for (int i = 0; i < n; i++) {
                        fltarr[i] = arr[i];
                    }
                    delete[] arr;
                    Furniture* arr = new Furniture[n + 1];
                    for (int i = 0; i < n + 1; i++) {
                        arr[i] = fltarr[i];
                    }
                    delete[] fltarr;
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
                    break;
                }
                case 4: {
                    cout << "Which string - ";
                    cin >> strnumber;
                    for (int i = 0; i < n; i++) {
                        if (i == strnumber) {
                            Furniture* fltarr = new Furniture[n - 1];
                            for (int i = 0; i < strnumber; i++) {
                                fltarr[i] = arr[i];
                            }
                            for (int i = strnumber + 1; i < n - 1; i++) {
                                fltarr[i] = arr[i];
                            }
                            delete[] arr;
                            Furniture* arr = new Furniture[n - 1];
                            for (int i = 0; i < n - 1; i++) {
                                arr[i] = fltarr[i];
                            }
                            delete[] fltarr;
                            save(arr, n - 1);
                        }
                    }
                    break;
                }
                default:
                    break;
            }
            
        }
        case 2: {
            cout << "loading from (Furniture.txt): " << endl;
            arr = load(n);
            cout << "n=" << n << endl;
            if (!arr) {
                cout << "arr is null (hehehehaw)" << endl;
                return 0;
            }
            for (int i = 0; i < n; i++) {
                cout << arr[i].name()<<" "<< arr[i].material() << " " << arr[i].per() << endl;
            }
            break;
        }
        case 3: {
            cout << "1 - name, 2 - material, 3 - period" << endl;
            cin >> flt3;
            switch (flt3) {
                case 1: {
                    cout << "name=";
                    cin >> fltname;
                    for (int i = 0; i < n; i++) {
                        if (arr[i].name() == fltname)
                            cout << "found->" << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
                        else cout << "not found (hehehehaw)" << endl;
                    }
                    break;
                }
                case 2: {
                    cout << "material=";
                    cin >> fltmaterial;
                    for (int i = 0; i < n; i++) {
                        if (arr[i].material() == fltmaterial)
                            cout << "found->" << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
                        else cout << "not found (hehehehaw)" << endl;
                    }
                    break;
                }
                case 3: {
                    cout << "period=";
                    cin >> fltper;
                    for (int i = 0; i < n; i++) {
                        if (arr[i].per() == fltper)
                            cout << "found->" << arr[i].name() << " " << arr[i].material() << " " << arr[i].per() << endl;
                        else cout << "not found (hehehehaw)" << endl;
                    }
                    break;
                }
                default:
                    break;
            }
        }
        case 4: {
            break;
        }
        default:
            break;
    }
    delete[]arr;
    return 0;
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
