#include<iostream>
#include<stdlib.h>
#include<list>
using namespace std;

class animal{
    string animalName;
    int orderNum;
    public:
    void setOrder(int ord){
        orderNum = ord;
        return;
    }
    void setName(string name){
        animalName = name;
        return;
    }
    int order(){
        return orderNum;
    }
    string name(){
        return animalName;
    }
};

class animalShelter{
    list<animal> dogList;
    list<animal> catList;
    public:
    void enqueueDog(animal newAnimal){
        if (newAnimal.name() == "dog") dogList.push_back(newAnimal);
        else cout << "animal should be dog" << endl;
        return;
    }
    void enqueueCat(animal newAnimal){
        if (newAnimal.name() == "cat") catList.push_back(newAnimal);
        else cout << "animal should be cat" << endl;
        return;
    }
    void enqueueAny(animal newAnimal){
        if (newAnimal.name() == "dog") enqueueDog(newAnimal);
        else if (newAnimal.name() == "cat") enqueueCat(newAnimal);
        else cout << "animal should be dog or cat" << endl;
        return;
    }
    void dequeueDog(){
        if (!dogList.empty()) {
            cout << "Dequeue : " << dogList.begin()->order() << " : " << dogList.begin()->name() << endl;
            dogList.pop_front();
        }
        else cout << "dog list is empty" << endl;
        return;
    }
    void dequeueCat(){
        if (!catList.empty()) {
            cout << "Dequeue : " << catList.begin()->order() << " : " << catList.begin()->name() << endl;
            catList.pop_front();
        }
        else cout << "cat list is empty" << endl;
        return;
    }
    void dequeueAny(){
        if (!catList.empty() && !dogList.empty()){
            (catList.begin()->order() < dogList.begin()->order()) ? dequeueCat() : dequeueDog();
        }
        else if (!catList.empty()) dequeueCat();
        else if (!dogList.empty()) dequeueDog();
        else cout << "all lists are empty" << endl;
        return;
    }
};

int main(){
    int shelterSize = 10;
    animal newAnimal;
    animalShelter newShelter;
    cout << "Shelter :" << endl;
    for(int i=0;i<shelterSize;i++){
        // if i is odd then dog, if even then cat
        (i&1) ? newAnimal.setName("dog") : newAnimal.setName("cat");
        newAnimal.setOrder(rand()%100);
        cout << newAnimal.order() << " : " << newAnimal.name() << " | ";
        newShelter.enqueueAny(newAnimal);
    }
    cout << endl;
    for(int i=0;i<shelterSize;i++){
        // newShelter.dequeueDog();
        // newShelter.dequeueCat();
        newShelter.dequeueAny();
    }
    return 0;
}