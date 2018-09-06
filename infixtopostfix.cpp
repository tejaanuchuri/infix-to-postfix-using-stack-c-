#include<bits/stdc++.h>
using namespace std;
int operand(char ch){
    return ((ch>='a' && ch<='z') || (ch>='A'&& ch<='Z'));	
}
int precedence(char ch){
	if(ch=='^')return 3;
	else if(ch =='*' || ch =='/' )return 2;
	else if(ch =='+' || ch == '-')return 1;
	return 0;
}
int infix_to_postfix(char *s){
	stack <char> st;
	st.push('N');
	int i,k;
	k=-1;
	string ans;
	for(i=0;s[i]!='\0';i++){
		if(operand(s[i])){
	      ans+=s[i];             // if it is a operand not push to stack
		}
	    else if(s[i]=='('){
	    	st.push('(');
		}
		else if(s[i]==')'){
			while(st.top()!='N' && st.top()!='('){
			     char ch=st.top();
			     st.pop();
				 ans+=ch;	
			}
			if(st.top()=='('){
				char c=st.top();
				st.pop();
			}
		}else{
		    while(st.top()!='N' && precedence(s[i])<=precedence(st.top())){
		    	char ch=st.top();
		    	st.pop();
				ans+=ch;
			}
			st.push(s[i]);
		}
	}
	while(st.top()!='N'){
		char ch=st.top();
		st.pop();
		ans+=ch;
	}
	cout<<ans;
}
int main(){
    char *s=(char*)malloc(sizeof(char)*100000);
	scanf("%[^\n]s",s);
	infix_to_postfix(s); 
	return 0;
}
