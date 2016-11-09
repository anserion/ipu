#include <stdio.h>
#include "soklib.h"
#include "ipu.h"

void ipu_reset(int *fnd, int fn, int fn1, int flag, int ip)
{int i;
ipu_fn=fn; ipu_flag=flag; ipu_ip=ip; ipu_N=0; 
Mov(ipu_fnd,Zero); for(i=0;i<ipu_fn;i++) ipu_fnd[i]=fnd[i];

DigitsNum=ipu_fn; OrthoDigits=fn1;
Mov(Foundation,ipu_fnd);
soklib_init();
BMCalculate();

for(i=0;i<MaxRegs;i++) Mov(ipu_r[i],Zero);
for(i=0;i<MaxAddr;i++) {
    ipu_prog[i].mne=0;
    ipu_prog[i].op1=0;
    ipu_prog[i].op2=0;
    ipu_prog[i].op3=0;
    ipu_prog[i].op4=0;
    }
ipu_prog[MaxAddr-1].mne=IHLT;
}

int ipu_clock()
{int mne,op1,op2,op3,op4,i;
int h[MaxDigs];
mne=ipu_prog[ipu_ip].mne;
op1=ipu_prog[ipu_ip].op1;
op2=ipu_prog[ipu_ip].op2;
op3=ipu_prog[ipu_ip].op3;
op4=ipu_prog[ipu_ip].op4;
switch (mne) {
case INOP: break;
case INEG:
	Mov(ipu_r[op2],ipu_r[op1]);
	Negative(ipu_r[op2]);
    	break;
case IADD:
	Add(ipu_r[op1],ipu_r[op2],ipu_r[op3]);
	break;
case ISUB:
	Sub(ipu_r[op1],ipu_r[op2],ipu_r[op3]);
	break;
case IMUL:
	Mul(ipu_r[op1],ipu_r[op2],ipu_r[op3]);
	break;
case IDIV:
	DivA(ipu_r[op1],ipu_r[op2],ipu_r[op3],ipu_r[op4]);
	break;
case ICMP:
	ipu_flag=CompareZ(ipu_r[op1],ipu_r[op2]);
	break;
case INOD:
	NOD(ipu_r[op1],ipu_r[op2],ipu_r[op3]);
	break;
case INOK:
	NOK(ipu_r[op1],ipu_r[op2],ipu_r[op3]);
	break;
case IFAK:
	Faktor(ipu_r[op1],ipu_r[op2]);
	break;
case IMOV:
	Mov(ipu_r[op1],ipu_r[op2]);
	break;
case ICTD:
	ipu_N=ConvertToDecOrtho(ipu_r[op1]);
	ConvertToChislo(ipu_r[op2],ipu_N);
	break;
case ICTS:
	ConvertToSok(ipu_r[op1],ipu_r[op2]);
	break;
case ICTC:
	ConvertToChislo(ipu_r[op1],ipu_N);
	break;
case ICFC:
	ipu_N=ConvertFromChislo(ipu_r[op1]);
	break;
case ILDN:
	ipu_N=op1;
	break;
case IJPE:
	if (ipu_flag==0) ipu_ip=op1-1;
	break;
case IJPL:
	if (ipu_flag<0) ipu_ip=op1-1;
	break;
case IJPG:
	if (ipu_flag>0) ipu_ip=op1-1;
	break;
case IJLE:
	if (ipu_flag<=0) ipu_ip=op1-1;
	break;
case IJGE:
	if (ipu_flag>=0) ipu_ip=op1-1;
	break;
case IJNE:
	if (ipu_flag!=0) ipu_ip=op1-1;
	break;
case IJMP:
	ipu_ip=op1-1;
	break;
case IHLT:
	return 1;
	break;
case IPRC:
	printf("reg[%d]=",op1);
	for(i=0;i<ipu_fn;i++) printf("%d ",ipu_r[op1][i]);
	printf("\n");
	break;
case IPRN:
	printf("N=%d\n",ipu_N);
	break;
}
ipu_ip++;
return 0;
}
