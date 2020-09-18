import java.util.*;

public class MinStack {
    Stack<Integer> mins;
    Stack<Integer> objects;

    public MinStack() {
        mins = new Stack();
        objects = new Stack();

    }

    public void push(int x) {
        objects.push(x);

        if (mins.empty() || x <= mins.peek()) {
            mins.push(x);
        }
    }

    public void pop() {
        if (objects.pop().equals(mins.peek())) {
            mins.pop();
        }
    }

    public int top() {
        return objects.peek();
    }

    public int getMin() {
        return mins.peek();
    }

    public static void main(String[] args) {
        MinStack minStack = new MinStack();

        minStack.push(3);
        System.out.println(minStack.top());
        minStack.pop();
    }
}

