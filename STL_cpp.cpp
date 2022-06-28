#include<bits/stdc++.h>
using namespace std;

void explainPair(){
    pair<int, int> pi = make_pair(1, 2);//{1,2}
    cout<<pi.first<<" "<<pi.second<<endl;
    pair<int,pair<int,int>> p  = {1,{3,4}};
    cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
    pair<int,int> arr[] = {{1,2},{3,4},{5,6}};
    //print it
    for(auto i:arr){
        cout<<i.first<<" "<<i.second<<endl;
    }
}

void explainVector(){
    vector<int> v(5,5);
    v.push_back(1);
    v.emplace_back(2); //faster than push_back
    vector<pair<int,int>> vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int> vc(5,100);
    //print each of them
    for(auto i:vc){
        cout<<i<<endl;
    }
    // print v
    
    // print vec
    for(auto i:vec){
        cout<<i.first<<" "<<i.second<<endl;
    }

    v.erase(v.begin()+1);
    v.insert(v.begin(),11);
    v.insert(v.begin()+1,3,12);
    for(auto i:v){
        cout<<i<<endl;
    }
}

void explainList(){
    // show all the functions of list
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    l.pop_back();
    l.pop_front();
    l.front();
    l.back();
    l.empty();
    l.size();
    l.clear();
    l.resize(5,100);
    l.resize(5);
    l.reserve(5);
    l.max_size();
    l.shrink_to_fit();
    l.swap(l);
    l.splice(l.begin(),l);
    l.sort();
    l.merge(l);
    l.remove(1);
    l.unique();
    l.reverse();
    l.sort();
}

void explainPriorityQueue(){
    // show all the functions of priority_queue
    priority_queue<int> pq;
    pq.push(1);
    pq.top();
    pq.pop();
    pq.empty();
    pq.size();
    pq.max_size();
    pq.clear();
    pq.resize(5,100);
    pq.reserve(5);
    pq.swap(pq);
    pq.merge(pq);
    pq.sort();
    pq.unique();
    pq.reverse();
    pq.sort();

    //min priority
    priority_queue<int,vector<int>,greater<int>> pq2;
    pq2.push(1);
    pq2.top();
    pq2.pop();
    pq2.empty();
    pq2.size();
    pq2.max_size();
    pq2.clear();
    pq2.resize(5,100);
    pq2.reserve(5);
    pq2.swap(pq2);
    pq2.merge(pq2);
}

void explainSet(){
    // show all the functions of set
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    s.insert(4);

    auto it = s.find(3);
    
}

int main(){
    // explainPair();
    explainVector();
    return 0;
}