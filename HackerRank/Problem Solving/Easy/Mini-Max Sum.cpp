//Shiro23

//https://www.hackerrank.com/challenges/mini-max-sum/problem

#include <bits/stdc++.h>
#include <numeric>

using namespace std;

vector<string> split_string(string);

void miniMaxSum(vector<int> &arr) {
    long long min = 10000000000, max = 0;

    for(auto it = arr.begin(); it < arr.end(); it++){
        long long fourElementsSum = 0;

        for(auto it = arr.begin(); it < arr.end()-1; it++){
            fourElementsSum += *it;
        }

        if (fourElementsSum < min)
            min = fourElementsSum;

        if (fourElementsSum > max)
            max = fourElementsSum;

        rotate(arr.begin(), arr.begin() + 1, arr.end());
    }
    cout << min << " " << max << endl;
}

int main()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
