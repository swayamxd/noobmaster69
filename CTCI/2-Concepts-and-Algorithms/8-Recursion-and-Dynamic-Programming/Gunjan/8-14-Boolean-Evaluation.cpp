#include<iostream>
#include<unordered_map>
using namespace std;

bool stringToBool(string x){
    if(x=="1") return true;
    else if(x=="0") return false;
    else cout << "error in conversion"  << endl;
    return false;
}

string boolToString(bool x){
    if(x==true) return "true";
    else if(x==false) return "false";
    else cout << "error in conversion"  << endl;
    return "false";
}

int wayOfParenthesis(string booleanExpression, bool result, unordered_map<string, int> cache){
    if(booleanExpression.length()==0) return 0;
    else if(booleanExpression.length()==1)
        return (stringToBool(booleanExpression)==result)? 1 : 0;
    else if(cache[boolToString(result)+booleanExpression]<=0){
        for(int i=1;i<booleanExpression.length();i+=2){
            char booleanOperator = booleanExpression[i];
            string leftSubString = booleanExpression.substr(0,i);
            string rightSubString = booleanExpression.substr(i+1,booleanExpression.length());

            int leftSubStringTrue = wayOfParenthesis (leftSubString,true,cache);
            int leftSubStringFalse = wayOfParenthesis (leftSubString,false,cache);
            int rightSubStringTrue = wayOfParenthesis (rightSubString,true,cache);
            int rightSubStringFalse = wayOfParenthesis (rightSubString,false,cache);
            // total ways of true or false
            int totalWays =(leftSubStringFalse+leftSubStringTrue)+(rightSubStringFalse+rightSubStringTrue);
            // total ways of only true
            int totalWaysTrue = 0;
            if (booleanOperator=='&'){
                totalWaysTrue = leftSubStringTrue * rightSubStringTrue;
            }
            else if (booleanOperator=='|'){
                totalWaysTrue = leftSubStringTrue * rightSubStringTrue +
                                            leftSubStringTrue * rightSubStringFalse +
                                            leftSubStringFalse * rightSubStringTrue ;
            }
            else if (booleanOperator=='^'){
                totalWaysTrue = leftSubStringTrue * rightSubStringFalse +
                                            leftSubStringFalse * rightSubStringTrue ;
            }
            // if result is true, then ways is totalWaysTrue
            // if results is false, then ways is totalWaysFalse = (totalWays-totalWaysTrue)
            cache[boolToString(result)+booleanExpression] += (result) ? totalWaysTrue : (totalWays-totalWaysTrue);
        }
    }
    return cache[boolToString(result)+booleanExpression];
}

int wayOfParenthesis(string booleanExpression, bool result){
    unordered_map<string, int> cache;
    return wayOfParenthesis(booleanExpression, result, cache);
}
int main(){
    string booleanExpression = "0&0&0&1^1|0";
    bool result = true;
    cout << "Total ways : " << wayOfParenthesis(booleanExpression,result) << endl;
    return 0;
}