#include "libLDPC/libldpc.h"
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
    cout<<"kek"<<endl;
    vector<bool> check, ldpc, ans;

    for(int i = 0 ; i < 1000; i++)
    {
        check.push_back(rand()%2);
        cout<<check.at(i)<<' ';
    }
    cout<<endl<<endl;

    ldpc = Encoder(check, 0.035, 3);

    for(int i = 0 ; i < ldpc.size(); i++)
    {
        cout<<ldpc.at(i)<<' ';
    }
    cout<<endl<<endl;

    ans = Decoder(check, ldpc, 0.035,"q", 3);

    for(int i = 0 ; i <ans.size(); i++)
    {
        cout<<ans.at(i)<<' ';
    }
    cout<<endl;

    return 0;
}
