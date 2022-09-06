#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int period_length(int n) {
   int a_0, a, b, c, b_0, c_0, result=0;
   a_0=sqrt(n*1.0);
   b=b_0=a_0;
   c=c_0=n-a_0*a_0;
   do {
      a=(a_0+b)/c;
      b=a*c-b;
      c=(n-b*b)/c;
      result++;
   } while ((b!=b_0)||(c!=c_0));
   return result;
}

int nodiv(int n) {
   int i, j, result=1;
   //fprintf(stderr, "%ld = ", n);
   for (i=2; i*i<=n; i++)
      if ((n%i)==0) {
         //fprintf(stderr, "%ld^", i);
         j=1;
         while ((n%i)==0) {
            j++;
            n=n/i;
         }
         //fprintf(stderr, " %ld * ", j-1);
         result=result*j;
      }
   //fprintf(stderr, "\n");
   if (n!=1) return result<<1;
   return result;
}

int estim(int n) {
   int i, result=0, j=sqrt(n*1.0);
   for (i=1; i<j; i++)
      result+=nodiv(n-i*i);
   return result;
}

         
int main() {
   int i, j, i2, imax;
   int l, lmax;
   double r, r0=0.0, s, lavg;
   int beginning_number=9332, end_number=10001;
   printf("%d %d\n", beginning_number, end_number);
   for (i=beginning_number*beginning_number,
           i2=beginning_number, imax=i+(i2<<1)+1;
        i2<end_number; i=imax, i2++, imax+=(i2<<1)+1) {
      lavg=0.0;
      lmax=0;
      for (j=i+1; j<imax; j++) {
         l=period_length(j);
         if (l>lmax) lmax=l;
         s=sqrt(j*1.0);
         r=l/s;
         lavg+=l*1.0;
         if (r>r0) {
            r0=r;
            fprintf(stderr,
                    "n=%d l(n)=%d sqrt(n)=%.3f r=%.3f 2nd estimate=%.1f\n",
                    j, l, s, r, sqrt(j*1.0)*log(j*1.0));
         }
      }
      printf("Square root= %d Maximum= %d Average= %.3f\n",
             i2, lmax, lavg/((imax-i-1)*1.0));
   }
   return 0;
}
