#include <iostream>
#include <vector>

using namespace std;

//func1: return vector
vector<int> FindSubString(string str, string ss ){

    vector<int> vec;
    //std::size_t pos = str.find("live", start from);// position of "live" in str
    int position = str.find(ss);

//string::npos ->  means "until the end of the string".
   while(position != string::npos){
        vec.push_back(position);
        position = str.find(ss, position+1);
       }
       return vec;
}

//func2: return a vector
string ReplaceALLtheSubStrings(string str, string ss1, string ss2){

    //find substring
   vector<int> vector1 = FindSubString(str, ss1);
   int lengthDiffernce = ss2.size() - ss1.size();
   string original = str;
   string newStr = str;

  if(vector1.size() != 0){

     int lengthDiff = ss2.size() - ss1.size();
     int times = 0;
     for (auto y: vector1){
         str.replace(y + times*lengthDiff, ss1.size(), ss2 );
         times ++;
         }
         }

    return  str;

}

int main() {

    string phase = "stupid cat, 3 cat in total";
    vector<int> matches = FindSubString(phase, "cat");
    for(int i = 0; i < matches.size(); ++i){
        cout << "The position of word cat " << matches[i] << endl;
    }

    //func 2

    cout << ReplaceALLtheSubStrings(phase, "cat", "fisher") << endl;

}