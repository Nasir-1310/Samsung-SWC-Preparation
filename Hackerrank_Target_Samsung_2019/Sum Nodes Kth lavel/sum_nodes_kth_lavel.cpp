#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<cctype>
using namespace std;


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int k;
    cin>>k;
    string s;
    cin>>s;
   int s_len=s.length();
    
    int len=-1;
    int sum=0;
  
    for(int i=0;i<s_len;i++){
        
        int sign=1;
        int val=0;
        
        if(s[i]=='(')
            len++;
        else if(s[i]==')')
            len--;
        else if(isdigit(s[i]) || s[i]=='-'){
            if(s[i]=='-')
            {
                sign=-1;
                i++;
            }
            while(i<s_len && isdigit(s[i])){
                val=val*10+(s[i]-'0');
                i++;
            }
            i--;
            
            if(len==k){
                sum+=val*sign;
            }
            
            
        }
        
    }
    
    cout<<sum<<"\n";
    return 0;
}
