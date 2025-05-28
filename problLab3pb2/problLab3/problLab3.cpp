#include "Canvas.h"

int main() {
    Canvas canvas(40, 20);

    canvas.Clear();
    canvas.DrawLine(1, 1, 38, 18, '*');
    canvas.DrawCircle(20, 10, 5, 'O');
    canvas.FillCircle(30, 10, 3, '@');
    canvas.DrawRect(5, 5, 15, 15, '#');
    canvas.FillRect(10, 10, 14, 14, '%');

    canvas.Print();

    return 0;
}