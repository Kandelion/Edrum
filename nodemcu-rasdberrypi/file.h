#include <iostream>
#include <fstream>


typedef struct _note
{
    // ���� �ð����κ��� ���� ��Ʈ�� �ð� (milli�� ����)
    long long int msec;
    // ������ �Ǳ��� ����
    int drum;
    // �Ǳ� ģ ����
    int power;
} note;

bool makefile(note);
bool fexists(const char*);
