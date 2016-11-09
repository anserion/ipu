#include "soklib.h"

void soklib_init()
{int i;
for(i=0;i<MaxDigits;i++) {
    One[i]=1;
    Zero[i]=0;
    }
}

void ConvertToChislo(int *A, int N)
{int i; for(i=0;i<MaxDigits;i++) {A[i]=N%10; N=N/10;} }

int ConvertFromChislo(int *A)
{int i,S=0;
 for(i=MaxDigits-1;i>=0;i--) S=10*S+A[i];
return S;
}

void MCalculate()
{int i,j,k;
int A[MaxDigits],B[MaxDigits],P[MaxDigits],PP[MaxDigits];

for(i=0;i<DigitsNum;i++) {
    Mov(PP,One);
    for(k=0;k<i;k++) {
      for(j=0;j<DigitsNum;j++) P[j]=(Foundation[k]%Foundation[j]);
      Mul(PP,P,PP);
      }
    for(k=i+1;k<DigitsNum;k++) {
      for(j=0;j<DigitsNum;j++) P[j]=(Foundation[k]%Foundation[j]);
      Mul(PP,P,PP);
      }
    Mov(B,Zero); B[i]=1;
    k=0;
    do {
        Sub(B,PP,B);
        k++;
    } while (CompareB(B,Zero)==0);
    M[i]=k;
 }
}

void BMCalculate()
{int i,PM1,PM2;
PM=1;
for(i=0;i<OrthoDigits;i++) PM=PM*Foundation[i];
for(i=0;i<OrthoDigits;i++) {
  PM1=PM/Foundation[i]; PM2=PM1;
  while ((PM1%Foundation[i])!=1) PM1=PM1+PM2;
  Basis[i]=PM1;
  M[i]=Basis[i]*Foundation[i] / PM;
  }
}

int ARang(int *A)
{int i; double R=0;
for(i=0;i<DigitsNum;i++) R=R+(1.0*A[i]*M[i])/Foundation[i];
return ((int)R);
}

int GrConvertToDec(int *A, int N)
{int i; int B[MaxDigits];
for(i=0;i<=N;i++) {
    GrConvertToSok(B,i);
    if (CompareB(A,B)) return i;
    }
}

int ConvertToDecEuler(int *a)
{int i,j,b,c,d,f,f1,x,v; int P[MaxDigits],A[MaxDigits];
Mov(P,Foundation); Mov(A,a);
f1=P[1];
for(i=1;i<DigitsNum;i++) {
    if (P[0]<P[i]) f=P[i]-1;
    f1=f1*(P[i]-1);
    if (P[0]>P[i]) {
	b=P[0]; P[0]=P[i]; P[i]=b;
        c=A[0]; A[0]=A[i]; A[i]=c;
        f=f1;
        }

    d=1;
    for(j=1;j<f;j++) d=d*(abs(P[i]-P[0]))% P[i];

    v=(A[0]-A[i])% P[i];
    if (v<0) v=v+P[i];
    v=d*v%P[i];
    if (v<0) v=v+P[i];
    x=v*P[0]+A[0];
    P[0]=P[0]*P[i];
    A[0]=x;
 }
return x;
}

int ConvertToDecOrtho(int *A)
{int i,PM1=0;
for(i=0;i<OrthoDigits;i++) {
    PM1=PM1+A[i]*Basis[i];
    PM1=PM1%PM; if (PM1<0) PM1=PM1+PM;
    }
return PM1;
}

void DigControl(int *A)
{int i;
for(i=0;i<DigitsNum;i++) {
  if ((A[i]<0)||(A[i]>=Foundation[i])) A[i]=A[i]%Foundation[i];
  if (A[i]<0) A[i]=A[i]+Foundation[i];
  }
}

void Mov(int *dst, int *src)
{int i; for(i=0;i<MaxDigits;i++) dst[i]=src[i]; }

void Add(int *a, int *b, int *c)
{int i; for(i=0;i<DigitsNum;i++) c[i]=a[i]+b[i];
DigControl(c);
}

void Sub(int *a, int *b, int *c)
{int i; for(i=0;i<DigitsNum;i++) c[i]=a[i]-b[i];
DigControl(c);
}

void Mul(int *a, int *b, int *c)
{int i; for(i=0;i<DigitsNum;i++) c[i]=a[i]*b[i];
DigControl(c);
}

void Negative(int *a)
{int i; for(i=0;i<DigitsNum;i++) a[i]=Foundation[i]-a[i];
DigControl(a);
}

int CompareB(int *a, int *b)
{int i; for(i=0;i<DigitsNum;i++) if (a[i]!=b[i]) return 0;
return 1;
}

int CompareZ(int *a, int *b)
{int RA,RB,RC,RAB,i,s,h; int c[MaxDigits];
if (CompareB(a,b)==0) {
     RA=ARang(a); RB=ARang(b);
     Sub(a,b,c); RC=ARang(c);
     s=0; for(i=0;i<DigitsNum;i++) if (a[i]<b[i]) s=s-M[i];
     RAB=RA-RB-s;
     if (RC==RAB) h=1;
     if (RC!=RAB) h= -1;
  } else h=0;
return h;
}

void GrConvertToSok(int *A, int x)
{int i; for(i=0;i<DigitsNum;i++) A[i]=x%Foundation[i];
DigControl(A);
}

void ConvertToSok(int *N, int *A)
{int i,j;
int x[MaxDigits][MaxDigits], b[MaxDigits][MaxDigits];
int ten[MaxDigits],NC[MaxDigits];
 GrConvertToSok(ten,10);
 GrConvertToSok(b[0],1);
 Mov(NC,N);
 for(i=1;i<MaxDigits;i++) Mul(b[i-1],ten,b[i]);
 for(i=0;i<MaxDigits;i++) GrConvertToSok(x[i],NC[i]);
 for(j=0;j<DigitsNum;j++) {
    A[j]=0; for(i=0;i<MaxDigits;i++) A[j]=A[j]+x[i][j]*b[i][j];
    }
DigControl(A);
}

void ConvertToFoundation(int *a, int *NewFoundation, int NewDigNum, int *X)
{int F[MaxDigits],ANew[MaxDigits],ZeroRel[MaxDigits],Koef[MaxDigits],A[MaxDigits];
int k1[MaxDigits],k2[MaxDigits],
     A1[MaxDigits],B1[MaxDigits],
     B2[MaxDigits],A2[MaxDigits],A3[MaxDigits];
int DN;
Mov(F,Foundation); DN=DigitsNum; Mov(A,a);
Mov(X,Zero); Mov(ANew,Zero); Mov(ZeroRel,Zero);

do {
   Mov(k2,Zero); Mov(k1,One);
   Mov(A3,Zero); Mov(A2,One);
   Mov(B2,Zero); Mov(B1,One);
   Sub(A,ZeroRel,A1);
   while (CompareZ(B1,A1)<=0) {
         Mov(B2,B1); Add(B1,B1,B1);
         Mov(k2,k1); Add(k1,k1,k1);
         Mov(Foundation,NewFoundation); DigitsNum=NewDigNum;
         Mov(A3,A2); Add(A2,A2,A2);
         Mov(Foundation,F); DigitsNum=DN;
        }
   Add(ZeroRel,B2,ZeroRel);
   Mov(Koef,k2);
   Mov(Foundation,NewFoundation); DigitsNum=NewDigNum;
   Add(ANew,A3,ANew);
   Mov(Foundation,F); DigitsNum=DN;
} while (CompareB(Koef,Zero)==0);
Mov(X,ANew);
}

void DivP(int *a, int *b, int *q)
{int A[MaxDigits], B[MaxDigits];
Mov(A,a); Mov(B,b); Mov(q,Zero);
while (CompareB(A,Zero)==0) {
    Sub(A,B,A);
    Add(q,One,q);
    }
}

void DivA(int *a, int *b, int *q, int *r)
{int ZeroRel[MaxDigits],Koef[MaxDigits], Q[MaxDigits], R[MaxDigits];
int k1[MaxDigits],k2[MaxDigits],A1[MaxDigits],B1[MaxDigits],B2[MaxDigits];
Mov(Q,Zero); Mov(R,Zero); Mov(ZeroRel,Zero);
do {
   Mov(k2,Zero); Mov(k1,One);
   Mov(B2,Zero); Mov(B1,b);
   Sub(a,ZeroRel,A1);
   while (CompareZ(B1,A1)<=0) {
      Mov(B2,B1); Add(B1,B1,B1);
      Mov(k2,k1); Add(k1,k1,k1);
      }
   Add(ZeroRel,B2,ZeroRel);
   Mov(Koef,k2);

   Add(Q,Koef,Q);
} while (CompareB(Koef,Zero)==0);
Sub(a,ZeroRel,R);
Mov(q,Q); Mov(r,R);
}

void NOD(int *n, int *m, int *x)
{int Q[MaxDigits], L[MaxDigits], N[MaxDigits], M[MaxDigits];
Mov(N,n); Mov(M,m);
do {
   Mov(L,M);
   DivA(N,M,Q,M);
   Mov(N,L);
} while (CompareB(M,Zero)==0);
Mov(x,N);
}

void NOK(int *n, int *m, int *x)
{int h1[MaxDigits], h2[MaxDigits];
     Mul(n,m,h1);
     NOD(n,m,h2);
     DivA(h1,h2,x,h1);
}

void Faktor(int *n, int *x)
{int N[MaxDigits];
Mov(x,One); Mov(N,n);
while (CompareB(N,Zero)==0) {
    Mul(x,N,x);
    Sub(N,One,N);
    }
}
