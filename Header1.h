#pragma once
HANDLE hConsole;    // ����
void initChess();   //  ���������� ����� �����
void showAr();      //  ����� �����
void dialog();      //  ������
void inputAr(int x, int y, int x1, int y1); //����
bool hod(int x, int y, int x1, int y1);       // �������� ����
bool March(int x, int y, int a, int b);
bool HOD(int x, int y, int x1, int y1);
bool PAT(int k1, int k2);     // �������� �� ���
void Koord(int x, int y, int x1, int y1); //��������� ���������
bool proverka(int x2, int y2);    //�������� ���� �� ��� �����