//������������� ����������� ��� ipu.h
#ifndef IPU_H
#define IPU_H
//������� ������ ������������
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
//�������������� �������
#define IPRC 21
#define IPRN 22
#define INOD 23
#define INOK 24
#define IFAK 25


#define MaxRegs 64
#define MaxDigs 20
int ipu_r[MaxRegs][MaxDigs]; //�������� ������������
int ipu_fn;   //����� ��������� ���
int ipu_N;    //����� ����� ��� ��������/��������
int ipu_flag; //������� �������� ��������� ������������
int ipu_ip;   //��������� ������ ������� �������
int ipu_fnd[MaxDigs]; //��������� ���

//������������ ������ ���������
#define IPU_PRG struct ipu_prog_str
IPU_PRG {
    int mne;             //��� ���������
    int op1,op2,op3,op4; //�������� ���������
    };

#define MaxAddr 1000
IPU_PRG ipu_prog[MaxAddr]; //������ ��� ��������������

//������������� ������������
void ipu_reset(int *fnd, int fn, int fn1, int flag, int ip);
//��� ���������� �������
int ipu_clock();
#endif
//ipu.h ����� ������������� �����
