#include<iostream>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

bool isAlpha(char c){
    return (c >= '0' && c <= '9') ||(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'z');
}
int main(){
    string str;
    getline(cin,str);
    map<string,int>words;
    map<string,int>::iterator it,tmp;
    transform(str.begin(),str.end(),str.begin(),::tolower);
    int s,e,i = 0;
    int max = 0;
    string max_str;

    while(i < str.length()){
        while(!isAlpha(str[i]) && i < str.length())
            ++i;
        if(i == str.length())
            break;
        s = i;
        while(isAlpha(str[i]) && i < str.length())
            ++i;
        e = i;
        string word = str.substr(s,e - s);
        if(words.count(word) == 0)
            words[word] = 1;
        else
            words[word] ++;

    }
    for(it = words.begin();it != words.end();it ++){
        if(it->second > max){
            max = it -> second;
            max_str = it -> first;
        }
        else if(it -> second == max && it -> first < max_str)
            max_str = it -> first;
    }

    cout << max_str<<" "<<max<<endl;
}


