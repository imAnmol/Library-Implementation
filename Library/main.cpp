
#include <bits/stdc++.h>
#include "DSU.h"
#include "SEGMENTTREE.h"
#include "MAXHEAP.h"

using namespace std;

struct node
{
    int ans;
    int tot;
    int pref;
    int suf;
    node() {}
    node(int val) { tot = ans = pref = suf = val; }
};
node combine(node x, node y)
{
    node *ptr = new node();
    ptr->ans = max(x.ans, y.ans);
    ptr->ans = max(ptr->ans, y.pref + x.suf);
    ptr->pref = max(x.tot + y.pref, x.pref);
    ptr->suf = max(y.tot + x.suf, y.suf);
    ptr->tot = x.tot + y.tot;
    return *ptr;
}

bool comp(int x, int y) { return x < y; }
int main()
{
    cout << "1) Disjoint Set" << endl;
    cout << "2) Segment Tree" << endl;
    cout << "3) Priority Queue" << endl;
    cout << "4) Exit" << endl;

    //     Disjoint Set Implementation
    cout << "Enter Choice of  Data Structure to Implement : " << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "Disjoint Set Implementation - " << endl;
        int n;
        cout << "Enter no. of Elements : ";
        cin >> n;
        DSU D(n);

        int unionOperation;
        cout<<"Enter no. of Union Operations to Perform : ";
        cin>>unionOperation;
        for (int i = 0; i < unionOperation; i++)
        {
            int x, y;
            cin >> x >> y;
            D.Union(x, y);
        }

        cout << "Enter No. of Find operation to perform : ";
        int noOfOperation;
        cin >> noOfOperation;

        for (int i = 0; i < noOfOperation; i++)
        {
            int ele;
            cout << "Enter element to Find : ";
            cin >> ele;
            cout << D.Find(ele) << endl;
                 
        }

        

        break;
    }

    case 2:
    {
        //     Segment Tree Implementation
        cout << "Segment Tree Implementation -" << endl
             << "Enter Vector Size : ";
        int t, i, j, n;
        cin >> n;
        vector<node> v(n);
        cout << "Enter Values : ";
        for (i = 0; i < n; i++)
        {
            cin >> j;
            v[i] = node(j);
        }
        SegmentTree<node> sg(v, node(-20000), combine);
        cout << "Enter Number of Query Cases : ";
        cin >> t;
        cout << "Enter Query Values (a and b) : ";
        while (n--)
        {
            cin >> i >> j;
            node as = sg.query(i - 1, j - 1);
            cout << (as.ans) << endl;
        }
        break;
    }
    case 3:
    {
        //    Priority Queue Implementation
        cout << "Priority Queue Implementation -" << endl;
        MaxHeap<int> myPriorityQueue(comp);
        int n;
        cout << "Enter no. of Elements : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            myPriorityQueue.push(x);
        }

        cout << "Top Element in Max Heap is : ";
        cout << myPriorityQueue.top() << endl;
        cout << "After Pop Operation " << endl;
        myPriorityQueue.pop();
        cout << "Top Element in Max Heap is : ";
        cout << myPriorityQueue.top() << endl;
        cout << endl;
        break;
    }
    
    }
    return 0;
}
