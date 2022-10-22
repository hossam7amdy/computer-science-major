/// Homework 7: Double
/*
● Have u ever failed to compare doubles directly?
    ○ This is due to double representation
● More worse: Map<double, >
    ○ Won’t work
● Never compare doubles directly
    ○ Either function to compare: EPS
    ○ Or Double class
● Create double class that supports operators < > <= >= ==
*/

#include<iostream>
#include<map>
#include<cmath>
using namespace std;

class Double
{
private:
    double val;
    const double EPS = 1e-10;
    int cmpd(const double &val1, const double &val2) const
    {
        if(abs(val1-val2)<=EPS)
            return 0;
        else if(val>val2)
            return 1;
        else
            return -1;
    }
public:
    Double(): val(0) {}
    Double(const double& val): val(val) {}

    bool operator==(const Double &val2) const
    {
        return(!cmpd(val, val2.val));
    }
    bool operator<(Double &val2) const
    {
        return cmpd(val, val2.val)<0;
    }
    bool operator>(const Double &val2) const
    {
        return cmpd(val, val2.val)>0;
    }
    bool operator<=(const Double &val2) const
    {
        return !(*this>val2);
    }
    bool operator>=(const Double &val2) const
    {
        return !(*this<val2);
    }
};

int main()
{
    double a = 1+3.0/7.0-1;
    double b = 3.0/7.0;

    Double aa(a);
    Double bb(b);

    cout << (aa == bb) << "\n";

    cout << (aa >= bb) << "\n";

    cout << (aa <= bb) << "\n";

    cout << (aa > bb) << "\n";

    cout << (aa < bb) << "\n";

    map<Double, string> mp;
    mp[aa] = 10;
    mp[bb] = 20;

    cout << mp.size();

    //for(const auto& pair : mp)
     //   cout << pair.first << " " << pair.second << endl;


    return 0;
}
