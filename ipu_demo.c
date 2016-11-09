#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ipu.h"

main(int argc, char **argv)
{FILE *fd; char str[255];
int mne,op1,op2,op3,op4,addr,i,fn,fn1,fnd[MaxDigs];

if (argc<2) {
    printf("не указано имя файла с программой для сопроцессора\n");
    return 1;
    }
fd=fopen("ipu.cfg","r");
if(fd==NULL) {
    printf("ошибка открытия конфигурационного файла\n");
    return 3;
    }
    
fscanf(fd,"%s",str); fn=atoi(str);
fscanf(fd,"%s",str); fn1=atoi(str);
for(i=0;i<fn;i++) {fscanf(fd,"%s",str); fnd[i]=atoi(str);}
fclose(fd);

printf("число оснований: %d, из них для конвертации %d\n",fn,fn1);
printf("основания: "); for(i=0;i<fn;i++) printf("%d ",fnd[i]);
printf("\n");

ipu_reset(fnd, fn, fn1, 0, 0);
printf("сопроцессор настроен\n");

fd=fopen(argv[1],"r");
if(fd==NULL) {
    printf("ошибка открытия файла\n");
    return 4;
    }

while (feof(fd)==0) {
 fscanf(fd,"%s",str);
 if ((str[0]!=';')&&(str[0]!='#')) {
    addr=atoi(str); op1=0; op2=0; op3=0; op4=0;
    fscanf(fd,"%s",str);
    printf("%d %s ",addr, str);
    if (strcmp(str,"INOP")==0) mne=INOP;
    if (strcmp(str,"IADD")==0) mne=IADD;
    if (strcmp(str,"ISUB")==0) mne=ISUB;
    if (strcmp(str,"IMUL")==0) mne=IMUL;
    if (strcmp(str,"IDIV")==0) mne=IDIV;
    if (strcmp(str,"ICMP")==0) mne=ICMP;
    if (strcmp(str,"INOD")==0) mne=INOD;
    if (strcmp(str,"INOK")==0) mne=INOK;
    if (strcmp(str,"IFAK")==0) mne=IFAK;
    if (strcmp(str,"IMOV")==0) mne=IMOV;
    if (strcmp(str,"ICTD")==0) mne=ICTD;
    if (strcmp(str,"ICTS")==0) mne=ICTS;
    if (strcmp(str,"ICTC")==0) mne=ICTC;
    if (strcmp(str,"ICFC")==0) mne=ICFC;
    if (strcmp(str,"ILDN")==0) mne=ILDN;
    if (strcmp(str,"IJPE")==0) mne=IJPE;
    if (strcmp(str,"IJPL")==0) mne=IJPL;
    if (strcmp(str,"IJPG")==0) mne=IJPG;
    if (strcmp(str,"IJLE")==0) mne=IJLE;
    if (strcmp(str,"IJGE")==0) mne=IJGE;
    if (strcmp(str,"IJNE")==0) mne=IJNE;
    if (strcmp(str,"IJMP")==0) mne=IJMP;
    if (strcmp(str,"IHLT")==0) mne=IHLT;
    if (strcmp(str,"IPRC")==0) mne=IPRC;
    if (strcmp(str,"IPRN")==0) mne=IPRN;

    switch (mne) {
    case INOP: break;
    case INEG:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
    	break;
    case IADD:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	fscanf(fd,"%s",str); op3=atoi(str);
	break;
    case ISUB:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	fscanf(fd,"%s",str); op3=atoi(str);
	break;
    case IMUL:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	fscanf(fd,"%s",str); op3=atoi(str);
	break;
    case IDIV:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	fscanf(fd,"%s",str); op3=atoi(str);
	fscanf(fd,"%s",str); op4=atoi(str);
	break;
    case ICMP:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	break;
    case INOD:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	fscanf(fd,"%s",str); op3=atoi(str);
	break;
    case INOK:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	fscanf(fd,"%s",str); op3=atoi(str);
	break;
    case IFAK:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	break;
    case IMOV:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	break;
    case ICTD:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	break;
    case ICTS:
	fscanf(fd,"%s",str); op1=atoi(str);
	fscanf(fd,"%s",str); op2=atoi(str);
	break;
    case ICTC:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case ICFC:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case ILDN:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case IJPE:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case IJPL:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case IJPG:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case IJLE:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case IJGE:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case IJNE:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case IJMP:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case IHLT:
	break;
    case IPRC:
	fscanf(fd,"%s",str); op1=atoi(str);
	break;
    case IPRN:
	break;
    }
 printf("(%d) %d %d %d %d\n",mne,op1,op2,op3,op4);
 ipu_prog[addr].mne=mne;
 ipu_prog[addr].op1=op1;
 ipu_prog[addr].op2=op2;
 ipu_prog[addr].op3=op3;
 ipu_prog[addr].op4=op4;
 }
}
fclose(fd);
printf("программа загружена\n");


while (ipu_clock()==0);

return 0;
}
