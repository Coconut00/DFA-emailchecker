#include <iostream>
#include <map>
#include <set>
#include <string>
#include <iterator>

using namespace std;

struct DFA
{
    map<pair<int,char>,int> transitions;
    set<int> acceptingStates;
    int startState;
};

DFA LoadEmailDFA()
{
    DFA d;
    d.transitions.insert(make_pair(make_pair(0,'a'),1));
    d.transitions.insert(make_pair(make_pair(0,'.'),7));
    d.transitions.insert(make_pair(make_pair(0,'@'),7));
    d.transitions.insert(make_pair(make_pair(1,'a'),1));
    d.transitions.insert(make_pair(make_pair(1,'.'),2));
    d.transitions.insert(make_pair(make_pair(1,'@'),3));
    d.transitions.insert(make_pair(make_pair(2,'a'),1));
    d.transitions.insert(make_pair(make_pair(2,'.'),7));
    d.transitions.insert(make_pair(make_pair(2,'@'),7));
    d.transitions.insert(make_pair(make_pair(3,'a'),4));
    d.transitions.insert(make_pair(make_pair(3,'.'),7));
    d.transitions.insert(make_pair(make_pair(3,'@'),7));
    d.transitions.insert(make_pair(make_pair(4,'a'),4));
    d.transitions.insert(make_pair(make_pair(4,'.'),5));
    d.transitions.insert(make_pair(make_pair(4,'@'),7));
    d.transitions.insert(make_pair(make_pair(5,'a'),6));
    d.transitions.insert(make_pair(make_pair(5,'.'),7));
    d.transitions.insert(make_pair(make_pair(5,'@'),7));
    d.transitions.insert(make_pair(make_pair(6,'a'),6));
    d.transitions.insert(make_pair(make_pair(6,'.'),5));
    d.transitions.insert(make_pair(make_pair(6,'@'),7));
    d.transitions.insert(make_pair(make_pair(7,'a'),7));
    d.transitions.insert(make_pair(make_pair(7,'.'),7));
    d.transitions.insert(make_pair(make_pair(7,'@'),7));
    d.startState = 0;
    d.acceptingStates.insert(6);
    return d;
}

bool SimulateDFA(DFA& d, string input)
{
    int currState = d.startState;
    for(string::iterator itr=input.begin();itr!=input.end();++itr)
        currState = d.transitions[make_pair(currState, *itr)];
    return d.acceptingStates.find(currState) != d.acceptingStates.end();
}

bool IsEmailAddress(string input)
{
    DFA emailChecker = LoadEmailDFA();
    for(string::iterator itr=input.begin();itr!=input.end();++itr)
    {
        if(isalnum(*itr))
            *itr='a';
        else if(*itr!='.'&&*itr!='@')
            return false;
    }
    return SimulateDFA(emailChecker, input);
}


int main()
{

    string input;

    cout<<"Please input your email address:";
    cin>>input;
    if(!IsEmailAddress(input))
        cout<<"error"<<endl;
    else
        cout<<"valid"<<endl;
    return 0;

}
