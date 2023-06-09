#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1); // last mei
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i]; // end se shuru karo curr hoga last element
            while(s.top() != -1 && arr[s.top()] >= curr)
            { // agar stack ka jo top element hai woh badha hai curr se toh nikaldo stack wale ko
                s.pop(); // badha hai toh pop kardo aur chota element daalo
            }
            //nahi toh fir ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1); // stack mei -1 push kardo start mei hi
        vector<int> ans(n);
        
        for(int i=0; i<n; i++) {
            int curr = arr[i]; 
            while(s.top() != -1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n= heights.size();
        
        vector<int> next(n); // element ke next small element nikalo aur waha tak jaate b extend karte raho jab tak chota miljaaye
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);// prev element mei se smallest nikalo
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i]; // basically jo height hai element ki woh length
            
            if(next[i] == -1) { //  jab sab sam height ke ho then next ko n ko kardo ie bahar kardo array ke
                next[i] = n;    // n matlab last element ka next jagae 
            } // -1 -(-1) -1 = -1 = breadth jis sey area bhi -ve hojayega jo possible nahi
            
            int b = next[i] - prev[i] - 1; // breadth hoga dono ka diff -1
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};