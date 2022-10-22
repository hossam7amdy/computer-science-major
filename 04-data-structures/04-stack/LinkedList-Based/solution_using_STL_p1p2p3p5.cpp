#include<iostream>
#include<stack>
#include<vector>
#include<cmath>
#include<assert.h>
#include<algorithm>
using namespace std;

/// p1
int precedence(const char &ch){
    if(ch == '+' || ch == '-')
        return 1;
    else if(ch == '*' || ch == '/')
        return 2;
    else if(ch == '^')
        return 3;
    return 0;
}
string infixToPostfix(string infix){
    string postfix;
    stack<char> operators;

    infix += '-'; // force stack to get empty
    operators.push('#'); // dummy

    for(int i = 0; i < (int)infix.size(); ++i){
        char ch{ infix[i] };
        if(isalnum(ch))
            postfix += ch;
        else if(ch == '(')
            operators.push(ch);
        else if(ch == ')'){
            while(operators.top() != '('){
                postfix += operators.top();
                operators.pop();
            }
            operators.pop(); // '(' itself
        }
        else{
            while(precedence(ch) < precedence(operators.top()) || // special case to handle '^' operator
                  precedence(ch) == precedence(operators.top()) && operators.top() != '^'){
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }
    return postfix;
}

/// p2
double calculator(const double &op1, const char &ch, const double &op2){
    if(ch == '+')
        return op1 + op2;
    else if(ch == '-')
        return op1 - op2;
    else if(ch == '*')
        return op1 * op2;
    else if(ch == '/')
        return op1 / op2;

    return pow(op1, op2);
}
double evaluatePostfix(const string &postfix){
    stack<double> result;
    for(int i = 0; i < (int)postfix.size(); ++i){
        char ch { postfix[i] };
        if(isalnum(ch))
            result.push((double)ch - '0');
        else{
            double op1{ result.top() };
            result.pop();
            double op2{ result.top() };
            result.pop();

            result.push( calculator(op2, ch, op1) );
        }
    }

    return result.top();
}

/// p3
string infixToPrefix(string infix){
    string prefix;
    stack<char> operators;

    infix = '#' + infix;
    operators.push('#');

    for(int i = (int)infix.size()-1; i >= 0; --i){
        char ch{ infix[i] };

        if(isalnum(ch))
            prefix += ch;
        else{
            while(precedence(ch) < precedence(operators.top()) ||
                precedence(ch) == precedence(operators.top()) && ch == '^'){
                    prefix += operators.top();
                    operators.pop();
            }
            operators.push(ch);
        }
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

/// p5
string removeExpBrackets(string exp){
    stack<char> op;
    op.push('+'); // causes no change

    string ans;
    for(int i = 0; i < (int)exp.size(); ++i){
        char ch{ exp[i] };

        if(isdigit(ch))
            ans += ch;
        else if(ch == '(')
            op.push(ans.back());
        else if(ch == ')')
            op.pop();
        else
            (ch == op.top()) ? ch = '+' : ch = '-', ans += ch;
    }

    return ans;
}

// testing
void p1(){
    assert(infixToPostfix("4^3^2") == "432^^");
    assert(infixToPostfix("5+4^3^2-9") == "5432^^+9-");
    assert(infixToPostfix("a+b*(c^d-e)^(f+G*h)-i") == "abcd^e-fGh*+^*+i-");
    assert(infixToPostfix("1+2^3^4*5-6") == "1234^^5*+6-");
}

void p2(){
    assert(evaluatePostfix(infixToPostfix("5/2")) == 2.5);
    assert(evaluatePostfix(infixToPostfix("1+2+3")) == 6);
    assert(evaluatePostfix(infixToPostfix("1+2*3")) == 7);
    assert(evaluatePostfix(infixToPostfix("2*3+4")) == 10);
    assert(evaluatePostfix(infixToPostfix("1+3*5-7/2")) == 12.5);
    assert(evaluatePostfix(infixToPostfix("4^3^2")) == 262144);
}

void p3(){
    assert(infixToPrefix("1+2") == "+12");
    assert(infixToPrefix("9-2+3") == "+-923");
    assert(infixToPrefix("4^3^2") == "^4^32");
    assert(infixToPrefix("1+2+3") == "++123");
    assert(infixToPrefix("1+2*3") == "+1*23");
    assert(infixToPrefix("2*3+4") == "+*234");
    assert(infixToPrefix("1+3*5-8/2") == "-+1*35/82");
}

void p5(){
    string test;

	test = "1+2-3-4+5-6-7+8";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("1+2-3-4+5-6-7+8" == removeExpBrackets(test));

	test = "9-(2+3)";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("9-2-3" == removeExpBrackets(test));

	test = "9-(2-3)";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("9-2+3" == removeExpBrackets(test));

	test = "9+(2-3)";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("9+2-3" == removeExpBrackets(test));

	test = "1-(2-3-(4+5))-6-(7-8)";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("1-2+3+4+5-6-7+8" == removeExpBrackets(test));

	test = "1-(2-3-(4+5)+6-7)";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("1-2+3+4+5-6+7" == removeExpBrackets(test));

	test = "1-(2-3-(4+5-(6-7)))";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("1-2+3+4+5-6+7" == removeExpBrackets(test));

	test = "1-((4+5)-(6-7)))";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("1-4-5+6-7" == removeExpBrackets(test));

	test = "1-(((4-5)-(6-7))))";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("1-4+5+6-7" == removeExpBrackets(test));

	test = "1-(2-3-((4+5)-(6-7)))";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("1-2+3+4+5-6+7" == removeExpBrackets(test));

	test = "1-(2-3-((4-5)-(6-7)))";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("1-2+3+4-5-6+7" == removeExpBrackets(test));

	test = "1-(2-3+((4-5)-(6-7)))";
	//cout << test << " => " << removeExpBrackets(test) << "\n";
	assert("1-2+3-4+5+6-7" == removeExpBrackets(test));

}

int main(){
    //p1();
    //p2();
    //p3();
    //p5();

    cout << infixToPostfix("A+B*((C*D)-E)*(F/G)") << endl;

    return 0;
}
