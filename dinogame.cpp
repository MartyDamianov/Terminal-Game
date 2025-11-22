#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

struct Dino{
    int y;
    bool jumping;
};

struct Obstacle{
    int x;
};

struct Game{
    bool running;
    int score;
    int Highscore;
    int width;
    Dino dino;
    Obstacle obstacle;
};

void Draw(const Game &g){
    system("cls");
    for (int y = 0; y < 5; y++){
        for(int x = 0; x < 30; x++){
            if (x == 5 && y == 4 - g.dino.y){
                std::cout << "|"; // dinosaur
            }
            else if (x == g.obstacle.x && y == 4){
                std::cout << "o"; // cactus
            }
            else {
                std::cout << " ";
            }
        }
        std::cout << endl;
    }
    for (int i = 0; i < 30; i++){
        std::cout << "=";
    } 
    std::cout << "\nScore: " << g.score << endl;
}

void Inputs(Game &g){
    if (_kbhit()){
        char key = _getch();
        if (key == ' '){
            if (!g.dino.jumping){
                g.dino.jumping = true;
            }
        }
    }
}

void Logic(Game &g){
    g.obstacle.x--;
    if (g.obstacle.x < 0){
        g.obstacle.x = 30;
        g.score++;
    }

    if (g.dino.jumping){
        g.dino.y++;
        if (g.dino.y > 2){
            g.dino.jumping = false;
        }
    }
    else if (g.dino.y > 0){
        g.dino.y--;
    }
    //Collision detection
    if(g.obstacle.x == 5 && g.dino.y == 0){
        g.running = false;
    }
}

int main(){
    Game g = {true, 0, 30, 0, {0, false}, {30}};

    while (g.running){
        Draw(g);
        Logic(g);
        Inputs(g);

        Sleep(5);
    }
}