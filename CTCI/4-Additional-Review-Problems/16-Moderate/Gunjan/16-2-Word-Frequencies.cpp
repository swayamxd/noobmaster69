#include<iostream>
#include<unordered_map>
using namespace std;

string getBook(){
    string book = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean scelerisque consectetur laoreet. Curabitur lacinia lorem a sagittis molestie. Phasellus aliquet enim ac nunc interdum interdum. Pellentesque odio metus, eleifend in felis in, fermentum blandit risus. Nunc fringilla semper dui in mattis. Donec suscipit sit amet nulla eu pretium. Curabitur sollicitudin condimentum tellus ac accumsan. Curabitur sapien urna, maximus eu tempor sed, euismod eget nisi. Morbi vel felis quis metus ornare elementum. Morbi ut nisi est. Integer sit amet justo mauris. Phasellus tempus auctor lacus, vitae scelerisque nibh consequat vitae. Suspendisse sollicitudin sed erat tempus posuere. Duis porta enim et odio posuere molestie. Cras eget urna a nunc fermentum sagittis. Nam luctus pharetra scelerisque. Vivamus at maximus arcu. Vestibulum eros massa, lobortis vitae blandit in, vulputate faucibus eros. Quisque mollis gravida eros. Pellentesque eu viverra urna, nec tincidunt purus. Nullam lacus orci, varius eget leo ultrices, cursus aliquet orci. Vivamus tristique iaculis facilisis. Suspendisse euismod erat molestie nulla placerat elementum. Donec lacus sapien, ornare et augue id, porta tincidunt diam. Vivamus in ullamcorper enim. Curabitur sapien neque, placerat nec eleifend et, lacinia vitae nisi. Nulla viverra elementum pharetra. Phasellus pellentesque nec sem id vehicula. Vivamus convallis interdum enim, sed sodales elit laoreet nec.";
    return book;
}

unordered_map <string,int> getFreq(string&book){
    unordered_map <string,int> wordFreqTable;
    string word = "";
    for(int i=0;i<book.length();i++){
        if(book[i]==' '){
            wordFreqTable[word]++;
            word.clear();
        } else {
            word.push_back(book[i]);
        }
    }
    return wordFreqTable;
}

void test(string&book,unordered_map<string,int>&wordFreqTable){
    string word;
    for(int i=0;i<book.length();i++){
        if(book[i]==' '){
            cout << "Frequency of '" << word << "' is : " << wordFreqTable[word] << endl;
            word.clear();
        } else {
            word.push_back(book[i]);
        }
    }
}

int main(){
    string book = getBook();
    unordered_map <string,int> wordFreqTable = getFreq(book);
    test(book,wordFreqTable);
    return 0;
}