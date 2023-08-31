#include <iostream>
#include <vector>

using namespace std;

int minJumpsToEnd(const vector<int>& arr) {
    int n = arr.size();
    
    if (n <= 1)
        return 0; // If there's only one element, no jumps needed
    
    if (arr[0] == 0)
        return -1; // Can't start from the first element
    
    int jumps = 1; // Initialize jumps to 1 (starting from the first element)
    int maxReach = arr[0]; // Maximum reachable index from the current position
    int steps = arr[0]; // Steps remaining at the current jump
    
    for (int i = 1; i < n; ++i) {
        if (i == n - 1)
            return jumps; // Reached the end
        
        maxReach = max(maxReach, i + arr[i]); // Update the maximum reachable index
        
        steps--; // Use a step to move to the current index
        
        if (steps == 0) {
            if (i >= maxReach)
                return -1; // Can't move further
            jumps++; // Need another jump
            steps = maxReach - i; // Update steps to the remaining distance in the current jump
        }
    }
    
    return -1; // If we haven't reached the end, it's not possible
}

int main() {
    int N = 11;
    vector<int> arr = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};
    
    int result = minJumpsToEnd(arr);
    cout << "Output: " << result << endl;
    
    return 0;
}
