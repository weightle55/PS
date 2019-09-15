import java.math.BigInteger;
import java.util.Scanner;

public class level{

    public static void main(String[] args){

        Scanner input = new Scanner(System.in);
        int N;
        N=input.nextInt();

        System.out.println(fibo(N));
    }

    public static BigInteger fibo(int N){
        if(N==0) return BigInteger.ZERO;
        else if(N==1) return BigInteger.ONE;
        else{
            BigInteger x=BigInteger.ZERO;
            BigInteger y=BigInteger.ONE;
            BigInteger z=BigInteger.ONE;
            for(int i=2;i<N;i++){
                x=y;
                y=z;
                z=x.add(y);
            }
            return z;
        }
    }
}