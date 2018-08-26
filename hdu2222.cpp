#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 26;
int tail, head;

struct node{
	node *next[maxn];
	node *fail;
	int count;
	node(){
		fail = NULL;
		count = 0;
		for (int i = 0; i < 26; ++i){
			next[i] = NULL;
		}
	}
} *root,*q[500000];



void insert(char *s){
	node *p = root;
	int i = 0;
	while(s[i] != '\0'){
		if(p -> next[s[i] - 'a'] == NULL)
			p -> next[s[i] - 'a'] = new node();
		p = p -> next[s[i] - 'a'];
		i++;
	}
	p -> count ++;
}

void build_ac(){
	tail = 0, head = 0;
	q[tail++] = root;
	while(head != tail){
		node *p = q[head++];
		node *temp = NULL;
		for (int i = 0; i < 26; ++i){
			if(p -> next[i] != NULL){
				if(p == root)
					p -> next[i]->fail = root;
				else{
					temp = p -> fail;
					while(temp != NULL){
						if(temp -> next[i] != NULL){
							p->next[i]->fail = temp->next[i];
							break;
						}
						temp = temp -> fail;
					}	
					if(temp==NULL)
						p->next[i]->fail = root;
				}
				q[tail++] = p -> next[i];
			}
		}
	}
}


int query(char *str){
	int index,len,result;
	node *p = root;
	result = 0;
	len = strlen(str);
	for (int i = 0; i < len; ++i){
		index = str[i] - 'a';
		while(p->next[index]==NULL && p != root)
			p = p -> fail;
		p = p -> next[index];
		if(p == NULL)
			p = root;
		node *temp = p;
		while(temp != root && temp -> count != -1){
			result += temp -> count;
			temp -> count = -1;
			temp = temp -> fail;
		}
	}
	return result;
}

int main(int argc, char const *argv[]){
	
	int n,num;
	scanf("%d",&n);
	char keyword[55],str[1000100];
	while(n--){
		root = new node();
		scanf("%d",&num);
		for (int i = 0; i < num; ++i){
			scanf("%s",keyword);
			insert(keyword);
		}
		build_ac();
		scanf("%s",str);
		printf("%d\n",query(str));
	}
	return 0;
}