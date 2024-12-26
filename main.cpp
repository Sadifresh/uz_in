#include "TXLib.h"


struct Button
{
    int x;
    int y;
    int w;
    int h;
    const char* text;
    bool visible;

    void draw()
    {
    txSetColor (TX_WHITE, 2);
    txSetFillColor (TX_RED);
    Win32::RoundRect (txDC(), x, y, x+w, y+h, 30, 30);
    txSelectFont("Courier", 20);
    txDrawText(x, y, x+w, y+h, text);
    }

    bool click()
    {
        return (txMouseX()>x && txMouseX()<x+w &&
                txMouseY()>y && txMouseY()<y+h &&
                txMouseButtons() == 1 && visible);


    }

};

int main()
{
txCreateWindow (800, 600);
txTextCursor (false);

string PAGE = "menu";

Button btn = {80, 150, 120, 40, "Старт", true};
Button btn1 = {80, 200, 120, 40, "Настройки", true};
Button btn2 = {80, 250, 120, 40, "Правила", true};
Button btn3 = {80, 300, 120, 40, "О проге", true};
Button btn4 = {80, 350, 120, 40, "Выход", true};


    while(!btn4.click())
    {
        txClear();
        txBegin();
//меню
        if(PAGE == "menu")
        {
            btn.draw();
            btn1.draw();
            btn2.draw();
            btn3.draw();
            btn4.draw();

            btn.visible=true;
            btn1.visible=true;
            btn2.visible=true;
            btn3.visible=true;
            btn4.visible=true;


            if(btn.click())
            {
                while(btn.click()) txSleep(50);
                PAGE = "game";
                btn.visible=false;
                btn1.visible=false;
                btn2.visible=false;
                btn3.visible=false;
                btn4.visible=false;

            }

            if(btn1.click())
            {
                while(btn1.click()) txSleep(50);
                PAGE = "nastr";
                btn.visible=false;
                btn1.visible=false;
                btn2.visible=false;
                btn3.visible=false;
                btn4.visible=false;
            }

            if(btn2.click())
            {
                while(btn2.click()) txSleep(50);
                PAGE = "rules";
                btn.visible=false;
                btn1.visible=false;
                btn2.visible=false;
                btn3.visible=false;
                btn4.visible=false;
            }

            if(btn3.click())
            {
                while(btn3.click()) txSleep(50);
                PAGE = "about";
                btn.visible=false;
                btn1.visible=false;
                btn2.visible=false;
                btn3.visible=false;
                btn4.visible=false;
            }

        txSetFillColor (TX_BLACK);

       }




//Настройки
        if(PAGE == "nastr")
        {
            txSetColor (TX_BLACK);
            txTextOut(0, 0, "Страница настройки");
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_BLUE);

        }

//Правила
        if(PAGE == "rules")
        {
            txSetColor (TX_BLACK);
            txTextOut(0, 0, "Страница правил");
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_WHITE);
        }

//О программе

        if(PAGE == "about")
        {
            txSetColor (TX_BLACK);
            txTextOut(0, 0, "О ПРОГРАММЕ");
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_GREEN);
        }

//Игра
        if(PAGE == "game")
        {
            txSetColor (TX_BLACK);
            txTextOut(200, 50, "Пожалуйста подождите...");
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                PAGE = "menu";
            }
            txSetFillColor (TX_YELLOW);
        }




    txEnd();
    txSleep(10);
    }





    txDisableAutoPause();

    return 0;
}

