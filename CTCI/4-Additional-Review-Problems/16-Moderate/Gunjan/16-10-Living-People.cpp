#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>& year){
    for(auto x:year){
        cout << x << ",";
    }
    cout << endl;
}

void display(vector<int> &birthYear, vector<int> &deathYear){
    for(int i=0;i<birthYear.size() &&i<deathYear.size();i++){
        cout << "(" << birthYear[i] << "-" << deathYear[i] << "), ";
    }
    cout << endl;
}

void generateRandomPeople(int totalPeople, pair<int,int> yearSpan, vector<int> &birthYear, vector<int> &deathYear){
    int min = yearSpan.first;
    int max = yearSpan.second;
    int randomBirthYear, randomDeathYear;
    for (int i = 0; i < totalPeople; i++){
        randomBirthYear = (rand()%(max-min))+min;
        randomDeathYear = (rand()%(max-randomBirthYear))+randomBirthYear;
        birthYear.push_back(randomBirthYear);
        deathYear.push_back(randomDeathYear);
    }
}

pair<int,int> getMaxAliveCount(pair<int,int> yearSpan, vector<int> &birthYear, vector<int> &deathYear){
    int startingYear = yearSpan.first;
    int endingYear = yearSpan.second;
    // we have to add another 1 as the years are inclusive
    vector<int> personCountYear(endingYear-startingYear+1,0);
    int peopleCount=0, maxPeopleCount=0, yearOfMaxPeople=0;
    for(int i=0;i<birthYear.size();i++){
        personCountYear[birthYear[i]-startingYear]++;
        personCountYear[deathYear[i]-startingYear+1]--;
    }
    for(int i=0;i<personCountYear.size();i++){
        peopleCount += personCountYear[i];
        if(peopleCount>maxPeopleCount){
            maxPeopleCount=peopleCount;
            yearOfMaxPeople = i+startingYear;
        }
    }
    return(make_pair(maxPeopleCount,yearOfMaxPeople));
}

int main(){
    int totalPeople = 100;
    pair<int,int> yearSpan = make_pair(1900,2000);
    vector<int> birthYear;
    vector<int> deathYear;
    generateRandomPeople(totalPeople,yearSpan,birthYear,deathYear);
    // display(birthYear);
    // display(deathYear);
    display(birthYear,deathYear);
    pair<int,int> result = getMaxAliveCount(yearSpan,birthYear,deathYear);
    cout << "Max number of people alive : " << result.first << " on year : " << result.second << endl;
    return 0;
}