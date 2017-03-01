
import java.math.BigInteger;
import java.util.Scanner;

public class Main{

	public Main(){
	}
	
	public static void main(String[] args){
		
		BigInteger b,ans;
		int n=-1,a=-1,cont=1;
		Scanner ler = new Scanner(System.in);
		
		while(n!=0 && a!=0){
			n = ler.nextInt();
			a = ler.nextInt();
			if(n==0 && a==0)
				break;
			ans = BigInteger.ZERO;
			for(int i = 0;i<n;i++){
				b = ler.nextBigInteger();
				ans = ans.add(b);
			}
			b = ans.divide(BigInteger.valueOf(a));
			System.out.println("Bill #"+cont+" costs "+ans.toString()+": each friend should pay "+b.toString()+"\n");
			cont++;
		}
		
	
	}

}
