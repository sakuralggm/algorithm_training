#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 110;
int a[N], b[N];
int n;

bool compare(const vector<int> &arr1, const vector<int> &arr2)
{
    for (int i = 0; i < arr1.size(); i++)
        if (arr1[i] != arr2[i])
            return false;
    return true;
}

void insertionStep(vector<int> &arr, int step) // 这是第step+1步
{
    for (int i = 0; i < step; i++)
    {
        if (arr[i] <= arr[step])
            continue;
        else
        {
            int temp = arr[step];
            for (int j = step - 1; j >= i; j--)
                arr[j + 1] = arr[j];
            arr[i] = temp;
            break;
        }
    }
}

void HeapAdjust(vector<int> &arr, int start, int fina)
{
    int temp = arr[start];
    for (int j = 2 * start + 1; j <= fina; j = j * 2 + 1)
    {
        if (j < fina && arr[j] < arr[j + 1])
            j++;
        if (temp >= arr[j])
            break;
        arr[start] = arr[j];
        start = j;
    }
    arr[start] = temp;
}

void Heap(vector<int> &arr, int step) // 这是第step+1步
{
    swap(arr[0], arr[arr.size() - step]);
    HeapAdjust(arr, 0, arr.size() - step - 1);
}



int main()
{
    
    cin >> n;
    vector<int> initial(n), middle(n);
    vector<int> temp(n);

    for (int i = 0; i < n; i++)
    {
        cin >> initial[i];
        temp[i] = initial[i];
    }
    for (int i = 0; i < n; i++)
        cin >> middle[i];

    // for (int i = 0; i < n; i++)
    // {
    //     insertionStep(initial, i);
    //     if (compare(initial, middle))
    //     {
    //         cout << "Insertion Sort" << endl;
    //         if (i < n - 1)
    //         {
    //             while (true)
    //             {
    //                 insertionStep(initial, i + 1); // modified
    //                 if (compare(initial, middle))
    //                     i++;
    //                 else
    //                     break;
    //             }
                
    //         }
    //         cout << initial[0];
    //         for (int i = 1; i < n; i++)
    //             cout << " " << initial[i];
    //         return 0;
    //     }
    // }

    for (int i = 0; i < n; i++)
        initial[i] = temp[i];


    for (int i = (initial.size() - 1) / 2; i >= 0; i--)
        HeapAdjust(initial, i, initial.size()-1);//建初始大堆

    for (int i = 1; i <= n; i++)
    {
        Heap(initial, i);
        if (compare(initial, middle))
        {
            cout << "Heap Sort" << endl;
            Heap(initial, i + 1);
            cout << initial[0];
            for (int i = 1; i < n; i++)
                cout << " " << initial[i];
            return 0;
        }
    }
}