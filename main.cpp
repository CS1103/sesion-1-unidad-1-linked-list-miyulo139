#include <iostream>
#include <cassert>
#include <string>
#include "linked_list.h"

using namespace std;

int main() {

    utec::linked_list_t ll;

//PRUEBAS DE LOS MÉTODOS
//1. PUSH FRONT: Insert node at beginning

    for(int i = 0; i < 10; ++i) {
        ll.push_front(i);
    }

    // Verifico el tamano
    assert(ll.size() == 10);

    string result;
    for (int i = 0; i < 10; ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    assert(result == "9 8 7 6 5 4 3 2 1 0 ");

    cout<<"El método push_front ejecuta correctamente"<<endl;


//2. POP FRONT: Remove node from the front

    for(int i = 0; i < 5; ++i) {
        ll.pop_front();
    }
    // Verifico el tamano
    assert(ll.size() == 5);

    // Probar el metodo push_front;
    for(int i = 0; i < 5; ++i) {
        ll.pop_front();
    }
    // Verifico el tamano
    assert(ll.size() == 0);

    cout<<"El método pop_front ejecuta correctamente"<<endl;


//3. PUSH BACK: Insert node at ending

    for(int i = 0; i < 10; ++i) {
        ll.push_back(i);
    }

    // Verifico el tamano
    assert(ll.size() == 10);

    string result1;
    for (int i = 0; i < 10; ++i) {
        result1 += to_string(ll.item(i)) + " ";
    }
    assert(result1 == "0 1 2 3 4 5 6 7 8 9 ");

    cout<<"El método push_back ejecuta correctamente"<<endl;


//4. POP BACK: Remove last node

    ll.pop_back();

    // Verifico el tamano
    assert(ll.size() == 9);

    string result3;
    for (int i = 0; i < 9; ++i) {
        result3 += to_string(ll.item(i)) + " ";
    }
    assert(result3 == "0 1 2 3 4 5 6 7 8 ");

    cout<<"El método pop_back ejecuta correctamente"<<endl;

//5. ERASE: Remove node in index position

    ll.erase(1);

    // Verifico el tamano
    assert(ll.size() == 8);

    string result4;
    for (int i = 0; i < 8; ++i) {
        result4 += to_string(ll.item(i)) + " ";
    }
    assert(result4 == "0 2 3 4 5 6 7 8 ");

    cout<<"El método erase ejecuta correctamente"<<endl;

//6. INSERT: Insert node in index position
    ll.insert(1,1);

    // Verifico el tamano
    assert(ll.size() == 9);

    string result5;
    for (int i = 0; i < 9; ++i) {
        result5 += to_string(ll.item(i)) + " ";
    }
    assert(result5 == "0 1 2 3 4 5 6 7 8 ");

    cout<<"El método insert ejecuta correctamente"<<endl;

    return 0;
}
