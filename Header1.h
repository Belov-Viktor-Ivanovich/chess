#pragma once
HANDLE hConsole;    // ЦВЕТ
void initChess();   //  КООРДИНАТЫ ФИГУР ФИГУР
void showAr();      //  ВЫВОД ДОСКИ
void dialog();      //  ДИАЛОГ
void inputAr(int x, int y, int x1, int y1); //ХОДЫ
bool hod(int x, int y, int x1, int y1);       // проверка хода
bool March(int x, int y, int a, int b);
bool HOD(int x, int y, int x1, int y1);
bool PAT(int k1, int k2);     // Проверка на пат
void Koord(int x, int y, int x1, int y1); //ИЗМЕНЕНИЕ КООРДИНАТ
bool proverka(int x2, int y2);    //Проверка есть ли еще атака