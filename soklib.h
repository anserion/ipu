//модуль работы с числами в системе остаточных классов soklib.h
#ifndef SOKLIB_H
#define SOKLIB_H
//максимальное количество остатков
#define MaxDigits 20

//количество оснований, диапазон СОК
int OrthoDigits,DigitsNum,PM;
//основания, веса базисов, базис
int Foundation[MaxDigits],M[MaxDigits],Basis[MaxDigits];
//часто встpечающиеся в pасчетах нyль и единица
int Zero[MaxDigits],One[MaxDigits];

//инициализация основных констант
void soklib_init();

//вспомогательные процедуры, разложения числа на цифры и обратно
void ConvertToChislo(int *A, int N);
int ConvertFromChislo(int *A);

//---------------------------------------------------------------------------
//вычисление базисов, весов базисов (работает с глобальными структурами)
//запустить в самом начале после определения оснований СОК
void MCalculate(); //с использованием функции Эйлера
void BMCalculate(); //с использованием ортогональных базисов
//Вычисляет ранг произвольного числа
int ARang(int *A);
//Переводит из СОК в десятичную систему счисления
int GrConvertToDec(int *A, int N); //прямым перебором
int ConvertToDecOrtho(int *A); //по методу ортогональных базисов
int ConvertToDecEuler(int *a); //при помощи функции Эйлера
//проверка цифр числа в СОК (приведение по модулю)
void DigControl(int *A);
//процедура копирования числа
void Mov(int *dst, int *src);
//Сложение
void Add(int *a, int *b, int *c);
//Вычитание
void Sub(int *a, int *b, int *c);
//Умножение
void Mul(int *a, int *b, int *c);
//изменение знака на противоположный
void Negative(int *a);
//Сравнивает 2 числа в СОК на равенство (если равны, то возвращается 1)
int CompareB(int *a, int *b);
//Сравнивает 2 числа в СОК в обычном смысле
//Возвращает:
//           -1 если a<b
//    	      0 если a=b
//            1 если a>b
int CompareZ(int *a, int *b);
//Грубое преобразование из десятичной системы в СОК (рац. для маленьких чисел)
void GrConvertToSok(int *A, int x);
//Преобразование из десятичной системы в СОК
void ConvertToSok(int *N, int *A);
//Пpеобpазование числа A из СОК с основаниями Foundation
//в число X=A СОК с основаниями NewFoundation
void ConvertToFoundation(int *A, int *NewFoundation, int NewDigNum, int *X);
//общий случай деления методом последовательного вычитания
//только если деление производится нацело
void DivP(int *a, int *b, int *q);
//общий слyчай деления, основанный на сложении
void DivA(int *a, int *b, int *q, int *r);
//Hаходит HОД двyх чисел
void NOD(int *n, int *m, int *x);
//Hаходит HОК двyх чисел
void NOK(int *n, int *m, int *x);
//Вычисление фактоpиала числа
void Faktor(int *n, int *x);
#endif
//soklib.h конец заголовочного файла
