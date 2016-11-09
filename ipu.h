//целочисленный сопроцессор СОК ipu.h
#ifndef IPU_H
#define IPU_H
//система команд сопроцессора
#define INOP 0
#define INEG 1
#define IADD 2
#define ISUB 3
#define IMUL 4
#define IDIV 5
#define ICMP 6
#define IMOV 7
#define ICTD 8
#define ICTS 9
#define ICTC 10
#define ICFC 11
#define ILDN 12
#define IJPE 13
#define IJPL 14
#define IJPG 15
#define IJLE 16
#define IJGE 17
#define IJNE 18
#define IJMP 19
#define IHLT 20
//дополнительные команды
#define IPRC 21
#define IPRN 22
#define INOD 23
#define INOK 24
#define IFAK 25


#define MaxRegs 64
#define MaxDigs 20
int ipu_r[MaxRegs][MaxDigs]; //регистры сопроцессора
int ipu_fn;   //число оснований СОК
int ipu_N;    //целое число для загрузки/выгрузки
int ipu_flag; //регистр текущего состояния сопроцессора
int ipu_ip;   //указатель адреса текущей команды
int ipu_fnd[MaxDigs]; //основания СОК

//элементарная строка программы
#define IPU_PRG struct ipu_prog_str
IPU_PRG {
    int mne;             //код мнемоники
    int op1,op2,op3,op4; //операнды мнемоники
    };

#define MaxAddr 1000
IPU_PRG ipu_prog[MaxAddr]; //память для микропрограммы

//перенастройка сопроцессора
void ipu_reset(int *fnd, int fn, int fn1, int flag, int ip);
//тик исполнения команды
int ipu_clock();
#endif
//ipu.h конец заголовочного файла
