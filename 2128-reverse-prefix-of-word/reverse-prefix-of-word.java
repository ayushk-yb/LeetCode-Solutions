class Solution {
    public String reversePrefix(String word, char ch) {
        Stack<Character> st = new Stack<>();
        int i = 0;
        int n = word.length();
        while(i < n && word.charAt(i) != ch){
            st.push(word.charAt(i));
            i++;
        }

        if(i == n || i == 0){
            return word;
        }
        String result = new String();
        result += ch;
        while(!st.empty()){
            char currChar = st.peek();
            st.pop();
            result += currChar;
        }
        while(++i < n){
            result += word.charAt(i);
        }

        return result;
    }
}