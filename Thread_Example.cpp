#include <bits/stdc++.h>
#include<thread>
#include<unistd.h>
using namespace std;

void taskA()
{
    for(int i=0;i<5;i++)
    {
        sleep(1);
        cout<<"Thread A"<<endl;
        fflush(stdout);
    }
}

void taskB()
{
    for(int i=0;i<5;i++)
    {
        sleep(1);
        cout<<"Thread B"<<endl;
        fflush(stdout);
    }
}

int main()
{
    cout<<"Hello World";
    cout<<endl;
    thread t1(taskA);
    thread t2(taskB);
    t1.join();
    t2.join();
    return 0;
}