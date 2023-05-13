// using LinkedList
import java.util.*;

public class LRUpageReplacement {
    public static void main(String[] args) {
        int[] pageRequests =  {1, 2, 3, 4, 2, 1, 5, 3, 2, 4, 6};
        int numPageFrames = 3;

        LinkedList<Integer> pageFrames = new LinkedList<>();
        int pageFaults = 0;

        for (int i = 0; i < pageRequests.length; i++) {
            int page = pageRequests[i];

            if (!pageFrames.contains(page)) {
                if (pageFrames.size() < numPageFrames) {
                    pageFrames.addLast(page);
                } else {
                    pageFrames.removeFirst();
                    pageFrames.addLast(page);
                }

                pageFaults++;
                System.out.print("F ");
            } else {
                pageFrames.removeFirst();
                pageFrames.addLast(page);
                System.out.print("H ");
            }
        }

        System.out.println("Page faults: " + pageFaults);
    }
}
