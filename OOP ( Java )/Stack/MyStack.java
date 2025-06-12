import java.util.Scanner;
import mystack.*;
import stackex.*;
	public class MyStack{
		public static void main(String[] args){
			Scanner sc = new Scanner(System.in);
			System.out.println("Dat N: ");
			int N = sc.nextInt();
			
			StivaStatica s = new StivaStatica(N);
			try{
				s.push("10");
				s.push("10");
				s.pop();
				s.pop();
				s.pop();
			}catch(StackFullException ex) {
				ex.printStackTrace();
			}
			catch(StackEmptyException ex) {
				ex.printStackTrace();
			}
			//System.out.println(s + " ");
			
		}
	}
	