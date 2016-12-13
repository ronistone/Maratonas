/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package j;

import java.math.BigInteger;
import java.util.Scanner;

/**
 *
 * @author roni
 */
public class J {

    private static BigInteger fat(BigInteger n) {
      BigInteger answer = BigInteger.ONE;
        while(!n.min(BigInteger.ONE).equals(n)){
            answer = answer.multiply(n);
            n = n.subtract(BigInteger.ONE);
        }
        return n;
    }

    /**
     * @param args the command line arguments
     */
   
    public static void main(String[] args) {
       Scanner l = new Scanner(System.in);
       BigInteger n = l.nextBigInteger();
       
       n = fat(n);
       
       String saida = n.toString();
       int cont =0;
        int i;
        for(i=saida.length()-1;i>=0;i++){
           if(saida.charAt(i)==0){
               break;
           }
           cont++;
        }
       System.out.println(cont);
    }
    
}
