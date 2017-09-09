#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/***プロトタイプ宣言***/
int num(int num,int mask,int cnt);
void bitprint(int cnt);
void main(){
        //int outputs =295040,i;
        char results[128];
        int outputs, i;
        int mask = 0x7FFFFFFF;
/*リード・マラー標準形に変換したい真理値表の出力部を
 * 下部ほど重みがあると捉えて10進数で入力してください*/
        printf("\x1b[36minput the results of truth table you would like to make it simply with EX-ORing known as an Algebraic normal form.\x1b[39m\n");
/*キーボードから値を入力して、数値に変換する処理*/
        outputs=atoi(gets(results));
/*入力された数値を記憶するのに必要なビット数を計算は
 * log2(数値)だが、底がネイピア数か10か不明なので底の変換を用いた
 *
 * 底の変換：log X(Y)=log Z(X)/log(Y)*/
        double length = (double)outputs;
        length = log(length)/log(2.0);
/*ビットマスクを必要な桁数に設定する*/
        for(i=0;i<30-(int)length+0.9;i++)
        mask>>=1;
        //printf("debug %.5f\n",length);
        //printf("debug hex:%X\n",mask);

        shift(outputs,mask,0);
}

int shift(int num,int mask,int cnt){
        if(num&1){
                puts("Zhegalkin poly:");
                bitprint(cnt);
        }
        cnt++;

/*Zhegalkin Polynomialを探す*/
        num = num ^ num >> 1;
        num = num & mask;
        mask = mask >> 1;
/**/
        //printf("out = %d\n",num);
/*0になるまで再帰する*/
        if(num>0)
                shift(num,mask,cnt);
        return num;
}

void bitprint(int cnt){
/*2進数に変換して表示*/
        unsigned int bit = (1 << (sizeof(int)) * 8 - 1);
        for(;bit!=0;bit>>=1){
        if(cnt&bit)
                putchar('1');
        else
                putchar('0');
        }
        puts("");
}