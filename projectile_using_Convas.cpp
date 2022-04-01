#include<simplecpp>
using namespace std;
int main(){
//Write your code here
initCanvas("Amit",500,500);
int w=getClick();
int x,y;
x=w/6553;
y=w%65536;
cout<<x<<"    "<<y<<endl;
Circle c(x,y,5);
c.penDown();
c.setFill(true);
c.setColor("red");
double vx,vy;
vx=1;vy=-1;
double g=0.01;
repeat(500)
{
c.imprint();
c.move(vx,vy);
vy+=g;
wait(0.01);
}
getClick();
}
