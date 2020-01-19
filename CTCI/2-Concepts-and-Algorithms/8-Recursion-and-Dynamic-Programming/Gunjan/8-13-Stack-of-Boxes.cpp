#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<time.h>
#include<vector>
#define max(a,b) (a>b?a:b)
using namespace std;

class box{
    public:
    int height,width,length;
    box(int inputHeight, int inputWidth, int inputLength){
        height = inputHeight;
        width = inputWidth;
        length = inputLength;
    }
};

// comparator function to help sorting with decreasing height
bool comparator(box b1, box b2){
    return (b1.height>b2.height);
}

// print box list
void display(vector<box> boxList){
    cout << "Total box count : " << boxList.size() << endl;
    for(box x:boxList){
        cout << "Height : " << x.height <<
                " ; Width : " << x.width <<
                " ; Length : " << x.length << endl;
    }
}

// generate a list of box
vector<box> generateBox(int boxCount){
    vector<box> boxList;
    srand(time(0));
    for(int i=0;i<boxCount;i++){
        box newBox(rand()%boxCount, rand()%boxCount, rand()%boxCount);
        boxList.push_back(newBox);
    }
    return boxList;
}

// check if box2 can be placed on top of box1
bool check(box b1,box b2){
    if(b1.height>=b2.height && b1.length>=b2.length && b1.width>=b2.width)
        return true;
    return false;
}

// maxHeight method returns maximum stack height which can be possible
int maxHeight(int index, int height, vector<box> boxStack, vector<box> &boxList, vector<int> &cache){
    // out of bound case, here no stack is possible, so return -1 as height
    if(index>boxList.size()-1){
        return -1;
    }
    // base case, if stack can be formed, then return current height
    else if(index == boxList.size()-1) {
        return height;
    }
    // if cache doesn't have the max height for given index, then calculate maxHeight for that index and store
    else if (cache[index]<=0) {
        int newHeight=0, newIndex=index;
        // finding next index for which a box can be placed on top
        while(newIndex < boxList.size()){
            // if stack is empty, or new index box is smaller than stacks last box then this is the box to be placed
            if(boxStack.empty() || check(*boxStack.end(),boxList[newIndex])){
                newHeight = height+boxList[newIndex].height;
                break;
            }
            newIndex++;
        }
        // if new box index found
        if(newHeight){
            // find height when we add that box to the stack
            newHeight = maxHeight(newIndex+1,newHeight,boxStack,boxList,cache);
        }
        // find height when we don't add that box to the stack
        height = maxHeight(index+1,height,boxStack,boxList,cache);
        // now find the maximum of both previous results, as max height and store it in cache
        cache[index] = max(newHeight,height);
    }
    // return cache max height of that index
    return cache[index];
}

// calls maxHeight helper method
int maxHeight(vector<box> boxList){
    vector<box> boxStack;
    vector<int> cache (boxList.size());
    sort(boxList.begin(),boxList.end(),comparator);
    return maxHeight(0,0,boxStack,boxList,cache);
}

int main(){
    int boxCount = 1000;
    vector<box> boxList = generateBox(boxCount);
    display(boxList);
    cout << "Max added stack height can be : " << maxHeight(boxList) << endl;
    return 0;
}