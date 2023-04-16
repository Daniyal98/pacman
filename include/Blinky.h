#pragma once
#include <iostream>
#include "Ghosts.h"
using namespace std;

class Blinky : public Ghosts
{
    public:
    Blinky();
    void Move();
};