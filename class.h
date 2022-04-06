#pragma once
class Object {
public:
    int i;
    int j;
    char repr;
    int hp;
    Object(int i_, int j_, char r, int h);
};

class Empty : public Object {
public:
    Empty(int i, int j);
};

class Creature : public Object {
public:
    Creature(int i, int j, char repr, int hp);
};
class Hero : public Creature {
public:
    Hero(int i, int j);
};

class Enemy :public Creature {
public:
    Enemy(int i, int j);
};
