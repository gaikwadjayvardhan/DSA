#include<iostream>
#include<string>
using namespace std;


class Stack{
	char arr[100];
	char top;
	
	public:
	
	Stack(){top = -1;}
	
	void push(char val){
		if(top == 99){
			// cout<<"Stack Overflow\n";
			return;
		}
		arr[++top] = val;
	}
	char peek(){
		if (top == -1){
			// cout<< "Stack Underflow\n";
			return '\0';
		}
		return arr[top];
	}
	
	char pop(){
		if (top == -1){
			// cout<< "Stack Underflow\n";
			return '\0';
		}
		return arr[top--];
	}

	bool isEmpty(){
		if (top == -1){
			// cout<< "Stack Underflow\n";
			return true;
		}	
		return false;
	}
	bool isFull(){
		if(top == 99){
			// cout<<"Stack Overflow\n";
			return true;
		}
		return false;
	}


	void display(){
		for(int i = top; i>=0; i--){
			cout<< arr[i]<< " ";
		cout<<endl;
		}
	
	}
};

int prec(char op){
	if(op == '^') return 3;
	else if(op == '*' || op == '/') return 2;
	else if(op == '+' || op == '-') return 1;
	else return -1;
}

bool isRightAssociative(char c){
	return c == '^';
}

string InfixToPostfix(string &s){
	Stack st;
	string res;

	for(int i = 0; i < s.length(); i++){
		char c = s[i];

		if((c >= 'a' && c <= 'z') || (c>='A' && c<='Z') || (c>='0' && c<= '9')){
			res += c;

		}

		else if(c == '('){
			st.push(c);
		}
		else if(c == ')'){
			while(!st.isEmpty() && st.peek() != '('){
				res += st.pop();
			}
			st.pop();
		}
		else{
			while(!st.isEmpty() && prec(st.peek()) >= prec(c)){
				res += st.pop();
			}
			st.push(c);
		}	
	}

	while(!st.isEmpty()){
		res += st.pop();

	}
	return res;
}	

bool paranCheck(char o, char c){
	if(o == '(' && c == ')') return true;
	if(o == '{' && c == '}') return true;
	if(o == '[' && c == ']') return true;
	return false;
}

bool wellParan(string &a){
	Stack s;
	for(int i = 0; a[i]!='\0'; i++){
		char c = a[i];

		if(c == '(' || c == '{' || c == '['){
			s.push(c);
		}
		else if(c == ')' || c == '}' || c == ']'){
			if(s.isEmpty()) return false;

			if(!paranCheck(s.pop(), c)) return false;

		}
	}
	return s.isEmpty();
}



int main(int argc, char* argv[]){




	if (argc != 2) return 1;
	string paran = argv[1];
	if(wellParan(paran)) cout<<"Well Paran"<<endl;
	else cout<<"Not Well Paran."<< endl;
 //    // cout << "Enter infix: ";
 //    // cin >> infix;

 //    cout << "Postfix: " << InfixToPostfix(infix) << "\n";
    return 0;	
}