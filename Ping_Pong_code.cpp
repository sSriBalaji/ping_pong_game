#include<iostream>
using namespace std;
enum eDirection{STOP =0, LEFT = 1, UPLEFT =2,DOWNLEFT=3,RIGHT =4,UPRIGHT=5, DOWNRIGHT=6};
class cBall{
    private:
        int x,y;
        int originalX,originalY;
        eDirection direction;
    public:
        cBall(int posX,int posY){
            originalX = posX;
            originalY = posY;
            x = posX;
            y = posY;
            direction = STOP;
        }
        void reset(){
            x = originalX;
            y = originalY;
            direction = STOP;
        }
        void changeDirection(eDirection d){
            direction = d;
        }
        void randomDirection(){
            direction = (eDirection)((rand()%6)+1);
        }
        void move(){
            switch (direction)
            {
            case STOP:
                break;
            case LEFT:
                x--;
                break;
            case UPLEFT:
                x--;y--;
                break;
            case DOWNLEFT:
                x--;y++;
                break;
            case RIGHT:
                x++;
                break;
            case UPRIGHT:
                x++;y--;
                break;
            case DOWNRIGHT:
                x++;y++;
                break;
            
            default:
                break;
            }
        }


};

int main(){
    cBall ball(0,0);
    return 0;
}