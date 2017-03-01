import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	public Main(){}

	public static void main(String[] args){
		
		BigInteger a,b;
		Scanner ler = new Scanner(System.in);
		
		while(ler.hasNext()){
			a = ler.nextBigInteger();
			b = ler.nextBigInteger();
			
			System.out.println(a.multiply(b));
		}
	
	}
	
}
