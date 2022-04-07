#ifndef PELI_LOOP_COUNTDOWN_H
#define PELI_LOOP_COUNTDOWN_H

#include "tallentaja.h"

class Peli_loop_countdown: public Tallentaja
{
private:
    bool wincondition = 0;

public:
    Peli_loop_countdown(int x);
};

#endif // PELI_LOOP_COUNTDOWN_H
