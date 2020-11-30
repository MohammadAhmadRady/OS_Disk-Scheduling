#include <bits/stdc++.h>
using namespace std;
/*
98
183
37
122
14
124
65
67
*/
void optimal (vector<int> arr, int sz, int initial, int head)
{
    arr.push_back(initial);
    arr.push_back(0);
    sz++;
    sz++;
    sort(arr.begin(),arr.end());
    cout<<"Optimal:\n";
    cout << "Sequence is : ";
    for (int i = 0; i < sz; i++)
    {
        cout << arr [i] << ' ';
        if (i == 0)
            head += (initial>arr[0])?(initial-arr[0]):(arr[0]-initial);
        else
            head += (arr[i-1]>arr[i])?(arr[i-1]-arr[i]):(arr[i]-arr[i-1]);
    }
    cout << endl;
    cout << "The head time is: "<< head << endl;
}

void Clook (vector<int> arr, int sz, int initial, int head)
{
    cout<<"C-Scan\n";
    sort(arr.begin(),arr.end());
    int index=0;
    for(int i=0;i<sz;i++)
    {
        if(initial<arr[i])
        {
            index =i;
            break;
        }
    }
    for(int i=index;i<sz;i++)
    {
        cout<<arr[i]<<' ';
        head+=abs(arr[i]-initial);
        initial=arr[i];
    }
    for(int i=0;i<index;i++)
    {
        cout<<arr[i]<<' ';
        head+=abs(arr[i]-initial);
        initial=arr[i];
    }
    cout << endl;
    cout << "The head time is: "<< head << endl;
}
void Cscan (vector<int> arr, int sz, int initial, int head)
{
    cout<<"C-Scan\n";
    arr.push_back(0);
    arr.push_back(199);
    sort(arr.begin(),arr.end());
    int index=0;
    sz++;
    sz++;
    cout<<endl;
    for(int i=0;i<sz;i++)
    {
        if(initial<arr[i])
        {
            index =i;
            break;
        }
    }
    for(int i=index;i<sz;i++)
    {
        cout<<arr[i]<<' ';
        head+=abs(arr[i]-initial);
        initial=arr[i];
    }
    for(int i=0;i<index;i++)
    {
        cout<<arr[i]<<' ';
        head+=abs(arr[i]-initial);
        initial=arr[i];
    }
    cout << endl;
    cout << "The head time is: "<< head << endl;

}
void fcfs (int arr [], int sz, int initial)
{
    cout << "FCFS: \n";
    int head = 0;
    for (int i = 0; i < sz; i++)
    {
        cout << arr [i] << ' ';
        if (i == 0)
            head += (initial>arr[0])?(initial-arr[0]):(arr[0]-initial);
        else
            head += (arr[i-1]>arr[i])?(arr[i-1]-arr[i]):(arr[i]-arr[i-1]);
    }
    cout << endl;
    cout << "The head time is: "<< head << endl;
}
void scan (vector<int> arr, int sz, int initial, int head)
{
    cout<<"Scan\n";
    arr.push_back(0);
    sort(arr.begin(),arr.end());
    int index=0;
    sz++;
    cout<<endl;
    for(int i=0;i<sz;i++)
    {
        if(initial>arr[i])
        {
            index =i;
        }
    }
    for(int i=index;i>=0;i--)
    {
        cout<<arr[i]<<' ';
        head+=abs(arr[i]-initial);
        initial=arr[i];
    }
    for(int i=index+1;i<sz;i++)
    {
        cout<<arr[i]<<' ';
        head+=abs(arr[i]-initial);
        initial=arr[i];
    }
    cout << endl;
    cout << "The head time is: "<< head << endl;
}
void sstf (vector<int> arr, int sz, int initial, int&head)
{
    if(sz==1)
    {
        head += (initial>arr[0])?(initial-arr[0]):(arr[0]-initial);
        cout << arr [0] << ' ';
        return;
    }

    int best = 0,currHead=(initial>arr[0])?(initial-arr[0]):(arr[0]-initial);

    for (int i = 1; i < sz; i++)
    {

        int temp=(initial>arr[i])?(initial-arr[i]):(arr[i]-initial);
        if(temp < currHead)
        {
            best = i;
            currHead = temp;
        }
    }
    head += currHead;
    int newInitial = arr [best];
    cout << newInitial << ' ';
    arr[best]= arr[sz-1];
    arr.pop_back();
    sstf(arr,sz-1, newInitial,head);
}
int main()
{
    int Size,start,anotherStart,* arr,val;
    vector<int> a,b,c,d ;
    cout<<"Enter size: ";cin>>Size;
    arr = new int[Size];
    for(int i=0;i<Size;i++)
    {
        cin>>val;
        arr[i]=val;
        a.push_back(val);
        b.push_back(val);
        c.push_back(val);
        d.push_back(val);
    }
    cout<<"Enter Start: ";cin>>start;anotherStart=start;

    fcfs(arr,Size,start);
    cout<<"\n**********************\n";

    cout<<"SSTF: \n";
    int head = 0;
    sstf(a, Size, start,head);
    cout << "\nThe head time is: "<< head << endl;
    cout<<"\n**********************\n";

    head=0;
    scan(b,Size,anotherStart,head);
    cout<<"\n**********************\n";

    head=0;
    Cscan(c,Size,anotherStart,head);
    cout<<"\n**********************\n";

    head=0;
    Clook(d,Size,anotherStart,head);
    cout<<"\n**********************\n";

    head=0;
    optimal(d,Size,anotherStart,head);
    cout<<"\n**********************\n";
    return 0;
}
