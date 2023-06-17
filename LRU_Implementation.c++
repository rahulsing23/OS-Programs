#include<bits/stdc++.h>
using namespace std;

int PageFault(vector<int>pages,int n, int size)
{
    int nopagefault=0;
    unordered_set<int> s;
    unordered_map<int,int>index;
    for(int i=0;i<n;i++)
    {
        // if frames are empty
        if(s.size()<size)
        {

            if(s.find(pages[i])==s.end())
            {
                s.insert(pages[i]);
                nopagefault++;
            }
            index[pages[i]]=i;

        }
        // if frames are full then remove least recently used page
        else{
            if(s.find(pages[i])==s.end())
            {
                int minindex = INT_MAX,page;
                for(auto c: s)
                {
                    // finding the minimum index element
                     if(index[c]<minindex)
                     {
                         minindex = index[c];
                         page=c;
                     }
                }
                s.erase(page);
                s.insert(pages[i]);
                nopagefault++;
            }
            index[pages[i]]=i;
        }
    }
    
    return nopagefault;

}




int main()
{
    vector<int>pages;
    int nopage,frame;
    cout << "Enter number of pages: ";
    cin >> nopage;
    cout << "Enter number of frame: ";
    cin >> frame;
    for(int i=0;i<nopage;i++)
    {
        int a;
        cin >> a;
        pages.push_back(a);
    }
    cout << "Page Fault are: "<<PageFault(pages,nopage,frame);
}