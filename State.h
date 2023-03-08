#pragma once

#include <string>
#include "symbole.h"
#include "automate.h"
#include <stack>

class State
{
    private:
        /* data */
    public:
        State(/* args */);
        virtual void Transition(automate& a, Symbole* s)=0;
        virtual string toString()=0;
        ~State();
};

class State0 : public State
{
    private:
        /* data */
    public:
        State0(/* args */);
        void Transition(automate& a, Symbole* s);
        virtual string toString();
        ~State0();
};


class State1 : public State
{
    private:
        /* data */
    public:
        State1(/* args */);
        void Transition(automate& a, Symbole* s);
        virtual string toString();
        ~State1();
};

class State2 : public State
{
    private:
        /* data */
    public:
        State2(/* args */);
        void Transition(automate& a, Symbole* s);
        virtual string toString();
        ~State2();
};

class State3 : public State
{
    private:
        /* data */
    public:
        State3(/* args */);
        void Transition(automate& a, Symbole* s);
        virtual string toString();
        ~State3();
};

class State4 : public State
{
    private:
        /* data */
    public:
        State4(/* args */);
        void Transition(automate& a, Symbole* s);
        virtual string toString();
        ~State4();
};

class State5 : public State
{
    private:
        /* data */
    public:
        State5(/* args */);
        void Transition(automate& a, Symbole* s);
        virtual string toString();
        ~State5();
};

class State6 : public State
{
    private:
        /* data */
    public:
        State6(/* args */);
        void Transition(automate& a, Symbole* s);
        virtual string toString();
        ~State6();
};

class State7 : public State
{
    private:
        /* data */
    public:
        State7(/* args */);
        void Transition(automate& a, Symbole* s);
        virtual string toString();
        ~State7();
};

class State8 : public State
{
    private:
        /* data */
    public:
        State8(/* args */);
        void Transition(automate& a, Symbole* s);
        virtual string toString();
        ~State8();
};

class State9 : public State
{
    private:
        /* data */
    public:
        State9(/* args */);
        void Transition(automate& a, Symbole* s);
        virtual string toString();
        ~State9();
};

