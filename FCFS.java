import java.lang.*;
import java.util.*;

class LLData {
    int n;
    int cpuTime;
    int arrivalTime;

    public LLData(int a, int b, int c) {
        n = a;
        cpuTime = b;
        arrivalTime = c;
    }
}

public class FCFS {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        LinkedList<LLData> ll = new LinkedList<LLData>();
        int ans = 1;
        int n = 0;
        while (ans == 1) {
            System.out.println("Enter Process Number, Cpu Time and Arrival Time");
            LLData lldata = new LLData(sc.nextInt(), sc.nextInt(), sc.nextInt());
            ll.add(lldata);
            n = n + 1;
            System.out.println("Enter 1 to add a process data and 0 to exit");
            ans = sc.nextInt();
        }
        int current = 0;
        int index = 0;
        while (current != ll.size()) {
            index = current + 1;
            while (index != ll.size()) {
                if (ll.get(index).arrivalTime < ll.get(current).arrivalTime) {
                    LLData temp;
                    LLData temp2;
                    temp = ll.get(index);
                    temp2 = ll.get(current);
                    ll.remove(index);
                    ll.remove(current);
                    ll.add(current, temp);
                    ll.add(index, temp2);
                }
                index += 1;
            }
            current += 1;
        }
        int completionTimes[] = new int[ll.size()];
        int turnaroundTimes[] = new int[ll.size()];
        int waitingTimes[] = new int[ll.size()];

        System.out.println();
        int time = 0;
        if (time != ll.get(0).arrivalTime) {
            time = ll.get(0).arrivalTime;
            System.out.print("0 \t Idle \t\t" + time + " \t");
            time += ll.get(0).cpuTime;
            System.out.print("\t P" + ll.get(0).n + "\t\t " + time + " \t");
        } else {
            System.out.print("0 ");
            time += ll.get(0).cpuTime;
            System.out.print("\t P" + ll.get(0).n + " \t " + time + " \t");
        }
        completionTimes[0] = time;
        turnaroundTimes[0] = (time - ll.get(0).arrivalTime);
        waitingTimes[0] = (turnaroundTimes[0] - ll.get(0).cpuTime);

        int i = 1;
        float atat=0.0f,awat=0.0f;
        while (i != n) {
            if (ll.get(i).arrivalTime <= time) {
                time += ll.get(i).cpuTime;
                completionTimes[i] = time;
                turnaroundTimes[i] = (time - ll.get(i).arrivalTime);
                atat+=turnaroundTimes[i];
                waitingTimes[i] = (turnaroundTimes[i] - ll.get(i).cpuTime);
                awat+=waitingTimes[i];
                System.out.print("\t P" + ll.get(i).n + "\t\t " + time + " \t");
                i++;
            } else {
                time += (ll.get(i).arrivalTime - time);
                System.out.print("\t Idle \t\t" + time + "\t");
            }
        }

        System.out.println("\n");
        System.out.println("Process \t Turnaround Time \t Waiting Time");
        for (i = 0; i < n; i++) {
            System.out.println("P" + ll.get(i).n + "\t\t\t" + turnaroundTimes[i] + "\t\t\t" + waitingTimes[i]);
        }
        System.out.println();
        System.out.println("Average Turnaround Time is "+(atat/ll.size()));
        System.out.println("Average Waiting Time is "+(awat/ll.size()));
        sc.close();
    }
}