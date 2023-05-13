import java.util.*;

public class producer_consumer{

    public static int n = 7;
    public static int full = 0, empty = n;
    public static Stack<Integer> buffer = new Stack<Integer>();
    
    public static void main(String[] args) {

        Producer p = new Producer();
        p.start();
        Consumer c = new Consumer();
        c.start();

    }

    public static void push_item(int item) {
        buffer.push(item);
        System.out.println("Pushed "+item);
    }
    
    public static void consume_item() {
        Integer y = (Integer) buffer.pop();
        System.out.println("Popped "+y);
    }

    // Getter method to access the stack
    public static Integer getBufferSize() {
        return buffer.size();
    }
}


class Producer extends Thread{
    public synchronized void run(){
        producer_consumer obj1 = new producer_consumer();
        int[] item_p = {1,2,3,4,5,6,7};
        int i = 0, in = 0, s;
        try {
            while(i != item_p.length){
                while(obj1.full == obj1.n){
                    Integer size = obj1.getBufferSize();
                    if(size > 3){
                        System.out.println("waiting for consumer to consume ( buffer is full )");
                        Thread.sleep(2000);
                    }
                    else {
                        System.out.println("Exit , Every item produced");
                        return;
                    } 
                }
                obj1.empty-=1;
                s = 0;
                obj1.push_item(item_p[i]);
                // buffer[in] = item_p;
                // in = (in+1)%n;
                s = 1;
                obj1.full+=1;
                i++;
                Thread.sleep(500);
            }
        } catch (Exception e) {
            System.out.println("exception in Producer : "+e);
        }
    }
}

class Consumer extends Thread{
    public synchronized void run(){
        producer_consumer obj2 = new producer_consumer();
        int i = 0, out = 0, s;
        try {   
            Thread.sleep(50);
            while(true){
                while(obj2.full == 0){
                    if(i==obj2.n){
                        System.out.println("Exit , Every item consumed");
                        return;
                    }
                    else{
                        System.out.println("waiting for producer to produce ( buffer is empty )");
                        Thread.sleep(2000);
                    }
                }
                obj2.full-=1;
                s = 0;
                obj2.consume_item();
                // out = (out+1)%n;
                obj2.empty+=1;
                s = 1;
                i++;
                Thread.sleep(3000);
            }
        } catch (Exception e) {
            System.out.println("exception in Consumer : "+e);
        }
    }
}