#include<iostream>
#include<vector>
#include <stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<Windows.h>
#include "class.h"
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    srand(time(NULL));
    Object* hero = new Hero(0, 0);
    Object* enemy = new Enemy(5, 5);
    int row = 20;
    int col = 50;
    vector<vector<Object*>>v;
    for (int i = 0; i < row; ++i)
    {
        vector<Object*>vv;
        for (int j = 0; j < col; ++j)
        {
            vv.push_back(new Empty(i, j));
        }
        v.push_back(vv);
    }
    v[0][0] = hero;
    v[5][5] = enemy;
    char command;
    while (true) {
        command = _getch();


        if (command == 'a')
        {
            if (hero->j - 1 >= 0) {
                auto tmp = v[hero->i][hero->j - 1];
                if (tmp == v[enemy->i][enemy->j]) {
                    if (hero->hp > enemy->hp) {
                        system("cls");
                        cout << "Hero win!\n";

                    }
                    else if (hero->hp < enemy->hp) {
                        system("cls");
                        cout << "Enemy win!\n";
                    }
                    else {
                        system("cls");
                        cout << "Draw!\n";
                    }
                    break;
                }
                v[hero->i][hero->j - 1] = hero;
                v[hero->i][hero->j] = tmp;
                hero->j--;
            }
        }
        else if (command == 'd')
        {
            if (hero->j + 1 < col) {
                auto tmp = v[hero->i][hero->j + 1];
                if (tmp == v[enemy->i][enemy->j]) {
                    if (hero->hp > enemy->hp) {
                        system("cls");
                        cout << "Hero win!\n";

                    }
                    else if (hero->hp < enemy->hp) {
                        system("cls");
                        cout << "Enemy win!\n";
                    }
                    else {
                        system("cls");
                        cout << "Draw!\n";
                    }
                    break;
                }

                v[hero->i][hero->j + 1] = hero;
                v[hero->i][hero->j] = tmp;
                hero->j++;
            }
        }
        else if (command == 's')
        {
            if (hero->i + 1 < row) {
                auto tmp = v[hero->i + 1][hero->j];
                if (tmp == v[enemy->i][enemy->j]) {
                    if (hero->hp > enemy->hp) {
                        system("cls");
                        cout << "Hero win!\n";

                    }
                    else if (hero->hp < enemy->hp) {
                        system("cls");
                        cout << "Enemy win!\n";
                    }
                    else {
                        system("cls");
                        cout << "Draw!\n";
                    }
                    break;
                }


                v[hero->i + 1][hero->j] = hero;
                v[hero->i][hero->j] = tmp;
                hero->i++;
            }
        }
        else if (command == 'w')
        {
            if (hero->i - 1 >= 0) {
                auto tmp = v[hero->i - 1][hero->j];
                if (tmp == v[enemy->i][enemy->j]) {
                    if (hero->hp > enemy->hp) {
                        system("cls");
                        cout << "Hero win!\n";

                    }
                    else if (hero->hp < enemy->hp) {
                        system("cls");
                        cout << "Enemy win!\n";
                    }
                    else {
                        system("cls");
                        cout << "Draw!\n";
                    }
                    break;
                }

                v[hero->i - 1][hero->j] = hero;
                v[hero->i][hero->j] = tmp;
                hero->i--;
            }
        }
        else if (command == 'f')
        {


            if (!(enemy->i - 1 >= 0 && enemy->i + 1 < row && enemy->j + 1 < col && enemy->j - 1 >= 0)) {
                //enemy->i = 3;
                //enemy->j = 3;
                enemy = new Empty(enemy->i, enemy->j);
                v[enemy->i][enemy->j] = new Empty(enemy->i, enemy->j);
                enemy = new Enemy(5, 5);
                v[enemy->i][enemy->j] = new Enemy(5, 5);

            }
            else {
                int count = 5;
                while (count-- && (enemy->i - 1 >= 0 && enemy->i + 1 < row && enemy->j + 1 < col && enemy->j - 1 >= 0)) {
                    int chose = 1 + rand() % 4;
                    if (chose == 1) {
                        auto tmp = v[enemy->i][enemy->j - 1];
                        if (tmp == v[hero->i][hero->j]) {
                            if (hero->hp > enemy->hp) {
                                system("cls");
                                cout << "Hero win!\n";

                            }
                            else if (hero->hp < enemy->hp) {
                                system("cls");
                                cout << "Enemy win!\n";
                            }
                            else {
                                system("cls");
                                cout << "Draw!\n";
                            }
                            return 0;
                        }
                        v[enemy->i][enemy->j - 1] = enemy;
                        v[enemy->i][enemy->j] = tmp;
                        enemy->j--;
                    }
                    else if (chose == 2) {
                        auto tmp = v[enemy->i][enemy->j + 1];
                        if (tmp == v[hero->i][hero->j]) {
                            if (hero->hp > enemy->hp) {
                                system("cls");
                                cout << "Hero win!\n";
                            }
                            else if (hero->hp < enemy->hp) {
                                system("cls");
                                cout << "Enemy win!\n";
                            }
                            else {
                                system("cls");
                                cout << "Draw!\n";
                            }
                            return 0;
                        }
                        v[enemy->i][enemy->j + 1] = enemy;
                        v[enemy->i][enemy->j] = tmp;
                        enemy->j++;
                    }
                    else if (chose == 3) {
                        auto tmp = v[enemy->i + 1][enemy->j];
                        if (tmp == v[hero->i][hero->j]) {
                            if (hero->hp > enemy->hp) {
                                system("cls");
                                cout << "Hero win!\n";

                            }
                            else if (hero->hp < enemy->hp) {
                                system("cls");
                                cout << "Enemy win!\n";
                            }
                            else {
                                system("cls");
                                cout << "Draw!\n";
                            }
                            return 0;
                        }
                        v[enemy->i + 1][enemy->j] = enemy;
                        v[enemy->i][enemy->j] = tmp;
                        enemy->i++;
                    }
                    else if (chose == 4) {
                        auto tmp = v[enemy->i - 1][enemy->j];
                        if (tmp == v[hero->i][hero->j]) {
                            if (hero->hp > enemy->hp) {
                                system("cls");
                                cout << "Hero win!\n";

                            }
                            else if (hero->hp < enemy->hp) {
                                system("cls");
                                cout << "Enemy win!\n";
                            }
                            else {
                                system("cls");
                                cout << "Draw!\n";
                            }
                            return 0;
                        }
                        v[enemy->i - 1][enemy->j] = enemy;
                        v[enemy->i][enemy->j] = tmp;
                        enemy->i--;
                    }
                    system("cls");
                    for (int i = 0; i < v.size(); ++i) {
                        for (int j = 0; j < v[0].size(); ++j) {
                            cout << v[i][j]->repr;
                        }
                        cout << "\n";
                    }
                }
            }
            }
            system("cls");
            for (int i = 0; i < v.size(); ++i) {
                for (int j = 0; j < v[0].size(); ++j) {
                    cout << v[i][j]->repr;
                }
                cout << "\n";
            }
            cout << "\nHero hp:" << hero->hp;
            cout << "\nEnemy hp:" << enemy->hp;
    }
    return 0;
}