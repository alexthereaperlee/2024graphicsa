#include <windows.h>
#include <stdio.h>
int main()
{
    PlaySound("c:/mykbeat.wav", NULL, SND_ASYNC);
    printf("請輸入一個整數: ");
    int n;
    scanf("%d", &n);
}
