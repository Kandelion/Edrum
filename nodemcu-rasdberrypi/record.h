#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>


typedef struct _note
{
    // ���� �ð����κ��� ���� ��Ʈ�� �ð� (milli�� ����)
    long long int msec;
    // ������ �Ǳ��� ����
    int drum;
    // �Ǳ� ģ ����
    int power;
} note;

bool makefile(char*, char *);
bool fexists(const char*);
