#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <list>
using namespace std;

class Animal{
  public:
  string name;
  int order;
  Animal(string n, int ord){
    name = n;
    order = ord;
  }
};


class AnimalQueue{
  private:
  list <Animal> _cats, _dogs;
  int order = 0;
  public:
  void enqueueAny(string animal){
    if (animal=="dog"){
      Animal dog("dog", order++);
      _dogs.push_back(dog);
    } 
    else if (animal=="cat"){
      Animal cat("cat", order++);
      _cats.push_back(cat);
    }
  }
  bool dequeueCat(){
    if (_cats.empty()) {
      return false;
    }
    _cats.pop_front();
    return true;
  }
  
  bool dequeueDog(){
    if (_dogs.empty()) {
      return false;
    }
    _dogs.pop_front();
    return true;
  }

  bool dequeueAny(){
    if (_dogs.empty()){
      return dequeueCat();
    }
    else if (_cats.empty()){
      return dequeueDog();
    }
    else if (_dogs.front().order < _cats.front().order){
      return dequeueDog();
    }
    else if (_dogs.front().order >= _cats.front().order){
      return dequeueCat();
    }
    return false;
  }
  void display(){
    cout << "==============" << endl;
    cout << "Dog" << endl;
    for(auto i: _dogs){
      cout << i.name << " -> "<< i.order << ", " ;
    }
    cout << endl;
    cout << "Cat" << endl;
    for(auto i: _cats){
      cout << i.name << " -> "<< i.order << ", " ;
    }
    cout << endl;
    cout << "==============" << endl;
  }
};

int main(){

  srand(time(0));
  AnimalQueue shelter;
  cout << "Shelter :" << endl;
  for(int i=0;i<10;i++){
      // if i is odd then dog, if even then cat
      string animal = (rand()&1) ? "dog" : "cat";
      cout << animal << ", ";
      shelter.enqueueAny(animal);
  }
  cout << endl;
  shelter.display();
  shelter.dequeueDog();
  shelter.display();
  shelter.dequeueCat();
  shelter.display();
  shelter.dequeueAny();
  shelter.display();
  return 0;
}