#include "TXLib.h"


struct Button
{
    int x;
    int y;
    int w;
    int h;

    const char* text ;

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
                txMouseButtons() == 1);


    }

};

int main()
{
txCreateWindow (800, 600);
txTextCursor (false);

Button btn = {80, 150, 120, 40, "Play"};
Button btn1 = {80, 200, 120, 40, "Exit"};

    while(!btn1.click())
    {
        txSetFillColor (TX_BLACK);
        txClear();
        txBegin();

        btn.draw();
        btn1.draw();



        if(btn.click())
        {
            while(btn.click()) txSleep(50);
            txSetFillColor (TX_WHITE);
            txCircle(400, 300, 50);
        }


    txEnd();
    txSleep(10);
    }





    txDisableAutoPause();

    return 0;
}

