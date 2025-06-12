public class HelperChecksum{
	
	public static int  computeCkSum1(String s){
		int sum = 0;
		for(int i = 0 ; i < s.length(); ++i ){
			sum += s.charAt(i);
		}
		return sum;
	}
	
	public static int  computeCkSum2(String s){
		int sum1 = 0;
		   int sum2 = 0;
		   int index;

		   for( index = 0; index < s.length(); ++index )
		   {
			  sum1 = (sum1 + s.charAt(index)) % 255;
			  sum2 = (sum2 + sum1) % 255;
		   }

		   return (sum2 << 8) | sum1;
		}
}
