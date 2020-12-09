#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int count = 0;
void check_repetition(int i, vector<int> &time)
{
    if (time[i] == time[i + 1])
    {
        ::count++;
        i = i + 1;
    }
    else
    {
        return;
    }
}
int binarySearch(vector<int> &time, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        // itself
        if (time[mid] == x)
        {
            ::count++;

            check_repetition(mid, time);

            return mid;
        }

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (time[mid] > x)
            return binarySearch(time, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(time, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
}
int numPairsDivisibleBy60(vector<int> &time)
{
    int checker = 60;
    sort(time.begin(), time.end());

    for (int i = 0; i < time.size() - 1; i++)
    {
        checker = 60;
        while (time[time.size() - 1] >= checker - time[i])
        {
            binarySearch(time, i + 1, time.size() - 1, checker - time[i]);
            checker += 60;
        }
    }
    return ::count;
}
int main()
{

    int n;
    int x;
    cin >> n;
    vector<int> time;
    for (int i = 0; i < n; i++)
    {

        cin >> x;
        time.push_back(x);
    }

    x = numPairsDivisibleBy60(time);
    cout << x;
    //type your code here

    return 0;
}
