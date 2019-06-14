#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double get_time (){
  struct timeval tv;/*struct timeval {
		      long tv_sec;//指定する時間の1秒以上の部分（秒単位）
		      long tv_usec;//指定する時間の1秒未満の部分（マイクロ秒単位）
		      };*/
  gettimeofday(&tv, NULL);/*時刻を取得する*/
  return tv.tv_sec + tv.tv_usec * 1e-6;
}/*現在の時刻を求める関数*/


int main (int argc, char** argv){
  
  if (argc != 2) {
    printf("usage: %s N\n", argv[0]);
    return -1;
  }/*エラー処理*/
  
  int n = atoi (argv[1]);/*文字列を数字に直す*/
  double* a = (double*) malloc (n * n * sizeof(double)); // Matrix A
  double* b = (double*) malloc (n * n * sizeof(double)); // Matrix B
  double* c = (double*) malloc (n * n * sizeof(double)); // Matrix C
  // Initialize the matrices to some values.
  int i, j;
  int  k;
  
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      a[i * n + j] = i * n + j; // A[i][j]
      b[i * n + j] = j * n + i; // B[i][j]
      c[i * n + j] = 0; // C[i][j]
    }
  }
  
  double begin = get_time();
  /**************************************/
  /* Write code to calculate C = A * B. */
 


  printf ("A = \t");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf ("%d\t",(int)a[i * n + j]); // A[i][j]
    }
    printf ("\n\t");
  }/*行列Aの出力*/

  printf ("\n\n");

  printf ("B = \t");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf ("%d\t",(int)b[i * n + j]); // B[i][j]
    }
    printf ("\n\t");
  }/*行列Bの出力*/

  printf ("\n\n");

  for (i = 0; i < n; i++) {
    for ( k = 0; k < n; k++) {
      for (j = 0; j < n; j++) {
	c[i * n + k] += a[i * n + j] * b [j * n + k];
      }
    }
  }/*行列Cの計算*/
    
  printf ("AB = \t");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf ("%d\t",(int)c[i * n + j]); // C[i][j]
    }
    printf ("\n\t");
  }/*行列Cの出力*/

  printf ("\n\n");
  
 /**************************************/
  
  double end = get_time();
  printf("time: %.6lf sec\n", end - begin);
  // Print C for debugging. Comment out the print before measuring the execution time.
  double sum = 0;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      sum += c[i * n + j];
      // printf("c[%d][%d]=%lf\n", i, j, c[i * n + j]);
    }
  }
  // Print out the sum of all values in C.
  // This should be 450 for N=3, 3680 for N=4, and 18250 for N=5.
  printf("sum: %.6lf\n", sum);
  free(a);
  free(b);
  free(c);
  return 0;
}
