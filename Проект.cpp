

#include <iostream>
#include <Windows.h>
#include<conio.h>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include "Header1.h"
using namespace std;


// Первоначальная расстановка фигур и цвета доски
void initChess()
{
    
    for (int i = 7; i >= 0; i--)
    {
        for (int j = 7; j >= 0; j--)
        {
            if (i % 2 == j % 2) ar[i][j] = char(219);
            else ar[i][j] =' ';
        }
    }
    ar[7][7] = 'l';
    ar[7][0] = 'l';
    ar[7][6] = 'h';
    ar[7][1] = 'h';
    ar[7][5] = 'e';
    ar[7][2] = 'e';
    ar[7][4] = 'k';
    ar[7][3] = 'q';

    ar[0][7] = 'L';
    ar[0][0] = 'L';
    ar[0][6] = 'H';
    ar[0][1] = 'H';
    ar[0][5] = 'E';
    ar[0][2] = 'E';
    ar[0][4] = 'K';
    ar[0][3] = 'Q';
    for (int i = 7; i >= 0; i--)
    {
        ar[6][i] = 'p';
        ar[1][i] = 'P';

    }
}

//  проверяет только возможность хода
bool HOD(int x, int y, int x1, int y1)
{
    bool flag = false;
    bool flagL = false;
    switch (ar[x][y])
    {
        // Пешка Белая
    case 'P':
        if (/*chet % 2 != 0 ||*/ ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if ((y == BPsB + 1 || y == BPsB - 1) && x == 4 && BPB > 0 && x1 == 5 && y1 == BPsB)
        {
            if ((x1 - 1) % 2 == y1 % 2)ar[x1 - 1][y1] = char(219);
            else ar[x1 - 1][y1] = ' ';
            flag = true;
        }
        else if (x == 1 && x1 - x == 1 && y == y1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)))
        {
            flag = true;
        }
        else if (x == 1 && x1 - x == 2 && y == y1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)) && (ar[x1-1][y] == ' ' || ar[x1-1][y] == char(219)))
        {
            flag = true;
        }
        else if (x > 1 && y == y1 && x1 - x == 1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)))
        {
            flag = true;
        }
        else if ((y1 == y + 1 || y1 == y - 1) && (ar[x1][y1] >='a' && ar[x1][y1] <='z') && x1 - x == 1)
        {
            flag = true;
        }
        break;
        // Пешка Черная
    case 'p':
        if (/*chet % 2 == 0 ||*/ ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((y == BPsW + 1 || y == BPsW - 1) && x == 3 && BPW > 0 && x1 == 2 && y1 == BPsW)
        {
            if ((x1 + 1) % 2 == y1 % 2)ar[x1 + 1][y1] = char(219);
            else ar[x1 + 1][y1] = ' ';
            flag = true;
        }
        if (x == 6 && (x - x1 == 1) && y == y1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)))
        {
            flag = true;
        }
        else if (x == 6 && (x - x1 == 2) && y == y1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)) && (ar[x1 + 1][y] == ' ' || ar[x1 + 1][y] == char(219)))
        {
            flag = true;
        }
        else if (x < 6 && y == y1 && x - x1 == 1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)))
        {
            flag = true;
        }
        else if ((y1 == y + 1 || y1 == y - 1) && (ar[x1][y1] >='A' && ar[x1][y1] <='Z') && x - x1 == 1)
        {
            flag = true;
        }
        break;
        // Ладья Белая
    case 'L':
        if (/*chet % 2 != 0 || */ ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if (x1 - x > 1 || x - x1 > 1 || y1 - y > 1 || y - y1 > 1)
        {
            if (x1 > x && y1 == y && x1>=0 && x1<=7)
            {
                for (int i = x + 1; i < x1; i++)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;

            }
            else if (x1 < x&& y1 == y && x1 >= 0 && x1 <= 7)
            {
                for (int i = x - 1; i > x1; i--)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }

            else if (y1 > y && x1 == x && y1 >= 0 && y1 <= 7)
            {
                for (int i = y + 1; i < y1; i++)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }

            else if (y1 < y&& x1 == x && y1 >= 0 && y1 <= 7)
            {
                for (int i = y - 1; i > y1; i--)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
        }
        else if (x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1)
        {
            if (x1 > x && y1 == y && x1 >= 0 && x1 <= 7)flag = true;
            else if (x1 < x && y1 == y && x1 >= 0 && x1 <= 7)flag = true;
            else if (y1 > y && x1 == x && y1 >= 0 && y1 <= 7)flag = true;
            else if (y1 < y && x1 == x && y1 >= 0 && y1 <= 7)flag = true;
        }
        break;
        // Ладья Черная
    case 'l':
        if (/*chet % 2 == 0 || */ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((x1 - x > 1 || x - x1 > 1 || y1 - y > 1 || y - y1 > 1)&&x1>=0 && x1<=7 && y1>=0 && y1<=7)
        {
            if (x1 > x && y1 == y)
            {
                for (int i = x + 1; i < x1; i++)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x1 < x&& y1 == y)
            {
                for (int i = x - 1; i > x1; i--)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (y1 > y && x1 == x)
            {
                for (int i = y + 1; i < y1; i++)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }

            else if (y1 < y&& x1 == x)
            {
                for (int i = y - 1; i > y1; i--)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
        }
        if ((x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
        {
            if (x1 > x && y1 == y) flag = true;
            else if (x1 < x && y1 == y)flag = true;
            else if (y1 > y && x1 == x)flag = true;
            else if (y1 < y && x1 == x)flag = true;
        }
        break;
        // Офицер Черный
    case 'e':
        if (/*chet % 2 == 0 || */ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((x1 - x > 1 || x - x1 > 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
        {
            if (x1 > x && x1 - x == y1 - y)                                       // Диагональ верхняя правая
            {
                for (int i = x + 1, j = y + 1; i < x1; i++, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (y > y1 && y1 == y - (x1 - x))                              // Диагональ верхняя левая
            {
                for (int i = x + 1, j = y - 1; i < x1; i++, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x1 == x - (y1 - y))                              // Диагональ нижняя правая
            {
                for (int i = x - 1, j = y + 1; i > x1; i--, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x - x1 == y - y1)                                // Диагональ нижняя левая
            {
                for (int i = x - 1, j = y - 1; i > x1; i--, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
        }
        else if ((x1 - x == 1 || x - x1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)                               //На один ход
        {
            if (x1 - x == y1 - y)
            {
                flag = true;
            }
            else if (y1 == y - (x1 - x))
            {
                flag = true;
            }
            else if (x1 == x - (y1 - y))
            {
                flag = true;
            }
            else if (x - x1 == y - y1)
            {
                flag = true;
            }
        }
        break;
        //  Офицер белый
    case 'E':
        if (/*chet % 2 != 0 || */ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if ((x1 - x > 1 || x - x1 > 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
        {
            if (x1 > x && x1 - x == y1 - y)                                       // Диагональ верхняя правая
            {
                for (int i = x + 1, j = y + 1; i < x1; i++, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (y > y1 && y1 == y - (x1 - x))                              // Диагональ верхняя левая
            {
                for (int i = x + 1, j = y - 1; i < x1; i++, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x1 == x - (y1 - y))                              // Диагональ нижняя правая
            {
                for (int i = x - 1, j = y + 1; i > x1; i--, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x - x1 == y - y1)                                // Диагональ нижняя левая
            {
                for (int i = x - 1, j = y - 1; i > x1; i--, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
        }
        else if ((x1 - x == 1 || x - x1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
        {
            if (x1 - x == y1 - y)
            {
                flag = true;
            }
            else if (y1 == y - (x1 - x))
            {
                flag = true;
            }
            else if (x1 == x - (y1 - y))
            {
                flag = true;
            }
            else if (x - x1 == y - y1)
            {
                flag = true;
            }
        }
        break;
        // Королева (Ферзь) Белая
    case 'Q':
        if (/*chet % 2 != 0 && */ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if ((x1 - x > 1 || x - x1 > 1 || y1 - y > 1 || y - y1 > 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
        {
            if (x1 > x && x1 - x == y1 - y)                                       // Диагональ верхняя правая
            {
                for (int i = x + 1, j = y + 1; i < x1; i++, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (y > y1 && y1 == y - (x1 - x))                              // Диагональ верхняя левая
            {
                for (int i = x + 1, j = y - 1; i < x1; i++, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x1 == x - (y1 - y))                              // Диагональ нижняя правая
            {
                for (int i = x - 1, j = y + 1; i > x1; i--, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x - x1 == y - y1)                                // Диагональ нижняя левая
            {
                for (int i = x - 1, j = y - 1; i > x1; i--, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;

            }
            else if (x1 > x && y1 == y)
            {
                for (int i = x + 1; i < x1; i++)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
            else if (x1 < x&& y1 == y)
            {
                for (int i = x - 1; i > x1; i--)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
            else if (y1 > y && x1 == x)
            {
                for (int i = y + 1; i < y1; i++)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
            else if (y1 < y&& x1 == x)
            {
                for (int i = y - 1; i > y1; i--)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
        }
        else if ((x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)    // На один ход
        {
            if (x1 > x && y1 == y)
            {
                flag = true;
            }
            else if (x1 < x && y1 == y)
            {
                flag = true;
            }
            else if (y1 > y && x1 == x)
            {
                flag = true;
            }
            else if (y1 < y && x1 == x)
            {
                flag = true;
            }
            else if (x1 - x == y1 - y)
            {
                flag = true;
            }
            else if (y1 == y - (x1 - x))
            {
                flag = true;
            }
            else if (x1 == x - (y1 - y))
            {
                flag = true;
            }
            else if (x - x1 == y - y1)
            {
                flag = true;
            }
        }
        break;

        // Королева (Ферзь) Черная
    case 'q':
        if (ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((x1 - x > 1 || x - x1 > 1 || y1 - y > 1 || y - y1 > 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
        {
            if (x1 > x && x1 - x == y1 - y)                                       // Диагональ верхняя правая
            {
                for (int i = x + 1, j = y + 1; i < x1; i++, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (y > y1 && y1 == y - (x1 - x))                              // Диагональ верхняя левая
            {
                for (int i = x + 1, j = y - 1; i < x1; i++, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x1 == x - (y1 - y))                              // Диагональ нижняя правая
            {
                for (int i = x - 1, j = y + 1; i > x1; i--, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x - x1 == y - y1)                                // Диагональ нижняя левая
            {
                for (int i = x - 1, j = y - 1; i > x1; i--, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x1 > x && y1 == y)
            {
                for (int i = x + 1; i < x1; i++)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
            else if (x1 < x&& y1 == y)
            {
                for (int i = x - 1; i > x1; i--)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
            else if (y1 > y && x1 == x)
            {
                for (int i = y + 1; i < y1; i++)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }

            else if (y1 < y&& x1 == x)
            {
                for (int i = y - 1; i > y1; i--)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
        }
        else if ((x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)    // На один ход
        {
            if (x1 > x && y1 == y)
            {
                flag = true;
            }
            else if (x1 < x && y1 == y)
            {
                flag = true;
            }
            else if (y1 > y && x1 == x)
            {
                flag = true;
            }
            else if (y1 < y && x1 == x)
            {
                flag = true;
            }
            else if (x1 - x == y1 - y)
            {
                flag = true;
            }
            else if (y1 == y - (x1 - x))
            {
                flag = true;
            }
            else if (x1 == x - (y1 - y))
            {
                flag = true;
            }
            else if (x - x1 == y - y1)
            {
                flag = true;
            }
        }
        break;
        // Король Белый
    case 'K':
        if (/*chet % 2 != 0 || */ ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if ((x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)    // На один ход
        {
            if (x1 > x && y1 == y)flag = true;
            else if (x1 < x && y1 == y)flag = true;
            else if (y1 > y && x1 == x)flag = true;
            else if (y1 < y && x1 == x)flag = true;
            else if (x1 - x == y1 - y)flag = true;
            else if (y1 == y - (x1 - x))flag = true;
            else if (x1 == x - (y1 - y))flag = true;
            else if (x - x1 == y - y1)flag = true;
        }
        break;

        // Король Черный
    case 'k':
        if (/*chet % 2 == 0 || */ ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)    // На один ход
        {
            if (x1 > x && y1 == y)flag = true;
            else if (x1 < x && y1 == y)flag = true;
            else if (y1 > y && x1 == x)flag = true;
            else if (y1 < y && x1 == x)flag = true;
            else if (x1 - x == y1 - y)flag = true;
            else if (y1 == y - (x1 - x))flag = true;
            else if (x1 == x - (y1 - y))flag = true;
            else if (x - x1 == y - y1)flag = true;
        }
        break;
        // Конь Белый
    case 'H':
        if (/*chet % 2 != 0 ||*/ ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if ((x1 == x + 2 && (y1 == y + 1 || y1 == y - 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (y1 == y + 2 && (x1 == x - 1 || x1 == x + 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (x1 == x - 2 && (y1 == y - 1 || y1 == y + 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (y1 == y - 2 && (x1 == x + 1 || x1 == x - 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7))
        {
            flag = true;
        }
        break;
        // Конь Черный
    case 'h':
        if (/*chet % 2 == 0 || */ ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((x1 == x + 2 && (y1 == y + 1 || y1 == y - 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (y1 == y + 2 && (x1 == x - 1 || x1 == x + 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (x1 == x - 2 && (y1 == y - 1 || y1 == y + 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (y1 == y - 2 && (x1 == x + 1 || x1 == x - 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7))
        {
            flag = true;
        }
        break;
    }
    return flag;
}

// проверка хода и не только
bool hod(int x, int y, int x1, int y1) 
{
    bool flag = false;
    bool flagL = false;
    roki = false;
    rok2 = 0;
    switch (ar[x][y])
    {
        // Пешка Белая
    case 'P':
        if (chet % 2 == 0 && ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if ((y == BPsB + 1 || y == BPsB - 1) && x == 4 && BPB > 0 && x1 == 5 && y1 == BPsB)
        {
            if ((x1 - 1) % 2 == y1 % 2)ar[x1 - 1][y1] = char(219);
            else ar[x1 - 1][y1] = ' ';
            BPB--;
            flag = true;
        }
        else if (x == 1 && x1 - x == 1 && y == y1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)))
        {
            BPB--;
            flag = true;
        }
        else if (x == 1 && x1 - x == 2 && y == y1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)) && (ar[x1 - 1][y] == ' ' || ar[x1 - 1][y] == char(219)))
        {
            BPW = 1;
            BPB--;
            BPsW = y;
            flag = true;
        }
        else if (x > 1 && y == y1 && x1 - x == 1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)))
        {
            BPB--;
            flag = true;
        }
        else if ((y1 == y + 1 || y1 == y - 1) && (ar[x1][y1] != ' ' && ar[x1][y1] != char(219)) && x1 - x == 1)
        {
            BPB--;
            flag = true;
        }
        break;
        // Пешка Черная
    case 'p':
        if (chet % 2 != 0 && ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((y == BPsW + 1 || y == BPsW - 1) && x == 3 && BPW > 0 && x1 == 2 && y1 == BPsW)
        {
            if ((x1 + 1) % 2 == y1 % 2)ar[x1 + 1][y1] = char(219);
            else ar[x1 + 1][y1] = ' ';
            BPW--;
            flag = true;
        }
        if (x == 6 && (x - x1 == 1) && y == y1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)))
        {
            BPW--;
            flag = true;
        }
        else if (x == 6 && (x - x1 == 2) && y == y1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)) && (ar[x1 + 1][y] == ' ' || ar[x1 + 1][y] == char(219)))
        {
            BPB = 1;
            BPW--;
            BPsB = y;
            flag = true;
        }
        else if (x < 6 && y == y1 && x - x1 == 1 && (ar[x1][y] == ' ' || ar[x1][y] == char(219)))
        {
            BPW--;
            flag = true;
        }
        else if ((y1 == y + 1 || y1 == y - 1) && (ar[x1][y1] != ' ' && ar[x1][y1] != char(219)) && x - x1 == 1)
        {
            BPW--;
            flag = true;
        }
        break;
        // Ладья Белая
    case 'L':
        if (chet % 2 == 0 && ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if (x1 - x > 1 || x - x1 > 1 || y1 - y > 1 || y - y1 > 1)
        {
            if (x1 > x && y1 == y && x1 >= 0 && x1 <= 7)
            {
                for (int i = x + 1; i < x1; i++)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    if (x == 0 && y == 0)counterLWL++;
                    else if (x == 0 && y == 7)counterLWR++;
                }
            }

            //рокировка белой левой
            else if (y1 == 3 && y == 0 && x1 == 0 && x == 0 && counterKW == 0 && counterLWL == 0)
            {
                for (int i = y + 1; i < y1; i++)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    counterLWL++;

                    cout << "compleat the castling?" << endl;
                    cout << "1 - yes, 2 -no" << endl;
                    do
                    {
                        cin >> rok;
                        if (rok == 1)
                        {
                            ar[0][4] = char(219);
                            ar[0][2] = 'K';
                            counterKW++;
                            rok2 = 1;
                            roki = true;
                            b2 = 2;
                            
                        }
                        else if (rok == 2)
                        {
                            counterLWL++;
                            break;
                        }
                        else if (rok > 2 || rok < 1)
                        {
                            cout << "unacceptable symbol" << endl;
                            cout << "try again" << endl;
                        }
                    } while (rok != 1 && rok != 2);
                }
            }
            //рокировка белой правой
            else if (y1 == 5 && y == 7 && x1 == 0 && x == 0 && counterKW == 0 && counterLWR == 0)
            {
                for (int i = y - 1; i > y1; i--)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    counterLWR++;

                    cout << "compleate the castling again?" << endl;
                    cout << "1 - yes, 2 -no" << endl;
                    do
                    {
                        cin >> rok;
                        if (rok == 1)
                        {
                            ar[0][4] = char(219);
                            ar[0][6] = 'K';
                            counterKW++;
                            b2 = 6;
                            rok2 = 2;
                            roki = true;
                        }
                        else if (rok == 2)
                        {
                            counterLWR++;
                            break;
                        }
                        else if (rok > 2 || rok < 1)
                        {
                            cout << "unacceptable symbol" << endl;
                            cout << "try again" << endl;
                        }
                    } while (rok != 1 && rok != 2);
                }
            }

            else if (x1 < x&& y1 == y && x1 >= 0 && x1 <= 7)
            {
                for (int i = x - 1; i > x1; i--)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    if (x == 0 && y == 0)counterLWL++;
                    else if (x == 0 && y == 7)counterLWR++;
                }
            }

            else if (y1 > y && x1 == x && y1 >= 0 && y1 <= 7)
            {
                for (int i = y + 1; i < y1; i++)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    if (x == 0 && y == 0)counterLWL++;
                    else if (x == 0 && y == 7)counterLWR++;
                }
            }

            else if (y1 < y&& x1 == x && y1 >= 0 && y1 <= 7)
            {
                for (int i = y - 1; i > y1; i--)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    if (x == 0 && y == 0)counterLWL++;
                    else if (x == 0 && y == 7)counterLWR++;
                }
            }
        }
        else if (x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1)
        {
            if (x1 > x && y1 == y && x1 >= 0 && x1 <= 7)
            {
                flag = true;
                if (x == 0 && y == 0)counterLWL++;
                else if (x == 0 && y == 7)counterLWR++;
            }
            else if (x1 < x && y1 == y && x1 >= 0 && x1 <= 7)
            {
                flag = true;
                if (x == 0 && y == 0)counterLWL++;
                else if (x == 0 && y == 7)counterLWR++;
            }
            else if (y1 > y && x1 == x && y1 >= 0 && y1 <= 7)
            {
                flag = true;
                if (x == 0 && y == 0)counterLWL++;
                else if (x == 0 && y == 7)counterLWR++;
            }
            else if (y1 < y && x1 == x && y1 >= 0 && y1 <= 7)
            {
                flag = true;
                if (x == 0 && y == 0)counterLWL++;
                else if (x == 0 && y == 7)counterLWR++;
            }
        }
        break;
        // Ладья Черная
    case 'l':
        if (chet % 2 != 0 && ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if (x1 - x > 1 || x - x1 > 1 || y1 - y > 1 || y - y1 > 1)
        {
            if (x1 > x && y1 == y && x1 >= 0 && x1 <= 7)
            {
                for (int i = x + 1; i < x1; i++)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    if (x == 7 && y == 0)counterLBL++;
                    else if (x == 7 && y == 7)counterLBR++;
                }
            }
            //рокировка черной правой
            else if (y1 == 5 && y == 7 && x1 == 7 && x == 7 && counterKB == 0 && counterLBR == 0)
            {
                for (int i = y - 1; i > y1; i--)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    counterLBR++;

                    cout << "compleate the castling?" << endl;
                    cout << "1 - yes, 2 -no" << endl;
                    do
                    {
                        cin >> rok;
                        if (rok == 1)
                        {
                            ar[7][4] = ' ';
                            ar[7][6] = 'k';
                            counterKB++;
                            b1 = 6;
                            rok2 = 1;
                            roki = true;
                        }
                        else if (rok == 2)
                        {
                            counterLBR--;
                            break;
                        }
                        else if (rok > 2 || rok < 1)
                        {
                            cout << "unacceptable symbol" << endl;
                            cout << "try again" << endl;
                        }
                    } while (rok != 1 && rok != 2);
                }
            }
            //рокировка черной левой
            else if (y1 == 3 && y == 0 && x1 == 7 && x == 7 && counterKB == 0 && counterLBL == 0)
            {
                for (int i = y + 1; i < y1; i++)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    counterLBL++;

                    cout << "compleate the castling?" << endl;
                    cout << "1 - yes, 2 -no" << endl;
                    do
                    {
                        cin >> rok;
                        if (rok == 1)
                        {
                            ar[7][4] = ' ';
                            ar[7][2] = 'k';
                            counterKB++;
                            roki = true;
                            b1 = 2;
                            rok2 = 2;

                        }
                        else if (rok == 2)
                        {
                            counterLBL--;
                            break;
                        }
                        else if (rok > 2 || rok < 1)
                        {
                            cout << "unacceptable symbol" << endl;
                            cout << "try again" << endl;
                        }
                    } while (rok != 1 && rok != 2);
                }
            }
            else if (x1 < x&& y1 == y && x1 >= 0 && x1 <= 7)
            {
                for (int i = x - 1; i > x1; i--)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    if (x == 7 && y == 0)counterLBL++;
                    else if (x == 7 && y == 7)counterLBR++;
                }
            }
            else if (y1 > y && x1 == x && y1 >= 0 && y1 <= 7)
            {
                for (int i = y + 1; i < y1; i++)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    if (x == 7 && y == 0)counterLBL++;
                    else if (x == 7 && y == 7)counterLBR++;
                }
            }

            else if (y1 < y&& x1 == x && y1 >= 0 && y1 <= 7)
            {
                for (int i = y - 1; i > y1; i--)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)
                {
                    flag = true;
                    if (x == 7 && y == 0)counterLBL++;
                    else if (x == 7 && y == 7)counterLBR++;
                }
            }
        }
        if (x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1)
        {
            if (x1 > x && y1 == y && x1 >= 0 && x1 <= 7)
            {
                flag = true;
                if (x == 7 && y == 0)counterLBL++;
                else if (x == 7 && y == 7)counterLBR++;
            }
            else if (x1 < x && y1 == y && x1 >= 0 && x1 <= 7)
            {
                flag = true;
                if (x == 7 && y == 0)counterLBL++;
                else if (x == 7 && y == 7)counterLBR++;
            }
            else if (y1 > y && x1 == x && y1 >= 0 && y1 <= 7)
            {
                flag = true;
                if (x == 7 && y == 0)counterLBL++;
                else if (x == 7 && y == 7)counterLBR++;
            }
            else if (y1 < y && x1 == x && y1 >= 0 && y1 <= 7)
            {
                flag = true;
                if (x == 7 && y == 0)counterLBL++;
                else if (x == 7 && y == 7)counterLBR++;
            }
        }
        break;
        // Офицер Черный
    case 'e':
        if (chet % 2 != 0 && ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((x1 - x > 1 || x - x1 > 1))
        {
            if (x1 > x && x1 - x == y1 - y && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)                                       // Диагональ верхняя правая
            {
                for (int i = x + 1, j = y + 1; i < x1; i++, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (y > y1 && y1 == y - (x1 - x) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)                              // Диагональ верхняя левая
            {
                for (int i = x + 1, j = y - 1; i < x1; i++, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x1 == x - (y1 - y) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)                              // Диагональ нижняя правая
            {
                for (int i = x - 1, j = y + 1; i > x1; i--, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x - x1 == y - y1 && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)                                // Диагональ нижняя левая
            {
                for (int i = x - 1, j = y - 1; i > x1; i--, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
        }
        else if (x1 - x == 1 || x - x1 == 1)                               //На один ход
        {
            if (x1 - x == y1 - y && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
            {
                flag = true;
            }
            else if (y1 == y - (x1 - x) && x1 >= 0 && x1 <= 7 && y1>=0 && y1<=7)
            {
                flag = true;
            }
            else if (x1 == x - (y1 - y) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
            {
                flag = true;
            }
            else if (x - x1 == y - y1 && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
            {
                flag = true;
            }
        }
        break;
        //  Офицер белый
    case 'E':
        if (chet % 2 == 0 && ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if (x1 - x > 1 || x - x1 > 1)
        {
            if (x1 > x && x1 - x == y1 - y && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)                                       // Диагональ верхняя правая
            {
                for (int i = x + 1, j = y + 1; i < x1; i++, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (y > y1 && y1 == y - (x1 - x) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)                              // Диагональ верхняя левая
            {
                for (int i = x + 1, j = y - 1; i < x1; i++, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x1 == x - (y1 - y) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)                              // Диагональ нижняя правая
            {
                for (int i = x - 1, j = y + 1; i > x1; i--, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x - x1 == y - y1 && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)                                // Диагональ нижняя левая
            {
                for (int i = x - 1, j = y - 1; i > x1; i--, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
        }
        else if ((x1 - x == 1 || x - x1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
        {
            if (x1 - x == y1 - y)
            {
                flag = true;
            }
            else if (y1 == y - (x1 - x))
            {
                flag = true;
            }
            else if (x1 == x - (y1 - y))
            {
                flag = true;
            }
            else if (x - x1 == y - y1)
            {
                flag = true;
            }
        }
        break;
        // Королева (Ферзь) Белая
    case 'Q':
        if (chet % 2 == 0 && ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if ((x1 - x > 1 || x - x1 > 1 || y1 - y > 1 || y - y1 > 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
        {
            if (x1 > x && x1 - x == y1 - y)                                       // Диагональ верхняя правая
            {
                for (int i = x + 1, j = y + 1; i < x1; i++, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (y > y1 && y1 == y - (x1 - x))                              // Диагональ верхняя левая
            {
                for (int i = x + 1, j = y - 1; i < x1; i++, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x1 == x - (y1 - y))                              // Диагональ нижняя правая
            {
                for (int i = x - 1, j = y + 1; i > x1; i--, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x - x1 == y - y1)                                // Диагональ нижняя левая
            {
                for (int i = x - 1, j = y - 1; i > x1; i--, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;

            }
            else if (x1 > x && y1 == y)
            {
                for (int i = x + 1; i < x1; i++)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
            else if (x1 < x&& y1 == y)
            {
                for (int i = x - 1; i > x1; i--)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
            else if (y1 > y && x1 == x)
            {
                for (int i = y + 1; i < y1; i++)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
            else if (y1 < y&& x1 == x)
            {
                for (int i = y - 1; i > y1; i--)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
        }
        else if ((x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)    // На один ход
        {
            if (x1 > x && y1 == y)
            {
                flag = true;
            }
            else if (x1 < x && y1 == y)
            {
                flag = true;
            }
            else if (y1 > y && x1 == x)
            {
                flag = true;
            }
            else if (y1 < y && x1 == x)
            {
                flag = true;
            }
            else if (x1 - x == y1 - y)
            {
                flag = true;
            }
            else if (y1 == y - (x1 - x))
            {
                flag = true;
            }
            else if (x1 == x - (y1 - y))
            {
                flag = true;
            }
            else if (x - x1 == y - y1)
            {
                flag = true;
            }
        }
        break;

        // Королева (Ферзь) Черная
    case 'q':
        if (chet % 2 != 0 && ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((x1 - x > 1 || x - x1 > 1 || y1 - y > 1 || y - y1 > 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)
        {
            if (x1 > x && x1 - x == y1 - y)                                       // Диагональ верхняя правая
            {
                for (int i = x + 1, j = y + 1; i < x1; i++, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (y > y1 && y1 == y - (x1 - x))                              // Диагональ верхняя левая
            {
                for (int i = x + 1, j = y - 1; i < x1; i++, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x1 == x - (y1 - y))                              // Диагональ нижняя правая
            {
                for (int i = x - 1, j = y + 1; i > x1; i--, j++)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x > x1 && x - x1 == y - y1)                                // Диагональ нижняя левая
            {
                for (int i = x - 1, j = y - 1; i > x1; i--, j--)
                {
                    if (ar[i][j] != ' ' && ar[i][j] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false)flag = true;
            }
            else if (x1 > x && y1 == y)
            {
                for (int i = x + 1; i < x1; i++)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
            else if (x1 < x&& y1 == y)
            {
                for (int i = x - 1; i > x1; i--)
                {
                    if (ar[i][y] != ' ' && ar[i][y] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
            else if (y1 > y && x1 == x)
            {
                for (int i = y + 1; i < y1; i++)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }

            else if (y1 < y&& x1 == x)
            {
                for (int i = y - 1; i > y1; i--)
                {
                    if (ar[x][i] != ' ' && ar[x][i] != char(219))
                    {
                        flagL = true;
                        break;
                    }
                }
                if (flagL == false) flag = true;
            }
        }
        else if ((x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)    // На один ход
        {
            if (x1 > x && y1 == y)
            {
                flag = true;
            }
            else if (x1 < x && y1 == y)
            {
                flag = true;
            }
            else if (y1 > y && x1 == x)
            {
                flag = true;
            }
            else if (y1 < y && x1 == x)
            {
                flag = true;
            }
            else if (x1 - x == y1 - y)
            {
                flag = true;
            }
            else if (y1 == y - (x1 - x))
            {
                flag = true;
            }
            else if (x1 == x - (y1 - y))
            {
                flag = true;
            }
            else if (x - x1 == y - y1)
            {
                flag = true;
            }
        }
        break;
        // Король Белый
    case 'K':
        if (chet % 2 == 0 && ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if ((x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)    // На один ход
        {
            if (x1 > x && y1 == y)
            {
                flag = true;
                counterKW++;
            }
            else if (x1 < x && y1 == y)
            {
                flag = true;
                counterKW++;
            }
            else if (y1 > y && x1 == x)
            {
                flag = true;
                counterKW++;
            }
            else if (y1 < y && x1 == x)
            {
                flag = true;
                counterKW++;
            }
            else if (x1 - x == y1 - y)
            {
                flag = true;
                counterKW++;
            }
            else if (y1 == y - (x1 - x))
            {
                flag = true;
                counterKW++;
            }
            else if (x1 == x - (y1 - y))
            {
                flag = true;
                counterKW++;
            }
            else if (x - x1 == y - y1)
            {
                flag = true;
                counterKW++;
            }
        }
        if (counterK % 2 == 0) {

            a2 = x1;
            b2 = y1;
        }
        counterK++;
        break;

        // Король Черный
    case 'k':
        if (chet % 2 != 0 && ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((x1 - x == 1 || x - x1 == 1 || y1 - y == 1 || y - y1 == 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7)    // На один ход
        {
            if (x1 > x && y1 == y)
            {
                flag = true;
                counterKB++;
            }
            else if (x1 < x && y1 == y)
            {
                flag = true;
                counterKB++;
            }
            else if (y1 > y && x1 == x)
            {
                flag = true;
                counterKB++;
            }
            else if (y1 < y && x1 == x)
            {
                flag = true;
                counterKB++;
            }
            else if (x1 - x == y1 - y)
            {
                flag = true;
                counterKB++;
            }
            else if (y1 == y - (x1 - x))
            {
                flag = true;
                counterKB++;
            }
            else if (x1 == x - (y1 - y))
            {
                flag = true;
                counterKB++;
            }
            else if (x - x1 == y - y1)
            {
                flag = true;
                counterKB++;
            }
        }
        if (counterK % 2 == 0) {

            a1 = x1;
            b1 = y1;
        }
        counterK++;
        break;
        // Конь Белый
    case 'H':
        if (chet % 2 == 0 && ar[x1][y1] >= 'A' && ar[x1][y1] <= 'Z')break;
        if ((x1 == x + 2 && (y1 == y + 1 || y1 == y - 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (y1 == y + 2 && (x1 == x - 1 || x1 == x + 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (x1 == x - 2 && (y1 == y - 1 || y1 == y + 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (y1 == y - 2 && (x1 == x + 1 || x1 == x - 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7))
        {
            flag = true;
        }
        break;
        // Конь Черный
    case 'h':
        if (chet % 2 != 0 && ar[x1][y1] >= 'a' && ar[x1][y1] <= 'z')break;
        if ((x1 == x + 2 && (y1 == y + 1 || y1 == y - 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (y1 == y + 2 && (x1 == x - 1 || x1 == x + 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (x1 == x - 2 && (y1 == y - 1 || y1 == y + 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7) || (y1 == y - 2 && (x1 == x + 1 || x1 == x - 1) && x1 >= 0 && x1 <= 7 && y1 >= 0 && y1 <= 7))
        {
            flag = true;
        }
        break;
    }
    return flag;
}   

// цвет текста и фона под ним
enum ConsoleColor
{
    Black,
    Blue,
    Green,
    Cyan,
    Red,
    Magenta,
    Brown,
    LightGray,
    DarkGray,
    LightBlue,
    LightGreen,
    LightCyan,
    LightRed,
    LightMagenta,
    Yellow,
    White
};
void SetColor(int text, int bg) {
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);                   //Получаем дескриптор вывода на консоль
    SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | text));         //Устанавливаем атрибуты текста
}

// Вывод доски с фигурами
void showAr()
{
    cout << "\t\t\t\tCHESS" << endl << endl << endl;
    char letter = 'a';
    cout << endl << endl;
    if (chet % 2 == 0)cout << "WHIT'S MOVE";
    else cout << "BLACK'S MOVE";
    cout << endl << endl;
    cout << "\t\t\t  ";
    for (int i = 0; i < 8; i++)
    {
        cout << letter << " ";
        letter++;
    }
    cout << endl;
    cout << "\t\t\t";
    for (int i = 7; i >=0; i--)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 8; j++)
        {
            if (ar[i][j] == 32 || ar[i][j] == char(219)) 
            {
                cout << ar[i][j] << ar[i][j];
            }
            else 
            {
                if (i % 2 == j % 2)
                {
                   SetColor(White,0);
                    cout << ar[i][j] << " ";                    
                }
                else if (i % 2 != j % 2)
                {
                    SetColor(0,White);
                    cout << ar[i][j] << " ";
                }
            }
            SetColor(0, White);
        }
        cout << i + 1 << " ";
        cout << endl;
        cout << "\t\t\t";

    }
    cout << "  ";
    letter = 'a';
    for (int i = 0; i < 8; i++)
    {
        cout << letter << " ";
        letter++;
    }
    cout << endl << endl;
    
}

// Диалог с игроком, ввод координат
void dialog()
{
    while (matt==false)
    {

        cout << " input chessman's location : ";
        cin >> x2;
        if (x2 == 113)
        {
            system("cls");
            cout << "\t\t\t\tGAME OVER" << endl << endl << endl;
            break;
        }
        while (x2 != 'a' && x2 != 'b' && x2 != 'c' && x2 != 'd' && x2 != 'e' && x2 != 'f' && x2 != 'g' && x2 != 'h')
        {
            cout << " incorrect coordinate " << endl;
            cin >> x2;
        }
        cin >> x;
        if (x == 113)
        {
            system("cls");
            cout << "\t\t\t\tGAME OVER" << endl << endl << endl;
            break;
        }
        while (x < 1 || x > 8 /*|| (x2 != 'a' && x2 != 'b' && x2 != 'c' && x2 != 'd' && x2 != 'e' && x2 != 'f' && x2 != 'g' && x2 != 'h')*/)
        {
            cout << " incorrect coordinate " << endl;
            // cin >> x2;
            cin >> x;
        }
        cout << "what location to chose? :  ";
        cin >> y2;
        if (y2 == 113)
        {
            system("cls");
            cout << "\t\t\t\tGAME OVER" << endl << endl << endl;
            break;
        }
        cin >> y;
        if (y == 113)
        {
            system("cls");
            cout << "\t\t\t\tGAME OVER" << endl << endl << endl;
            break;
        }
        int yv1 = x2 - 97;
        int yv2 = y2 - 97;
        int xv1 = x - 1;
        int xv2 = y - 1;

        inputAr(xv1, yv1, xv2, yv2);
        system("cls");
        showAr();

    }
    system("cls");
    showAr();
    if (chet % 2 == 0)cout << "VIKTORY BLACK";
    else cout << "VIKTORY WHITE";
}

// Проверка на ПАТ                                                                     
bool PAT(int k1, int k2)
{
    bool flag = false;

    ////////////////////////////////////////////////////////////////////////////////////
    if (HOD(k1, k2, k1 + 1, k2) == true) {
        Koord(k1, k2, k1 + 1, k2);
        if (proverka(k1 + 1, k2) == false) {
            flag = true;
            Koord(k1 + 1, k2, k1, k2);
            return flag;
        }
        else {
            Koord(k1 + 1, k2, k1, k2);
            flag = false;
        }
    }
    if (HOD(k1, k2, k1 - 1, k2) == true) {
        Koord(k1, k2, k1 - 1, k2);
        if (proverka(k1 - 1, k2) == false) {
            flag = true;
            Koord(k1 - 1, k2, k1, k2);
            return flag;
        }
        else {
            flag = false;
            Koord(k1 - 1, k2, k1, k2);
        }
    }
    if (HOD(k1, k2, k1, k2 + 1) == true) {
        Koord(k1, k2, k1, k2 + 1);
        if (proverka(k1, k2 + 1) == false) {
            flag = true;
            Koord(k1, k2 + 1, k1, k2);
            return flag;
        }
        else {
            flag = false;
            Koord(k1, k2 + 1, k1, k2);
        }
    }
    if (HOD(k1, k2, k1, k2 - 1) == true) {
        Koord(k1, k2, k1, k2 - 1);
        if (proverka(k1, k2 - 1) == false) {
            flag = true;
            Koord(k1, k2 - 1, k1, k2);
            return flag;
        }
        else {
            flag = false;
            Koord(k1, k2 - 1, k1, k2);

        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chet % 2 == 0 && ar[i][j] >= 'A' && ar[i][j] <= 'Z') {
                for (int i2 = 0; i2 < 8; i2++)
                {
                    for (int j2 = 0; j2 < 8; j2++)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);
                            if (proverka(k1, k2) == false) {
                                flag = true;
                                Koord(i2, j2, i, j);
                                return flag;
                            }
                            Koord(i2, j2, i, j);
                        }
                    }
                }
            }

            else if (chet % 2 != 0 && ar[i][j] >= 'a' && ar[i][j] <= 'z') {
                for (int i2 = 0; i2 < 8; i2++)
                {
                    for (int j2 = 0; j2 < 8; j2++)
                    {
                        if (HOD(i, j, i2, j2) == true) {                               
                            Koord(i, j, i2, j2);
                            if (proverka(k1, k2) == false) {
                                flag = true;
                                Koord(i2, j2, i, j);
                                return flag;
                            }
                            Koord(i2, j2, i, j);
                        }
                    }
                }
            }
        }
    }



    return flag;
}

//    Проверяет на возможность хода, делает ход, проверяет на МАТ и ПАТ и ШАХ 
void inputAr(int x, int y, int x1, int y1)
{
    chek2 = false;
    pat = true;
    if (chet % 2 == 0 && ar[x][y] >= 'a' && ar[x][y] <= 'z' || chet % 2 != 0 && ar[x][y] >= 'A' && ar[x][y] <= 'Z')                 // Определение чей ход
    {
        cout << " not your turn " << endl;
        cout << "try again " << endl;
        system("pause");
        system("cls");
        showAr();
        dialog();
    }

    if (hod(x, y, x1, y1) == false)
    {
        cout << "wrong move" << endl;
        system("pause");
        system("cls");
        showAr();
        dialog();
    }

    Koord(x, y, x1, y1);
    // if (check == true) {
    if (chet % 2 != 0 && ar[x1][y1] == 'k') {
        //chet++;
        if (proverka(x1, y1) == true) {
            cout << "wrong move" << endl;
            Koord(x1, y1, x, y);
            //chet++;
            system("pause");
            system("cls");
            showAr();
            dialog();
        }
        //chet++;
        check = false;

    }
    else  if (chet % 2 == 0 && ar[x1][y1] == 'K') {
        //chet++;
        if (proverka(x1, y1) == true) {
            cout << "wrong move" << endl;
            Koord(x1, y1, x, y);
            //chet++;
            system("pause");
            system("cls");
            showAr();
            dialog();
        }
        //chet++;
        check = false;
    }
    else  if (chet % 2 != 0) {
        //chet++;
        if (proverka(a1, b1) == true) {
            cout << "wrong move" << endl;
            Koord(x1, y1, x, y);
            if (roki == true) {
                if (rok2 == 1) {
                    ar[7][4] = 'k';
                    ar[7][6] = ' ';
                    b2 = 4;
                    counterLBR--;
                }
                else if (rok2 == 2) {
                    ar[7][4] = 'k';
                    ar[7][2] = ' ';
                    b2 = 4;
                    counterLBL--;
                }
                counterKB--;
            }
            system("pause");
            system("cls");
            showAr();
            dialog();
        }
        //chet++;
        check = false;
    }
    else  if (chet % 2 == 0) {
        //chet++;
        if (proverka(a2, b2) == true) {
            cout << "wrong move" << endl;
            Koord(x1, y1, x, y);
            if (roki == true) {
                if (rok2 == 1) {
                    ar[0][4] = 'K';
                    ar[0][2] = char(219);
                    b2 = 4;
                    counterLWL--;
                }
                else if (rok2 == 2) {
                    ar[0][4] = 'K';
                    ar[0][6] = char(219);
                    b2 = 4;
                    counterLWR--;
                }
                counterKW--;
            }
            system("pause");
            system("cls");
            showAr();
            dialog();
        }
        //chet++;
        check = false;

    }

    // }
    Koord(x1, y1, x, y);



    char a = ar[x][y];             // ИЗМЕНЕНИЕ КООРДИНАТ ФИГУРЫ
    if (x % 2 == y % 2)
    {
        ar[x][y] = char(219);
    }
    else if (x % 2 != y % 2)
    {
        ar[x][y] = ' ';
    }
    ar[x1][y1] = a;
    if (chet % 2 != 0 && ar[x1][y1] == 'k') {
        a1 = x1;
        b1 = y1;
    }
    else if (chet % 2 == 0 && ar[x1][y1] == 'K') {
        a2 = x1;
        b2 = y1;
    }
    if (x1 == 7 && ar[x1][y1] == 'P')
    {
        char w;
        cout << "imput necessary chessman ?" << endl;
        cin >> w;
        while (w != 'L' && w != 'H' && w != 'E' && w != 'Q' && w != 'P')
        {
            cout << "unaccaptable chessman" << endl;
            cin >> w;
        }
        ar[x1][y1] = w;
    }
    else if (x1 == 0 && ar[x1][y1] == 'p')
    {
        char w;
        cout << "imput necessary chessman ?" << endl;
        cin >> w;
        while (w != 'l' && w != 'h' && w != 'e' && w != 'q' && w != 'p')
        {
            cout << "unaccaptable chessman" << endl;
            cin >> w;
        }
        ar[x1][y1] = w;
    }
    chet++;
    if (chet % 2 != 0) {
        if (HOD(x1, y1, a1, b1) == true)
        {
            if (March(x1, y1, a1, b1) == true) {
                system("cls");
                showAr();
                cout << endl << "CHECK" << endl;
                check = true;
                pat = false;
                system("pause");
            }
            else {
                system("cls");
                showAr();
                cout << endl << "matt" << endl;
                matt = true;
                system("pause");
                system("cls");

                if (chet % 2 == 0)cout << "VIKTORY BLACK";
                else cout << "VIKTORY WHITE";
                if (matt == true)exit(1);
            }
        }
        else
        {
            if (proverka(a1, b1) == true) {
                if (March(A1, A2, a1, b1) == true) {
                    system("cls");
                    showAr();
                    cout << endl << "CHECK" << endl;
                    check = true;
                    pat = false;
                    system("pause");
                }
                else {
                    system("cls");
                    showAr();
                    cout << endl << "matt" << endl;
                    matt = true;
                    system("pause");
                    system("cls");
                    if (chet % 2 == 0)cout << "VIKTORY BLACK";
                    else cout << "VIKTORY WHITE";
                    if (matt == true)exit(1);
                }
            }
            else pat = false;
        }
    }
    else if (chet % 2 == 0) {
        if (HOD(x1, y1, a2, b2) == true)
        {
            if (March(x1, y1, a2, b2) == true) {
                system("cls");
                showAr();
                cout << endl << "CHECK" << endl;
                check = true;
                pat = false;
                system("pause");
            }
            else {
                system("cls");
                showAr();
                cout << endl << "matt" << endl;
                matt = true;
                system("pause");
                system("cls");
                if (chet % 2 == 0)cout << "VIKTORY BLACK";
                else cout << "VIKTORY WHITE";
                if (matt == true)exit(1);
            }
        }
        else
        {
            if (proverka(a2, b2) == true) {
                if (March(A1, A2, a2, b2) == true) {
                    system("cls");
                    showAr();
                    cout << endl << "CHECK" << endl;
                    check = true;
                    pat = false;
                    system("pause");
                }
                else {
                    system("cls");
                    showAr();
                    cout << endl << "matt" << endl;
                    matt = true;
                    system("pause");
                    system("cls");
                    if (chet % 2 == 0)cout << "VIKTORY BLACK";
                    else cout << "VIKTORY WHITE";
                    if (matt == true)exit(1);
                }
            }
            else pat = false;
        }
    }
    if (pat == false) {
        if (chet % 2 == 0) {
            k1 = a2;
            k2 = b2;
        }
        else if (chet % 2 != 0) {
            k1 = a1;
            k2 = b1;
        }
        if (PAT(k1, k2) == false) {
            system("cls");
            showAr();
            cout << endl << "PAT" << endl;
            system("pause");
            system("cls");
            if (chet % 2 == 0)cout << "VIKTORY BLACK";
            else cout << "VIKTORY WHITE";
            exit(1);
        }
    }


}

// ОПРЕДЕЛЕНИЕ ПО КАКОМУ МАРШРУТУ ДЕЛАЕТСЯ ШАГ И ЕСТЬ ЛИ МАТ
bool March(int x, int y, int a, int b)           // буду передавать коорд. фигуры нападающей и короля
{
    bool flag = false;


    if (y == b && x < a)                                                 //ВЕРТИКАЛЬ СНИЗУ ВВЕРХ
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (ar[i][j] >= 'a' && ar[i][j] <= 'z'&& chet%2!=0)
                {
                    for (int i2 = x,j2=y; i2 < a ; i2++)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                    Koord(i2, j2, i, j);
                                    if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                else if(ar[i][j] >= 'A' && ar[i][j] <= 'Z' && chet % 2 == 0)
                {
                    for (int i2 = x,j2=y; i2 < a; i2++)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                    Koord(i2, j2, i, j);
                                    if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                if (flag == true)break;
            }
            if (flag == true)break;
        }
    }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if (y == b && x > a)                                                 //ВЕРТИКАЛЬ СВВЕРХ ВНИЗ
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (ar[i][j] >= 'a' && ar[i][j] <= 'z' && chet % 2 != 0)
                {
                    for (int i2 = x,j2=y; i2 > a; i2--)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                    Koord(i2, j2, i, j);
                                    if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                else if (ar[i][j] >= 'A' && ar[i][j] <= 'Z' && chet % 2 == 0)
                {
                    for (int i2 = x,j2=y; i2 > a; i2--)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                if (flag == true)break;
            }
            if (flag == true)break;
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////

    else if(x<a&&y>b)                                               //ДИАГОНАЛЬ ГЛАВНАЯ СНИЗУ ВВЕРХ
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (ar[i][j] >= 'a' && ar[i][j] <= 'z' && chet % 2 != 0)
                {
                    for (int i2 = x,j2=y; i2 < a; i2++,j2--)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);                                    

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i2, j2, i, j);                                                                    //вот так правильно
                                if(flag==true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }                                                               //ВСЕ ЧТО ВЫШЕ ВЕРНО НУЖНО ОСТАЛЬНЫЕ ПЕРЕДЕЛАТЬ!!!
                        }
                    }
                }
                else if (ar[i][j] >= 'A' && ar[i][j] <= 'Z' && chet % 2 == 0)
                {
                    for (int i2 = x,j2 = y; i2 < a; i2++,j2--)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                    Koord(i2, j2, i, j);
                                    if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                if (flag == true)break;
            }
            if (flag == true)break;
        }
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    else if (x>a && y<b)                                               //ДИАГОНАЛЬ ГЛАВНАЯ СВЕРХУ ВНИЗ
    {
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            if (ar[i][j] >= 'a' && ar[i][j] <= 'z' && chet % 2 != 0)
            {
                for (int i2 = x, j2 = y; i2 > a; i2--, j2++)
                {
                    if (HOD(i, j, i2, j2) == true) {
                        Koord(i, j, i2, j2);

                        if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                            if (HOD(x, y, i2, j2) == false) {
                                flag = true;
                                if (proverka(i2, j2) == true) {
                                    flag = false;
                                }
                            }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;
                            if (HOD(i, j, i + 1, j) == true) {
                                Koord(i, j, i + 1, j);
                                if (HOD(x, y, i + 1, j) == false) {
                                    flag = true;
                                    if (proverka(i + 1, j) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i + 1, j, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i - 1, j) == true) {
                                Koord(i, j, i - 1, j);
                                if (HOD(x, y, i - 1, j) == false) {
                                    flag = true;
                                    if (proverka(i - 1, j) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i - 1, j, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i, j + 1) == true) {
                                Koord(i, j, i, j + 1);
                                if (HOD(x, y, i, j + 1) == false) {
                                    flag = true;
                                    if (proverka(i, j + 1) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i, j + 1, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i, j - 1) == true) {
                                Koord(i, j, i, j - 1);
                                if (HOD(x, y, i, j - 1) == false) {
                                    flag = true;
                                    if (proverka(i, j - 1) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i, j - 1, i, j);
                                if (flag == true)break;
                            }
                        }
                        else {
                            flag = true;
                            if (proverka(a, b) == true) {
                                flag = false;
                            }
                            Koord(i2, j2, i, j);
                            if (flag == true)break;

                        }
                    }
                }
            }
            else if (ar[i][j] >= 'A' && ar[i][j] <= 'Z' && chet % 2 == 0)
            {
                for (int i2 = x, j2 = y; i2 > a; i2--, j2++)
                {
                    if (HOD(i, j, i2, j2) == true) {
                        Koord(i, j, i2, j2);

                        if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                            if (HOD(x, y, i2, j2) == false) {
                                flag = true;
                                if (proverka(i2, j2) == true) {
                                    flag = false;
                                }
                            }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;
                            if (HOD(i, j, i + 1, j) == true) {
                                Koord(i, j, i + 1, j);
                                if (HOD(x, y, i + 1, j) == false) {
                                    flag = true;
                                    if (proverka(i + 1, j) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i + 1, j, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i - 1, j) == true) {
                                Koord(i, j, i - 1, j);
                                if (HOD(x, y, i - 1, j) == false) {
                                    flag = true;
                                    if (proverka(i - 1, j) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i - 1, j, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i, j + 1) == true) {
                                Koord(i, j, i, j + 1);
                                if (HOD(x, y, i, j + 1) == false) {
                                    flag = true;
                                    if (proverka(i, j + 1) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i, j + 1, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i, j - 1) == true) {
                                Koord(i, j, i, j - 1);
                                if (HOD(x, y, i, j - 1) == false) {
                                    flag = true;
                                    if (proverka(i, j - 1) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i, j - 1, i, j);
                                if (flag == true)break;
                            }
                        }
                        else {
                            flag = true;
                            if (proverka(a, b) == true) {
                                flag = false;
                            }
                            Koord(i2, j2, i, j);
                            if (flag == true)break;

                        }
                    }
                }
            }
            if (flag == true)break;
        }
        if (flag == true)break;
    }
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////


    else if (x < a && y < b)                                               //ДИАГОНАЛЬ ПОБОЧНАЯ СНИЗУ ВВЕРХ
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (ar[i][j] >= 'a' && ar[i][j] <= 'z' && chet % 2 != 0)
                {
                    for (int i2 = x, j2 = y; i2 < a; i2++, j2++)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                    Koord(i2, j2, i, j);
                                    if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                else if (ar[i][j] >= 'A' && ar[i][j] <= 'Z' && chet % 2 == 0)
                {
                    for (int i2 = x, j2 = y; i2 < a; i2++, j2++)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                    Koord(i2, j2, i, j);
                                    if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                if (flag == true)break;
            }
            if (flag == true)break;
        }
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////


    else if (x > a && y > b)                                               //ДИАГОНАЛЬ ПОБОЧНАЯ СВЕРХУ ВНИЗ /////////////////////////////////////////////////////////////////////////////////////////////
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (ar[i][j] >= 'a' && ar[i][j] <= 'z' && chet % 2 != 0)
                {
                    for (int i2 = x, j2 = y; i2 > a; i2--, j2--)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                    Koord(i2, j2, i, j);
                                    if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                else if (ar[i][j] >= 'A' && ar[i][j] <= 'Z' && chet % 2 == 0)
                {
                    for (int i2 = x, j2 = y; i2 > a; i2--, j2--)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                    Koord(i2, j2, i, j);
                                    if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                if (flag == true)break;
            }
            if (flag == true)break;
        }
    }



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if (y < b && x == a)                                                 //ГОРИЗОНТАЛЬ СЛЕВО НА ПРАВО
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {

                if (ar[i][j] >= 'a' && ar[i][j] <= 'z' && chet % 2 != 0)
                {
                    for (int i2 = x,j2=y; j2 < b; j2++)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                    Koord(i2, j2, i, j);
                                    if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                else if (ar[i][j] >= 'A' && ar[i][j] <= 'Z' && chet % 2 == 0)
                {
                    for (int i2 = x,j2=y; j2 < b; j2++)
                    {
                        if (HOD(i, j, i2, j2) == true) {
                            Koord(i, j, i2, j2);

                            if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                                if (HOD(x, y, i2, j2) == false) {
                                    flag = true;
                                    if (proverka(i2, j2) == true) {
                                        flag = false;
                                    }
                                }
                                    Koord(i2, j2, i, j);
                                    if (flag == true)break;
                                if (HOD(i, j, i + 1, j) == true) {
                                    Koord(i, j, i + 1, j);
                                    if (HOD(x, y, i + 1, j) == false) {
                                        flag = true;
                                        if (proverka(i + 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i + 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i - 1, j) == true) {
                                    Koord(i, j, i - 1, j);
                                    if (HOD(x, y, i - 1, j) == false) {
                                        flag = true;
                                        if (proverka(i - 1, j) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i - 1, j, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j + 1) == true) {
                                    Koord(i, j, i, j + 1);
                                    if (HOD(x, y, i, j + 1) == false) {
                                        flag = true;
                                        if (proverka(i, j + 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j + 1, i, j);
                                    if (flag == true)break;

                                }
                                if (HOD(i, j, i, j - 1) == true) {
                                    Koord(i, j, i, j - 1);
                                    if (HOD(x, y, i, j - 1) == false) {
                                        flag = true;
                                        if (proverka(i, j - 1) == true) {
                                            flag = false;
                                        }
                                    }
                                    Koord(i, j - 1, i, j);
                                    if (flag == true)break;
                                }
                            }
                            else {
                                flag = true;
                                if (proverka(a, b) == true) {
                                    flag = false;
                                }
                                Koord(i2, j2, i, j);
                                if (flag == true)break;

                            }
                        }
                    }
                }
                if (flag == true)break;
            }
            if (flag == true)break;
        }
    }



    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    else if (y > b && x == a)                                                 //ГОРИЗОНТАЛЬ СПРАВО НА ЛЕВО
    {
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {

            if (ar[i][j] >= 'a' && ar[i][j] <= 'z' && chet % 2 != 0)
            {
                for (int i2 = x, j2 = y; j2 > b; j2--)
                {
                    if (HOD(i, j, i2, j2) == true) {
                        Koord(i, j, i2, j2);

                        if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                            if (HOD(x, y, i2, j2) == false) {
                                flag = true;
                                if (proverka(i2, j2) == true) {
                                    flag = false;
                                }
                            }
                            Koord(i2, j2, i, j);
                            if (flag == true)break;
                            if (HOD(i, j, i + 1, j) == true) {
                                Koord(i, j, i + 1, j);
                                if (HOD(x, y, i + 1, j) == false) {
                                    flag = true;
                                    if (proverka(i + 1, j) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i + 1, j, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i - 1, j) == true) {
                                Koord(i, j, i - 1, j);
                                if (HOD(x, y, i - 1, j) == false) {
                                    flag = true;
                                    if (proverka(i - 1, j) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i - 1, j, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i, j + 1) == true) {
                                Koord(i, j, i, j + 1);
                                if (HOD(x, y, i, j + 1) == false) {
                                    flag = true;
                                    if (proverka(i, j + 1) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i, j + 1, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i, j - 1) == true) {
                                Koord(i, j, i, j - 1);
                                if (HOD(x, y, i, j - 1) == false) {
                                    flag = true;
                                    if (proverka(i, j - 1) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i, j - 1, i, j);
                                if (flag == true)break;
                            }
                        }
                        else {
                            flag = true;
                            if (proverka(a, b) == true) {
                                flag = false;
                            }
                            Koord(i2, j2, i, j);
                            if (flag == true)break;

                        }
                    }
                }
            }
            else if (ar[i][j] >= 'A' && ar[i][j] <= 'Z' && chet % 2 == 0)
            {
                for (int i2 = x, j2 = y; j2 > b; j2--)
                {
                    if (HOD(i, j, i2, j2) == true) {
                        Koord(i, j, i2, j2);

                        if (ar[i2][j2] == 'K' || ar[i2][j2] == 'k') {
                            if (HOD(x, y, i2, j2) == false) {                                                           //////////////////////////////
                                flag = true;
                                if (proverka(i2, j2) == true) {
                                    flag = false;
                                }
                            }                                                                                   ///////////////////////////////////////
                            Koord(i2, j2, i, j);
                            if (flag == true)break;
                            if (HOD(i, j, i + 1, j) == true) {
                                Koord(i, j, i + 1, j);
                                if (HOD(x, y, i + 1, j) == false) {
                                    flag = true;
                                    if (proverka(i + 1, j) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i + 1, j, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i - 1, j) == true) {
                                Koord(i, j, i - 1, j);
                                if (HOD(x, y, i - 1, j) == false) {
                                    flag = true;
                                    if (proverka(i - 1, j) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i - 1, j, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i, j + 1) == true) {
                                Koord(i, j, i, j + 1);
                                if (HOD(x, y, i, j + 1) == false) {
                                    flag = true;
                                    if (proverka(i, j + 1) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i, j + 1, i, j);
                                if (flag == true)break;

                            }
                            if (HOD(i, j, i, j - 1) == true) {
                                Koord(i, j, i, j - 1);
                                if (HOD(x, y, i, j - 1) == false) {
                                    flag = true;
                                    if (proverka(i, j - 1) == true) {
                                        flag = false;
                                    }
                                }
                                Koord(i, j - 1, i, j);
                                if (flag == true)break;
                            }
                        }
                        else {
                            flag = true;
                            if (proverka(a, b) == true) {
                                flag = false;
                            }
                            Koord(i2, j2, i, j);
                            if (flag == true)break;

                        }
                    }
                }
            }
            if (flag == true)break;
        }
        if (flag == true)break;
    }
    }


////////////////////////////////////////////////////////////////////////////////////////////////////

    else if (ar[x][y] == 'H' || ar[x][y] == 'h')       ////////////////////////ШАХ ОТ КОНЯ
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (ar[i][j] == 'k' && chet % 2 != 0)
                {
                    if (HOD(i, j, i + 1, j) == true) {
                        Koord(i, j, i + 1, j);
                        {
                            if (HOD(x, y, i + 1, j) == false) {
                                flag = true;
                                if (proverka(i+1, j) == true) {
                                    flag = false;
                                }
                            }
                        }
                        Koord(i + 1, j, i, j);
                        if (flag == true)break;
                    }
                    if (HOD(i, j, i - 1, j) == true) {
                        Koord(i, j, i - 1, j);
                        {
                            if (HOD(x, y, i - 1, j) == false) {
                                flag = true;
                                if (proverka(i-1, j) == true) {
                                    flag = false;
                                }
                            }
                        }
                        Koord(i - 1, j, i, j);
                        if (flag == true)break;
                    }
                    if (HOD(i, j, i, j + 1) == true) {
                        Koord(i, j, i, j + 1);
                        {
                            if (HOD(x, y, i, j + 1) == false) {
                                flag = true;
                                if (proverka(i, j+1) == true) {
                                    flag = false;
                                }
                            }
                        }
                        Koord(i, j + 1, i, j);
                        if (flag == true)break;
                    }
                    if (HOD(i, j, i, j - 1) == true) {
                        Koord(i, j, i, j - 1);
                        {
                            if (HOD(x, y, i, j - 1) == false) {
                                flag = true;
                                if (proverka(i, j-1) == true) {
                                    flag = false;
                                }
                            }
                        }
                        Koord(i, j - 1, i, j);
                        if (flag == true)break;
                    }
                }
            

                else if (ar[i][j] == 'K' && chet % 2 == 0)
                {
                    if (HOD(i, j, i + 1, j) == true) {
                        Koord(i, j, i + 1, j);
                        {
                            if (HOD(x, y, i + 1, j) == false) {
                                flag = true;
                                if (proverka(i+1, j) == true) {
                                    flag = false;
                                }
                            }
                        }
                        Koord(i+1, j, i, j);
                        if (flag == true)break;
                    }
                    if (HOD(i, j, i - 1, j) == true) {
                        Koord(i, j, i - 1, j);
                        {
                            if (HOD(x, y, i - 1, j) == false) {
                                flag = true;
                                if (proverka(i-1, j) == true) {
                                    flag = false;
                                }
                            }
                        }
                        Koord(i-1, j, i, j);
                        if (flag == true)break;
                    }
                    if (HOD(i, j, i, j + 1) == true) {
                        Koord(i, j, i, j + 1);
                        {
                            if (HOD(x, y, i, j + 1) == false) {
                                flag = true;
                                if (proverka(i, j+1) == true) {
                                    flag = false;
                                }
                            }
                        }
                        Koord(i, j + 1, i, j);
                        if (flag == true)break;
                    }
                    if (HOD(i, j, i, j - 1) == true) {
                        Koord(i, j, i, j - 1);
                        {
                            if (HOD(x, y, i, j - 1) == false) {
                                flag = true;
                                if (proverka(i, j-1) == true) {
                                    flag = false;
                                }
                            }
                        }
                        Koord(i, j - 1, i, j);
                        if (flag == true)break;
                    }
                }
                
                else if (ar[i][j] >= 'a' && ar[i][j] <= 'z' && chet % 2 != 0)
                {
                    if (HOD(i, j, x, y) == true) {
                        flag = true;
                        if (proverka(a, b) == true) {
                            flag = false;
                        }
                        if (flag == true)break;
                    }
                }
                else if (ar[i][j] >= 'A' && ar[i][j] <= 'Z' && chet % 2 == 0)
                {
                    if (HOD(i, j, x, y) == true) {
                        flag = true;
                        if (proverka(a, b) == true) {
                            flag = false;
                        }
                        if (flag == true)break;
                    }
                }
            }
            if (flag == true)break;
        }
    }
    return flag;
}

//менять местами фигуры при объявлении шага для проверки
void Koord(int x, int y, int x1, int y1)
{
    if (counter % 2 == 0) {
        a = ar[x][y];             // ИЗМЕНЕНИЕ КООРДИНАТ ФИГУРЫ
        b = ar[x1][y1];
        ar[x1][y1] = a;    
        if (x % 2 == y % 2) ar[x][y] = char(219);
        else ar[x][y] = ' ';
    }
    else {
        ar[x1][y1] = a;
        ar[x][y] = b;
    }

    counter++;

}                  

//Проверка есть ли еще атака
bool proverka(int x2, int y2)
{ 
    bool b = false;
    chet++;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            A1 = i;
            A2 = j;
            if (HOD(i, j, x2, y2) == true) {
                chet++;
                b = true;
                break;
            }
        }
        if (b == true)break;
        
    }
    if (b == false)chet++;
    
    return b;
}


int main()
{
    initChess();
	showAr();
    dialog();
}

    