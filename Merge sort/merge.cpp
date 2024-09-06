#include <iostream>
using namespace std;

void merge(int arp[], int l, int m, int r, int size)
{
    int i = l;
    int j = m + 1;
    int k = l;

    int temp[size];

    while (i <= m && j <= r) {
        if (arp[i] <= arp[j]) {
            temp[k] = arp[i];
            i++;
            k++;
        }
        else {
            temp[k] = arp[j];
            j++;
            k++;
        }
    }
    while (i <= m) {
        temp[k] = arp[i];
        i++;
        k++;
    }
    while (j <= r) {
        temp[k] = arp[j];
        j++;
        k++;
    }

    for (int p = l; p <= r; p++) {
        arp[p] = temp[p];
    }
}

void mergeSort(int arp[], int l, int r, int size)
{
    if (l < r) {

        int m = (l + r) / 2;

        mergeSort(arp, l, m, size);
        mergeSort(arp, m + 1, r, size);
        merge(arp, l, m, r, size);
    }
}

int main()
{
    cout << "Size of array: " << endl;
    int size;
    cin >> size;
    int ArpArray[size];

    cout << "Integers in any order: " << endl;
    for (int i = 0; i < size; i++) {
        cin >> ArpArray[i];
    }

    cout << endl;
    mergeSort(ArpArray, 0, (size - 1), size);

    cout << "Merge Sorting List :" << endl;
    for (int i = 0; i < size; i++) {
        cout << ArpArray[i] << " ";
    }
    return 0;
}
