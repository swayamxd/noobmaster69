#include<iostream>
#include<vector>
#define sign(x) ((x<0)?-1:1)
using namespace std;

template<typename T>
void display(vector<T> &randomArray){
    for(T x:randomArray){
        cout << x << ",";
    }
    cout << endl;
}

void generateRandomArray(vector<int> &randomArray){
    int length = randomArray.size();
    for(int i=0;i<randomArray.size();i++){
        int randomNumber = (rand() % length);
        randomArray[i] = (randomNumber&1) ? randomNumber : (-randomNumber);
    }
}

vector<int> condenseSameSignedNumbers(vector<int> &array){
    vector<int> condensedArray;
    // take first element in sum
    int sum=array[0];
    // loop will start from index 1 as we already have
    // value of index 0 stored in the sum
    for(int i=1;i<array.size();i++){
        // if every sign of next element not equals to
        // sign of prev element, then store that sum
        // in condensedArray and make sum the
        // current value which didn't match
        if (sign(array[i]) != sign(array[i-1])) {
            condensedArray.push_back(sum);
            sum = array[i];
        } else {
            // if sign of both prev and next element
            // are same then add that to sum
            sum += array[i];
        }
    }
    // when the loop breaks, we still have sum value
    // which needs to be pushed to condensedArray
    condensedArray.push_back(sum);
    // return condensedArray
    return condensedArray;
}

int maxSum(vector<int>& array){
    vector<int> condensedArray = condenseSameSignedNumbers(array);
    // display(condensedArray);
    int sum = condensedArray[0];
    int maxSum = sum;
    for(int i=1;i<condensedArray.size();i++){
        sum += condensedArray[i];
        if (sum < maxSum) {
            sum = condensedArray[i];
        } else if (maxSum < sum) {
            maxSum = sum;
        }
    }
    return maxSum;
}

int main(){
    int length = 20;
    vector<int> randomArray(length);
    generateRandomArray(randomArray);
    display(randomArray);
    cout << "Max sum : " <<  maxSum(randomArray) << endl;
    return 0;
}