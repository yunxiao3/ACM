#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=800005;

int a[maxn][26];
int b[maxn];
char str[1000];
int size = 0;
int ans = 0;

void init(){
    size = 0;
    ans = 0;
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
}
void insert(){
    int len = strlen(str);
    int root = 0;
    for (int i = 0; i < len; ++i){
        int index = str[i] - 'a';
        if(!a[root][index])
            a[root][index] = ++size;
        root = a[root][index];
        b[root]++;
    }   
}

void check(){
    int len = strlen(str);
    int root = 0;
    for (int i = 0; i < len; ++i){
        int index = str[i] - 'a';
        if(!a[root][index])
            break;
        root = a[root][index];
        if(b[root])
            ans++, b[root]--;
    }   
}

int main(int argc, char const *argv[]){
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; ++i){
        scanf("%s",str);
        insert();
    }
    for (int i = 0; i < n; ++i){
         scanf("%s",str);
         check();
    }
    printf("%d\n",ans);
    return 0;
}