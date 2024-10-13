# include <iostream>
# include <string>
# include <stack>

using namespace std ; 

void reverse(string &s ){
    int n = s.size();
    int start = 0 ;
    int end = n - 1 ;
    
    while(start <= end ){
        if(s[start] == '('){
            s[start] = ')';
        }
        if(s[start] == ')'){
            s[start] = '(';
        }
        if(s[end] == '('){
            s[end] = ')';
        }if(s[end] == ')'){
            s[end] = '(';
        }

        swap(s[start] , s[end]);
        start++;
        end--;

    }

}

int priority( char c ){
    if(c == '^')return 3 ; 
    else if(c == '*' || c == '/')return 2 ; 
    else if(c == '+' || c == '-')return 1 ; 
    return -1 ; 
    
}

void infixtoprefix(string s ){

    reverse(s) ; 
    int i ;
    stack<char>st ; 
    string result = "";
    int n =s.size() ; 

    for(i = 0 ; i < n ; i ++ ){
        char c = s[i] ;

        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')|| (c >= '0') && (c <= '9'))result += c ; 
        else if(c == '(')st.push(c) ;
        else if(c == ')'){
            while(!st.empty() && st.top() != '('){
                result += st.top() ; 
                st.pop() ; 
            }
            st.pop() ; 
        }
        else {
            if(c == '^'){
                while(!st.empty() && priority(c) <= priority(st.top())){
                    result += st.top() ; 
                    st.pop() ; 
                }

            
            }
            else {
                while(!st.empty() && priority(c) < priority(st.top())){
                    result += st.top() ; 
                    st.pop() ; 
                }
            }

            st.push(c) ; 
        }

    } 
    while(!st.empty()){
        result += st.top() ; 
        st.pop() ; 
    }

    reverse(result) ; 
    string prefix = "" ; 

   for(int j = 0 ; j < result.size() ; j ++ ){
    if(result[j] == '(' || result[j] == ')')continue;

    prefix +=result[j];

   }

    cout << "your prefix expression is : " << prefix << endl ; 

}

int main() {
    string s = "(a+b)-(c+d)*b";

    cout << "infix expression is : " << s << endl ; 
    

    infixtoprefix(s);
    return 0 ; 
}