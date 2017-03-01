import java.math.BigInteger;
import java.util.Scanner;


public class Main{
	
	public Main(){}
	
	public static void main(String[] args){
			
		BigInteger ans = BigInteger.ZERO,b;
		Scanner ler = new Scanner(System.in);
		while(ler.hasNext()){
				b = ler.nextBigInteger();
				ans = ans.add(b);
		}
		System.out.println(ans);
		
	}
	
}
