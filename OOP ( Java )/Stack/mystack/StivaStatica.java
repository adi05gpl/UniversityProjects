package mystack;
import stackex.*;

public class StivaStatica{
		private Object[] _stack;
		private int _top = 0;
		
		public StivaStatica(int N){
			_stack = new Object[N];
		}
		public void push(Object o) throws StackFullException{
			if(_top == _stack.length)
				throw new StackFullException("Stiva plina");
			else
				_stack[_top++] = o;
		}
		public Object pop() throws StackEmptyException{
			if(isEmpty() != true)
				throw new StackEmptyException("Stiva goala");
			
			return _stack[--_top];
		}
		public Object peek() throws StackFullException{
			if(isFull() != true)
				throw new StackFullException("Stiva plina");
			
			return _stack[_top-1];
		}
		public boolean isFull(){
			if(_top == _stack.length)
				return true;
			else return false;
		}
		public boolean isEmpty(){
			if(_top == 0)
				return true;
			else return false;
		}
		public void clear(){
			_top = 0;
		}
}
	