import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	public Main(){}
	
	public static void main(String[] args){
		
		BigInteger t,ans1,ans2,ans[] = new BigInteger[110];
		int a,b;
		String e;
		Scanner ler = new Scanner(System.in);
		
		
		while(ler.hasNext()){
			t = BigInteger.ZERO;
			int n = 0;
				// max positive product ending at the current position
			BigInteger max_ending_here = BigInteger.ONE;
			 
				// min negative product ending at the current position
			BigInteger min_ending_here = BigInteger.ONE;
			 
				// Initialize overall max product
			BigInteger max_so_far = BigInteger.ONE,max = new BigInteger("-99999999999999999999999999999999");
			while(!t.equals(new BigInteger("-999999"))){
				t = ler.nextBigInteger();
					max = t.max(max);
				if(t.equals(new BigInteger("-999999")))
					break;
				ans[n] = t;
				 
				if (ans[n].compareTo(BigInteger.ZERO)==1)
				{
					max_ending_here = max_ending_here.multiply(ans[n]);
					min_ending_here = min_ending_here.multiply(ans[n]).min(BigInteger.ONE);
				}
				else if (ans[n].equals(BigInteger.ZERO))
				{
					max_ending_here = BigInteger.ONE;
					min_ending_here = BigInteger.ONE;
				}
				else
				{
					BigInteger temp = max_ending_here;
					max_ending_here = min_ending_here.multiply(ans[n]).max(BigInteger.ONE);
					min_ending_here = temp.multiply(ans[n]);
				}
				//if (max_so_far <  max_ending_here)
				  max_so_far  =  max_so_far.max(max_ending_here);
				 
				n++;
			}
			if(max_so_far.equals(BigInteger.ONE))
				max_so_far = max;
			System.out.println(max_so_far);
			
		}
	}
	
}


