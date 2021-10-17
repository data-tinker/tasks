class Solution {
    public int calculate(String s) {
        return calculateWithoutStack(s);
    }

    private int calculateWithStack(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }

        int len = s.length();
        Stack<Integer> stack = new Stack<Integer>();
        int currentNumber = 0;
        char operation = '+';
        for (int i = 0; i < len; ++i) {
            char currentChar = s.charAt(i);

            if (Character.isDigit(currentChar)) {
                currentNumber = currentNumber * 10 + (currentChar - '0');
            } else if (!Character.isWhitespace(currentChar)) {
                if (operation == '-') {
                    stack.push(-currentNumber);
                } else if (operation == '+') {
                    stack.push(currentNumber);
                } else if (operation == '*') {
                    stack.push(stack.pop() * currentNumber);
                } else {
                    stack.push(stack.pop() / currentNumber);
                }

                operation = currentChar;
                currentNumber = 0;
            }
        }

        if (operation == '-') {
            stack.push(-currentNumber);
        } else if (operation == '+') {
            stack.push(currentNumber);
        } else if (operation == '*') {
            stack.push(stack.pop() * currentNumber);
        } else {
            stack.push(stack.pop() / currentNumber);
        }

        int result = 0;
        while (!stack.isEmpty()) {
            result += stack.pop();
        }

        return result;
    }

    private int calculateWithoutStack(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }

        int len = s.length();
        int currentNumber = 0;
        int lastNumber = 0;
        int result = 0;

        char operation = '+';
        for (int i = 0; i < len; ++i) {
            char currentChar = s.charAt(i);
            if (Character.isDigit(currentChar)) {
                currentNumber = (currentNumber * 10) + (currentChar - '0');
            }

            if (!Character.isDigit(currentChar) && !Character.isWhitespace(currentChar) || i == len - 1) {
                if (operation == '+') {
                    result += lastNumber;
                    lastNumber = currentNumber;
                } else if (operation == '-') {
                    result += lastNumber;
                    lastNumber = -currentNumber;
                } else if (operation == '*') {
                    lastNumber = lastNumber * currentNumber;
                } else {
                    lastNumber = lastNumber / currentNumber;
                }

                operation = currentChar;
                currentNumber = 0;
            }
        }

        result += lastNumber;
        return result;
    }
}
