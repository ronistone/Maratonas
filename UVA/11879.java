import java.math.BigInteger;
import java.util.Scanner;


public class Main{
	
	public Main(){}
	
	public static void main(String[] args){
			
			BigInteger b;
			Scanner ler = new Scanner(System.in);
			
			while(ler.hasNext()){
				b = ler.nextBigInteger();
				if(b.equals(BigInteger.ZERO))
					break;
				
				if(b.remainder(new BigInteger("17")).equals(BigInteger.ZERO))
					System.out.println("1");
				else
					System.out.println("0");
			}
		
	}
}
