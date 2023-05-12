#include "ozVector.cpp"

int main()
{
    int arr[4] = {8, 6, 2, 7};
    ozVector<int> ozvec(arr, 4);
    cout << ozvec;
    return 0;
}
