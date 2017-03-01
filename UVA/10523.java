import java.math.BigInteger;
import java.util.Scanner;


public class Main{

	public Main(){}
	
	public static void main(String[] args){
		BigInteger a,b;
		int n;
		Scanner ler = new Scanner(System.in);
		
		while(ler.hasNext()){
			n = ler.nextInt();
			b = ler.nextBigInteger();
			a = BigInteger.ZERO;
			for(int i=1;i<=n;i++){
				a = a.add(b.pow(i).multiply(BigInteger.valueOf(i)));
			}
			System.out.println(a);
		}
	
	}

}
