#include <iostream>
#include <windows.h>
#include "Point.h"

void DisplayPointsValue(Point points[], int length) 
{
    if (points == NULL)
        return;
    for (int i = 0; i < length; i++)
    {
        cout << points[i].ToString(); // (*point)
    }
}

void DisplayPointsPointer(Point *points, int length) 
{
    if (points == NULL)
        return;
    for(int i = 0; i < length; i++)
    {
        cout << (*points++).ToString();
    }
}
Point OperationPoint(Point point) { // Передаем по значению Работает конструктор копирования
    point.SetX(point.GetX() * point.GetY());
    cout << "----------------------------------\n" << endl;
    cout << point.GetX() * point.GetY() << endl;
    cout << "----------------------------------\n" << endl;
    Point newPoint = point;
    return point;
}

Point & WorkerPoints(Point points[]) {
    points[0].SetX(5);
    points[0].SetY(1);
    cout << points[0].ToString() << endl;
    return *points;
}

int main()
{
    HANDLE hwnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hwnd, FOREGROUND_GREEN | FOREGROUND_INTENSITY); // Color and Font Console
    //--------------------------------
    Point dynamicPoints(10); // Вызвали конструктор для создания динамического массива points 10
    dynamicPoints = WorkerPoints(&dynamicPoints);
    //--------------------------------
    cout << OperationPoint(dynamicPoints).GetX() << endl; // Error! 
    //--------------------------------
    int length = 10;
    Point *points = new Point[length]
    {
        Point(25.30, 17),
        Point(15, 3),
        Point(0.1, 0.5),
        Point(90, 85),
        Point(15.85, 87),
        Point(30, 150),
        Point(25, 25),
        Point(99, 87),
        Point(14, 74),
        Point(18, 11)
    };

    DisplayPointsValue(points, length);
    DisplayPointsPointer(points, length);

    delete[length] points;
}
