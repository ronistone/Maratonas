import java.math.BigInteger;
import java.util.Scanner;

public class Main{
	
	public Main(){}
	
	public static void main(String[] args){
			
			BigInteger a,b;
			String a1,b1,e;
			Scanner ler = new Scanner(System.in);
			while(ler.hasNext()){
				boolean num1=false,num2=false,ans=false;
				a1 = ler.next();
				e = ler.next();
				b1 = ler.next();
				System.out.println(a1 + " " + e + " " + b1);
				a = new BigInteger(a1);
				b = new BigInteger(b1);
				if(a.bitLength() > 31)
					System.out.println("first number too big");
				if(b.bitLength() > 31)
					System.out.println("second number too big");
				if(e.equals("+")){
					if(a.add(b).bitLength() > 31)
						ans = true;
				}
				if(e.equals("*")){
					if(a.multiply(b).bitLength() > 31)
						ans = true;
				}
				if(ans)
					System.out.println("result too big");
			}
	}
}
