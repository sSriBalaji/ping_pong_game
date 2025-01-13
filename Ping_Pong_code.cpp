#include<iostream>
using namespace std;
class cBall{
    private:
        int x,y;
        int originalX,originalY;
    public:
        cBall(int posX,int posY){
            x = posX;
            y = posY;
        }

};

int main(){
    cBall ball(0,0);
    return 0;
}