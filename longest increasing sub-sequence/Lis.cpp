#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

class LISsolveDP
{
    //recursive function to return LIS(arr,n) as described
    int LISDP(vector<int> arr,int ind,vector<int> & LISArr)
    {
        int i=0;
        if (LISArr[ind] !=0)
            return LISArr[ind];
        if (ind == 0)
        {
            LISArr[ind]=1;
            return 1;
        }
        int temp=0,max=1;

        for (i=0;i<ind;++i)
        {
            temp = LISArr[i];
            if (temp==0)
                temp = LISDP(arr,i,LISArr);
            if (arr[i]<arr[ind])
                temp++;
            if (temp>max&&arr[i]<arr[ind])
            {
                max = temp;
                //uncomment below to understand
                //cout << "...ind = " << ind<< " i=" << i << " max= " << max << "\n";
            }
        }
        LISArr[ind] = max;
        return max;
    }

public:
    int LIS(vector<int> arr)
    {
        int result = 0,temp=0;
        //initialize LISArr
        vector<int> LISArr(arr.size(),0);

        for (int i=0;i<arr.size();++i)
        {
            temp = LISDP(arr,i,LISArr);
            if (temp>result)
                result = temp;
        }
        return result;
    }
};

class LISsolveFast
{
    //temporary array that stores the index of all end elements
    //the zeroth index won't be used as the index of LISArr represents
    //the length of the longest subsequence
    vector<int>LISArr;
    int lastIndex;
    //return the index of the array where item can be placed
    //first is the index where to start
    //last is the index where to end
    int binarySearchIndices(vector<int> arr,int item)
    {
        //check the boundaries first
        if (item < arr[LISArr[1]])
            return 1;
        if (item > arr[LISArr[lastIndex]])
            return lastIndex+1;

        int first = 1;          //index
        int last = lastIndex;   //index
        int mid = (first+last)/2;
        bool found = false;
        while (!found && first<=last)
        {

            cout.flush();
            if (item<arr[LISArr[mid]])
                last = mid-1;
            else if(item>arr[LISArr[mid]])
                first = mid+1;
            else found = true;
            mid = (first+last)/2;

        }
        if (item>arr[LISArr[mid]])
            mid = mid+1;
        return mid;


    }
public:
//function implements the (nlog n) solution
    int LIS(vector<int> arr)
    {
        int i,ind;
        //handle an exception first thing
        if (arr.size()==0)
            return 0;

        LISArr.resize(arr.size()+1,0);
        LISArr[1] = 0;                 //arr[0] is subsequence of length 1
        lastIndex = 1;                 //this is the index of the longet sequence found so far
        for (i=1;i<arr.size();++i)
        {
            ind = binarySearchIndices(arr,arr[i]);
            LISArr[ind] = i;
            if (ind>lastIndex)      //inserting at end
                lastIndex = ind;
        }
        return lastIndex;           //this is LIS
    }
};
int main()
{
    int arr[] = {5, 15 ,8, 7, 4, 10, 20, 19, 7, 25, 29, 11 };
    vector <int> myArray(sizeof(arr)/sizeof(arr[0]),0);
    for (int i=0;i<myArray.size();++i)
    {
        myArray[i] = arr[i];
    }
    LISsolveDP lisDP;
    LISsolveFast lisFast;
    int result = lisDP.LIS(myArray);
    cout << "\n *** result from DP = " << result << "\n";

    result = lisFast.LIS(myArray);
    cout << "\n *** result from fast method = " << result << "\n";

}
