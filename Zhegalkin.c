#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/***�v���g�^�C�v�錾***/
int num(int num,int mask,int cnt);
void bitprint(int cnt);
void main(){
        //int outputs =295040,i;
        char results[128];
        int outputs, i;
        int mask = 0x7FFFFFFF;
/*���[�h�E�}���[�W���`�ɕϊ��������^���l�\�̏o�͕���
 * �����قǏd�݂�����Ƒ�����10�i���œ��͂��Ă�������*/
        printf("\x1b[36minput the results of truth table you would like to make it simply with EX-ORing known as an Algebraic normal form.\x1b[39m\n");
/*�L�[�{�[�h����l����͂��āA���l�ɕϊ����鏈��*/
        outputs=atoi(gets(results));
/*���͂��ꂽ���l���L������̂ɕK�v�ȃr�b�g�����v�Z��
 * log2(���l)�����A�ꂪ�l�C�s�A����10���s���Ȃ̂Œ�̕ϊ���p����
 *
 * ��̕ϊ��Flog X(Y)=log Z(X)/log(Y)*/
        double length = (double)outputs;
        length = log(length)/log(2.0);
/*�r�b�g�}�X�N��K�v�Ȍ����ɐݒ肷��*/
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

/*Zhegalkin Polynomial��T��*/
        num = num ^ num >> 1;
        num = num & mask;
        mask = mask >> 1;
/**/
        //printf("out = %d\n",num);
/*0�ɂȂ�܂ōċA����*/
        if(num>0)
                shift(num,mask,cnt);
        return num;
}

void bitprint(int cnt){
/*2�i���ɕϊ����ĕ\��*/
        unsigned int bit = (1 << (sizeof(int)) * 8 - 1);
        for(;bit!=0;bit>>=1){
        if(cnt&bit)
                putchar('1');
        else
                putchar('0');
        }
        puts("");
}