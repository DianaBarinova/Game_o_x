#include<iostream>
#include "class.h"
Object::Object(int i_, int j_, char r, int h) :i(i_), j(j_), repr(r), hp(h) {}
Empty::Empty(int i, int j) : Object(i, j, ' ', 0) {}
Creature:: Creature(int i, int j, char repr, int hp) :Object(i, j, repr, hp) {}
Hero:: Hero(int i, int j) :Creature(i, j, 'o', 1 + rand() % 100) {}
Enemy::Enemy(int i, int j) :Creature(i, j, 'x', 1 + rand() % 100) {}
