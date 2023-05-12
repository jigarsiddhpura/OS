import java.util.*;

public class multiThreading {
    public static void main(String args[]){
        Movie m = new Movie(5);
        
        Thread t1 = new Thread(m);
        Thread t2 = new Thread(m);

        t1.setName("Ajay");
        t2.setName("Vijay");
        t1.start();
        t2.start();
    }
}

class Movie extends Thread
{   
    int vacant, required = 3;
    // constructor
    Movie(int x){
        vacant = x;
    }

    public synchronized void run(){
        if(vacant >= required){
            System.out.println(required + " ticket is givennn to " + Thread.currentThread().getName());
            try{
                Thread.sleep(1000);
            }
            catch(Exception e){
                System.out.println("exception"+e);
            }
            vacant -= required ;
            
        }
        else{
            System.out.println("Housefull " + Thread.currentThread().getName());
        }
    }
}