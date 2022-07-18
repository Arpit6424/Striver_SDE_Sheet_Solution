bool isValidParenthesis(string expression)
{
    // Write your code here.
	Stack<char> st;
	for(int i = 0; i<expression.length(); i++){
		char ch = expression[i];
		
		if(expression[i] == ')' || expression == ']' || expression == '}'){
			if(expression[i] == ')' && st.top() == '(')
				st.pop();
			else
				return false;
			
			if(expression[i] == ']' && st.top() == '[')
				st.pop();
			else
				return false;
			
			if(expression[i] == '}' && st.top() == '{')
				st.pop();
			else
				return false;
			
			st.push(expression[i]);
		}
	}
	return true;
}