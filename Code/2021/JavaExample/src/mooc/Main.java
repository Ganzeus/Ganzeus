package mooc;

import java.util.Scanner;

public class Main {
    public static void f(){
        int a[]=new int [10];
        int index;
        Scanner in = new Scanner(System.in);
        index = in.nextInt();
        try{
            a[index]=index;
            System.out.println("No Exception");
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("f()");
            throw e;
        }
    }
    public static void main(String[] args) {

        try{
            System.out.println("Before");
            f();
            System.out.println("No Exception");
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Caught");
            e.printStackTrace();
        }
    }
}
