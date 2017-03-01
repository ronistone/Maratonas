import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	public Main(){}
	
	public static String reverse(String a){
		String aux = "";
		
		for(int i=a.length()-1;i>=0;i--){
				aux = aux.concat(a.substring(i,i+1));
		}
		return aux;
	}
	
	public static void main(String[] args){
		long n;
		Scanner ler = new Scanner(System.in);
		BigInteger a,b;
		String s1,s2,aux,aux2;
		
		n = ler.nextLong();
		
		for(long i = 0;i< n;i++){
			a = ler.nextBigInteger();
			b = ler.nextBigInteger();
			
			s1 = reverse(a.toString());
			s2 = reverse(b.toString());
			a = new BigInteger(s1);
			b = new BigInteger(s2);
			
			s1 = reverse(a.add(b).toString());
			a = new BigInteger(s1);
			System.out.println(a);
		}
	
	}

}
