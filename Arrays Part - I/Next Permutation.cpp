#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &p, int n)
{
    int index = -1;

    // find the longest prefix - break points
    for(int i = n-2; i >= 0; i--) {
        if(p[i] < p[i+1]) {
            index = i;
            break;
        }
    }

    // if no break point found
    if(index == -1) {
        reverse(p.begin(), p.end());
        return p;
    }
        

    // find val which is greater than the value at index, but the smaller one and swap them
    for(int i = n-1; i > index; i--) {
        if(p[i] > p[index]) {
            swap(p[i], p[index]);
            break;
        }
    }

    // reverse the rest values from ind+1 to n-1
    reverse(p.begin() + index + 1, p.end());

    return p;

}
