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
        inline int getX(){return x;}
        inline int getY(){return y;}
        inline eDirection getDirection(){return direction; }
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
        inline int getX(){return x;}
        inline int getY(){return y;}


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
            player2 = new cPaddle(w-3,h/2-3);
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
            ball->move();

            int ballx = ball->getX();
            int bally = ball->getY();
            int player1x = player1->getX();
            int player1y = player1->getY();
            int player2x = player2->getX();
            int player2y = player2->getY();

            if(_kbhit()){
                char current = _getch();
                if(current == up1){
                    if(player1y > 0){
                        player1->moveUp();
                    }
                }
                if(current == up2){
                    if(player2y > 0){
                        player2->moveUp();
                    }
                }
                if(current == down1){
                    if(player1y + 4 < height){
                        player1->moveDown();
                    }
                }
                if(current == down2){
                    if(player2y + 4 < height){
                        player2->moveDown();
                    }
                }
                if(ball->getDirection() == STOP) ball->randomDirection();
                if(current=='q') quit = true;

            }
        }
        void logic(){
            int ballx = ball->getX();
            int bally = ball->getY();
            int player1x = player1->getX();
            int player1y = player1->getY();
            int player2x = player2->getX();
            int player2y = player2->getY();

            //left paddle;
            for(int i=0;i<4;i++){
                if(ballx == player1x +1){
                    if(bally == player1y+ i){
                        ball->changeDirection((eDirection)((rand()%3)+4));
                    }
                }
            }

            //right paddle
            for(int i=0;i<4;i++){
                if(ballx == player2x - 1){
                    if(bally == player2y+ i){
                        ball->changeDirection((eDirection)((rand()%3)+1));
                    }
                }
            }

            //bottom wall:
            if(bally == height-1){
                ball->changeDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
            }

            //top wall
            if(bally == 1){
                ball->changeDirection(ball->getDirection()== UPRIGHT ? DOWNRIGHT : DOWNLEFT);
            }

            //right wall
            if(ballx == width-1){
                scoreUp(player1);
            }

            //left wall
            if(ballx == 1){
                scoreUp(player2);
            }
        }
        void draw(){
            system("cls");
            for(int i=0;i<width+1;i++){
                cout<<"\xB2";
            }
            cout<<endl;
            for(int i=0;i<height;i++){
                for(int j=0;j<width;j++){
                    int ballx = ball->getX();
                    int bally = ball->getY();
                    int player1x = player1->getX();
                    int player1y = player1->getY();
                    int player2x = player2->getX();
                    int player2y = player2->getY();

                    if(j==0 || j==width-1) cout<<"\xB2";
                    if(j==ballx && i==bally) cout<<"O"; // ball
                    else if(j==player1x && i==player1y) cout<<"\xDB"; //player 1 paddle
                    else if(j == player2x && i==player2y) cout<<"\xDB"; //player 2 paddle

                    else if(j==player1x && i==player1y+1) cout<<"\xDB";
                    else if(j==player1x && i==player1y+2) cout<<"\xDB";
                    else if(j==player1x && i==player1y+3) cout<<"\xDB";

                    else if(j==player2x && i==player2y+1) cout<<"\xDB";
                    else if(j==player2x && i==player2y+2) cout<<"\xDB";
                    else if(j==player2x && i==player2y+3) cout<<"\xDB";
                    else cout<<" ";
                }
                cout<<endl;
            }
            for(int i=0;i<width+1;i++){
                cout<<"\xB2";
            }
            cout<<endl;
            cout<<"Player 1: "<<score1<<endl;
            cout<<"Player 2: "<<score2<<endl;
            
        }
        void run(){
            while(!quit){
                draw();
                input();
                logic();
            }
        }
};

int main(){
    cGameManager game(40,20);
    game.run();
    return 0;
}