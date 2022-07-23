// Design a number container system that can do the following:

// Insert or Replace a number at the given index in the system.
// Return the smallest index for the given number in the system.
// Implement the NumberContainers class:

// NumberContainers() Initializes the number container system.
// void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
// int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.


class NumberContainers {
private:
    // vector<int> v;
    map<int, int> m;
public:
    NumberContainers() {
        m.clear();
    }
    
    void change(int index, int number) {
        m[index] = number;
    }
    
    int find(int number) {
        // number is in m.second
        // find number
        for(auto i:m){
            if(i.second == number){
                return i.first;
            }
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */

