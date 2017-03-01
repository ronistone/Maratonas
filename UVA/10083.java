import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	public Main(){}
	
	public static void main(String[] args){
		
		BigInteger t,ans1,ans2;
		int a,b;
		String e;
		Scanner ler = new Scanner(System.in);
		
		
		while(ler.hasNext()){
			t = ler.nextBigInteger();
			a = ler.nextInt();
			b = ler.nextInt();
			
			ans1 = t.pow(a).subtract(BigInteger.ONE);
			ans2 = t.pow(b).subtract(BigInteger.ONE);
			if(ans1.remainder(ans2).equals(BigInteger.ZERO) ans ans1.divide(ans2).toString().length() < 100 )
				System.out.println("("+t+"^"+a+"-1)/("+t+"^"+b+"-1) "+ ans1.divide(ans2));
			else
				System.out.println("("+t+"^"+a+"-1)/("+t+"^"+b+"-1) "+"is not an integer with less than 100 digits.");
		}
	
	}

}
