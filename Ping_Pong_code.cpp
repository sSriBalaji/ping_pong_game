#include<iostream>
#include<time.h>
#include<conio.h>
#include<Windows.h>
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
class cPaddle{
    private:
        int x,y;
        int originalX,originalY;
    public:
        cPaddle(){
            x = y = 0;
        }
        cPaddle(int posX,int posY) : cPaddle(){ //delegrating contructor
            originalX = posX;
            originalY = posY;
            x =  posX;
            y = posY;
        }
        inline void reset(){x=originalX; y=originalY;}
        inline void moveUp(){y--;}
        inline void moveDown(){y++;}


};

class cGameManager{
    private:
        int width;
        int height;
        int score1,score2;
        char up1,down1,up2,down2;
        bool quit;
        cBall * ball;
        cPaddle *player1;
        cPaddle *player2;
    public:
        cGameManager(int w,int h){
            srand(time(NULL));
            quit = false;
            up1 = 'w';down1 = 's';
            up2 = 'i';down2 ='k';
            score1 = 0; score2 =0;
            width = w;
            height = h;
            ball = new cBall(w/2,h/2);
            player1 = new cPaddle(1,h/2-3);
            player2 = new cPaddle(w-2,h/2-3);
        }
        ~cGameManager(){
            delete ball,player1,player2;
        }
        void scoreUp(cPaddle *player){
            if(player == player1) score1++;
            else if(player == player2) score2++;
            ball->reset();
            player1->reset();
            player2->reset();
        }
        void input(){

        }
        void logic(){

        }
        void draw(){

        }
};

int main(){
    cBall ball(0,0);
    return 0;
}