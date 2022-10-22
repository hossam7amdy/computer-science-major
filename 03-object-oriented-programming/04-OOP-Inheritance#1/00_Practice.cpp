#include<iostream>
#include<new>
using namespace std;

int main()
{
    double *ptr[50];

    try
    {
        for(int i=0; i<50; i++)
        {
            ptr[i] = new double[500000000];
            cout << "ptr[" << i << "] points to 50 000 000 new doubles.\n";
        }
    }
    catch(bad_alloc &e)
    {
        cerr << "Exception occurred: " << e.what() << endl;
    }
    return 0;
}
