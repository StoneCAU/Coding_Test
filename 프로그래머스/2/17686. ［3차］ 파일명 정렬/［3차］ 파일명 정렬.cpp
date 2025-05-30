#include<bits/stdc++.h>

using namespace std;

string getNum(const string& a) {    
    string num = "";
    bool foundNum = false;
    
    for (int i=0;i<a.length();i++) {
        if (isdigit(a[i])) {
            foundNum = true;
            num += a[i];
            
            if (num.length() == 5) break;
        }
        else {
            if (foundNum) break;
        }
    }
    
    return num;
}

string getHead(const string& a) {
    string head = "";
    
    for (int i=0;i<a.length();i++) {
        if (isdigit(a[i])) break;
        
        head += tolower(a[i]);
    }
    
    return head;
}

bool cmp(const string& a, const string& b) {
    string headA = getHead(a);
    string headB = getHead(b);
    
    if (headA == headB) {
       if (stoi(getNum(a)) == stoi(getNum(b))) return false;
       else return stoi(getNum(a)) < stoi(getNum(b)); 
    }
    
    return headA < headB;
}

vector<string> solution(vector<string> files) {    
    stable_sort(files.begin(), files.end(), cmp);
    
    return files;
}