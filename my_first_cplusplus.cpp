#include<iostream>
#include<list>
using namespace std;

class MyHashtable
{
    //busket size of the hash table
    int maxBUCKETSIZE;

    list<int>  *MyList;

    public:

    MyHashtable(int size)
    {
        this->maxBUCKETSIZE = size;
        this->MyList = new list<int>[maxBUCKETSIZE];
    }

    void insert(int key)
    {
        //to insert the element we need to find the index where we will insert the element in the list for that
        //we will find the hash value for the value to be inserted
        int index = hash_function(key);
        MyList[index].push_back(key);
    }

    void delete_element(int key)
    {
        //to delete the element we first need to find the index at which the element is present
        int index = hash_function(key);
        list<int>::iterator it;
        for (it = MyList[index].begin(); it!= MyList[index].end(); it++)
        {
            if((*it) == key)
            {
                break;
            }
        }
        if(it != MyList[index].end())
        {
            MyList[index].erase(it);
        }
    }

    void display_hashtable()
    {
        list<int>::iterator it;
        for(int i = 0 ; i < maxBUCKETSIZE ; i++)
        {
            cout << i ;
            for(it = MyList[i].begin(); it != MyList[i].end(); ++it)
            {
                cout << "-->" << *it;
            }
            cout << endl;
        }
    }

    int hash_function(int key)
    {
        return(key % maxBUCKETSIZE);
    }
};

int main(void)
{
    // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);
 
  // insert the keys into the hash table
  MyHashtable h(7);   // 7 is count of buckets in
               // hash table
  for (int i = 0; i < n; i++)
  {
      h.insert(a[i]);  
  }
  // delete 12 from hash table
  h.delete_element(12);
 
  // display the Hash table
  h.display_hashtable();
 
  return 0;
}