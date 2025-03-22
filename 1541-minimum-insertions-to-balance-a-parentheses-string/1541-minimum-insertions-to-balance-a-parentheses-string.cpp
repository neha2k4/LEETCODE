class Solution {
public:
    int minInsertions(string s) {
        stack <char> st;
        
        // open & close denote number of open and close brackets needed respectively
        int open = 0, close = 0;
        
        for(int i = 0; i<s.length(); i++){
            // Push all open brackets
            if(s[i]=='(') st.push(s[i]);
            
            // For close brackets
            else if(s[i]==')') {
                // if consecutive close brackets appear, remove one open bracket from stack which would balance the two close brackets.  
				// If however stack is empty, an open bracket is needed. 
                if(  i<s.length()-1 && s[i+1]==')'){
                    if(!st.empty()) st.pop();
                    else open++;
                    i++; //Remember to increment the ith pointer!!
                }
                
                // if the next element is not a closing bracket- 2 cases: stack is empty or not
                else{
                    // for an empty stack ->    ')' bracket needs an '(' and a ')' to make '( ) )' 
                    if(st.empty()){
                        open++;
                        close++; 
                    }
                    
                    //for a filled stack ->     ')' bracket and atleast 1 '(' in stack would need 1 ')' to make '( )) ' 
                    else{
                        close++;
                        st.pop();
                    }
                }
            }
        }
        
        /* After traversing the complete string, the minimum brackets needed include:
        1. st.size() indicates the '(' which never had the required number of ')' found in the string.
        2. close indicates number of close bracketes needed
        3. open indicates number of open brackets needed. Note that these are the need of '(' brackets encountered when stack was empty. 
        */
        int total = st.size() * 2 + close + open;
        return total; 
		}
};