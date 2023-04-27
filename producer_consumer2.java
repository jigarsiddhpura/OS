import java.util.*;

public class producer_consumer2 {
    static Stack<Integer> buffer = new Stack<Integer>();
    static int n = 7;
    static int full = 0, empty = n;
    
    public static void main(String[] args) {
        // buffer.setSize(n);
        Producer p = new Producer();
        p.start();
        Consumer c = new Consumer();
        c.start();
    }

    public static void push_item(int item) {
        synchronized(buffer) {
            if(full == n) {
                try {
                    buffer.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            buffer.push(item);
            full++;
            empty--;
            System.out.println("Pushed "+item);
            buffer.notify();
        }
    }
        

    public static void consume_item(int item) {
        synchronized(buffer) {
            if(empty == n) {
                try {
                    buffer.wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            Integer y = (Integer) buffer.pop();
            full--;
            empty++;
            System.out.println("Popped "+y);
            buffer.notify();
        }
    }
}

class Producer extends Thread {
    public void run() {
        for(int i=1;i<=10;i++) {
            producer_consumer2.push_item(i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

class Consumer extends Thread {
    public void run() {
        for(int i=1;i<=10;i++) {
            producer_consumer2.consume_item(i);
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
