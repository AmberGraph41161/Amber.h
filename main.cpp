#include <iostream>
#include <vector>
#include <windows.h>
#include "Amber.h"
#include "AmberWin32.h"

void test1()
{
    std::vector<POINT> points;
    std::cout << "press [UP] to log a point" << std::endl;
    std::cout << "press [ESC] OR [ESCAPE] to exit logging points" << std::endl;
    while(true)
    {
        if(GetAsyncKeyState(VK_UP))
        {
            POINT temp;
            GetCursorPos(&temp);
            points.push_back(temp);
            std::cout << "logged point " << points.size() << std::endl;
            std::cout << "x: " << temp.x << std::endl;
            std::cout << "y: " << temp.y << std::endl;
            std::cout << "____________________" << std::endl;

            AMBER::SLEEP(0.01);
        }
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            std::cout << "break" << std::endl;
            break;
        }
    }

    int delay;
    std::cout << "[ENTER DELAY]" << std::endl;
    std::cout << "> " << std::endl;
    std::cin >> delay;

    std::cout << "starting clickpointsL()... " << std::endl;
    AMBER::SLEEP(1);
    std::cout << "clickpointsL(points, " << delay << ", true);" << std::endl;
    AMBER::clickpointsL(points, delay, true, AMBER::DragAllPoints);

    std::cout << "done" << std::endl;
}

void test2()
{
    AMBER::DOUBLERATIO slope;
    slope.num = 2;
    slope.den = 3;
    std::cout << "slope.num: " << slope.num << std::endl;
    std::cout << "slope.den: " << slope.den << std::endl;
    std::cout << "_____________" << std::endl;
    slope.simplify();
    std::cout << "slope.num: " << slope.num << std::endl;
    std::cout << "slope.den: " << slope.den << std::endl;
}
////////////////////////////////////////////////////////////////////////

void test3()
{
    AMBER::RATIO slope;
    slope.num = 0;
    slope.den = 0;

    std::cout << "slope nudm: " << slope.num << std::endl;
    std::cout << "slope den: " << slope.den << std::endl;
    slope.simplify();
    std::cout << "slope num: " << slope.num << std::endl;
    std::cout << "slope den: " << slope.den << std::endl;
}

void test4()
{
    std::string filepath = "resources\\test.txt";
    AMBER::SLEEP(1);
    AMBER::presskeyfile(filepath, 0.001, false);
}

int main()
{
    test4();
}
