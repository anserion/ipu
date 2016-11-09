//������ ������ � ������� � ������� ���������� ������� soklib.h
#ifndef SOKLIB_H
#define SOKLIB_H
//������������ ���������� ��������
#define MaxDigits 20

//���������� ���������, �������� ���
int OrthoDigits,DigitsNum,PM;
//���������, ���� �������, �����
int Foundation[MaxDigits],M[MaxDigits],Basis[MaxDigits];
//����� ���p��������� � p������� �y�� � �������
int Zero[MaxDigits],One[MaxDigits];

//������������� �������� ��������
void soklib_init();

//��������������� ���������, ���������� ����� �� ����� � �������
void ConvertToChislo(int *A, int N);
int ConvertFromChislo(int *A);

//---------------------------------------------------------------------------
//���������� �������, ����� ������� (�������� � ����������� �����������)
//��������� � ����� ������ ����� ����������� ��������� ���
void MCalculate(); //� �������������� ������� ������
void BMCalculate(); //� �������������� ������������� �������
//��������� ���� ������������� �����
int ARang(int *A);
//��������� �� ��� � ���������� ������� ���������
int GrConvertToDec(int *A, int N); //������ ���������
int ConvertToDecOrtho(int *A); //�� ������ ������������� �������
int ConvertToDecEuler(int *a); //��� ������ ������� ������
//�������� ���� ����� � ��� (���������� �� ������)
void DigControl(int *A);
//��������� ����������� �����
void Mov(int *dst, int *src);
//��������
void Add(int *a, int *b, int *c);
//���������
void Sub(int *a, int *b, int *c);
//���������
void Mul(int *a, int *b, int *c);
//��������� ����� �� ���������������
void Negative(int *a);
//���������� 2 ����� � ��� �� ��������� (���� �����, �� ������������ 1)
int CompareB(int *a, int *b);
//���������� 2 ����� � ��� � ������� ������
//����������:
//           -1 ���� a<b
//    	      0 ���� a=b
//            1 ���� a>b
int CompareZ(int *a, int *b);
//������ �������������� �� ���������� ������� � ��� (���. ��� ��������� �����)
void GrConvertToSok(int *A, int x);
//�������������� �� ���������� ������� � ���
void ConvertToSok(int *N, int *A);
//�p���p�������� ����� A �� ��� � ����������� Foundation
//� ����� X=A ��� � ����������� NewFoundation
void ConvertToFoundation(int *A, int *NewFoundation, int NewDigNum, int *X);
//����� ������ ������� ������� ����������������� ���������
//������ ���� ������� ������������ ������
void DivP(int *a, int *b, int *q);
//����� ��y��� �������, ���������� �� ��������
void DivA(int *a, int *b, int *q, int *r);
//H������ H�� ��y� �����
void NOD(int *n, int *m, int *x);
//H������ H�� ��y� �����
void NOK(int *n, int *m, int *x);
//���������� �����p���� �����
void Faktor(int *n, int *x);
#endif
//soklib.h ����� ������������� �����
